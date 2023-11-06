/** 
* @file graphmatrixutil.cpp
* @brief 图的邻接矩阵表示以及辅助函数                                                               
*/

#include "graphmatrixutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * @brief  初始化图
  * @param[in]   num    图中结点的个数
  * @return    用邻接矩阵表示的图
  */
GraphMatrix* InitGraph(int num)
{
	int i;
	int j;
	GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
	/** 图中结点的个数 */
	graphMatrix->size = num;
	/** 给图分配空间 */
	graphMatrix->graph = (int**)malloc(sizeof(int*) * graphMatrix->size);
	for (i=0;i<graphMatrix->size;i++)
	{
		graphMatrix->graph[i] = (int*)malloc(sizeof(int) * graphMatrix->size);
	}

	/** 给图中所有元素设置初值 */
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
  * @brief  将数据读入图中,方式为点 点  权值，如果输入的权值为0，则输入结束
  * @param[in]   graphMatrix    图
  */
void ReadGraph(GraphMatrix* graphMatrix)
{
	int vex1, vex2, weight;

	/** 输入方式为点 点 权值，权值为0，则输入结束 */
	printf("请输入，输入方式为点 点 权值，权值为0，则输入结束\n");
	scanf("%d%d%d", &vex1, &vex2, &weight);

	while(weight != 0)
	{
		graphMatrix->graph[vex1][vex2] = weight;
		scanf("%d%d%d", &vex1, &vex2, &weight);
	}
}

/**
  * @brief  将数据读入图中，该数据是用二维数组数据形式表示
  * @param[in]   graphMatrix    图
  */
void ReadGraphMatrix(GraphMatrix* graphMatrix)
{
	int i,j;

	printf("请输入图的结构，按照邻接矩阵的方式，其中点之间无边则用1000表示\n");

	for (i=0; i<graphMatrix->size; i++)
	{
		for (j=0; j<graphMatrix->size; j++)
		{
			scanf("%d", &graphMatrix->graph[i][j]);
		}
	}
}

/**
  * @brief  将图的结构显示出来,输出方式为点， 点， 权值
  * @param[in]   graphMatrix    图
  */
void WriteGraph(GraphMatrix* graphMatrix)
{
	int i, j;

	printf("图的结构如下，输出方式为点 ，点 ，权值\n");
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