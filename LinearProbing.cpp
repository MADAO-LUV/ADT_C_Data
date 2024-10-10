#include<stdio.h>
#define SIZE 10

int hash(int key)
{
	return key % SIZE;
}

//�������Լ�� ���ҳ���һ�����еĿռ� ̽�빦�� Linear
int probe(int H[],int key)
{
	int index = hash(key); // ���Hash����ֵ
	int i = 0;
	while (H[index + i] % SIZE != 0)
		i++;
	return (index + i) % SIZE; //��������λ��
}


void Insert(int H[], int key)
{
	int index = hash(key);

	if (H[index] != 0) //����H[index]������ֵ�ͽ���probe
	{
		index = probe(H, key);
	}
	H[index] = key;

}

// Ѱ�������ֵ �� λ��
int Search(int H[], int key)
{
	int index = hash(key);//������Բ���ʧ�ܵĻ�

	int i = 0;

	while (H[(index + i) % SIZE] != key)
	{
		i++; //ֱ���ڸ�hash����Ѱ�ҵ��� ��ֵ
	}

	return (index + i) % SIZE;
}

/*-------------------------------------------*/
//������Quatric Probe
int Qprobe(int H[], int key)
{
	int index = hash(key);

	int i = 0;
	while (H[(index + i * i)%SIZE] != 0)
	{
		i++;
	}

	return (index + i * i) % SIZE;
}

int QSearch(int H[], int key)
{
	int index = hash(key);

	int i = 0;
	while (H[(index + i * i) % SIZE] != key)
	{
		i++;
	}

	return (index + i * i) % SIZE;
}


void QInsert(int H[], int key)
{
	int index = hash(key);

	if (H[index] != 0)
	{
		index = Qprobe(H, key);

	}
	H[index] = key;
}


int main()
{
	int HT[10] = { 0 };//ȫ����ʼ��Ϊ0
	QInsert(HT, 21);
	QInsert(HT, 12);
	QInsert(HT, 38);

	printf("Key Found at %d\n", QSearch(HT,38));
	return 0;
}

