#include <stdio.h>


/*
fib(n) = 0       n=0
         1       n=1
         fib(n-2) + fib(n-1)  n>1
*/
//递归版本
int fib(n)
{
    if(n<=1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

//循环版本
int fib1(n)
{
    int t0=0,t1=1,s,i;
    if(n<=1)
    {
        return n;
    }
    for(i=2;i<=n;i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}


//减少递归次数版本
int f[10];   //用来存放数据 记得在main中使用循环给它赋初始值

/*
int main()
{
    for(int i=0;i<10;i++)
    {
        f[i] = -1;
    }
    //给列表里的数赋予初始值
}

*/
int fib2(int n)
{
    if(n<=1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n-1] == -1)
        {
            f[n-1] = fib2(n-1);
        }
        if (f[n-2] == -1)
        {
            f[n-2] = fib2(n-2);
        }

        return f[n-2]+f[n-1];
    }
}








