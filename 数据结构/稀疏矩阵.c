/*************************************************************************
        > File Name: 稀疏矩阵.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年10月19日 星期三 21时03分19秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
 
#define MAX 1000

//三元组的定义
typedef struct 
{
    int row;
    int col;
    int value;
}Triple;


//三元组容器的定义
typedef struct
{
    Triple data[MAX+1];
    int rows;
    int cols;
    int nums;
}TSMatrix;

void TransposeTSMatrix(TSMatrix *A, TSMatrix *B)
{
    int i, j, min;
    B -> rows = A.cols;
    B -> cols = A.rows;
    B -> nums = A.nums;
    i = 1;
    while(i <= A.nums)
    {
        min = 1;
        for(j = 2; j <= A.nums; j++) 
          if(A.data[j].col < A.data[min].col )     min = j;
        B -> data[i].row = A.data[min].col;
        B -> data[i].col = A.data[min].row;
        B -> data[i].value = A.data[min].value;
        i++;
        A.data[min].col = A.cols + 1;
    }
}

int main()
{
    TSMatrix A, B;
    int i,j,e;
    int k = 0;
    printf("请输入三元组:");
     while(scanf("%d%d%d", &i, &j, &e)!=EOF)  
        {  
                A.data[k].row = i-1;  
                A.data[k].col = j-1;  
                A.data[k].e = e;  
                A.len = ++k;  
            }  




    return 0;
}
