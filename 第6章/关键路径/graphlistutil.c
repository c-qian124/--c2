/** 
* @file graphlistutil.c
* @brief ͼ���ڽӱ��ʾ�Լ���������                                                               
*/
#include "graphlistutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * @brief  ��ʼ��ͼ
  * @param[in]   num    ͼ�н��ĸ���
  * @return    ���ڽӱ��ʾ��ͼ
  */
GraphList* InitGraph(int num)
{
	int i;
	GraphList *graphList = (GraphList *)malloc(sizeof(GraphList));

	graphList->size = num;
	graphList->graphListArray = (GraphListNode*)malloc(sizeof(GraphListNode)*num);

	for (i=0; i<num; i++)
	{
		graphList->graphListArray[i].next = NULL;
		graphList->graphListArray[i].nodeno = i;
	}

	return graphList;
}
/**
  * @brief  �����ݶ���ͼ��
  * @param[in]   graphList    ͼ
  */
void ReadGraph(GraphList* graphList)
{
	int vex1, vex2, weight;
	GraphListNode *tempNode = NULL;
	/** ���뷽ʽΪ��� �յ�  ����Ȩֵ����Ϊ-1����������� */
	printf("�����룬���뷽ʽΪ��� �յ�  ����Ȩֵ����Ϊ-1�����������\n");
	scanf("%d%d%d", &vex1, &vex2, &weight);

	while(vex1>=0 && vex2>=0)
	{
		tempNode = (GraphListNode*)malloc(sizeof(GraphListNode));
		tempNode->nodeno = vex2;
		tempNode->weight = weight;
		tempNode->next = NULL;

		/**Ѱ�ҵ�Ҫ������ĵط�������Ϊ�˷���ͷ���ͷ��*/
		tempNode->next = graphList->graphListArray[vex1].next;
		graphList->graphListArray[vex1].next = tempNode;
		scanf("%d%d%d", &vex1, &vex2, &weight);
	}
}

/**
  * @brief  ��ͼ�Ľṹ��ʾ����
  * @param[in]   graphList    ͼ
  */
void WriteGraph(GraphList* graphList)
{
	int i;
	GraphListNode *tempNode = NULL;
	
	for (i=0; i<graphList->size; i++)
	{
		/**���ÿ������Ľ��*/
		tempNode = graphList->graphListArray[i].next;

		while(tempNode != NULL)
		{
			printf("���%d��%d����,ȨֵΪ%d\n",i,tempNode->nodeno, tempNode->weight);
			tempNode = tempNode->next;
		}
	}
}
