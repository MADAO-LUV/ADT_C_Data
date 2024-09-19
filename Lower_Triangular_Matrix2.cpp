#include<iostream>
using namespace std;

//�����Ǿ���

class LowerTri
{
private:
	int* A;  //������̬�����ڴ�
	int n; //ά��
public:
	LowerTri()
	{
		n = 2;
		A = new int[2*(2+1)/2]; //��������ǵ�Ĭ�Ϸַ�
	}
	LowerTri(int n)
	{
		//����ά�� n��ֵ
		this->n = n;
		this->A = new int[n*(n+1)/2];
	}
	void Set(int i, int j, int x);
	void Display();
	int Get(int i, int j);
	~LowerTri()
	{
		delete[]A; //ɾ��������Ķ�̬�ռ�
	}
};

void LowerTri::Set(int i, int j, int x)
{
	if (i >= j)
		A[i * (i - 1) / 2 + j - 1] = x;
}


int LowerTri::Get(int i, int j)
{
	if (i == j)
	{
		return A[i * (i - 1) / 2 + j - 1]; //���ضԽ����ϵ�ֵ
	}
	else
	{
		return 0;
	}
}


void LowerTri::Display()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i >= j)
			{
				cout << A[i * (i - 1) / 2 + j - 1] << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}

}int main()
{

	LowerTri d(4);

	d.Set(1, 1, 5);
	d.Set(2, 2, 6);
	d.Set(3, 3, 7);
	d.Set(4, 4, 8);

	cout << endl;
	cout << d.Get(2, 2) << endl;
	d.Display();

	return 0;
}