#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include"calc.h"

#define MAXOP 100
double mathfunc(char *s);

int main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error, zero divisor\n");
			break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case '?':
			stack_0_print();
			break;
		case 's':
			exchange_stack();
			break;
		case 'd':
			stack_0_copy();
			break;	
		case STRING:
			push(mathfunc(s));
			break;
		case '\n':
			printf("%f\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

}

double mathfunc(char *s) {
	double op2;
	if (strcmp(s, "sin") == 0) {
		op2 = pop();
		return sin(op2);
	}

	else if (strcmp(s, "exp") == 0) {
		op2 = pop();
		return exp(op2);
	}

	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		return pow(pop(), op2);
	}

	else {
		printf("error: the function %s is not found", s);
	}
}