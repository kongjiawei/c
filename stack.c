#include<stdio.h>
#include "calc.h"

#define MAXVAL 100
static int sp = 0;
static double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void stack_0_print(void){
	printf("top of stack: %f\n", val[--sp]);
	sp++;
}

double stack_0_copy(void){
	int p = sp - 1;
	val[sp++] = val[p];
}

void exchange_stack(void) {
	double temp;
	int p = sp - 1;
	temp = val[--p];
	val[p] = val[p + 1];
	val[p + 1] = temp;
}

void clear_stack(void) {
	sp = 0;
}