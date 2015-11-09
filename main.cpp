#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *int2String(int val, int base){
	char *string = (char *)malloc(sizeof(char)*32);
	char *p = string;
	char *p1 = string;
	unsigned char flag;
	if(-val == val) return "-2147483648";
	flag = val > 0 ? 0 : (val = -val, 1);
	while(val){
		*p += (*p = val % base, *p) > 9 ? '7' : '0';
		val /= base;
		p++;
	}
	if(flag) *(p++) = '-';
	*p-- = 0;
	while((p - p1) > 1){
		*p ^= *p1;
		*p1 ^= *p;
		*p ^= *p1;
		p1++, p--;
	}
	return string;
}
// Total 45bytes;

int main(int argc, const char *argv[]){
	printf("%s", int2String(-2147483648, 10));
}
