#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"

void preOrderTraverse(BinaryTree T) {
    if(T==NULL)
        return;
    printf("%d",T->val);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}
