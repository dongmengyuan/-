#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode,*BiTree;

void PreOrder(BiTree root)
{
	if(root)
	{
		printf("%c",root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

BiTNode *creat(char *in, char *post, int n)
{
	BiTNode *s; 
	int pos;
	char *p;
	if(n<=0)
		return NULL;
	s=(BiTNode *)malloc(sizeof(BiTNode));
	s->data=*(post+n-1);
	for(p=in;p<in+n;p++)
		if(*p==*(post+n-1))
			break;
	pos=p-in;
	s->lchild=creat(in,post,pos);
	s->rchild=creat(p+1,post+pos,n-pos-1);
	return s;
}


int main() 
{
	BiTree T;
	int n;
	char in[MAX],post[MAX];
	scanf("%s",in);
	scanf("%s",post);
	T=creat(in,post,strlen(post));
	PreOrder(T);
	printf("\n");
}
