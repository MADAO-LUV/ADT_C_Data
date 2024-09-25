![[Pasted image 20240924170008.png]]
前缀和 ， 后缀和

![[Pasted image 20240924170749.png]]
统一性


![[Pasted image 20240924172331.png]]
如何工作，
由图片可以看到

操作数优先级为 3 最大

然后 每次扫描一个字符，如果扫描到的字符 它的优先级 小于或等于 栈顶 元素 就 弹出到postfix处  否则 就直接放入 栈中即可。
![[Pasted image 20240925091258.png]]

Evaluation of Postfix
返回前缀和 的 值 
return pop(&st);