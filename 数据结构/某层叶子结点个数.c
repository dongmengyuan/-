/*************************************************************************
        > File Name: 某层叶子结点个数.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月22日 星期二 13时01分18秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
 
const int N = 50086;

typedef char datatype;
typedef struct Node
{
    datatype data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode, *BiTree;

void creat(BiTree *root)
{
    char ch;
    ch = getchar();
    if(ch == '#') {
        *root = NULL;
    }
    else {
        *root = (BiTree)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        creat(&(*root)->lchild);
        creat(&(*root)->rchild);
    }
}
 
int n;
int k = 0;

int leaf(BiTree root)
{
    if(root) {
        int i = 1;
        while(i != n){
            if(root->lchild==NULL && root->rchild==NULL) {
                k += 0;
            }
            if((root->lchild!=NULL && root->rchild==NULL) || (root->lchild==NULL && root->rchild!=NULL)) {
                k += 1;
            }
            if(root->lchild!=NULL && root->rchild!=NULL) {
                k += 2;
            }
           // leaf(root->lchild);
           // leaf(root->rchild);
        }
        if(i == n) {
            printf("%d",k);
        }
    }
}

int main()
{
    BiTree root;
    creat(&root);
    scanf("%d",&n);
    leaf(root);
 
    return 0;
}
