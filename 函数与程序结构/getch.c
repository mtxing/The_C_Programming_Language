#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZ];
int bufp = 0;
//由终端std输入或者由buffer输入，取决的上一次的操作有没有将操作数回退
int getch(void)
{
    return (bufp>0) ? buf[--bufp] : getchar();  
}

void ungetch(int c)
{
    if(bufp > BUFSIZ)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        // 对应的强制类型转换 
        buf[++bufp] = c;
    }
} 