#include <stdio.h>
#include <stdlib.h>

/*此处是建立循环双链表*/
//先定义一个循环双链表
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;

//链表的初始化
bool InitDLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->prior = L;
	L->next = L;
	return true;
}

//判断循环双链表是否为空
bool Empty(DLinkList L) {
	if (L->next == L) {
		return true;//利用L的头结点来判断
	}
	else {
		return false;
	}
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinkList L, DNode* p) {
	if (p->next == L) {
		return true;//这里是利用p的next来判断
	}
	else {
		return false;
	}
}

//在p结点之后插入s结点
bool InsertNextNode(DNode* p, DNode* s) {
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//删除p结点的后继结点q
bool DeteleNode(DLinkList L,DNode* p) {
	if (p == L) {
		return false;
	}
	DNode* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return true;
}

int main()
{

	return 0;
}