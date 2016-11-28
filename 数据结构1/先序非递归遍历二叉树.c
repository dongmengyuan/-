/*************************************************************************
        > File Name: 先序非递归遍历二叉树.c
      > Author: dongmengyuan
      > Mail: 1322762504@qq.com
      > Created Time: 2016年11月24日 星期四 21时57分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
 

//二叉链表结点结构 
typedef struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rchild;
}BiTNode, *BiTree;

//顺序栈
#define Max 100
typedef struct
{
    int data[Max];     //保存栈中的数据元素
    int top;
}Seqstack;

//置空栈
Seqstack *init_seqstack()
{
    Seqstack *s;
    s = (Seqstack *)malloc(sizeof(Seqstack));
    s->top = -1;       //空栈时栈顶指针top=-1
    return s;
}

//判空栈
int empty_seqstack(Seqstack *s)
{
    if(s->top == -1)
    return 1;
    else
    return 0;
}

//入栈
int push_seqstack(Seqstack *s, BiTree root)
{
    BiTree p = root;
    if(s->top == Max-1)
    return 0;
    else {
        s->top++;
        s->data[s->top] = p;
        return 1;
    }
}

//出栈
int pop_seqstack(Seqstack *s, BiTree *root)
{
    if(empty_seqstack(s))
    return 0;
    else {
        *root = s->data[s->top];
        s->top--;
        return 1;
    }
}

//取栈顶元素
int top_seqstack(Seqstack *s)
{
    if(empty_seqstack(s))
    return 0;
    else
    return s->data[s->top];

}

//先序创建二叉树
void create_tree(BiTree *root)
{
    char ch;
    ch = getchar();
    if(ch == '#') {
        *root = NULL;
    }
    else {
        *root = (BiTree) malloc (sizeof(BiTNode));
        (*root)->data = ch;
        create_tree(&(*root)->lchild);
        create_tree(&(*root)->rchild);
    }
}

//先序非递归遍历二叉树
void preorder(BiTree root)
{
    Seqstack *s;
    BiTree p;
    init_seqstack();            //置空栈
    p = root;              
    while(p != NULL || !empty_seqstack(s))      //当前结点指针及栈均空的话，则结束
    {
        while(p != NULL) {
            printf("%c",p->data);        //当前结点不为空，访问根结点
            push_seqstack(s,p);          //根指针入栈
            p = p->lchild;               //进入左子树
        }
        if(!empty_seqstack(s)) {
            pop_seqstack(s,&p);          //根指针出栈
            p = p->rchild;               //进入右子树
        }
    }
}

int main()
{
    BiTree root;
    Seqstack *s;
    int x;
    create_tree(&root);
    init_seqstack();
    empty_seqstack(s);
    push_seqstack(s,x);
    pop_seqstack(s,&x);
    top_seqstack(s);
    preorder(root);

    return 0;
}
