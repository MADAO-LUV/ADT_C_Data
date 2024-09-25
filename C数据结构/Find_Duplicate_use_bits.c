#include<stdio.h>
/**
使用 bit 字符位来 判断是否重复

找到一个字符串中重复的字母 (全都是小写时)
*/


void Find_Dupli(char s[])
{
	long int H = 0, x = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		x = 1; //初始位置 在 bit0 处 
		x = x << s[i] - 97;

		//关键部分 进行判断
		if (x & H > 0)
		{
			printf("%c is Duplicate", s[i]);
		}
		else
		{
			H = x | H;  //H里面记录 第一次出现的字符的位置
		}
	}
}

int main()
{
	char s[] = { "fuckyouiia" };
	Find_Dupli(s);

	return 0;
}






