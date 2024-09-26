#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node* root = NULL; //�����Ѿ�������Root���

void CCreate()
{
	struct Node* p,*t;
	int x;
	struct Queue q;
	Create(&q, 100); //�����Ǵ���һ�����г��� ��СΪ100

	printf("Eneter root Value: \n");
	scanf_s("%d", &x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	Enqueue(&q, root); //��root �����������Ķ�����

	while (!isEmpty(q))
	{
		p = dequeue(&q); //����ͷ�Ľ����� ���Ҹ����p
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


//ǰ���������
void PreOrder(struct Node* p)
{
	if (p)
	{
		printf("%d ", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}


//�������  ������Щ���� ���Խ� struct Node *p
// ��Ϊ�м�� ��� ���� �����
void InOrder(struct Node* p)
{
	if (p)
	{
		InOrder(p->lchild);
		printf("%d ", p->data);
		InOrder(p->rchild);
	}
}

//��������
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

//�������ĸ߶�
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