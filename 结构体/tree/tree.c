#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode
{
    char * word;
    int count;
    struct tnode * left;
    struct tnode * right;
};

struct tnode * talloc(void)
{
    //强制类型转换
    return (struct node* ) malloc(sizeof(struct tnode));
}

struct tnode * addtree(struct tnode * p, char * w)
{
    int cond;
    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    cond = strcmp(w, p->word);
    if(cond == 0)
    {
        p->count++;
    }
    else if(cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode*p)
{
    if(p!=NULL)
    {
        treeprint(p->left);
        printf("%4d %s", p->count, p->word);
        treeprint(p->right);
    }
}





