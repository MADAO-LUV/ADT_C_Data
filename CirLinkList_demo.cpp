#include <stdio.h>
#include <stdlib.h>

/*实现循环单链表*/

typedef struct LNode {
	int data; //每个结点存放一个数据元素
	struct LNode* next; //指针指向下一个结点
}LNode,*LinkList;

//初始化一个循环列表
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = L; //头结点指向头结点
	return true;
}

//判断循环链表是否为空
bool ifEmpty(LinkList L) {
	if (L->next == L) {
		return true;
	}
	else {
		return false;
	}
}

//判断结点P是否为表尾结点
bool isTail(LinkList L, LNode* p) {
	if (p->next == L) {
		return true; //传入链表是为了更好地判断
	}
	else {
		return false;
	}
}

//循环单链表的插入
bool InsertNextNode(LNode* p, int e) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false; //内存空间申请失败的话
	}
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}

//循环单链表的删除
bool DeteleNode(LinkList L, LNode* p) {
	//传入链表L是为了判断结点p是否为头结点
	if (p == L) {
		return false;
	}
	LNode* s = L;
	while (s->next != p) {
		s = s->next;
	}
	s->next = p->next;
	free(p);
	return true;
}

/*以上便是循环单链表的基本判断*/


int main()
{

	return 0;
}