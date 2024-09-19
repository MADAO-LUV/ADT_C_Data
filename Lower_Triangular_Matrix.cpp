#include <stdio.h>
#include <stdlib.h>
//���������Ǿ���
struct Matrix
{
	int* A;
	int n;
};


void Set(struct Matrix* m, int i, int j, int x)
{
	if (i >= j)
	{
		//����������Ǹ��� �д洢 �Ĺ�ʽ��
		m->A[i * (i - 1) / 2 + j - 1] = x;
	}
}


int Get(struct Matrix m, int i, int j)
{
	if (i >= j)
	{
		return m.A[i * (i - 1) / 2 + j - 1];
	//����Ϊ m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
	}
	else
	{
		return 0;
	}
}


void Display(struct Matrix m)
{
	int i, j;
	for (i = 1; i <= m.n; i++)
	{
		for (j = 1; j <= m.n; j++)
		{
			if (i >= j)
			{
				printf("%d ", m.A[i * (i - 1) / 2 + j - 1]);
			}
			else
			{
				printf("0 ");
			}
			printf("0 ");
		}
	}
	
}


int main()
{
	struct Matrix m;
	int i, j,x;
	printf("Enter Dimension\n");
	scanf_s("%d", &m.n);
	m.A = (int*)malloc(m.n * (m.n + 1) / 2 * sizeof(int)); //������ֻ�����Ԫ��

	printf("enter all elements\n");
	for (i = 1; i <= m.n; j++)
	{
		for (j = 1; j <= m.n; j++)
		{
			scanf_s("%d", &x);
			Set(&m, i, j, x);
		}
	}
	
	Display(m);

	return 0;
}