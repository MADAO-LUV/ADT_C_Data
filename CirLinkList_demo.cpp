#include <stdio.h>
#include <stdlib.h>

/*ʵ��ѭ��������*/

typedef struct LNode {
	int data; //ÿ�������һ������Ԫ��
	struct LNode* next; //ָ��ָ����һ�����
}LNode,*LinkList;

//��ʼ��һ��ѭ���б�
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = L; //ͷ���ָ��ͷ���
	return true;
}

//�ж�ѭ�������Ƿ�Ϊ��
bool ifEmpty(LinkList L) {
	if (L->next == L) {
		return true;
	}
	else {
		return false;
	}
}

//�жϽ��P�Ƿ�Ϊ��β���
bool isTail(LinkList L, LNode* p) {
	if (p->next == L) {
		return true; //����������Ϊ�˸��õ��ж�
	}
	else {
		return false;
	}
}

//ѭ��������Ĳ���
bool InsertNextNode(LNode* p, int e) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false; //�ڴ�ռ�����ʧ�ܵĻ�
	}
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}

//ѭ���������ɾ��
bool DeteleNode(LinkList L, LNode* p) {
	//��������L��Ϊ���жϽ��p�Ƿ�Ϊͷ���
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

/*���ϱ���ѭ��������Ļ����ж�*/


int main()
{

	return 0;
}