#include<stdio.h>

void escape(char *s, char *t);

int main() {
	char s[10], *t;
	t = "12	3";
	escape(s, t);
	printf("%s", s);
	
}

void escape(char *s, char *t) {
	while ((*t) != '\0') {
		switch (*t) {
		case '\t': 
			*s++ = '\\';
			t++;
			*s++ = 't';
			break;
		case'\n':
			*s++ = '\\';
			*s++ = 'n';
			t++;
			break;
		default:
			*s++ = *t++;
			break;
		}

	}
	*s = '\0';
}
