/*************************************************************************
        > File Name: 顺序表的插入.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年10月09日 星期日 10时25分46秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define Max 100;
typedef int Elemtype;

typedef struct {
    Elemtype elem[Max];
    int length;
}Seqlist;

Seqlist *L;


//顺序表的初始化
void init_Seqlist(Seqlist *L)
{
    L -> length = 0;
}

//顺序表的插入
int insert_Seqlist(Seqlist *L, int i, Elemtype x)
{
    if(L -> length == Max - 1) {
        printf("顺序表已满");
        return false;
    }
    if(i < 1 || i > length + 1) {
        printf("插入顺序不合法");
    }
    
}

int main()
{
    int i;
    Elemtype x;
　　init_Seqlist(&L);
    insert_Seqlist(&L, i, x);

    return 0;
}
