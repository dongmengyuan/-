

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <math.h>
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
	polynimial *r=h,*s;
	h->next=NULL;	
	fflush(stdin);
	for(j=1;j<=i;j++)
	{  
		s=(polyn)malloc(sizeof(polynimial)); 
		scanf("%c%d,%d%c",&a,&s->coef,&s->expn,&b);
		r->next=s;
		r=s;
	}
	r->next=NULL;
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
	pc->next=NULL;
	return head;
}
polyn mul(polyn a,polyn b)
{
	polyn qa,qb,head,n,r,m,t;
	head=(polyn)malloc(sizeof(polynimial));
	head->next=NULL;
	r=head;
	qa=a->next;
	while(qa)
	{
		t=(polyn)malloc(sizeof(polynimial));
		t->next=NULL;
		m=t;
		qb=b->next;
		while(qb)
		{
			n=(polyn)malloc(sizeof(polynimial));
			n->coef=(qa->coef*qb->coef);
			n->expn=(qa->expn+qb->expn);
			m->next=n;
			m=m->next;
			qb=qb->next;
		}
		qa=qa->next;
		m->next=NULL;
		head=add(head,t);
	}
	return head;
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
	polyn a,b,c;
	int m,n;
	scanf("%d",&m);
	a=creat(m);
	scanf("%d",&n);
	b=creat(n);
	out(a);
	out(b);
}
