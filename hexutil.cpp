#include "hexutil.h"

unsigned char* write_to_hex(long long *values, int length) {
	int i,j=0, leng = 0;
	
	long long buf;

	char tmp[3], buffer[MAX_SIZE] = "";
	
	while ((buf = *values++) != -1) {
		unsigned char *ptr = (unsigned char*)&buf;
		
		for (i = 3; i != -1; i--) {
			sprintf(tmp, "%02x", ptr[i]);
			strcat(buffer, tmp);
			leng += 2;
		}
	}
	
	buffer[leng++] = '\0';
	int size = sizeof(unsigned char) * leng;
	unsigned char *value = (unsigned char *)malloc(size);
	memmove(value, buffer, size);

	return value;
}

int hex_to_long(unsigned char *hex, long long **dest) {
	int j=0,k=0,l=0;

	char buf, ch[9] = "";
	long long buffer[MAX_SIZE];

	while ((buf = *(hex++)) != NULL) {
		ch[k] = buf;
		
		j++;
		k++;

		if (j % 8 == 0) {
			sscanf(ch, "%lx", &buffer[l]);

			j = 0;
			k = 0;
			l++;
		}
	}

	buffer[l++] = -1;

	int size = sizeof(long long) * l;
	*dest = (long long *)malloc(size);
	memset(*dest, -1, size);
	memmove(*dest, buffer, size);

	return l;
}
