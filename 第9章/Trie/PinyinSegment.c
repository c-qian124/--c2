#include<string.h>
#include<stdbool.h>
#include "Trie.h"
//��������:    ��������ƴ��������Ϊ�ո�ָ��ƴ���� */
//�������tree�� trie��
//�������origin�� Ҫ�зֵ�ƴ����
//�������splited�� �зֺ��ƴ����
//����ֵ:  �����ɹ����� 1        
int PinyinSegment(Trie tree, char *origin, char *splited)
{
	Trie parent, current;
	int index;
	int k = 0, i = 0;
	int len = strlen(origin);
	parent = tree;
	if (origin == NULL)
	{
		printf("Ҫ�зֵ�ƴ������������");
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
