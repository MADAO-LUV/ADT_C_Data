#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}




//�������
void Display(int A[],int n)
{
	int len = sizeof(A);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

//���� ð������
void Bubble(int A[], int n)
{
	int i, j;

	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j+1])
			{
				swap(&A[j], &A[j+1]);
			}
		}
	}
}

//�Ż��� ð������
/*
�Ż��ĵط�:
�������ͨ���ð�����򣬵����Ǵ�������Ѿ��ź��������
������ȻҪ����������n^2�Ρ�

�����Ǽ�����һ����־flag  ֻҪflag==0 û�н��г�ʼһ�ζ�û�н���comprasion�Ļ���
��˵������������˵ģ����Ǿ�ֱ��break ����ʱ����˷�
*/
void AdvanceBubble(int A[], int n)
{
	int i, j,flag;

	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}	

		}
		if (flag == 0)
		{
			break;  //���һֱû�н���comparison�Ļ����˳�
		}
	}
}

//��������
void InsertionSort(int A[], int n)
{
	int i, j, x;

	for (i = 1; i < n; i++)
	{
		j = i - 1;  //ʹ j Ϊ i��ǰһ�������±�
		x = A[i];  //������¼��ǰ����

//�˴����ж��� j�±�Ҫ����-1 ��Ȼ��Խ���� �����磩
// A[j] > x �� ��� x ��ǰ���Ѿ�����õĻ�С����ǰ�ƶ�

		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x; //���ճ�����λ������ �������� �Ѿ�j--��λ��
	}


}


//ѡ������
void SelectionSort(int A[], int n)
{
	int i, j, k; //����ָ����;

	for (i = 0; i < n - 1; i++)
	{

		for (j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
			{
				k = j; //����λ��
			}
			
		}
		//ֱ��һ�ֱ����������ٽ��н���λ��
		swap(&A[i], &A[k]); //����λ��
	}
}


//���� ���� r�� �±�
int Partition(int A[], int l, int r)
{
	int pivot = A[l];
	int i = l, j = r; //j �����������ұ�

	do {
		do { i++; } while (A[i] <= pivot); //��ߵ��� Ҫ С�ڵ��� pivot 
		do { j--; } while (A[j] > pivot);  //�ұߵ��� Ҫ ����pivot
	//���𵽷���������
	
		if (i < j)swap(&A[i], &A[j]); //����λ��
	} while (i < j);

	swap(&A[l], &A[j]); //��� ��pivot �� j����λ��
	return j; //�������ֹͣ��λ��

}

//����ͺ�Сѧ���Ŷ�һ��
//ÿ�������Լ�Ϊ��� ȥ���Լ�Ӧ��ȥ�ĵط��� 
//�ֳ���һ����pivot �����ź�����
//r���±�   Ȼ����ʾ �����кõ����� ���������1������ INT_MAXû��Ҫ��ʾ����
void QuickSort(int A[], int l, int r)
{
	int j;

	if (l < r)
	{
		j = Partition(A, l, r); //��ȡ ��ǰ��˵�λ��
		QuickSort(A, l, j); //�Ա��λ��Ϊ�ֽ� ��߽��п���
		QuickSort(A, j + 1, r);  // �Ա��+1Ϊ��ʼ���ұ߽��п���
	}

}



//�Ż����ð������

int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2 };

//�����ڿ��ŵ����� ���Ҳ�һ������������ ����������������
	int Q[] = { 3,7,9,10,6,5,12,4,11,2,INT_MAX };
	int L = 11; //����
	int n = 10;
//	AdvanceBubble(A, 10);
	QuickSort(Q, 0, 10);
	Display(Q,11);

	return 0;
}