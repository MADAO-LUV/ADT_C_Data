#include <stdio.h>

/*
    N
     C r  =  n! / r! * (n-r)! NCR选择公式

*/
//递归实现NCR公式
int C(int n,int r)
{
    if(r==0 || n == r)
    {
        return 1;
    }
    else
    {
        retrun C(n-1,r-1) + C(n-1,r);
    }
}


//方法二
int fact(int n) //这个是阶乘
{
    if(n==0)return 1;
    retrun fact(n-1)*n;
}

int nCr(int n,int r)
{
    int num,den;

    num=fact(n);
    den=fact(r)*fact(n-r);
    return num/den;
}