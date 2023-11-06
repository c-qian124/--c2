/** 
* @file graphinverselistutil.c
* @brief 图的逆邻接表表示以及辅助函数                                                               
*/
#include "graphinverselistutil.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * @brief  初始化图
  * @param[in]   num    图中结点的个数
  * @return    用逆邻接表表示的图
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
  * @brief  将数据读入图中
  * @param[in]   graphInverseList    图
  */
void ReadInverseGraph(GraphInverseList* graphInverseList)
{
	int vexBegin, vexEnd, weight;
	GraphInverseListNode *tempNode = NULL;
	/** 输入方式为起点 终点  边上权值，点为-1，则输入结束 */
	printf("请输入，输入方式为起点 终点  边上权值，点为-1，则输入结束\n");
	scanf("%d%d%d", &vexBegin, &vexEnd, &weight);

	while(vexBegin>=0 && vexEnd>=0)
	{
		tempNode = (GraphInverseListNode*)malloc(sizeof(GraphInverseListNode));
		tempNode->nodeno = vexBegin;
		tempNode->weight = weight;
		tempNode->next = NULL;

		/**寻找到要插入结点的地方，这里为了方便就放在头部*/
		tempNode->next = graphInverseList->graphInverseListArray[vexEnd].next;
		graphInverseList->graphInverseListArray[vexEnd].next = tempNode;
		scanf("%d%d%d", &vexBegin, &vexEnd, &weight);
	}
}

/**
  * @brief  将图的结构显示出来
  * @param[in]   graphInverseList    图
  */
void WriteInverseGraph(GraphInverseList* graphInverseList)
{
	int i;
	GraphInverseListNode *tempNode = NULL;
	
	for (i=0; i<graphInverseList->size; i++)
	{
		/**输出每条链表的结点*/
		tempNode = graphInverseList->graphInverseListArray[i].next;

		while(tempNode != NULL)
		{
			printf("结点%d和%d相连,权值为%d\n", tempNode->nodeno, i, tempNode->weight);
			tempNode = tempNode->next;
		}
	}
}
