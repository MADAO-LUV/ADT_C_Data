#include<stdio.h>

//实现泰勒公式
double e(int x,int n)
{
    static double p=1,f=1;
    double r; //用于保存前值
    if(n==0)
    {
        return 1;
    }
    else
    {
        r = e(x,n-1);
        p = p * x;   //这个是pow 乘方
        f = f * n;
        return r+p/f;
    }
}

//此时间复杂度为 O(n^2)

//另一种方法
double e1(int x,int n)
{
    static double s = 1;
    if(n==0)
    {
        return s;
    }
    s = 1+x*s/n;    //分别把乘法抽出来成为 (1 + x*s / n ) 的形式
    return e1(x,n-1);
}


//循环方法实现泰勒级数
double e(int x,int n)
{
    double s=1;
    int i;
    double num=1;
    double den=1;

    for(i=1;i<=n;i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}