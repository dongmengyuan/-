/*************************************************************************
        > File Name: 哈夫曼树.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月28日 星期一 12时07分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
 
#define N 30
#define M 2*N-1

typedef struct 
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode, HuffmanTree[M+1];

//建立哈夫曼树
void create(HuffmanTree ht, int w, int n)
{
    int i;
    int m = 2*n-1;
    for(i = 1; i <= n; i++)      ht[i] = {w[i],0,0,0};
    for(i = n+1; i <= m; i++)    ht[i] = {0,0,0,0};
    for(i = n+1; i <= m; i++) {
        select(ht,i-1,&s1,&s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].lchild = s1;
        ht[i].rchild = s2;
        ht[s1].parent  = i;
        ht[s2].parent = i;
    }
}

//哈夫曼编码
void crthuffmancode1(HuffmanTree ht, HuffmanTree hc, int n)
{
    int i;
    char *cd;
    int start;
    cd  = (char *)malloc(n*sizeof(char ));
    cd[n-1] = '\0';
    for(i = 1; i <= n; i++) {
        start = n-1;
        c = i;
        p = ht[i].parent;
        while(p != 0) {
            --start;
            if(ht[p].lchild == c)      cd[start] = '0';
            else                       cd[start] = '1';
            c = p;
            p = ht[p].parent;
        }
        hc[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
}

int main()
{
 
    return 0;
}
