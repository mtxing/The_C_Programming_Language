#include<stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main()
{
	int type;
	double op_temp;
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
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op_temp = pop();
				push(pop() - op_temp);
				break;
			case '/':
				op_temp = pop();
				if(op_temp != 0.0){
					push(pop() / op_temp);
				}
				else{
					printf("ERROR: Zero divisor\n");
				}
				break;
			case '\n':
				printf("\t %.8f\n", pop());
			default:
				printf("error: not supported %s", s);
				break;
		}
	}
	return 0;
}