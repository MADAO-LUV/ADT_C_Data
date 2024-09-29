#include <stdio.h>
#include <stdlib.h>
struct Node
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
}*root=NULL;

/*
BST (Binary Search Tree)
���������� 
1.û���ظ�
2.��������ʱ�� ���Բ���ڵ�

*/




//ʹ��ѭ�� ��������
void Insert(int key)
{
	struct Node* t = root;
	struct Node* p;
	struct Node* r = NULL;

	if (root == NULL)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return; //���return ǧ��Ҫ����
	}
	while (t != NULL)
	{
		r = t;
		if (key < t->data)
		{
			t = t->lchild;
		}
		else if (key > t->data)
		{
			t = t->rchild;
		}
		else
		{
			return; //�����������t->data==key �ظ��ˣ���������
		}
	}
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;

	if (key < r->data)
	{
		r->lchild = p;
	}
	else
	{
		r->rchild = p;
	}

}

//�������� BST
void Inorder(struct Node* p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

//�ݹ����
struct Node* RInsert(struct Node *p,int key)
{
	struct Node* t=NULL;
	if (p == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if (key < p->data)
	{
		p->lchild = RInsert(p->lchild, key);
	}
	else if (key > p->data)
	{
		p->rchild = RInsert(p->rchild, key);
	}
	return p; //���ؽڵ�
}

//���ظ߶�
int Height(struct Node* p)
{
	int x, y;
	if (p == NULL)return 0;
	x = Height(p->lchild);
	y = Height(p->rchild);
	return x > y ? x + 1 : y + 1;
}


//�������ҵĺ���
struct Node* Inpre(struct Node* p)
{
	while (p && p->rchild != NULL)
	{
		p = p->rchild;
	}
	return p;
}


//��������ĺ���
struct Node* Insucc(struct Node* p)
{
	while (p && p->lchild != NULL)
	{
		p = p->lchild;
	}
	
	return p;
}

//ɾ���ڵ�
struct Node* Delete(struct Node* p, int key)
{
	struct Node* q = NULL;
	if (p == NULL)
	{
		return NULL;
	}
	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == root)
			root = NULL;
		free(p);
		return NULL;
	}



	if (key < p->data)
	{
		p->lchild = Delete(p->lchild,key);
	}
	else if (key > p->data)
	{
		p->rchild = Delete(p->rchild, key);
	}

	else
	{
		//���� �߶��ж�ѡ���ĸ� �����Ľڵ� ȷ��ƽ��
		if (Height(p->lchild) > Height(p->rchild))
		{
			q = Inpre(p->lchild);   //Inpre����
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else //���ұ����� �߶� ���� ���ʱ
		{
			q = Insucc(p->rchild); //Insucc����
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}

	}

	return p;
}




//���غ���
struct Node* Search(int key)
{
	struct Node* t = root;

	while (t != NULL)
	{
		if (key == t->data)
		{
			return t;
		}
		else if (key < t->data)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	//���û���ҵ�
	return NULL;
}



int main()
{
	struct Node* p = NULL;
	root=RInsert(root,10);
	RInsert(root,5);
	RInsert(root,20);
	RInsert(root,8);
	RInsert(root,30);

	Delete(root, 20);
	Inorder(root);
	printf("\n");

	p = Search(20);
	if (p != NULL)
	{
		printf("Yes");
	}
	else
	{
		printf("false");
	}

	return 0;
}