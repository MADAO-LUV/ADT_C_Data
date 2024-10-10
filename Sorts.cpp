#include<stdio.h>
#include<stdlib.h>
#include<math.h> //Ϊ������pow()

struct Node
{
	int data;
	struct Node* next;
};

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//��Ԫ�ز�������(Ͱ)�� 
// value Ӧ���Ƕ�Ӧ��ֵ ��ôbin[value] �Ƕ�Ӧֵ���±�
void Insert(struct Node** bin, int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	if (bin[value] == NULL) //������±�Ļ�δ��������ʱ
	{
		bin[value] = temp;
	}
	else
	{
		struct Node* p = bin[value];
		while (p->next != NULL) //�ҵ���Ӧλ�õ����һ��Node
		{
			p = p->next;
		}
		p->next = temp;
	}
}

//����ǻ�������Ĳ��뺯�� ���Ǹ��ݻ������жϲ����
//index ������������Ļ��� 
//value �������Ƕ�Ӧ������ֵ ����϶��ǲ���ʡ�Ե�
void RadixInsert(struct Node** bin, int value, int index)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	if (bin[index] == NULL) //������±�Ļ�δ��������ʱ
	{
		bin[index] = temp;
	}
	else
	{
		struct Node* p = bin[index];
		while (p->next != NULL) //�ҵ���Ӧλ�õ����һ��Node
		{
			p = p->next;
		}
		p->next = temp;
	}
}


// ���������Ƴ�Ԫ�أ����ڴ�Ͱ��ȡ��Ԫ�أ� ��������Ҳ����ʹ��
int Delete(struct Node** bin, int index)
{
	struct Node* p = bin[index]; //Ѱ��ֵ ��ס bin�����ŵ���Node�ṹ��
	bin[index] = bin[index]->next; //������ͷɾ�� bin[index]����ʼ ָ����һ���ڵ�
	int value = p->data;
	free(p);
	return value;
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



//�ϲ�����  l--���  r--�ұ�
void Merge(int A[], int l, int mid, int r)
{
	int i=l, j=mid+1, k=l;
	int B[100]; //������� Ԫ�ص� �ڴ澡����һ��

	//�ж������� i С����λ  j С���ұ�
	while (i <= mid && j <= r)
	{
		if (A[i] < A[j])
		{
			B[k++] = A[i++]; //�Ƚ�С���ȷ���
		}
		else
		{
			B[k++] = A[j++];
		}
	}

	//�ѻ�δ����ķ���
	for (; i <= mid; i++)
	{
		B[k++] = A[i];
	}
	for (; j <= r; j++)
	{
		B[k++] = A[j];
	}
	//�����кõ�Ԫ�����·���
	for (i = l; i <= r; i++)
	{
		A[i] = B[i];
	}
}

//����� n Ϊ����Ĵ�С ����ǵ����汾
void IMergeSort(int A[], int n)
{
	int p, l, r, mid, i;

	//���� p�������� ������չһ�����顱��С��
	//�� 2��Ԫ��Ϊһ�� 4 ��Ԫ��Ϊһ�� �ȴ�С��ʼ�� Ȼ���ٺϲ�
	for (p = 2; p <= n; p = p * 2)
	{
		//i+p Ϊ���
		for (i = 0; i + p - 1 < n; i = i + p)
		{
			l = i; //��߽�
			r = i + p - 1; //�ұ߽�
			mid = (l + r) / 2; //�м�ֵ
			Merge(A, l, mid, r);
		}
	}

	if (p / 2 < n)
	{
		Merge(A, 0, p / 2 - 1, n-1); //��ϲ�
		//p/2 - 1 ���±� Ҫ����
	}
}

//ֱ�����һ�����ϲ��ź�����������
//���뱣֤ ���������鱾�����ź������
void TwoMergeSort(int A[], int B[], int m, int n)
{
	int i, j, k; //��Ϊָ��ʹ��
	int C[100];
	i = j = k = 0; //��ʼһ��ָ��

	while (i < m && j < n)
	{
		if (A[i] < B[j])
		{
			C[k++] = A[i++];
		}
		else
		{
			C[k++] = B[j++];
		}
	}

	//��ʣ�µ�����
	for (; i < m; i++)
	{
		C[k++] = A[i];
	}

	for (; j < n; j++)
	{
		C[k++] = B[j];
	}

	for (int k = 0; k < m + n; k++)
	{
		printf("%d ", C[k]);
	}
	printf("\n");
}


/*
***** �ݹ� �ϲ�����
���ǿ��Կ������ݹ�ϲ����� ���������������� ���ϵ� 2�� 2������С��Ȼ��ֱ�� һ������ֻ�� 1��Ԫ��(Sorted ������Ϊ�����Ѿ��ź����˵�).

����ź�������� �ݹ鷵�ظ���һ�������ٴν�������  ��һ��MergeSort��������������� Ȼ���ڵڶ���MergeSort���ұ�
Merge()��ʵ�������õ� ��һ���Ѿ�ʵ����
���ո߶����� �� һ���߶�����Ҫ���� n��Ԫ��

ʵ�ڲ��оͻ�һ����ͼ��ģ�� ����һ��BST Best Sinary Tree
*/
void RMerge(int A[], int l, int r)
{
	//������С���ұ�
	int mid;
	if (l < r) //�� l == r ��ʱ�� �����Ǹ��ݹ鵽ֻ��һ��Ԫ�ص���� �����ٷ���
	{
		mid = (l + r) / 2;
		RMerge(A, l, mid);
		RMerge(A, mid + 1, r);
		Merge(A, l, mid, r); //�����Ψһ�ĺϲ�����
	}
}

//����һ���ҵ����ֵ���� Ϊ���Ǹ���̬���������С
int FindMax(int A[], int n)
{
	int max = INT_MIN; //�����Ҫ����<stdlib.h>�ļ�
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}

	return max;
}

