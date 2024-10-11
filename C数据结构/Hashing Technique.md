Hashing 对搜索很有用
1.Linear --- O(n)
2.Binary --- O(logn)
3.Hashing --- O(1)

将键值 映射到 Hash Table
![[Pasted image 20241010190506.png]]
就是映射 --- h(x)=x
缺点:所需内存非常大
我们也可以使用模糊Hashing 使用 mod 取余
![[Pasted image 20241010190913.png]]
Open Hashing --- Chaining

Closed  Hashing
Open Addressing
 1. Linear Probing
 2. Quadratic Probing
 3. Double Hashing


1.Open Hashing---chaining
**![[Pasted image 20241010192034.png]]
Avg.Successful Search 
t = 1 + r/2

Avg>unsuccessful Search
t = 1 + r

![[Pasted image 20241010211601.png]]
Linear Probing --- 其实就是 如果这个数 取hash值的时候 ，哈希表里已经有数值占领了的话，就不断加f(x)再取余 直到 不再冲突为止。
 一旦获得可用空间 就截止

这里的为f(i)=i 线性探测

那个底数与哈希表的大小有关。
![[Pasted image 20241010212817.png]]
引入二次探测
这里为 f(i)=i^2   平方的
Quadratic Probing
![[Pasted image 20241010215451.png]]
![[Pasted image 20241010215536.png]]
公式以上

Double Hash(双重哈希表)
![[Pasted image 20241011085832.png]]
当我们发现 hash表发生冲突的时候，在相同的位置加上一个节点-----(一直加一个节点)直到成功到位为止
![[Pasted image 20241011090200.png]]
通过该图，我们可以发现，我们在hash表中放入元素时，一旦发生冲突，我们就修改i 的值 让它去到另一个位置，如果又发生碰撞，那么就重复这个动作 直到找到空闲的位置为止。

![[Pasted image 20241011090730.png]]
我们可以看到 这里是 散列映射 
1.Mod 取余值为 它key所存放的位置
2.MidSquare 将key值平方后 取key中间的数值
![[Pasted image 20241011090924.png]]
这个就是folding 的 所存放的位置

我们必须确保以上的方法必须正常执行