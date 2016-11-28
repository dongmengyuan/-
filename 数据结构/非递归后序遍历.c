/*************************************************************************
        > File Name: 非递归先序中序遍历序列.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月21日 星期一 10时12分38秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
 
const int N = 50086;


typedef char datatype;
typedef struct Node
{
    datatype data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode, *BiTree;

typedef struct 
{
    BiTree da[1000];
    int top;
}SeqStack;

SeqStack  *InitStack()
{
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int IsEmpty(SeqStack *s)
{
    if(s->top == -1)
    return 1;
    else 
    return 0;
}

void push(SeqStack *s, BiTree root) 
{
    BiTree p;
    p = root;
    if(s->top == 999) 
        return;
    else {
        s->top++;
        s->da[s->top]=p;
    }
}


void pop(SeqStack *s, BiTree *root) 
{
    BiTree p;
    p = *root;
    if(IsEmpty(s))
        return;
    else {
        *root = s-> da[s->top];
        s->top--;
    }
}

void getTop(SeqStack *s, BiTree *p)
{
    if(IsEmpty(s))
    return ;
    else
    *p = s->da[s->top];
}

void creat(BiTree *root) 
{
    char ch;
    ch = getchar();
    if(ch == '#') {
        *root = NULL;
    }
    else {
        *root = (BiTree)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        creat(&(*root)->lchild);
        creat(&(*root)->rchild);
    }
}
 

void PostOrder(BiTree root)
{
    SeqStack *s;
    BiTree p,q;
    s=InitStack();
    p = root;
    q = NULL;
    while(p != NULL || !IsEmpty(s)) {
        while(p != NULL) {
            push(s,p);
            p = p -> lchild;
        }
        if(!IsEmpty(s)) {
            getTop(s,&p);
            if(p->rchild==NULL || p->rchild == q) {
                 pop(s,&p);
                 printf("%c",p->data);
                 q=p;
                 p=NULL;
            }
            else
                p = p -> rchild;
        }
    }
}


int main()
{
    BiTree root;
    creat(&root);
    PostOrder(root);
 
    return 0;
}
