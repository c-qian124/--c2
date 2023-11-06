#ifndef TRIE_H
#define TRIE_H
#include<stdio.h>
#define MAXLEN 200
struct TrieNode		     //Tire����㶨��
{
	char key;			      //��ֵ
	struct TrieNode *next[26];
};
typedef struct TrieNode * Trie; //Trie�����Ͷ���

//�������ܣ���ʼ���ڵ�
//��������� Trie �����
//����ֵ�� �� 
void initialize(Trie node);

//��������: ���ļ���ȡ�ֵ乹�� Trie ��
//�������fp�� �ļ�
//����ֵ: tree ָ�� Trie �����ڵ� 
Trie buildTree(FILE *fp);
                     
//��������: �� Trie �������һ������  
//�������tree�� trie ��
//�������word�� Ҫ��ӵĴ���
// ����ֵ: �����ɹ����� 1 �����򷵻�0               
int addWord(Trie tree, char *word);

//�������ܣ��ͷ� trie ���ռ� 
//��������� trie ��
//����ֵ�� ��
void freeTrieTree(Trie tree);

#endif