#include<stdio.h>

//#define swap(t,x,y) { t _z; _z = x; x = y; y = _z;} 
void swap(int x, int y);

int main() {
	int a = 12, b = 3;
	swap(a, b);
	printf("%d\n", a);

}

void swap(int x, int y) {
	int z;
	z = x;
	x = y;
	y = z;
}