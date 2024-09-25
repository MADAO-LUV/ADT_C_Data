#include<stdio.h>
#include<stdlib.h>

//接下来会使用三种方式来创建2d array
int main()
{
// Way 1:
    int A[3][4] = {{1,2,3,4},{5,6,7,8},{1,3,5,7}};
//常规方法


// Way 2:
    int *B[3];     //使用整型数组指针


    B[0] = (int *)malloc(4*sizeof(int));
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));

// Way 3:
    int **C;       //使用二维指针
    C = (int **)malloc(3*sizeof(int*));
    C[0] = (int *)malloc(4*sizeof(int));
    C[1] = (int *)malloc(4*sizeof(int));
    C[2] = (int *)malloc(4*sizeof(int));

    return 0;
}