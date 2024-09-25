#include <stdio.h>

/*
统计 一个string中有多少个 单词

*/

//返回值为个数
int CountWords(char* s)
{
	int i, word = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' && s[i - 1] != ' ')
		{
			word++;
		}
	}

	return word;
}
/*
原理就是通过统计每个单词之间的空格数来判断

但是 当出现多个空格连在一起的时候 s[i-1] != ' '
来判断不是连续的空格 从而 判断为一个字符。
*/