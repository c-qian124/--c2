/** 
* @file graphlistutil.h
* @brief ͼ���ڽӱ��ʾ�Լ���������                                                               
*/
#ifndef GRAPHLISTUTIL_H
#define GRAPHLISTUTIL_H

typedef struct	GRAPHLISTNODE_STRU
{
	int nodeno;/*!< ͼ�н��ı�� */
	struct	GRAPHLISTNODE_STRU* next;/*!<ָ����һ������ָ�� */
}GraphListNode;

typedef struct	GRAPHLIST_STRU
{
	int size;/*!< ͼ�н��ĸ��� */
	GraphListNode* graphListArray;/*!<ͼ���ڽӱ� */
}GraphList;

/**
  * @brief  ��ʼ��ͼ
  * @param[in]   num    ͼ�н��ĸ���
  * @return    ���ڽӱ��ʾ��ͼ
  */
GraphList* InitGraph(int num);

/**
  * @brief  �����ݶ���ͼ��
  * @param[in]   graphList    ͼ
  */
void ReadGraph(GraphList* graphList);

/**
  * @brief  ��ͼ�Ľṹ��ʾ����
  * @param[in]   graphList    ͼ
  */
void WriteGraph(GraphList* graphList);

#endif

