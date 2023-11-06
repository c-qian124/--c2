#include<string.h>
#include<stdbool.h>
#include "Trie.h"
//函数功能:    将连续的拼音串划分为空格分割的拼音串 */
//输入参数tree： trie树
//输入参数origin： 要切分的拼音串
//输入参数splited： 切分后的拼音串
//返回值:  操作成功返回 1        
int PinyinSegment(Trie tree, char *origin, char *splited)
{
	Trie parent, current;
	int index;
	int k = 0, i = 0;
	int len = strlen(origin);
	parent = tree;
	if (origin == NULL)
	{
		printf("要切分的拼音串输入有误");
		return 0;
	}
	while (origin[i] != '\0')
	{
		while (true)
		{
			index = origin[i] - 'a';
			current = parent->next[index];
			if (current != NULL)
			{
				splited[k] = origin[i];
				parent = current;
				k++;
				i++;
			}
			else
			{
				break;
			}
		}
		splited[k++] = ' ';
		parent = tree;
	}
	splited[k] = '\0';
	return 1;
}
