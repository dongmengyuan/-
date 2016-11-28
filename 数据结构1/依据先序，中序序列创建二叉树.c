#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode, *BiTree;


void postorder(BiTree root)
{
	if(root)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c",root->data);
	}
}

BiTree creat(char *pre, char *in, int n)
{
	BiTree s; 
	int pos;
	char *p;
	if(n<=0)
		return NULL;
	s=(BiTree)malloc(sizeof(BiTNode));
	s->data=*pre;
	for(p=in;p<in+n;p++)
		if(*p==*pre)
			break;
	pos=p-in;
	s->lchild=creat(pre+1,in,pos);
	s->rchild=creat(pre+pos+1,p+1,n-pos-1);
	return s;
}


int main() 
{
	BiTree T;
	int n;
	char pre[MAX],in[MAX];
	scanf("%s",pre);
	scanf("%s",in);
	T=creat(pre,in,strlen(pre));
	postorder(T);
	printf("\n");
}
