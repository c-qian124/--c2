#include <stdio.h>
#include<string.h>

int patternMatch_BF(char *t, char *p);

int main()
{
	char *t = "ABCABDABABACDDABC";
	char *p = "ABABACDD";
	int result = patternMatch_BF(t, p);
	if (result == -1)
		printf("\n匹配失败\n");
	else printf( "子串在主串中的位置为:%d\n",result);
	return 0;
}
//模式匹配之BF(Brute Force)暴力算法
//若p是t的子串,返回子串p在串t第一次出现的位置(从1开始)
//若p不是t的子串,返回-1
int patternMatch_BF(char *t, char *p)
{
	int i = 0, j = 0;
	int n = strlen(t);   //主串t的长度
	int m = strlen(p);  //模式串p的长度
	while (i < n && j < m)  //两个串都没扫描完
	{
		if (t[i] == p[j])//该位置上字符相等，就比较下一个字符
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1; //否则，i为上次扫描位置的下一位置
			j = 0; //j从1开始
		}
	}
	if (j>=m)
		return i- m;
	else return -1;
}