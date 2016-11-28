/*************************************************************************
        > File Name: 建立二叉树.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年10月25日 星期二 11时35分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef char ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *lchild;
    struct Node *rchila;
} BiTNode, *BiTree;


void CreateBiTree(BiTree *T)
{
    ElemType ch;
    scanf("%c",&ch);
    if(ch == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTree) malloc (sizeof(BiTNode));
        if(!*T) {
            exit(OVERFLOW);
            (*T) -> data = ch;
            CreateBiTree(&(*T) -> lchild);
            CreateBiTree(&(*T) -> rchild);
        }
    }

}






int main()
{
    return 0;
}
