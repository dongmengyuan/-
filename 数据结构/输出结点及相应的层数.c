/*************************************************************************
        > File Name: 输出结点及相应的层数.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月22日 星期二 10时41分37秒
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
        *root = (BiTree) malloc (sizeof(BiTNode));
        (*root) -> data = ch;
        creat(&((*root)->lchild));
        creat(&((*root)->rchild));
    }
}

void preorder(BiTree root, int n)
{
    if(root) {
        printf("(%c,%d)",root->data,n);
        preorder(root->lchild,n+1);
        preorder(root->rchild,n+1);
    }
}

int main()
{
    int n;
    BiTree root;
    creat(&root);
    preorder(root,n+1);
    printf("\n");
 
    return 0;
}
