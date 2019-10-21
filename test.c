#include<stdio.h>
void squeeze(char *s1, char *s2);
int main() {
	char s1[] = "12345106";
	char s2[] = "123";
	squeeze(s1, s2);
	printf("%s", s1);
}

void squeeze(char *s1, char *s2)
{
	char *start = s1, *s1_copy = s1;
	for (; (*s2) != '\0'; s2++)
	{
		for (s1 = start, s1_copy = start; *s1 != '\0'; s1++)
		{
			if (*s1 != *s2)
			{
				*s1_copy++ = *s1;
			}

		}
		*s1_copy = '\0';
	}
}