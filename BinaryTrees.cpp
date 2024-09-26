#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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

	printf("%d", root->data);
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
	CCreate();
	PreOrder(root);
	InOrder(root);
	PostOrder(root);
	printf("%d \n", Height(root));

	return 0;
}