//ȡ��  power ��ȡ������Ҫ����һ��λ ��ӦλȨ�ϵ���
int remainder(int num, int power)
{
	int temp = pow(10, power);
	return (num / temp) % 10;
}

//��ȡλ��
int Bit_Int(int n)
{
	if (n == 0)
		return 1;
	else
		return log10(abs(n)) + 1;//��������λ��
	//����  1234  lgx+1;                   
}

void CountSort(int A[], int n)
{
	int i, j, max, * c;
	max = FindMax(A, n);
	c = (int*)malloc(sizeof(int) * (max + 1));

	//����̬����c��ȫ����ֵΪ0
	for (i = 0; i < max+1; i++)
	{
		c[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		c[A[i]]++;
	}
	i = 0; j = 0; //��ʼ��0 ��ͷ��ʼ
	while (j < max + 1)
	{
		if (c[j] > 0)
		{
			A[i++] = j;
			c[j]--;//����Ĵ�����1
		}
		else
		{
			j++; //�±��ƶ�
		}
	}
}

//Ͱ���� ��ʵ��˵ ��ʵ����Count Sort����
/*
˼��:

������Ԫ�ظ��ݷ�Χ���벻ͬ��Ͱ��bin���С�
��ÿ��Ͱ�ڵ�Ԫ�ؽ�������Ȼ�����Ǻϲ���һ������õ����顣
*/
void BinSort(int A[], int n)
{
	int max = FindMax(A, n);

	//��̬����ռ�
	struct Node** Bin = (struct Node**)malloc(sizeof(struct Node*) * (max + 1));

	//��ʼ��ÿ��ͰΪ��
	for (int i = 0; i < max + 1; i++)
	{
		Bin[i] = NULL;
	}

	//��ÿ����Ӧ��Ԫ�ط����Ӧ��Ͱ��
	for (int i = 0; i < n; i++)
	{
		Insert(Bin, A[i]);
	}

	//����Ͱ������ ����ȡ������������
	int k = 0;
	for (int j = 0; j < max + 1; j++)
	{
		//�ж��Ǹ�Ͱ�Ƿ�Ϊ��
		//�����j ����������
		while (Bin[j] != NULL)
		{
			A[k++] = Delete(Bin, j);
		}
	}
}





//�������� 
/*
˼��:

���������ǻ��ڡ����䡱�͡��ռ����ķ������е��������������Чλ��ʼ��λ�������������ֱ�������Чλ��
���ü���������Ϊ�Ӳ��账��ÿ��λ��������

*/
void RadixSort(int A[], int n)
{
	int i, j, max,s; //s �������
	max = FindMax(A, n); //���ҵ����ֵ
	s = Bit_Int(max); // ��ȡ��Ҫ����Ĵ���
	//�ṹ��ָ������
	struct Node** Bins = (struct Node**)malloc(sizeof(struct Node*) * 10);

	for (i = 0; i < 10; i++)
	{
		Bins[i] = NULL; //�ȳ�ʼ��Ϊ��
	}
//�����ظ����� k���ظ����� Ҳ��������������ȡλ��
	for (int k = 0; k < s; k++)
	{
		j = 0; //ÿһ�ֶ�Ҫ������ʼ��Ϊ0
		//�ȴ�������������
		while (j < n) //n �������С
		{
			int index = remainder(A[j], k);
			RadixInsert(Bins, A[j], index);
			j++; 
		}

		//���մ���ȡ�� ����ԭ�ȵ������� 
		int num = 0; // �����
		for (int w = 0; w < 10; w++)  //����10
		{
			while (Bins[w] != NULL)
			{
				A[num++] = Delete(Bins, w);
			}

		}
	}
}


//ϣ������
void ShellSort(int A[], int n)
{
	int gap, i, j,temp;

	for (gap = n / 2; gap >= 1; gap /= 2)
	{

		for (i = gap; i < n; i++)
		{
			temp = A[i]; //��j ���� һ��gap�ľ���
			j = i - gap;
			while (j >= 0 && A[j] > temp)
			{
				A[j + gap] = A[j];// ��ֵ
				j = j - gap;
			}
			A[j + gap] = temp;
		}
	}
}


int main()
{
	int A[] = { 3,7,9,10,6,5,12,4,11,2,19 };
	int b[] = { 1,8,45,67,200 };
//�����ڿ��ŵ����� ���Ҳ�һ������������ ����������������
	int Q[] = { 3,7,9,10,6,5,12,4,11,2,INT_MAX };
	int L = 11; //����
	int n = 10;
//	AdvanceBubble(A, 10);
//	QuickSort(Q, 0, 10);
//	Display(Q,11);

//	RMerge(A, 0, 9);
	RadixSort(A, 11);
	Display(A, 11);


//	TwoMergeSort(A, b, 10, 5);
	return 0;
}