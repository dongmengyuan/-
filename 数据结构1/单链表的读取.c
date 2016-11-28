/*************************************************************************
        > File Name: 单链表的读取.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年10月12日 星期三 22时00分38秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef int Elemtype;

typedef struct node
{
    Elemtype data;
    struct node * next;
}node, *lnode;

lnode creatlist(lnode L)
{
    lnode head;
    head = (struct node *) malloc (sizeof(struct node));
    head -> next = NULL;
    return head;
}


lnode get(lnode L, int i, Elemtype *e)
{
    int j;
    lnode p;
    p = L -> next;
    for(j = 1; j < i; j++)
    {
        if(p) {
            p = p -> next;
        }
        if(p == 0 && j > i) {
            return ERROR;
        }

        *e = p -> data;
        return OK;
    }
}


int main()
{
    int i;
    Elemtype *e;
    lnode L;
    lnode head = (struct node *) malloc (sizeof(struct node));
    creatlist(L);
    get(L,i,e);
}
