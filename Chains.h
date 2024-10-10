#pragma once

#ifndef Chains_H
#define Chains_H
#include <stdio.h>
#include <stdlib.h>
// 创建 节点
struct Node
{
	int data;
	struct Node* next;
}*first = NULL, * second = NULL, * third = NULL;


void create(int A[], int n)
{
	int i;
	struct Node* t, * last;   //头指针 尾指针
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
	struct Node* t, * last;   //头指针 尾指针
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

//递归调用 显示所有数据
void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->data);
		RDisplay(p->next);
	}

	/*
	另一种写法
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

//递归记录链表的长度
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

//修改版 Linear Search
//将这次寻找到的结点 放到最前面 方便下次再次查询
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
		return; //停止程序
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
	//这里是判断 头结点 链表是否为空
	if (*H == NULL)
	{
		*H = t;
	}
	else
	{
		//不为空时 ，比较大小 按顺序存储
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		//分两种情况 1.在头结点插入 2.在两个结点间插入
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
	if (index == 1) //如果在头部时
	{
		q = first;
		x = first->data;
		first = first->next;
		free(q);
		return x;
	}
	else    //不在头部处删除
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

//移除重复的元素
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

//翻转链表
void Reverse1(struct Node* p)
{
	int* A, i = 0;  //用来承接原来的链表中的元素顺序
	struct Node* q = p;
	A = (int*)malloc(sizeof(int) * CountNode(p));//动态空间

	while (q != NULL)
	{
		A[i++] = q->data;
		q = q->next;
	}
	q = p; //将这个指针重新放到开头处
	i--;
	while (q != NULL)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}

}

//slider pointer版 倒置
void Reverse2(struct Node* p)
{
	//这里的p是传入的头指针 p=first q = NULL r = NULL 
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

//这个不是顺序链接 就是两个链表直接链接
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
	//把剩下的那些顺序链表链接一起来
	if (p)last->next = p;
	if (q)last->next = q;
}

//判断是否循环
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
