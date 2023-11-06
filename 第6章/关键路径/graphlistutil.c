/** 
* @file graphlistutil.c
* @brief 图的邻接表表示以及辅助函数                                                               
*/
#include "graphlistutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * @brief  初始化图
  * @param[in]   num    图中结点的个数
  * @return    用邻接表表示的图
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
  * @brief  将数据读入图中
  * @param[in]   graphList    图
  */
void ReadGraph(GraphList* graphList)
{
	int vex1, vex2, weight;
	GraphListNode *tempNode = NULL;
	/** 输入方式为起点 终点  边上权值，点为-1，则输入结束 */
	printf("请输入，输入方式为起点 终点  边上权值，点为-1，则输入结束\n");
	scanf("%d%d%d", &vex1, &vex2, &weight);

	while(vex1>=0 && vex2>=0)
	{
		tempNode = (GraphListNode*)malloc(sizeof(GraphListNode));
		tempNode->nodeno = vex2;
		tempNode->weight = weight;
		tempNode->next = NULL;

		/**寻找到要插入结点的地方，这里为了方便就放在头部*/
		tempNode->next = graphList->graphListArray[vex1].next;
		graphList->graphListArray[vex1].next = tempNode;
		scanf("%d%d%d", &vex1, &vex2, &weight);
	}
}

/**
  * @brief  将图的结构显示出来
  * @param[in]   graphList    图
  */
void WriteGraph(GraphList* graphList)
{
	int i;
	GraphListNode *tempNode = NULL;
	
	for (i=0; i<graphList->size; i++)
	{
		/**输出每条链表的结点*/
		tempNode = graphList->graphListArray[i].next;

		while(tempNode != NULL)
		{
			printf("结点%d和%d相连,权值为%d\n",i,tempNode->nodeno, tempNode->weight);
			tempNode = tempNode->next;
		}
	}
}
