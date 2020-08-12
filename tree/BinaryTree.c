#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"

void preOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    printf("%c", T->data);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}

void inOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    inOrderTraverse(T->lchild);
    printf("%c", T->data);
    inOrderTraverse(T->rchild);
}

void postOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    inOrderTraverse(T->lchild);
    inOrderTraverse(T->rchild);
    printf("%c", T->data);
}

void createBinaryTree(BinaryTree *T) {
    elemType ch;
    scanf("%c",&ch);
    if(ch == '#')
        *T = NULL;
    else {
        /* code */
        //若不为空，则生成新结点
        *T = (BinaryTree) malloc(sizeof(BinaryNode));
        if(!*T)
            exit(-1);
        (*T)->data = ch;
        //递归创建左右孩子结点
        createBinaryTree(&(*T)->lchild);
        createBinaryTree(&(*T)->rchild);
    }
    
}

BinaryThreadTree preThTree; //全局变量，始终指向刚刚访问过的结点
void inThreading(BinaryThreadTree p) {
    if(p) {
        inThreading(p->lchild); //递归左子树线索化
        if(!p->lchild) {
            p->lTag = Thread; //前驱线索
            p->lchild = preThTree; //左孩子指针指向前驱
        }
        if(!preThTree->rchild) {
            preThTree->rTag = Thread; //后继线索
            preThTree->rchild = p; //前驱右孩子指针指向后继（当前p结点）
        }
        preThTree = p; // 保持preThTree指向p的前驱
        inThreading(p->rchild); //递归右子树线索化
    }
}
