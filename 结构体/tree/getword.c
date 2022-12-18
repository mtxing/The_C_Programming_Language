#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXSIZE 1000

char buffer[MAXSIZE];
int ptr;


int getch(void)
{
    int p = ptr > 0 ? buffer[--ptr] : getchar();
    return p;
}

void ungetch(int c)
{
    if(ptr >= MAXSIZE)
    {
        printf("out of range of buffer");
    }
    else
        buffer[ptr++] = c;
}

int getword(char * word, int lim)
{
    int c;
    char *w = word;
    
    while(isspace(c = getch()));
    if(c != EOF)
    {
        *w++ = c; 
    }
    if(! isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++)
    {
        //判断字符变量c是否为字母或数字，若是则返回非零，否则返回零
        if(!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}