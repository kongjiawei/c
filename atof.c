#include<stdio.h>
#include<ctype.h>
#include<math.h>

double atof(char *s);

int main() {
	char *s = "-123.45e3";
	double a = atof(s);
	int c = pow(2,3);
	printf("%.12f\n",a);

}

double atof(char *s) {
	double val, power;
	int sign, exp;
	for (; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0.0; isdigit(*s); s++)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1.0; isdigit(*s); s++)
	{
		val = 10.0 * val + (*s - '0');
		power = power * 10.0;
	}
	if (*s == 'e' || *s == 'E')
		s++;
	else {
		return sign * val / power;
	}
	int flag = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (exp = 0; isdigit(*s); s++)
	{
		exp = 10 * exp + (*s - '0');
	}
	return (sign * val / power) * pow(10, flag*exp);
		

}
