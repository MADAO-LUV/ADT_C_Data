#include <iostream>
using namespace std;


template <class T>
//创建 节点类
class Node
{
public:
	T data;
	Node* next;
};

template <class T>
//创建链表类
class LinkedList
{
private:
	Node<T>* first;
public:
	LinkedList() { first = NULL; }
	LinkedList(T A[],int n);
	~LinkedList();

	void Display();
	void Insert(int index, T x);
	T Delete(int index);
	int Length();
};

template <class T>
//初始化 链表
LinkedList<T>::LinkedList(T A[], int n)
{
	Node<T>* last, * t;
	int i = 0;

	first = new Node<T>;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = new Node<T>;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

template <class T>
// 析构函数
LinkedList<T>::~LinkedList()
{
	Node<T>* p = first; //刚开始的first是头结点
	while (first)
	{
		first = first->next;
		delete p; //删除该节点 释放内存
		p = first;
	}
}

template <class T>
void LinkedList<T>::Display()
{
	Node<T>* p = first;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
int LinkedList<T>::Length()
{
	Node<T>* p = first;
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

template <class T>
void LinkedList<T>::Insert(int index, T x)
{
	Node<T>* t, * p = first;

	if (index < 0 || index > Length())
	{
		return; //结束运行
	}
	t = new Node<T>;
	t->data = x;
	t->next = NULL;

	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;

	}

}

template <class T>
T LinkedList<T>::Delete(int index)
{
	Node* p, * q = NULL;
	int x = -1;

	if (index<1 || index>Length())
	{
		return -1;
	}
	//这是第一个结点状况
	if (index == 1)
	{
		p = first;
		first = first->next;
		x = p->data;
		delete p;
	}
	else
	{
		p = first;
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x; //返回 被删除值

}



int main()
{
	int A[] = { 1,2,3,4,5 };
	LinkedList<int> l(A, 5);
	//cout << l.Length() << endl;
	//cout << l.Delete(1) << endl;
	l.Insert(0, 10);
	l.Display();
}