#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skiplist.h"

// 创建结点
PNode CreateNode(int level, KeyType key)
{
	PNode p = (PNode)malloc(sizeof(struct node) + sizeof(PNode)*level);
	if (p == NULL) return NULL;
	p->level = level;
	p->key = key;
	return p;
}
// 创建跳跃链表
SkipList SetNullSkipList(int level)
{
	SkipList list = (SkipList)malloc(sizeof(SkipList));
	int i;
	if (list == NULL)// 申请内存失败
		return NULL;
	list->maxLevel = level; //跳跃链表的层数
	list->num = 0; //空跳跃链表计数器赋值0
	list->head = CreateNode(level, -1);//头结点的数据域赋值为-1
	if (list->head == NULL)
	{
		free(list);
		return NULL;
	}
	for (i = 0; i < level; i++)
		list->head->next[i] = NULL; //头结点的每一层的后继为空
	return list;
}

int RandomLevel(int maxlevel)// 产生随机层数
{
	int i = 1;
	//生成的层数 i>=1 && i<=maxlevel
	while (i < maxlevel && rand() % 2)
	{
		i++;
	}

	return i;
}

PNode SkipListSearch(SkipList list, KeyType key) // 按值查找
{
	PNode p = NULL, q = NULL;
	int n = 0;
	int i;
	p = list->head;
	for (i = list->maxLevel - 1; i >= 0; i--)
	{
		while ((q = p->next[i]) && (q->key <= key))
		{
			p = q;
			n++;      // 记录比较次数
			if (p->key == key)
			{
				printf("%d\n", n); 
				return p;
			}
		}
	}
	return NULL;
}

int SkipListInsert(SkipList list, KeyType key)// 插入结点，成功返回1，否则返回0
{
	int level = 0;
	PNode Pre[MAX_LEVEL]; // 记录每层的前驱结点位置
	PNode p, q = NULL;
	int i;
	p = list->head;
	//查找位置，记录前驱结点信息
	for (i = list->maxLevel - 1; i >= 0; i--) //纵向控制层
	{
		//横向查找插入位置， 而for循环是纵向移动查找位置
		while ((q = p->next[i]) && (q->key < key)) 
		{
			p = q;  		
		}
		Pre[i] = p;
	}
	// 已经存在相同的key，不能插入
	if ((q != NULL) && (q->key == key))
		return 0;
	level = RandomLevel(list->maxLevel);// 产生一个随机层数

	p = CreateNode(level, key);// 创建新结点
	if (p == NULL) return 0;
	for (i = 0; i < level; i++)// 逐层的变动指针的指向
	{
		p->next[i] = Pre[i]->next[i];
		Pre[i]->next[i] = p;
	}
	list->num++;  //跳跃链表的计数器加1
	return 1;
}


int SkipListDelete(SkipList list, KeyType key)// 按值删除，成功返回1，否则返回0
{
	PNode Pre[MAX_LEVEL];
	PNode  p = NULL;
	PNode q = NULL;
	int i;
	int k;
	p = list->head;
	k = list->maxLevel;
	for (i = k - 1; i >= 0; i--)
	{
		while ((q = p->next[i]) && (q->key < key))
		{
			p = q;
		}
		Pre[i] = p;
	}
	if (q&&q->key == key)// 存在key则进行删除
	{
		for (i = 0; i < list->maxLevel; i++)
		{
			if (Pre[i]->next[i] == q)
			{
				Pre[i]->next[i] = q->next[i];
			}
		}
		free(q);     //删除结点
		list->num--; //跳跃链表的计数器加1
		return 1;
	}
	return 0;
}



