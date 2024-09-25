#include <stdio.h>

//方法一 递归
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return sum(n-1) + n;
    }
}

//方法二 循环
int Isum(int n)
{
    int i,s=0;
    for(i=1;i<=n;i++)
    {
        s=s+i;
    }
    return s;
}


//方法三 公式
int Gsum(int n)
{
    return n*(n-1)/2;
}

int main()
{

}