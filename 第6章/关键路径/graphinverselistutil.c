/** 
* @file graphinverselistutil.c
* @brief ͼ�����ڽӱ��ʾ�Լ���������                                                               
*/
#include "graphinverselistutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * @brief  ��ʼ��ͼ
  * @param[in]   num    ͼ�н��ĸ���
  * @return    �����ڽӱ��ʾ��ͼ
  */
GraphInverseList* InitInverseGraph(int num)
{
	int i;
	GraphInverseList *graphInverseList = (GraphInverseList *)malloc(sizeof(GraphInverseList));

	graphInverseList->size = num;
	graphInverseList->graphInverseListArray = (GraphInverseListNode*)malloc(sizeof(GraphInverseListNode)*num);

	for (i=0; i<num; i++)
	{
		graphInverseList->graphInverseListArray[i].next = NULL;
		graphInverseList->graphInverseListArray[i].nodeno = i;
	}

	return graphInverseList;
}
/**
  * @brief  �����ݶ���ͼ��
  * @param[in]   graphInverseList    ͼ
  */
void ReadInverseGraph(GraphInverseList* graphInverseList)
{
	int vexBegin, vexEnd, weight;
	GraphInverseListNode *tempNode = NULL;
	/** ���뷽ʽΪ��� �յ�  ����Ȩֵ����Ϊ-1����������� */
	printf("�����룬���뷽ʽΪ��� �յ�  ����Ȩֵ����Ϊ-1�����������\n");
	scanf("%d%d%d", &vexBegin, &vexEnd, &weight);

	while(vexBegin>=0 && vexEnd>=0)
	{
		tempNode = (GraphInverseListNode*)malloc(sizeof(GraphInverseListNode));
		tempNode->nodeno = vexBegin;
		tempNode->weight = weight;
		tempNode->next = NULL;

		/**Ѱ�ҵ�Ҫ������ĵط�������Ϊ�˷���ͷ���ͷ��*/
		tempNode->next = graphInverseList->graphInverseListArray[vexEnd].next;
		graphInverseList->graphInverseListArray[vexEnd].next = tempNode;
		scanf("%d%d%d", &vexBegin, &vexEnd, &weight);
	}
}

/**
  * @brief  ��ͼ�Ľṹ��ʾ����
  * @param[in]   graphInverseList    ͼ
  */
void WriteInverseGraph(GraphInverseList* graphInverseList)
{
	int i;
	GraphInverseListNode *tempNode = NULL;
	
	for (i=0; i<graphInverseList->size; i++)
	{
		/**���ÿ������Ľ��*/
		tempNode = graphInverseList->graphInverseListArray[i].next;

		while(tempNode != NULL)
		{
			printf("���%d��%d����,ȨֵΪ%d\n", tempNode->nodeno, i, tempNode->weight);
			tempNode = tempNode->next;
		}
	}
}
