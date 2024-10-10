#pragma once

#ifndef Chains_H
#define Chains_H
#include <stdio.h>
#include <stdlib.h>
// ���� �ڵ�
struct Node
{
	int data;
	struct Node* next;
}*first = NULL, * second = NULL, * third = NULL;


void create(int A[], int n)
{
	int i;
	struct Node* t, * last;   //ͷָ�� βָ��
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}


}

void create2(int A[], int n)
{
	int i;
	struct Node* t, * last;   //ͷָ�� βָ��
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}


}



void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}

//�ݹ���� ��ʾ��������
void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		RDisplay(p->next);
	}

	/*
	��һ��д��
	if(p != NULL)
	{
		RDisplay(p->next);
		printf("%d ",p->data);
	}
	*/
}

int CountNode(struct Node* p)
{
	int l = 0;
	while (p)
	{
		l++;
		p = p->next;
	}
	return l;
}

//�ݹ��¼����ĳ���
int Rcount(struct Node* p)
{
	if (p != NULL)
	{
		return Rcount(p->next) + 1;
	}
	else
	{
		return 0;
	}
}


int Sum(struct Node* p)
{
	int s = 0;

	while (p != NULL)
	{
		s += p->data;
		p = p->next;
	}
	return s;
}

int Rsum(struct Node* p)
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return Rsum(p->next) + p->data;
	}

}


int Max(struct Node* p)
{
	int max = INT_MIN;

	while (p)
	{
		if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int RMax(struct Node* p)
{
	int x = 0;

	if (p == 0)
	{
		return INT_MIN;
	}
	x = RMax(p->next);
	if (x > p->data)
	{
		return x;
	}
	else
	{
		return p->data;
	}
}


//Linear Search

struct Node* LSearch(struct Node* p, int key)
{
	while (p != NULL)
	{
		if (key == p->data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}


struct Node* RSearch(struct Node* p, int key)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (key == p->data)
	{
		return p;
	}
	return RSearch(p->next, key);

}

//�޸İ� Linear Search
//�����Ѱ�ҵ��Ľ�� �ŵ���ǰ�� �����´��ٴβ�ѯ
struct Node* LSearch_demo(struct Node* p, int key)
{
	struct Node* q = (struct Node*)malloc(sizeof(struct Node));
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}


void Insert(struct Node* p, int index, int x)
{
	struct Node* t;

	if (index <0 || index > CountNode(p))
	{
		return; //ֹͣ����
	}
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;

	if (index == 0)
	{
		t->next = first;
		first = t;

	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}

}


void SortedInsert(struct Node** H, int x)
{
	struct Node* t, * q = NULL,*p=*H;

	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;
	//�������ж� ͷ��� �����Ƿ�Ϊ��
	if (*H == NULL)
	{
		*H = t;
	}
	else
	{
		//��Ϊ��ʱ ���Ƚϴ�С ��˳��洢
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		//��������� 1.��ͷ������ 2.�������������
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}

}

int Delete(struct Node* p, int index)
{
	struct Node* q = NULL;
	int x = -1;

	if (index<1 || index >CountNode(p))
	{
		return -1;
	}
	if (index == 1) //�����ͷ��ʱ
	{
		q = first;
		x = first->data;
		first = first->next;
		free(q);
		return x;
	}
	else    //����ͷ����ɾ��
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
		return x;
	}

}

//�Ƴ��ظ���Ԫ��
void RemoveDuplicate(struct Node* p)
{
	struct Node* q = p->next;

	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}

}





int isSorted(struct Node* p)
{
	int x = INT_MIN;

	while (p != NULL)
	{
		if (p->data < x)
		{
			return 0;
		}
		x = p->data;
		p = p->next;
	}
	return 1;
}

//��ת����
void Reverse1(struct Node* p)
{
	int* A, i = 0;  //�����н�ԭ���������е�Ԫ��˳��
	struct Node* q = p;
	A = (int*)malloc(sizeof(int) * CountNode(p));//��̬�ռ�

	while (q != NULL)
	{
		A[i++] = q->data;
		q = q->next;
	}
	q = p; //�����ָ�����·ŵ���ͷ��
	i--;
	while (q != NULL)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}

}

//slider pointer�� ����
void Reverse2(struct Node* p)
{
	//�����p�Ǵ����ͷָ�� p=first q = NULL r = NULL 
	struct Node* q = NULL, * r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;

}

//�������˳������ ������������ֱ������
void Conact(struct Node* p, struct Node* q)
{
	third = p;

	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
}


void Merge(struct Node* p, struct Node* q)
{
	struct Node* last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}

	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	//��ʣ�µ���Щ˳����������һ����
	if (p)last->next = p;
	if (q)last->next = q;
}

//�ж��Ƿ�ѭ��
int IsLoop(struct Node* f)
{
	struct Node* p, * q;
	p = q = f;

	do {
		p = p->next;
		q = q->next;
		q = q ? q->next : q;
	} while (p && q && p != q);

	if (p == q)
	{
		return 1;
	}
	else
	{
		return false;
	}
}


#endif 
