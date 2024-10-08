#include <stdio.h>
#include <stdlib.h>

// 红黑树节点颜色枚举
typedef enum { RED, BLACK } Color;

// 红黑树节点结构
typedef struct RBTreeNode {
    int data;                       // 数据域
    Color color;                    // 节点颜色
    struct RBTreeNode* left, * right, * parent; // 左、右孩子和父节点指针
} RBTreeNode;

// 红黑树结构
typedef struct RBTree {
    RBTreeNode* root;               // 根节点
    RBTreeNode* nil;                // 哨兵节点，所有叶子指向为nil（黑色）
} RBTree;

// 创建红黑树节点
RBTreeNode* create_node(int data, Color color, RBTreeNode* nil) {
    RBTreeNode* node = (RBTreeNode*)malloc(sizeof(RBTreeNode));
    node->data = data;
    node->color = color;
    node->left = node->right = node->parent = nil;
    return node;
}

// 初始化红黑树
RBTree* init_rbtree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->nil = create_node(0, BLACK, NULL); // 哨兵节点
    tree->root = tree->nil;
    return tree;
}

// 左旋转操作
void left_rotate(RBTree* tree, RBTreeNode* x) {
    RBTreeNode* y = x->right; // 将y设为x的右孩子
    x->right = y->left;       // 将y的左孩子转移给x的右孩子
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;    // 更新y的父节点为x的父节点
    if (x->parent == tree->nil) {
        tree->root = y;       // 如果x是根节点，则y成为新的根节点
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;              // 将x设为y的左孩子
    x->parent = y;
}

// 右旋转操作
void right_rotate(RBTree* tree, RBTreeNode* y) {
    RBTreeNode* x = y->left; // 将x设为y的左孩子
    y->left = x->right;      // 将x的右孩子转移给y的左孩子
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;   // 更新x的父节点为y的父节点
    if (y->parent == tree->nil) {
        tree->root = x;      // 如果y是根节点，则x成为新的根节点
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y;            // 将y设为x的右孩子
    y->parent = x;
}

// 插入修复
void insert_fixup(RBTree* tree, RBTreeNode* z) {
    while (z->parent->color == RED) { // 违反性质4的情况
        if (z->parent == z->parent->parent->left) { // 父节点是左孩子
            RBTreeNode* y = z->parent->parent->right; // z的叔叔
            if (y->color == RED) { // 情况1：叔叔是红色
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // 向上继续修复
            }
            else {
                if (z == z->parent->right) { // 情况2：z是右孩子
                    z = z->parent;
                    left_rotate(tree, z); // 左旋转
                }
                // 情况3：z是左孩子
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent); // 右旋转
            }
        }
        else { // 父节点是右孩子，与上面对称
            RBTreeNode* y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK; // 根节点始终为黑色
}

// 插入节点
void insert_rbtree(RBTree* tree, int data) {
    RBTreeNode* z = create_node(data, RED, tree->nil); // 新节点为红色
    RBTreeNode* y = tree->nil;
    RBTreeNode* x = tree->root;

    // 找到插入位置
    while (x != tree->nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;

    // 插入为左或右孩子
    if (y == tree->nil) {
        tree->root = z; // 树为空时，z为根节点
    }
    else if (z->data < y->data) {
        y->left = z;
    }
    else {
        y->right = z;
    }

    // 插入修复
    insert_fixup(tree, z);
}

// 中序遍历红黑树
void inorder_rbtree(RBTree* tree, RBTreeNode* node) {
    if (node != tree->nil) {
        inorder_rbtree(tree, node->left);
        printf("%d ", node->data);
        inorder_rbtree(tree, node->right);
    }
}

// 销毁红黑树
void destroy_rbtree(RBTree* tree, RBTreeNode* node) {
    if (node != tree->nil) {
        destroy_rbtree(tree, node->left);
        destroy_rbtree(tree, node->right);
        free(node);
    }
}

// 测试红黑树功能
int main() {
    RBTree* tree = init_rbtree();

    int values[] = { 20, 15, 25, 10, 5, 1, 30, 28, 35 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        insert_rbtree(tree, values[i]);
    }

    printf("红黑树中序遍历结果:\n");
    inorder_rbtree(tree, tree->root);
    printf("\n");

    destroy_rbtree(tree, tree->root);
    free(tree->nil);
    free(tree);

    return 0;
}
