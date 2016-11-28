/*************************************************************************
        > File Name: 先序创建二叉树.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月20日 星期日 18时42分50秒
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

void Creat(BiTree *root)
{
    char ch;
    ch = getchar();
    if(ch == '#') {
        *root = NULL;
    }
    else {
        *root = (BiTree)malloc(sizeof(BiTNode));
        (*root) -> data = ch;
        Creat(&((*root) -> lchild));
        Creat(&((*root) -> rchild));
    }
}

//先序遍历输出二叉树
void PreOrder(BiTree root) 
{
    if(root) {
        printf("%c",root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

//中序遍历输出二叉树
void InOrder(BiTree root)
{
    if(root) {
        InOrder(root->lchild);
        printf("%c",root->data);
        InOrder(root->rchild);
    }
    
}

//后序遍历输出二叉树
void PostOrder(BiTree root)
{
    if(root) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%c",root->data);
    }
}

int main()
{
    BiTree root;
    Creat(&root);

    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    return 0;
}
