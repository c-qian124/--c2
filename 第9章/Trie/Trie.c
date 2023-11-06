#include<string.h>
#include<stdbool.h>
#include "Trie.h"

void initialize(Trie node)//初始化节点
{
	for (int i = 0; i < 26; i++)
	{
		node->next[i] = NULL;
	}
	return 1;
}
Trie buildTree(FILE *fp)//从文件读取字典构建 Trie 树
{
	char ch;
	char str[20];
	Trie tree;
	tree = (Trie)malloc(sizeof(struct TrieNode));
	initialize(tree);

	while (fscanf(fp, "%s", str) != EOF)
	{
		addWord(tree, str);
	}

	return tree;
}
int addWord(Trie tree, char *word)//向 Trie 树中添加一个词条 
{
	int index;
	Trie parent, current;
	parent = tree;
	for (int i = 0; i < strlen(word); i++)
	{
		index = word[i] - 'a';
		if (parent->next[index] == NULL)
		{
			current = (Trie)malloc(sizeof(struct TrieNode));
			if (current == NULL) return 0;
			initialize(current);
			current->key = word[i];
			parent->next[index] = current;
			parent = current;
		}
		else
		{
			parent = parent->next[index];
		}
	}
	return 1;
}
void freeTrieTree(Trie tree)// 释放 trie 树空间 
{
	Trie current;

	if (tree == NULL)
		return 0;
	else
	{
		for (int i = 0; i < 26; i++)
		{
			current = tree->next[i];
			if (current != NULL)
			{
				freeTrieTree(current);
			}
		}
	}
	free(tree);
}