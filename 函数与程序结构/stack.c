#include <stdio.h>
#include "calc.h"

# define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double x)
{
    if (sp < MAXVAL){
        val[sp++] = x;
    }
    else{
        printf("error: stack overflow, push failed\n");
    }
}
double pop(void)
{
    if(sp > 0){
        return val[sp--];
    }
    else {
        printf("error: stack is empty!\n");
    }
    return 0.0;

}