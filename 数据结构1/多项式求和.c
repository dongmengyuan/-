/*************************************************************************
        > File Name: 多项式求和.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年09月27日 星期二 16时40分28秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node 
{
    int coef;
    int expn;
    struct node *next;
}polynimial,*polyn;

polyn creat(int i)
{
    polyn head;
    head = (polyn) malloc (sizeof(polyn));
    polynimial *r,*s;
    r = head;
    int j;
    char a,b;
    for(j = 0; j <= i; j++) {
        s = (polynimial *) malloc (sizeof(polynimial));
        scanf("%c%d,%d%c",&a,&s -> coef,&s -> expn,&b);
        r -> next = s;
        r = s;
    }
    return head;
}

void print(polyn p)
{
    polyn q = p -> next -> next;
    int flag = 1;
    if(!q) {
        putchar('0');
        printf("\n");
        return;
    }
    while(q) {
        if(q -> coef > 0 && flag != 1) {
            putchar('+');
        }
        if(q -> coef != 1 && q -> coef != -1) {
            printf("%d",q -> coef);
            if(q ->  expn == 1) {
                putchar('X');
            }
            else if(q -> expn) {
                printf("X^%d",q -> expn);
            }
        }
        else {
            if(q -> coef == 1) {
                if(!q -> expn) {
                    putchar('1');
                }
                else if(q -> expn == 1) {
                    putchar('X');
                }
                else {
                    printf("X^%d",q -> expn);
                }
            }
            if(q -> coef == -1) {
                if(!q -> expn) {
                    printf("-1");
                }
                else if(q -> expn == 1) {
                    printf("-X");
                }
                else {
                    printf("-X^%d",q ->  expn);
                }
            }
        }
        q = q -> next;
        flag++;
    }
    printf("\n");
}

polyn add(p,q)
{
    polynimial head;
    polyn pp = p -> next;
    polyn qq = q -> next;
    polyn 
   



int main()
{
    int i,m;
    scanf("%d",&i);
    polynimial *p,*q,*s;
    p = creat(i);
    scanf("%d",&m);
    q = creat(m);
    s = add(i,m);
    print(s);
}
