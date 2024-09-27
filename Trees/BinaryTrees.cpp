#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

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

	//˭�� ѡ˭
	if (x > y)
	{
		return x + 1;
	}
	else
	{
		return y + 1;
	}
}

//�б����ַ�� ��������
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
			p = p->lchild; //ȥ�����Ӵ�
		}
		else
		{
			//���ڵ�Ϊ�ڵ�ʱ
			p = popST(&stk);
			p = p->rchild;
		}
	}
}




//�б����ַ�� ��������  �������
void IInreorder(struct Node* p)
{
	struct Stack stk;
	STACKcreate(&stk, 100);

	while (p || !IsEmptyStack(stk))
	{
		if (p)
		{

			pushST(&stk, p);
			p = p->lchild; //ȥ�����Ӵ�
		}
		else
		{
			//���ڵ�Ϊ�ڵ�ʱ
			p = popST(&stk);
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}

//����ڵ���
int Count(struct Node* root)
{
	if (root)
	{
		return Count(root->lchild) + Count(root->rchild) + 1;
	}
	return 0;
}


//ͳ�� Ҷ�ӽڵ����
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

//ͳ�� ��Ҷ�ӽڵ����
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


//ͳ�� ��Ϊ2���ӽڵ����
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


//ͳ�� ��Ϊ1���ӽڵ����
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