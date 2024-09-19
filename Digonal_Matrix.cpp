#include<stdio.h>

//这是一个对角矩阵
struct Matrix
{
	int A[10];
	int n; // n是 矩阵的阶数
};

// i,j 是 类似于 x,y轴 用来判断该元素在矩阵中的位置
void Set(struct Matrix* m, int i, int j, int x) //x 为目标元素
{
	if (i == j)
	{
		m->A[i - 1] = x; //完成存储
	}
}

int Get(struct Matrix m, int i, int j)
{
	if (i == j)
	{
		return m.A[i - 1];//返回对角线上的元素
	}
	else
	{
		return 0;
	}
}

// 将该矩阵打印出来
void Display(struct Matrix m)
{
	int i, j;
	for (i = 0; i < m.n; i++)
	{
		for (j = 0; j < m.n; j++)
		{
			if (i == j)
			{
				printf("%d ", m.A[i]);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}

}

int main()
{
	struct Matrix m;
	m.n = 4;

	Set(&m, 1, 1, 6); Set(&m, 2, 2, 8); Set(&m, 3, 3, 9); Set(&m, 4, 4, 10);

	Display(m);

	return 0;
}