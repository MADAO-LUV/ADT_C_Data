#include<stdio.h>
/**
使用HashTable 完成该代码程序

找到一个字符串中重复的字母 (全都是小写时)
*/
#define MAX   26

int HashTable[MAX] = { 0 };

void Find_Dupli(char s[])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		HashTable[s[i] - 97] += 1; //将字符串中出现的字母以ASCII码放入对应处
	}

	for (int i = 0; i < 26; i++)
	{
		if (HashTable[i] > 1)
		{
			printf("%c\n", i + 97);
			printf("%d\n", HashTable[i]);
		}
	}
}

int main()
{
	char s[] = { "fuckyouiia" };
	Find_Dupli(s);

	return 0;
}






