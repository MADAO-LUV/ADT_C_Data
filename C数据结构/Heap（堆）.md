主要以数组的方式来表示Heap(堆)

Binary Heap代码实现
![[Pasted image 20241009090519.png]]
创建Heap的过程 遍历是从2开始因为要空出 0，1 因为插入的时候 那个 0, 1对于 i/2 是不能满足的。

因此为O(nlogn)---Max Heap

最大堆的删除要点
![[Pasted image 20241009091309.png]]
所删除的元素仍然在堆中，不过是在空闲空间处

一直删除到底部，它们会做堆排序
![[Pasted image 20241009093051.png]]

在创建 堆的时候，第一个位置 索引0的位置 元素可以填入一来进行补足，因为不会用到
