#include <stdio.h>
#include <stdlib.h>

/*�˴��ǽ���ѭ��˫����*/
//�ȶ���һ��ѭ��˫����
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;

//����ĳ�ʼ��
bool InitDLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;
	}
	L->prior = L;
	L->next = L;
	return true;
}

//�ж�ѭ��˫�����Ƿ�Ϊ��
bool Empty(DLinkList L) {
	if (L->next == L) {
		return true;//����L��ͷ������ж�
	}
	else {
		return false;
	}
}

//�жϽ��p�Ƿ�Ϊѭ��˫����ı�β���
bool isTail(DLinkList L, DNode* p) {
	if (p->next == L) {
		return true;//����������p��next���ж�
	}
	else {
		return false;
	}
}

//��p���֮�����s���
bool InsertNextNode(DNode* p, DNode* s) {
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//ɾ��p���ĺ�̽��q
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