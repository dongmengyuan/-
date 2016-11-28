/*************************************************************************
        > File Name: 先序创建二叉树.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月24日 星期四 16时53分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode, *BiTree;

void create(BiTree *root)
{
    char ch = getchar();
    if(ch == '#')             *root = NULL;
    else {
        *root = (BiTree)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        create(&(*root)->lchild);
        create(&(*root)->rchild);
    }
}

void preorder(BiTree root)
{
    if(root) {
        printf("%c",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main()
{
    BiTree root;
    create(&root);
    preorder(root);


    return 0;
}
