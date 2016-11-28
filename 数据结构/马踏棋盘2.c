#include<stdio.h>
#include<time.h>
#define N 8


int CHESS[N][N];

typedef struct 
{
    int x, y;
    int waysout;
}Node;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


void dfs(int x, int y, int count);
void Print();
void sortnode(Node *hn, int n);
int ways_out(int x, int y);

int ways_out(int x, int y)
{
    int i, count  = 0;
    int x1, y1;

    if(x < 0 || y <0 || x >= N || y >= N || CHESS[x][y] > 0)
    {
        return -1;
    }
    for(i = 0; i < 8; i++)
    {
        x1 = x + dx[i];
        y1 = y + dy[i];

        if(x1 < 0 || y1 < 0 || x1 >=N || y1 >= N )
        {
            continue;
        }
        if(0 == CHESS[x1][y1])
        {
            count += 1;
        }
    }
    return count;
}

//深搜遍历
void dfs(int x, int y, int count)
{
    int i, x1, y1;
    Node hn[8];

    if(count > N * N )//出口，全部遍历
    {
        //printf("count = %d\n\n\n\n\n\n\n", count);
        Print();
        return ;
    }

    for(i = 0; i < 8  ; i++ )
    {
        hn[i].x = x1 = x + dx[i];
        hn[i].y = y1 = y + dy[i];
        hn[i].waysout = ways_out(x1, y1);
    }
    sortnode(hn, 8);
    for(i = 0; hn[i].waysout < 0; ++i);
    for(; i < 8; ++i)
    {
        x1 = hn[i].x;
        y1 = hn[i].y;
        CHESS[x1][y1] = count;
        dfs(x1, y1, count + 1);
    }

}

void Print()
{
    int i, j;

    for(i = 0; i < N ;i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%5d", CHESS[i][j]);
        }

        printf("\n\n");
    }
    printf("\n\n");
}

void sortnode(Node *hn, int n)
{
    int i, j, t;
    Node temp;
    for(i = 0; i < n ; ++i)
    {
        for(t = i, j = i + 1; j < n; ++j)
        {
            if(hn[j].waysout < hn[t].waysout)
            {
                t = j;
            }
        }
        if(t > i)
        {
            temp = hn[i];
            hn[i] = hn[t];
            hn[t] = temp;
        }
    }
}

int main()
{
    clock_t start, end;
    int i, j, result = 0;
    int x, y;

    for(i = 0; i < N; i++)    //初始化棋盘
    {
        for(j = 0; j < N; j++)
        {
            CHESS[i][j] = 0;
        }
    }

    printf("请输入起始ｘ(0-%d):", N -1);
    scanf("%d", &x);
    printf("请输入起始y:(0-%d):", N -1);
    scanf("%d", &y);

    if(x < 0 || y < 0 || x >= N|| y >= N)
    {
        printf("输入错误，请重新输入\n");      
        return 0;
    }
    start = clock();
    CHESS[x][y] = 1;

    dfs(x,y,2);
    end = clock();
    printf("共用时 %fs\n\n", (double)(end -start) / 1000 ); 

    return 0;
}
