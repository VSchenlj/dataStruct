#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void preOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    cout << T->data << " ";
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}

void preOrderTraverse2(BinaryTree T) {
    if (T == NULL)
        return;
    stack<BinaryTree> myStack;
    while (!myStack.empty() || T) {
        if(T) {
            cout << T->data << " ";
            myStack.push(T);
            T = T->lchild;
        } else {
            T = myStack.top();
            myStack.pop();
            T = T->rchild;
        }
    }
}

void inOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    inOrderTraverse(T->lchild);
    cout << T->data << " ";
    inOrderTraverse(T->rchild);
}

void inOrderTraverse2(BinaryTree T) {
    if (T == NULL)
        return;
    stack<BinaryTree> myStack;
    while (!myStack.empty() || T) {
        if(T) {
            myStack.push(T);
            T = T->lchild;
        } else {
            T = myStack.top();
            cout << T->data << " ";
            myStack.pop();
            T = T->rchild;
        }
    }
}

void postOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    cout << T->data << " ";
}

void postOrderTraverse2(BinaryTree T) {
    if (T == NULL)
        return;
    stack<BinaryTree> myStack;
    stack<BinaryTree> myStack2;
    myStack.push(T);
    while (!myStack.empty()) {
        BinaryTree temp = myStack.top();
        myStack.pop();
        myStack2.push(temp);
        if(temp->lchild)
            myStack.push(temp->lchild);
        if(temp->rchild)
            myStack.push(temp->rchild);
    }
    while (!myStack2.empty()) {
        BinaryTree temp = myStack2.top();
        cout << temp->data << " ";
        myStack2.pop();
    }
}

void levelOrderTraverse(BinaryTree T) {
    if (T == NULL)
        return;
    queue<BinaryTree> q;
    BinaryTree front;
    q.push(T);
    while (!q.empty()) {
        front = q.front();
        q.pop();

        if (front->lchild)
            q.push(front->lchild);

        if (front->rchild)
            q.push(front->rchild);
        cout << front->data << " ";
    }
}

void createBinaryThrTree(BinaryThreadTree *T) {
    elemType ch;
    cin >> ch;
    if (ch == '#')
        *T = NULL;
    else {
        *T = (BinaryThreadTree)malloc(sizeof(BinaryThreadTree));
        if (!*T)
            return;
        (*T)->data = ch;
        (*T)->lTag = Link;
        (*T)->rTag = Link;
        //递归创建左右孩子结点
        createBinaryThrTree(&(*T)->lchild);
        createBinaryThrTree(&(*T)->rchild); 
    }
}

void inThreading(BinaryThreadTree T,BinaryThreadTree *pre) {
    if (T) {
        inThreading(T->lchild, pre); //递归左孩子线索化
        if (!T->lchild) {
            T->lTag = Thread;
            T->lchild = *pre;
        }
        if (*pre && !(*pre)->rchild) {
            (*pre)->rTag = Thread;
            (*pre)->rchild = T;
        }
        *pre = T;
        inThreading(T->rchild, pre); //递归右孩子线索化
    }
}

void inOrderTraverseThr(BinaryThreadTree T) {
    BinaryThreadTree p = T;
    while (p) {
        //查找前驱头部
        while (p->lTag == Link)
            p = p->lchild;
        cout << p->data << " ";
        //查找该前驱的后继
        while (p->rTag == Thread && p->rchild) {
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;
    }
}
