/*************************************************************************
        > File Name: 交换左右子树.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月22日 星期二 12时02分23秒
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
    ch  = getchar();
    if(ch == '#') {
        *root = NULL;
    }
    else {
        *root = (BiTree) malloc (sizeof(BiTNode));
        (*root) -> data = ch;
        creat(&(*root) -> lchild);
        creat(&(*root) -> rchild);
        
    }
}

BiTree change(BiTree root)
{
    BiTree t;
    if(root == NULL || (root -> lchild == NULL && root -> rchild == NULL)) {
        return root;
    }
    t = root -> lchild;
    root->lchild = root->rchild;
    root->rchild = t;
    if(root -> lchild) {
        root -> lchild = change(root->lchild);
    }
    if(root -> rchild) {
        root -> rchild = change(root->rchild);
    }
    return root;
}

void preorder(BiTree root)
{
    if(root) {
        printf("%c",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(BiTree root)
{
    if(root) {
        inorder(root->lchild);
        printf("%c",root->data);
        inorder(root->rchild);
    }
}

void postorder(BiTree root)
{
    if(root) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%c",root->data);
    }
}

int main()
{
    BiTree root;
    creat(&root);
    change(root);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}
