#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES 1000

int getline(char s[], int max_len);
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input out of range\n");
        return 1;
    }
}

#define MAXLEN 1000

int getline(char s[], int max_len)
{
    int c, i;
    for(i=0; i < max_len-1 && (c = getchar()!= EOF) && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    //p 用于临时指向malloc的空间
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p = (char*) malloc(sizeof(char) * len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i=0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
        
    }
}

void qsort(char *v[], int left, int right)
{   
    int i, last;
    void swap(char *v[], int i, int j);
    if(left >= right)
    {
        return;
    }
    //将中间位置的元素作为基本元素
    swap(v, left, (left + right) / 2); 
    last = left; 
    for(i = left+1; i <= right; i++)
    {
        if(strcmp(v[i], v[last]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}