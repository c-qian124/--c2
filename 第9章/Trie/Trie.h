#ifndef TRIE_H
#define TRIE_H
#include<stdio.h>
#define MAXLEN 200
struct TrieNode		     //Tire树结点定义
{
	char key;			      //键值
	struct TrieNode *next[26];
};
typedef struct TrieNode * Trie; //Trie树类型定义

//函数功能：初始化节点
//输入参数： Trie 树结点
//返回值： 无 
void initialize(Trie node);

//函数功能: 从文件读取字典构建 Trie 树
//输入参数fp： 文件
//返回值: tree 指向 Trie 树根节点 
Trie buildTree(FILE *fp);
                     
//函数功能: 向 Trie 树中添加一个词条  
//输入参数tree： trie 树
//输入参数word： 要添加的词条
// 返回值: 操作成功返回 1 ，否则返回0               
int addWord(Trie tree, char *word);

//函数功能：释放 trie 树空间 
//输入参数： trie 树
//返回值： 无
void freeTrieTree(Trie tree);

#endif