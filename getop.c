#include<stdio.h>
#include<ctype.h>
#include "calc.h"

int getop(char *s) {
	int i = 0, c,d;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	if (c == '\n')
		return c;

	if (islower(d = getch()) && islower(c)) {
		ungetch(d);
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return STRING;
	}
	ungetch(d);
	if (!isdigit(c) && c != '.' && c != '-' && c != '+') {		
			s[1] = '\0';
			return c;
	}
	if (!isdigit(d = getch()) && (c == '+' || c == '-'))
	{
		ungetch(d);
		return c;
	}
	ungetch(d);
	if (isdigit(s[0]) || (s[0] == '-') || (s[0] =='+'))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;	    
}