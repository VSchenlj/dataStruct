#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"
#include <queue>
#include <iostream>
using namespace std;

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
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    printf("%c", T->data);
}

void levelOrderTraverse(BinaryTree T) {
    if(T == NULL)
        return;
    //利用队列先进先出的特点
    queue<BinaryTree> q;
    BinaryTree front;
    q.push(T);
    while (!q.empty()) {
        /* code */
        front = q.front();
        q.pop();

        if(front->lchild)
            q.push(front->lchild);
        
        if(front->rchild)
            q.push(front->rchild);
        
        cout<<front->data<<" ";
    }
}

void createBinaryThrTree(BinaryThreadTree *T) {
    elemType ch;
    cin >> ch;
    if(ch == '#')
        *T = NULL;
    else {
        /* code */
        //若不为空，则生成新结点
        *T = (BinaryThreadTree) malloc(sizeof(BinaryThreadNode));
        if(!*T)
            exit(-1);
        (*T)->data = ch;
        (*T)->lTag = Link;
        (*T)->rTag = Link;
        //递归创建左右孩子结点
        createBinaryTree(&(*T)->lchild);
        createBinaryTree(&(*T)->rchild);
    }
    
}

void inThreading(BinaryThreadTree T,BinaryThreadTree *pre) {
    if(T) {
        inThreading(T->lchild,pre); //递归左孩子线索化
        if(!T->lchild) { //如果左孩子不存在，则指向前驱对象，pre即为前一个结点
            T->lTag = Thread;
            T->lchild = *pre;
        }

        if((*pre) && !(*pre)->rchild) { //若前一个结点的右孩子不存在，则当前结点为前一个结点的后驱对象
            (*pre)->rTag = Thread;
            (*pre)->rchild = T;
        }
        *pre = T;
        inThreading(T->rchild,pre); //递归右孩子线索化
    }
}

void inOrderTraverseThr(BinaryThreadTree T) {
    BinaryThreadTree p = T;
    while(p) {
        while(p->lTag == Link)
            p = p->lchild;
        cout << p->data << " ";
        while(p->rTag == Thread && p->rchild !=NULL) {
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;
    }
}
