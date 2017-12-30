#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
	size_t i;
	for (i = 0; i < len; i++)
	{
		printf("%.2x",start[i]);
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x,sizeof(int));
}
void show_float(float x){
	show_bytes((byte_pointer) &x,sizeof(float));
}
void show_pointer(void *x) {
	show_bytes((byte_pointer) &x,sizeof(void *));
}

void test(int val){
	int ival = val;
	float fval = (float)val;
	int *pval = &ival;
	show_int(ival);
	show_pointer(pval);
	show_float(fval);
}

int main()
{
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;
	show_bytes("abcdef",6);
	show_bytes(valp,2);
	show_bytes(valp,3);
}
