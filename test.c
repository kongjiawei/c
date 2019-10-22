#include<stdio.h>
#include<ctype.h>


void expand(char *s1, char *s2);

int main() {
	char *s1 = "-a-d-f", s2[100];
	expand(s1, s2);
	printf("%s\n", s2);

}

void expand(char *s1, char *s2) {
	char *p;
	for (; *s1 != '\0'; s1++)
	{
		
		if (isalnum(*s1) && *(s1 + 1) == '-') 
		{
			char i = *s1;
			for (; i != *(s1 + 2); i++) 
			{
				*s2++ = i;
			}
			*s2++ = i;
			s1 = s1 + 2;
		}
		else if ((*s1 == '-') && isalnum(*(s1 - 1)))
		{
			char i = *(s1 - 1);
			for (i++; i != *(s1 + 1); i++)
			{
				*s2++ = i;
			}
			*s2++ = i;
			s1 = s1 + 1;
		}
		else {
			*s2++ = *s1;
		}
	}
	*s2 = '\0';
}

