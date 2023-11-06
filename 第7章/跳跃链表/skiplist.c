#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skiplist.h"

// �������
PNode CreateNode(int level, KeyType key)
{
	PNode p = (PNode)malloc(sizeof(struct node) + sizeof(PNode)*level);
	if (p == NULL) return NULL;
	p->level = level;
	p->key = key;
	return p;
}
// ������Ծ����
SkipList SetNullSkipList(int level)
{
	SkipList list = (SkipList)malloc(sizeof(SkipList));
	int i;
	if (list == NULL)// �����ڴ�ʧ��
		return NULL;
	list->maxLevel = level; //��Ծ����Ĳ���
	list->num = 0; //����Ծ�����������ֵ0
	list->head = CreateNode(level, -1);//ͷ����������ֵΪ-1
	if (list->head == NULL)
	{
		free(list);
		return NULL;
	}
	for (i = 0; i < level; i++)
		list->head->next[i] = NULL; //ͷ����ÿһ��ĺ��Ϊ��
	return list;
}

int RandomLevel(int maxlevel)// �����������
{
	int i = 1;
	//���ɵĲ��� i>=1 && i<=maxlevel
	while (i < maxlevel && rand() % 2)
	{
		i++;
	}

	return i;
}

PNode SkipListSearch(SkipList list, KeyType key) // ��ֵ����
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
			n++;      // ��¼�Ƚϴ���
			if (p->key == key)
			{
				printf("%d\n", n); 
				return p;
			}
		}
	}
	return NULL;
}

int SkipListInsert(SkipList list, KeyType key)// �����㣬�ɹ�����1�����򷵻�0
{
	int level = 0;
	PNode Pre[MAX_LEVEL]; // ��¼ÿ���ǰ�����λ��
	PNode p, q = NULL;
	int i;
	p = list->head;
	//����λ�ã���¼ǰ�������Ϣ
	for (i = list->maxLevel - 1; i >= 0; i--) //������Ʋ�
	{
		//������Ҳ���λ�ã� ��forѭ���������ƶ�����λ��
		while ((q = p->next[i]) && (q->key < key)) 
		{
			p = q;  		
		}
		Pre[i] = p;
	}
	// �Ѿ�������ͬ��key�����ܲ���
	if ((q != NULL) && (q->key == key))
		return 0;
	level = RandomLevel(list->maxLevel);// ����һ���������

	p = CreateNode(level, key);// �����½��
	if (p == NULL) return 0;
	for (i = 0; i < level; i++)// ���ı䶯ָ���ָ��
	{
		p->next[i] = Pre[i]->next[i];
		Pre[i]->next[i] = p;
	}
	list->num++;  //��Ծ����ļ�������1
	return 1;
}


int SkipListDelete(SkipList list, KeyType key)// ��ֵɾ�����ɹ�����1�����򷵻�0
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
	if (q&&q->key == key)// ����key�����ɾ��
	{
		for (i = 0; i < list->maxLevel; i++)
		{
			if (Pre[i]->next[i] == q)
			{
				Pre[i]->next[i] = q->next[i];
			}
		}
		free(q);     //ɾ�����
		list->num--; //��Ծ����ļ�������1
		return 1;
	}
	return 0;
}



