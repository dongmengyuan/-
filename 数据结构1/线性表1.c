/*************************************************************************
        > File Name: 线性表1.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
*************************************************************************/
#include<stdio.h>
#define MAX 20

typedef int ElemType;

typedef struct
{
    ElemType data[MAX];
    int length;
}sqlist;

sqlist *l;

int insert(sqlist *l, int i, ElemType x)
{
    int j;
    if(l -> length == MAX-1) {
        printf("表满");
        reurn OVERFLOW;
    }

    if(i < 1 || i > l->length + 1) {
        printf("位置错");
        return ERROR;
    }

    for(j = l->length; j >= i; j--)
        l -> data[j+1] = l -> data[j];
    l -> data[i] = x;
    l->length++;
    return TRUE;
}

int delete(sqlist *l, int i)
{
    int j;
    if(i < 1 || i > l->length) {
        printf("位置错误，不存在");
    }
    for(j = i; j <= l->length-1; j++)
       l -> data[j] = l -> data[j+1];
    l->length--;
    return TRUE;
}

void print(sqlist *l)
{

    
}

int main()
{
    
}

