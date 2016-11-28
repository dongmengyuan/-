#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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
polyn add(polyn a,polyn b)
{
 polyn qa=a->next;
 polyn qb=b->next;
 polyn head,pc,qc;
 pc=(polyn)malloc(sizeof(polynimial));
 pc->next=NULL;
 head=pc;
 while(qa!=NULL&&qb!=NULL)
 {
  qc=(polyn)malloc(sizeof(polynimial));
  if(qa->expn<qb->expn)
  {
    qc->coef=qa->coef;
    qc->expn=qa->expn;
    qa=qa->next;
  }
  else if(qa->expn==qb->expn)
  {
   qc->coef=(qa->coef+qb->coef);
   qc->expn=qa->expn;
   qa=qa->next;
   qb=qb->next;
 }   
   else
  {
    qc->coef=qb->coef;
    qc->expn=qb->expn;
    qb=qb->next;
  }
  if(qc->coef!=0)
  {
   pc->next=qc;
   pc=qc;
  }
  else
   free(qc);
 }
 while(qa!=NULL)
 {
  qc=(polyn)malloc(sizeof(polynimial));
  qc->coef=qa->coef;
  qc->expn=qa->expn;
  qa=qa->next;
  pc->next=qc;
  pc=qc;
 }
while(qb!=NULL)
 {
  qc=(polyn)malloc(sizeof(polynimial));
  qc->coef=qb->coef;
  qc->expn=qb->expn;
  qb=qb->next;
  pc->next=qc;
  pc=qc;
 }
 return head;
}
void main()
{
  int m,n;
  scanf("%d",&m);
  polyn a,b,c;
  a=creat(m);
  scanf("%d",&n);
  b=creat(n);
  c=add(a,b);
  out(c);
}
