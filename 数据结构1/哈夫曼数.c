/*************************************************************************
        > File Name: 哈夫曼数.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年10月31日 星期一 17时30分14秒
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

void CrtHuffmanTree(HuffmanTree ht, int w, int n)
{
    int i,m;
    m = 2*n-1;
    for(i = 1; i <= n; i++) 
        ht[i] = {w[i],0,0,0};
    for(i = n+1; i <= m; i++)
        ht[i] = {0,0,0,0};
    for(i = n+1; i <= m; i++) {
       // select(ht, i-1,&s1,&s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].lchild = s1;
        ht[i].rchild = s2;
        ht[s1].parent = i;
        ht[s2].parent = i;
    }

}





int main()
{
 
    return 0;
}
