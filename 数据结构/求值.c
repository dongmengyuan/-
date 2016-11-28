#include<stdio.h>
#include<malloc.h>
#include<math.h>
typedef struct poly
{
 int coef;
 int expn;
 struct poly *next;
}polynimial,*polyn;
polyn creat(int i)
{
 int j;
 char a,b;
 polyn h=(polyn)malloc(sizeof(polyn));
 h->next=NULL;
 polynimial *r=h,*s;
 for(j=0;j<=i;j++)
 {  
  s=(polyn)malloc(sizeof(polynimial)); 
  scanf("%c%d,%d%c",&a,&s->coef,&s->expn,&b);
  r->next=s;
  r=s;
 }
 return h;
}
int qiuzhi(polyn a,int x)
{
 int sum=0;
 polyn qa=a->next;
 while(qa)
 {
  sum+=(qa->coef)*(pow(x,qa->expn));
  qa=qa->next;
 }
 return sum;
}
void main()
{
 int m,n,sum;
 scanf("%d",&m);
 polyn a;
 a=creat(m);
 scanf("%d",&n);
 printf("%d",qiuzhi(a,n));
}
