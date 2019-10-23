#include<stdio.h>
#include<ctype.h>
#include<string.h>

void itob(int n, char *s, int b);


int main() {
	int n = -100;
	char s[10];
	itob(n, s, 8);
	printf("%s", s);
}

void itob(int n, char *s, int b)
{
	int i, sign;
	void reverse(char *s);
	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % b) + '0'; //½«Êý×Ö×ª»¯Îª×Ö·û
	} while ((n = n / b) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char *s) {
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c; 
	
	}
}
