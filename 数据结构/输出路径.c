/*************************************************************************
        > File Name: 输出路径.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月22日 星期二 10时12分48秒
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

void outpath(BiTree root, char path[], int n)
{
    if(root->lchild == NULL && root->rchild == NULL) {
        printf("%c:",root->data);
        for(int i = 0; i < n; i++) {
            printf("%c",path[i]);
        }
        printf("\n");
    }
    else {
        path[n] = root->data;
        if(root->lchild != NULL) {
            outpath(root->lchild,path,n+1);
        }
        if(root->rchild != NULL) {
            outpath(root->rchild,path,n+1);
        }
    }
}

int main()
{
    char path[1000];
    int n = 0;
    BiTree root;
    creat(&root);
    outpath(root,path,n);
 
    return 0;
}

