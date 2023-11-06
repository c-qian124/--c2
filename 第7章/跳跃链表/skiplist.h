#ifndef SKIPlIST_H_
#define SKIPlIST_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 6
typedef int KeyType;

// ��Ծ������ṹ����
typedef struct node
{
	int level;                  // ������
	KeyType key;               // ����ֵ
	struct node *next[1];     // ָ������
}*PNode;


// ��Ծ����ṹ����
typedef struct SKIPLIST_STRU
{
	int num;                // ��Ծ�������ݸ���
	int maxLevel;            // ��Ծ����������            
	PNode head;     // ��Ծ�����ͷָ��
}*SkipList;

PNode CreateNode(int level, KeyType key);                // �������
SkipList SetNullSkipList(int level);                     // ������Ծ����
int RandomLevel(int maxLevel);                          // �����������
int SkipListInsert(SkipList list, KeyType key);                   // ������
PNode SkipListSearch(SkipList list, KeyType key);  // ��ֵ����
int SkipListDelete(SkipList list, KeyType key);                  // ��ֵɾ��

#endif