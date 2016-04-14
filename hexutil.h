#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 65535

unsigned char* write_to_hex(long long *, int length);
int hex_to_long(unsigned char *, long long **);