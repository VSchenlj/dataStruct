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

/**
 * @brief 二叉树节点
 * 
 */
typedef struct BinaryNode {
    int val;
    struct BinaryNode *lchild,*rchild;
}BinaryNode,*BinaryTree;

//遍历算法
/**
 * @brief 前序遍历递归算法
 * 
 * @param T 二叉树指针
 */
void preOrderTraverse(BinaryTree T);