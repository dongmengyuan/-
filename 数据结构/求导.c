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
polyn qiudao(polyn a)
{
 polyn h=a->next;
 polyn head,r,qa;
 head=(polyn)malloc(sizeof(polynimial));
 head=r;
 head->next=NULL;
 while(h)
 {
  qa=(polyn)malloc(sizeof(polynimial));
  qa->coef=(h->coef*h->expn);
  qa->expn=h->expn-1;
  if(qa->coef!=0)
  {
   r->next=qa;
   r=qa;
  }
  else
     free(qa);
  h=h->next;
 }
 return head;
}
void out(polyn h)
{
 polyn p=h->next;
 int flag=1;
 if(!p)
 {
  putchar('0');
  printf("\n");
  return ;
 }
 while(p)
 {
    if(p->coef>0&&flag!=1)   printf("+");
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
       else if(p->expn==1) printf("-X");
       else  printf("-X^%d",p->expn);
      }
    }
     p=p->next;
     flag++;
 }
  printf("\n");
}
void main()
{
 polyn a,b;
  int m;
  scanf("%d",&m);
  a=creat(m);
  b=qiudao(a);
  out(b);
}
