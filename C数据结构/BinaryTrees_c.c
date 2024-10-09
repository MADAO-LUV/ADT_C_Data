#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node* root = NULL; //这里已经创建了Root结点

void CCreate()
{
	struct Node* p,*t;
	int x;
	struct Queue q;
	Create(&q, 100); //这里是创建一个队列出来 大小为100

	printf("Eneter root Value: \n");
	scanf_s("%d", &x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	Enqueue(&q, root); //将root 这个树根加入的队列中

	while (!isEmpty(q))
	{
		p = dequeue(&q); //将队头的结点出队 并且赋予给p
		printf("Eneter Left Child oif %d: \n",p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Enqueue(&q, t);
		}

		printf("Eneter Right Child of %d: \n",p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			Enqueue(&q, t);
		}
	}


}


//前序遍历函数
void PreOrder(struct Node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}


//中序遍历  对于这些遍历 可以将 struct Node *p
// 看为中间的 结点 就是 父结点
void InOrder(struct Node* p)
{
	if (p)
	{
		InOrder(p->lchild);
		printf("%d ", p->data);
		InOrder(p->rchild);
	}
}

//后续遍历
void PostOrder(struct Node* p)
{
	if (p)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d ", p->data);
	}
}


void LeveLOrder(struct Node* root)
{
	struct Queue q;
	Create(&q, 100);

	printf("%d ", root->data);
	Enqueue(&q,root);

	while (!isEmpty(q))
	{
		root = dequeue(&q);

		if (root->lchild)
		{
			printf("%d ", root->lchild->data);
			Enqueue(&q, root->lchild);
		}

		if (root->rchild)
		{
			printf("%d ", root->rchild->data);
			Enqueue(&q, root->rchild);
		}
	}


}

//计算树的高度
int Height(struct Node* root)
{
	int x, y = 0;

	if (root == NULL)
	{
		return 0;
	}

	x = Height(root->lchild);
	y = Height(root->rchild);

	//谁大 选谁
	if (x > y)
	{
		return x + 1;
	}
	else
	{
		return y + 1;
	}
}

//有保存地址的 迭代遍历
void IPreorder(struct Node* p)
{
	struct Stack stk;
	STACKcreate(&stk, 100);

	while (p || !IsEmptyStack(stk))
	{
		if (p)
		{
			printf("%d ", p->data);
			pushST(&stk, p);
			p = p->lchild; //去到左孩子处
		}
		else
		{
			//当节点为节点时
			p = popST(&stk);
			p = p->rchild;
		}
	}
}




//有保存地址的 迭代遍历  中序遍历
void IInreorder(struct Node* p)
{
	struct Stack stk;
	STACKcreate(&stk, 100);

	while (p || !IsEmptyStack(stk))
	{
		if (p)
		{

			pushST(&stk, p);
			p = p->lchild; //去到左孩子处
		}
		else
		{
			//当节点为节点时
			p = popST(&stk);
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}

//计算节点数
int Count(struct Node* root)
{
	if (root)
	{
		return Count(root->lchild) + Count(root->rchild) + 1;
	}
	return 0;
}


//统计 叶子节点个数
int CountLeaf(struct Node* root)
{
	int x, y;
	if (root != NULL)
	{
		x = CountLeaf(root->lchild);
		y = CountLeaf(root->rchild);
		if (!root->lchild && !root->rchild)
		{
			return x + y + 1;
		}
		else
		{
			return x + y;
		}

	}
	return 0;
}

//统计 非叶子节点个数
int CountNonLeaf(struct Node* root)
{
	int x, y;
	if (root != NULL)
	{
		x = CountNonLeaf(root->lchild);
		y = CountNonLeaf(root->rchild);
		if (root->lchild || root->rchild)
		{
			return x + y + 1;
		}
		else
		{
			return x + y;
		}

	}
	return 0;
}


//统计 度为2的子节点个数
int CountNode2(struct Node* root)
{
	int x, y;
	if (root != NULL)
	{
		x = CountNode2(root->lchild);
		y = CountNode2(root->rchild);
		if (root->lchild && root->rchild)
		{
			return x + y + 1;
		}
		else
		{
			return x + y;
		}

	}
	return 0;
}


//统计 度为1的子节点个数
int CountNode1(struct Node* root)
{
	int x, y;
	if (root != NULL)
	{
		x = CountNode1(root->lchild);
		y = CountNode1(root->rchild);
		if (root->lchild != NULL ^ root->rchild != NULL)
		{
			return x + y + 1;
		}
		else
		{
			return x + y;
		}

	}
	return 0;
}


int main()
{
	CCreate();

	printf("Count LeafNodes :%d \n", CountLeaf(root));

	return 0;
}