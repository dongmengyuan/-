#include<stdio.h>
#include<malloc.h>
typedef struct poly
{
 int coef;
 int expn;
 struct poly *next; 
}polynimial,*polyn; 
polyn create(int i)
{
 int m,n,j;
 char a,b,c;
 polyn h;
 polynimial *r,*s;
 h=(polynimial *)malloc(sizeof(polynimial));
 r=h;
 for(j=0;j<=i;j++)
 {  
  s=(polynimial *)malloc(sizeof(polynimial)); 
  scanf("%c%d,%d%c",&a,&s->coef,&s->expn,&b);
  r->next=s; 
  r=s;
 }
 return h;
}
void print(polyn h)
{
 polyn p=h->next->next;
 int flag=1;
 if(!p)
 {
  putchar('0');
  printf("\n");
  return ;
 }
 while(p)
 {
    if(p->coef>0&&flag!=1) printf("+");
    if(p->coef!=1&&p->coef!=-1)
    {
     printf("%d",p->coef);
     if(p->expn==1) printf("X");
     else if(p->expn) printf("X^%d",p->expn);
    }
    else
    {
      if(p->coef==1)
      {
        if(!p->expn) printf("1");
        else if(p->expn==1) printf("X");
        else printf("X^%d",p->expn);
      }
      if(p->coef==-1)
      {
       if(!p->expn) printf("1");
       else if(p->expn==1) printf("X");
       else  printf("X^%d",p->expn);
      }
    }
     p=p->next;
     flag++;
 }
  printf("\n");
}
void main()
{
  int n;
  scanf("%d",&n);
  polyn a;
  a=create(n);
  print(a);
}
