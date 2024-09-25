
![[Pasted image 20240915221834.png]]
对于多项式在c\c++中的创立 
1. 就是对单个 参数  n *  x ^ k    n为系数  k为次方  x 为 自变量 进行定义
```
struct Term
{
	int Coegy;   //这是系数
	int Exp;    //这是次方 power 有次方的意思
}
```

2. 就是 对 整个多项式 的 定义  其中那个结构体指针 是用来指向存储 在 heap(堆)中的 数组  也 就是 我们所创建的多个 Term
```
struct Poly
{
	int n;   //多项式的个数
	struct Term *t;  //结构体指针
}
```


Polynomid addition
![[Pasted image 20240915223010.png]]
