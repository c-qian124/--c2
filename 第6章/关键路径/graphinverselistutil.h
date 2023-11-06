/** 
* @file graphinverselistutil.h
* @brief ͼ�����ڽӱ��ʾ�Լ���������                                                               
*/
#ifndef GRAPHINVERSELISTUTIL_H
#define GRAPHINVERSELISTUTIL_H

typedef struct	GRAPHINVERSELISTNODE_STRU
{
	int nodeno;/*!< ͼ�н��ı�� */
	int weight;/*!< ͼ�бߵ�Ȩֵ */
	struct	GRAPHINVERSELISTNODE_STRU* next;/*!<ָ����һ������ָ�� */
}GraphInverseListNode;

typedef struct	GRAPHINVERSELIST_STRU
{
	int size;/*!< ͼ�н��ĸ��� */
	GraphInverseListNode* graphInverseListArray;/*!<ͼ���ڽӱ� */
}GraphInverseList;

/**
  * @brief  ��ʼ��ͼ
  * @param[in]   num    ͼ�н��ĸ���
  * @return    �����ڽӱ��ʾ��ͼ
  */
GraphInverseList* InitInverseGraph(int num);

/**
  * @brief  �����ݶ���ͼ��
  * @param[in]   graphInverseList    ͼ
  */
void ReadInverseGraph(GraphInverseList* graphInverseList);

/**
  * @brief  ��ͼ�Ľṹ��ʾ����
  * @param[in]   graphInverseList    ͼ
  */
void WriteInverseGraph(GraphInverseList* graphInverseList);

#endif