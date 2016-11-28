/*************************************************************************
        > File Name: 马踏棋盘.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年10月07日 星期五 19时45分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define N 100
int chess[N][N];





int main()
{
    int x,y,i,j;
    //初始化棋盘
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            chess[i][j] = 0; 
        }
    }
    printf("请输入起始x(0-%d):",N-1);
    scanf("%d",&x);
    printf("请输入起始y(0-%d):",N-1);
    scanf("%d",&y);

    //判断输入位置是否合法
    if(x <0 || y < 0 || x >= N || y >= N) {
        printf("输入错误\n");
        return 0;
    }

}
