/** 
* @file graphmatrixutil.cpp
* @brief ͼ���ڽӾ����ʾ�Լ���������                                                               
*/

#include "graphmatrixutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * @brief  ��ʼ��ͼ
  * @param[in]   num    ͼ�н��ĸ���
  * @return    ���ڽӾ����ʾ��ͼ
  */
GraphMatrix* InitGraph(int num)
{
	int i;
	int j;
	GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
	/** ͼ�н��ĸ��� */
	graphMatrix->size = num;
	/** ��ͼ����ռ� */
	graphMatrix->graph = (int**)malloc(sizeof(int*) * graphMatrix->size);
	for (i=0;i<graphMatrix->size;i++)
	{
		graphMatrix->graph[i] = (int*)malloc(sizeof(int) * graphMatrix->size);
	}

	/** ��ͼ������Ԫ�����ó�ֵ */
	for (i=0;i<graphMatrix->size;i++)
	{
		for(j=0;j<graphMatrix->size;j++)
		{
			graphMatrix->graph[i][j]=INT_MAX;
		}
	}

	return graphMatrix;
}

/**
  * @brief  �����ݶ���ͼ��,��ʽΪ�� ��  Ȩֵ����������ȨֵΪ0�����������
  * @param[in]   graphMatrix    ͼ
  */
void ReadGraph(GraphMatrix* graphMatrix)
{
	int vex1, vex2, weight;

	/** ���뷽ʽΪ�� �� Ȩֵ��ȨֵΪ0����������� */
	printf("�����룬���뷽ʽΪ�� �� Ȩֵ��ȨֵΪ0�����������\n");
	scanf("%d%d%d", &vex1, &vex2, &weight);

	while(weight != 0)
	{
		graphMatrix->graph[vex1][vex2] = weight;
		scanf("%d%d%d", &vex1, &vex2, &weight);
	}
}

/**
  * @brief  �����ݶ���ͼ�У����������ö�ά����������ʽ��ʾ
  * @param[in]   graphMatrix    ͼ
  */
void ReadGraphMatrix(GraphMatrix* graphMatrix)
{
	int i,j;

	printf("������ͼ�Ľṹ�������ڽӾ���ķ�ʽ�����е�֮���ޱ�����1000��ʾ\n");

	for (i=0; i<graphMatrix->size; i++)
	{
		for (j=0; j<graphMatrix->size; j++)
		{
			scanf("%d", &graphMatrix->graph[i][j]);
		}
	}
}

/**
  * @brief  ��ͼ�Ľṹ��ʾ����,�����ʽΪ�㣬 �㣬 Ȩֵ
  * @param[in]   graphMatrix    ͼ
  */
void WriteGraph(GraphMatrix* graphMatrix)
{
	int i, j;

	printf("ͼ�Ľṹ���£������ʽΪ�� ���� ��Ȩֵ\n");
	for (i=0;i<graphMatrix->size; i++)
	{
		for (j=0; j<graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				printf("%d,%d,%d\n", i, j, graphMatrix->graph[i][j]);
			}
		}
	}
}