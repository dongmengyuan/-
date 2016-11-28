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

#define max 1000

typedef struct 
{
    BiTree da[max];
    int front;
    int rear;
}SeqQueue;

SeqQueue *InitQueue()
{
    SeqQueue *q;
    q = (SeqQueue *)malloc(sizeof(SeqQueue));
    q->front = q->rear = max-1;
    return q;
}

int IsEmpty(SeqQueue *q)
{
    if(q->front == q->rear) 
    return 1;
    else
    return 0;
}

void EnterQueue(SeqQueue *q,BiTree root)
{
    BiTree p;
    p = root;
    if((q->rear+1) % max == q->front) {
        return ;
    }
    else {
        q -> rear = (q->rear+1) % max;
        q->da[q->rear] = p;
    }
}

void out(SeqQueue *q, BiTree *root)
{
    if(q->front == q->rear) 
    return ;
    else {
        q->front = (q->front+1)%max;
        *root = q->da[q->front];
    }
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
 
void cengci(BiTree root) 
{
    SeqQueue *s;
    BiTree p;
    s=InitQueue();
    EnterQueue(s,root);
    while(!IsEmpty(s)) {
        out(s,&p);
        printf("%c",p->data);
        if(p->lchild != NULL) 
        EnterQueue(s,p->lchild);
        if(p->rchild != NULL)
        EnterQueue(s,p->rchild);
    }   
}

int main()
{
    BiTree root;
    creat(&root);
    cengci(root);
 
    return 0;
}
