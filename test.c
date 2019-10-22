#include<stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
	unsigned int i = 16, j;
	j = rightrot(i, 6);
	printf("%d",j);	
}

unsigned int rightrot(unsigned x, int n)
{
	unsigned intermediate = ~(~0 << n) & x;
	x = x >> n;
	intermediate = intermediate << (8 * sizeof(int) - n);
	x = x | intermediate;
	return x;
}