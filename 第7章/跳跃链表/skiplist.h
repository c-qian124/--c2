#ifndef SKIPlIST_H_
#define SKIPlIST_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 6
typedef int KeyType;

// 跳跃链表结点结构定义
typedef struct node
{
	int level;                  // 结点层数
	KeyType key;               // 结点的值
	struct node *next[1];     // 指针数组
}*PNode;


// 跳跃链表结构定义
typedef struct SKIPLIST_STRU
{
	int num;                // 跳跃链表数据个数
	int maxLevel;            // 跳跃链表最大层数            
	PNode head;     // 跳跃链表的头指针
}*SkipList;

PNode CreateNode(int level, KeyType key);                // 创建结点
SkipList SetNullSkipList(int level);                     // 创建跳跃链表
int RandomLevel(int maxLevel);                          // 产生随机层数
int SkipListInsert(SkipList list, KeyType key);                   // 插入结点
PNode SkipListSearch(SkipList list, KeyType key);  // 按值查找
int SkipListDelete(SkipList list, KeyType key);                  // 按值删除

#endif