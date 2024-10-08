#include <stdio.h>
#include <stdlib.h>

// ������ڵ���ɫö��
typedef enum { RED, BLACK } Color;

// ������ڵ�ṹ
typedef struct RBTreeNode {
    int data;                       // ������
    Color color;                    // �ڵ���ɫ
    struct RBTreeNode* left, * right, * parent; // ���Һ��Ӻ͸��ڵ�ָ��
} RBTreeNode;

// ������ṹ
typedef struct RBTree {
    RBTreeNode* root;               // ���ڵ�
    RBTreeNode* nil;                // �ڱ��ڵ㣬����Ҷ��ָ��Ϊnil����ɫ��
} RBTree;

// ����������ڵ�
RBTreeNode* create_node(int data, Color color, RBTreeNode* nil) {
    RBTreeNode* node = (RBTreeNode*)malloc(sizeof(RBTreeNode));
    node->data = data;
    node->color = color;
    node->left = node->right = node->parent = nil;
    return node;
}

// ��ʼ�������
RBTree* init_rbtree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->nil = create_node(0, BLACK, NULL); // �ڱ��ڵ�
    tree->root = tree->nil;
    return tree;
}

// ����ת����
void left_rotate(RBTree* tree, RBTreeNode* x) {
    RBTreeNode* y = x->right; // ��y��Ϊx���Һ���
    x->right = y->left;       // ��y������ת�Ƹ�x���Һ���
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;    // ����y�ĸ��ڵ�Ϊx�ĸ��ڵ�
    if (x->parent == tree->nil) {
        tree->root = y;       // ���x�Ǹ��ڵ㣬��y��Ϊ�µĸ��ڵ�
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;              // ��x��Ϊy������
    x->parent = y;
}

// ����ת����
void right_rotate(RBTree* tree, RBTreeNode* y) {
    RBTreeNode* x = y->left; // ��x��Ϊy������
    y->left = x->right;      // ��x���Һ���ת�Ƹ�y������
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;   // ����x�ĸ��ڵ�Ϊy�ĸ��ڵ�
    if (y->parent == tree->nil) {
        tree->root = x;      // ���y�Ǹ��ڵ㣬��x��Ϊ�µĸ��ڵ�
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y;            // ��y��Ϊx���Һ���
    y->parent = x;
}

// �����޸�
void insert_fixup(RBTree* tree, RBTreeNode* z) {
    while (z->parent->color == RED) { // Υ������4�����
        if (z->parent == z->parent->parent->left) { // ���ڵ�������
            RBTreeNode* y = z->parent->parent->right; // z������
            if (y->color == RED) { // ���1�������Ǻ�ɫ
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // ���ϼ����޸�
            }
            else {
                if (z == z->parent->right) { // ���2��z���Һ���
                    z = z->parent;
                    left_rotate(tree, z); // ����ת
                }
                // ���3��z������
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent); // ����ת
            }
        }
        else { // ���ڵ����Һ��ӣ�������Գ�
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
    tree->root->color = BLACK; // ���ڵ�ʼ��Ϊ��ɫ
}

// ����ڵ�
void insert_rbtree(RBTree* tree, int data) {
    RBTreeNode* z = create_node(data, RED, tree->nil); // �½ڵ�Ϊ��ɫ
    RBTreeNode* y = tree->nil;
    RBTreeNode* x = tree->root;

    // �ҵ�����λ��
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

    // ����Ϊ����Һ���
    if (y == tree->nil) {
        tree->root = z; // ��Ϊ��ʱ��zΪ���ڵ�
    }
    else if (z->data < y->data) {
        y->left = z;
    }
    else {
        y->right = z;
    }

    // �����޸�
    insert_fixup(tree, z);
}

// ������������
void inorder_rbtree(RBTree* tree, RBTreeNode* node) {
    if (node != tree->nil) {
        inorder_rbtree(tree, node->left);
        printf("%d ", node->data);
        inorder_rbtree(tree, node->right);
    }
}

// ���ٺ����
void destroy_rbtree(RBTree* tree, RBTreeNode* node) {
    if (node != tree->nil) {
        destroy_rbtree(tree, node->left);
        destroy_rbtree(tree, node->right);
        free(node);
    }
}

// ���Ժ��������
int main() {
    RBTree* tree = init_rbtree();

    int values[] = { 20, 15, 25, 10, 5, 1, 30, 28, 35 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        insert_rbtree(tree, values[i]);
    }

    printf("���������������:\n");
    inorder_rbtree(tree, tree->root);
    printf("\n");

    destroy_rbtree(tree, tree->root);
    free(tree->nil);
    free(tree);

    return 0;
}
