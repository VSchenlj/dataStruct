/**
 * @file BinaryTree.h
 * @author chenlj
 * @brief 二叉树结构及算法实现
 * @version 0.1
 * @date 2020-08-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

typedef char elemType; //二叉树结点存储数据的类型

/**
 * @brief 二叉树节点
 * 
 */
typedef struct BinaryNode {
    elemType data; //结点数据
    struct BinaryNode *lchild,*rchild; //左右孩子结点
}BinaryNode,*BinaryTree;

typedef enum {
    Link,
    Thread
}PointerTag;

/**
 * @brief 线索二叉树结点数据结构
 * 
 */
typedef struct BinaryThreadNode {
    elemType data; //结点数据
    struct BinaryThreadNode *lchild,*rchild; //左右孩子结点
    PointerTag lTag; //标志位，用于判断lchild指向左孩子还是前驱
    PointerTag rTag; //标志位，用于判断rchild指向右孩子还是后继
}BinaryThreadNode,*BinaryThreadTree;

//遍历算法
/**
 * @brief 前序遍历递归算法
 * 
 * @param T 二叉树指针
 */
void preOrderTraverse(BinaryTree T);

/**
 * @brief 中序遍历递归算法
 * 
 * @param T 二叉树指针
 */
void inOrderTraverse(BinaryTree T);

 /**
 * @brief 序遍历递归算法
 * 
 * @param T 二叉树指针
 */
void postOrderTraverse(BinaryTree T);

//二叉树的建立
/**
 * @brief 创建一个二叉树
 * 按前序输入二叉树中结点的值（一个字符）
 * '#'表示空树，构造二叉链表表示二叉树T
 * @param T 待构造的二叉树
 */
void createBinaryTree(BinaryTree *T);

//二叉树线索化：在遍历过程中修改空指针的过程
/**
 * @brief 中序遍历线索化二叉树
 * 
 * @param p 待线索化的二叉树
 */
void inThreading(BinaryThreadTree p);