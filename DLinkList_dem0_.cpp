#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct DNode {
	Elemtype data;//存放数据
	struct DNode* prior, * next;//两个指针
}DNode,*DLinkList;


//初始化双向链表
bool InitLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;//内存空间分配失败
	}
	L->prior = NULL;//头节点的piror指针永远指向NULL
	L->next = NULL; //头结点之后暂时还没有指针
	return true;
}

//双链表的插入 后插操作
bool InsertNextNode(DNode* p, DNode* s) {
	if (p == NULL) {
		return false;
	}
	s->next = p->next;
	if (p->next != NULL) {
		//如果p结点的后继结点不为空的时候
		p->next->prior = s;//后继结点的前指针指向s结点
	}
	s->prior = p;
	p->next = s;
	return true;
}


//双链表的插入  前插操作
bool InsertPriorNode(DNode* p, DNode* s) {
	if (p->prior == NULL || p == NULL) {
		return false;
	}
	s->prior = p->prior;
	p->prior->next = s;//p的前驱结点的相反指向
	p->prior = s;
	s->next = p;
	return true;
}

//双链表的删除 删除p结点的后继结点
bool DeleteDNode(DNode* p) {
	if (p == NULL) {
		return false;
	}
	DNode* s = p->next; //找到p的后继结点
	if (s == NULL) {
		return false; //p无后继结点
	}
	p->next = s->next;//p结点指向后继结点的后继结点
	if (s->next != NULL) {
		s->next->prior = p;
	//如果有后继结点，那么就指向p，如果为空，跳过此步
	}
	free(s);
	return true; //释放结点空间
}

//销毁一个双向链表
void DestoryList(DLinkList& L) {
	while (L->next != NULL) {
		DeleteDNode(L);//直到头结点指向为空时
	}
	free(L);//释放头结点空间
	L = NULL; //头指针指向为空
}

//双链表的遍历
//后向遍历
void printList(DLinkList L) {
	DNode* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}





//创建一个双向链表的操作 头结点处插入法
DLinkList InitList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	L->next = NULL;
	L->prior = NULL;
	Elemtype j;
	
	scanf("%d", &j);
	while (j != 999) {
		DNode* s = (DNode*)malloc(sizeof(DNode));
		s->data = j;
		s->next = L->next;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
		scanf("%d", &j);
		}
	
	return L;
	}

int main() {
	DLinkList L;
	InitList(L);
	printList(L);

	return 0;
}