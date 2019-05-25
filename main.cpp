#include<stdio.h>
#define MAXLENGTH 10
void delchar(char *s1, char *s2);
void getline(char *s);

int main() {
	char  s1[MAXLENGTH], s2[MAXLENGTH];
	getline(s1);
	getline(s2);
	printf("original:%s\n%s\n", s1,s2);
	delchar(s1, s2);
	printf("process:%s\n%s\n", s1, s2);
}

void getline(char *s)  //往s1 和 s2中读入字符串，整体读入只有在初始化时可以，之后只能逐字符串输入
{
	char c;
	int i = 0;
	for (i = 0; (i < MAXLENGTH - 1) && (c = getchar()) != '\n'; i++)
	{
		s[i] = c;
	}
	s[i] = '\0';
}

void delchar(char *s1, char *s2)  //删除s1 中和s2相同的字符
{
	for (int i = 0; (i < MAXLENGTH - 1) && (s1[i] != '\0'); i++) {
		for (int j = 0; (j < MAXLENGTH - 1) && (s2[j] != '\0'); j++)
		{
			if (s1[i] == s2[j])
			{
				for (int k = i + 1; k <= MAXLENGTH - 1; k++)
					s1[k - 1] = s1[k];
			}

		}
	}
}