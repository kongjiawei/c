#include<stdio.h>

int strrindex(char *s, char *t);

int main() {
	char *s = "qwertyuiqwer", *t = "qwert";
	int i = strrindex(s, t);
	printf("%d\n", i);


}

int strrindex(char *s, char *t) {

	char *p, *start_s = s, *start_t = t;
	int index = -1;
	for (; *s != '\0'; s++)
	{
		t = start_t;
		for (p = s; *p == *t; p++, t++)
			;
		if (*t == '\0')
		{
			index = s - start_s;
		}
	}
	return index;
}
