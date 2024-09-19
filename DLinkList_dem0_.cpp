#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct DNode {
	Elemtype data;//�������
	struct DNode* prior, * next;//����ָ��
}DNode,*DLinkList;


//��ʼ��˫������
bool InitLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL) {
		return false;//�ڴ�ռ����ʧ��
	}
	L->prior = NULL;//ͷ�ڵ��pirorָ����Զָ��NULL
	L->next = NULL; //ͷ���֮����ʱ��û��ָ��
	return true;
}

//˫����Ĳ��� ������
bool InsertNextNode(DNode* p, DNode* s) {
	if (p == NULL) {
		return false;
	}
	s->next = p->next;
	if (p->next != NULL) {
		//���p���ĺ�̽�㲻Ϊ�յ�ʱ��
		p->next->prior = s;//��̽���ǰָ��ָ��s���
	}
	s->prior = p;
	p->next = s;
	return true;
}


//˫����Ĳ���  ǰ�����
bool InsertPriorNode(DNode* p, DNode* s) {
	if (p->prior == NULL || p == NULL) {
		return false;
	}
	s->prior = p->prior;
	p->prior->next = s;//p��ǰ�������෴ָ��
	p->prior = s;
	s->next = p;
	return true;
}

//˫�����ɾ�� ɾ��p���ĺ�̽��
bool DeleteDNode(DNode* p) {
	if (p == NULL) {
		return false;
	}
	DNode* s = p->next; //�ҵ�p�ĺ�̽��
	if (s == NULL) {
		return false; //p�޺�̽��
	}
	p->next = s->next;//p���ָ���̽��ĺ�̽��
	if (s->next != NULL) {
		s->next->prior = p;
	//����к�̽�㣬��ô��ָ��p�����Ϊ�գ������˲�
	}
	free(s);
	return true; //�ͷŽ��ռ�
}

//����һ��˫������
void DestoryList(DLinkList& L) {
	while (L->next != NULL) {
		DeleteDNode(L);//ֱ��ͷ���ָ��Ϊ��ʱ
	}
	free(L);//�ͷ�ͷ���ռ�
	L = NULL; //ͷָ��ָ��Ϊ��
}

//˫����ı���
//�������
void printList(DLinkList L) {
	DNode* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}





//����һ��˫������Ĳ��� ͷ��㴦���뷨
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