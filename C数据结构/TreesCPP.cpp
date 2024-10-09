
#include "Queue.h"
#include <iostream>
#include<stdio.h>
using namespace std;
class Tree
{
public:
	Node* root;
	Tree() { root = NULL; }
	void CreateTree();
	void PreOrder(Node* p);
	void InOrder(Node* p);
	void PostOrder(Node* p);
	void LeveLOrder(Node* root);
	int Height(Node* root);
};


void Tree::CreateTree()
{
	Node* p, * t;
	int x;
	Queue q(100); //创建一个队列\

	printf("Enter Root Value: \n");
	scanf_s("%d", &x);
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.Enqueue(root);

	while (!q.IsEmpty())
	{
		p = q.Dequeue();
		printf("Enter Left Child value of %d: \n", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.Enqueue(t);
		}

		printf("Enter Right Child value of %d: \n", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.Enqueue(t);
		}
	}


}


void Tree::PreOrder(Node *p)
{
	if (p)
	{
		printf("%d ", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}


void Tree::InOrder(Node* p)
{
	if (p)
	{
		InOrder(p->lchild);
		printf("%d ", p->data);
		InOrder(p->rchild);
	}
}

//后续遍历
void Tree::PostOrder(Node* p)
{
	if (p)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d ", p->data);
	}
}

//层级遍历
void Tree::LeveLOrder(Node *root)
{
	Queue q(100); //创建一个队列 来存放队列

	printf("%d ", root->data);
	q.Enqueue(root);

	while (!q.IsEmpty())
	{
		root = q.Dequeue();

		//如果左子节点不为空时候
		if (root->lchild)
		{
			printf("%d ", root->lchild->data);
			q.Enqueue(root->lchild); 
		}

		//如果右子节点不为空的时候
		if (root->rchild)
		{
			printf("%d ", root->rchild->data);
			q.Enqueue(root->rchild);
		}

	}
}


//计算树的高度
int Tree::Height(Node* root)
{
	int x, y = 0;
	if (root == NULL)
	{
		return 0;
	}
	x = Height(root->lchild);
	y = Height(root->rchild);

	if (x > y)
	{
		return x + 1;
	}
	else
	{
		return y + 1;
	}
}


int main()
{
	Tree t;
	t.CreateTree();
	printf("%d ",t.Height(t.root));

	return 0;
}