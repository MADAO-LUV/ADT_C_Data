#include<iostream>
using namespace std;

class Diagond
{
private:
	int* A;  //������̬�����ڴ�
	int n; //ά��
public:
	Diagond()
	{
		n = 2;
		A = new int[2]; //��������ǵ�Ĭ�Ϸַ�
	}
	Diagond(int n)
	{
		//����ά�� n��ֵ
		this->n = n;
		this->A = new int[n];
	}
	void Set(int i,int j,int x);
	void Display();
	int Get(int i,int j);
	~Diagond()
	{
		delete[]A; //ɾ��������Ķ�̬�ռ�
	}
};

void Diagond::Set(int i, int j, int x)
{
	if (i == j)
		A[i - 1] = x;
}


int Diagond::Get(int i, int j)
{
	if (i == j)
	{
		return A[i - 1]; //���ضԽ����ϵ�ֵ
	}
	else
	{
		return 0;
	}
}


void Diagond::Display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				cout << A[i] << " ";
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

	Diagond d(4);

	d.Set(1, 1, 5);
	d.Set(2, 2, 6);
	d.Set(3, 3, 7);
	d.Set(4, 4, 8);

	cout << endl;
	cout << d.Get(2, 2) << endl;
	d.Display();

	return 0;
}