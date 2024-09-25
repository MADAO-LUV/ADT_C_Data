1.Diagonal Matrix (对角矩阵)
![[Pasted image 20240911000844.png]]
利用一维数组来存储二维的 矩阵 (对角矩阵)上的非零元素，0元素不浪费空间存取。


2.Lower Triangular Matrix (下三角矩阵)
![[Pasted image 20240912083951.png]]
非零元素个数:
n(n+1)/2 

零元素个数为
n(n-1)/2
![[Pasted image 20240912084645.png]]
使用一维数组存储下三角矩阵。(行存储)

列存储
![[Pasted image 20240912085222.png]]
后面的 (i-j) 可以看 A[4 [4---- 发现 i 为 4 ，j 也为 4 所以 i - j 为 0 在 index 第一个 可以发现。


Upper Triangluar Matrix (上三角矩阵)
![[Pasted image 20240912095147.png]]
非零元素所占空间为 --- n*(n+1)/2

Row-major  行 公式为
A[i[j  --- > (i-1)*n -(i-2)(i-1)/2  + (j-i)

column-major 列
![[Pasted image 20240912095642.png]]

Symmetric Matrix(对称矩阵)
if M[i,j] = M[j,i] 


![[Pasted image 20240913090042.png]]


Toeplitz Matrix（复杂矩阵） 
![[Pasted image 20240913091037.png]]

Matrix Menu
![[Pasted image 20240913093238.png]]


Sparse Matrix (稀疏矩阵)
![[Pasted image 20240913095423.png]]
解释：
A[] 是 按照 行 到列 顺序将 非零元素存入
IA[] 是计算每一行的元素个数 并且是 累积的 
JA[] 是 按照行 开头 从左到右 存入非零元素的 列位置。



