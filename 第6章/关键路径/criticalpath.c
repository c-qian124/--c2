/** 
* @file criticalpath.C
* @brief 图的关键路径                                                               
*/

#include "graphlistutil.h"
#include "graphinverselistutil.h"
#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * @brief  事件可能的最早发生时间
  * @param[in]   graphList 用邻接表表示的图   
  * @param[out]   earliestTime    事件可能的最早发生时间
  * @return   是否成功
  */
int eventEarliestTime(GraphList *graphList, int* earliestTime)
{
	int i;
	int cnt;
	int nodeNum;
	int success = 1;

	LinkStack nodeStack = NULL;
	GraphListNode *tempNode = NULL;
	int *inPoint = (int *)malloc(sizeof(int) * graphList->size);
	nodeStack = SetNullStack_Link();

	for (i=0; i<graphList->size; i++)
	{
		inPoint[i] = 0;
	}
	/**计算点的入度*/
	for (i=0; i<graphList->size; i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while(tempNode != NULL)
		{
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;
		}
	}
	/**将入度为0的顶点入栈*/
	for(i=0; i<graphList->size; i++)
	{
		if (inPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}
	/**如果记录结点的栈不为空*/
	cnt = 0;
	while(!IsNullStack_link(nodeStack))
	{
		/**取栈顶元素，获得边的起点，该事件的可能最早发生时间已经能定下*/
		nodeNum = Top_link(nodeStack);
		Pop_link(nodeStack);
		cnt++;

		/**检查v的出边，将每条出边的终端顶点的入度减1，若该顶点入度为0，入栈*/
		tempNode = graphList->graphListArray[nodeNum].next;
		while(tempNode != NULL)
		{
			/**去掉入边*/
			inPoint[tempNode->nodeno]--;
			/**为每条出边的终点事件更新可能的最早发生时间*/
			if (earliestTime[tempNode->nodeno] < earliestTime[nodeNum] + tempNode->weight)
			{
				earliestTime[tempNode->nodeno] = earliestTime[nodeNum] + tempNode->weight;
			}
			/**入栈*/
			if (inPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}

	if (cnt != graphList->size)
	{
		success = 0;
	} 

	return success;
}

/**
  * @brief  事件允许的最迟发生时间
  * @param[in]   graphInverseList    用逆邻接表表示的图
  * @param[out]   latestTime    事件允许的最迟发生时间
  * @return    是否成功
  */
int eventLatestTime(GraphInverseList *graphInverseList, int* latestTime)
{
	int i;
	int cnt;
	int nodeNum;
	int success = 1;

	LinkStack nodeStack = NULL;
	GraphInverseListNode *tempNode = NULL;
	int *outPoint = (int *)malloc(sizeof(int) * graphInverseList->size);
	nodeStack = SetNullStack_Link();

	for (i=0; i<graphInverseList->size; i++)
	{
		outPoint[i] = 0;
	}
	/**计算点的出度*/
	for (i=0; i<graphInverseList->size; i++)
	{
		tempNode = graphInverseList->graphInverseListArray[i].next;

		while(tempNode != NULL)
		{
			outPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;
		}
	}
	/**将出度为0的顶点入栈*/
	for(i=0; i<graphInverseList->size; i++)
	{
		if (outPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}
	/**如果记录结点的栈不为空*/
	cnt = 0;
	while(!IsNullStack_link(nodeStack))
	{
		/**取栈顶元素，获得边的终点，该事件的允许最迟发生时间已经能定下*/
		nodeNum = Top_link(nodeStack);
		Pop_link(nodeStack);
		cnt++;

		/**检查v的入边，将每条入边的终端顶点的出度减1，若该顶点出度为0，入栈*/
		tempNode = graphInverseList->graphInverseListArray[nodeNum].next;
		while(tempNode != NULL)
		{
			/**去掉出边*/
			outPoint[tempNode->nodeno]--;
			/**为每条入边的起点事件更新允许最迟发生时间*/
			if (latestTime[tempNode->nodeno] > latestTime[nodeNum] - tempNode->weight)
			{
				latestTime[tempNode->nodeno] = latestTime[nodeNum] - tempNode->weight;
			}
			/**如果去掉出边后，出度为0，则点入栈*/
			if (outPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}

	if (cnt != graphInverseList->size)
	{
		success = 0;
	} 

	return success;
}

/**
  * @brief  关键路径
  * @param[in]   graphList 用邻接表表示的图   
  * @param[in]   graphInverseList    用逆邻接表表示的图
  */
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)
{
	int i;
	int max;

	int* earliestTime = (int*)malloc(sizeof(int) * graphList->size);
	int* latestTime = (int*)malloc(sizeof(int) * graphInverseList->size);
	int activityEarliestTime;
	int activityLatestTime;

	GraphListNode *tempNode = NULL;
	
	/**初始化所有事件可能的最早发生时间为0*/
	for(i=0; i<graphList->size; i++)
	{
		earliestTime[i] = 0;
	}

	/**求事件可能的最早发生时间*/
	eventEarliestTime(graphList, earliestTime);

	/**求事件最早发生时间的最大值，方便后面设置事件允许最迟发生时间的初值*/
	max = earliestTime[0];
	for (i=0; i<graphList->size; i++)
	{
		if (max < earliestTime[i])
		{
			max = earliestTime[i];
		}
	}

	/**初始化所有事件允许的最迟发生时间为最大值*/
	for(i=0; i<graphInverseList->size; i++)
	{
		latestTime[i] = max;
	}

	eventLatestTime(graphInverseList, latestTime);


	/**遍历每条边，求每条边的最早开始时间和最晚开始时间，并对比，相等者为关键路径上的边*/
	for (i=0; i<graphList->size; i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while(tempNode != NULL)
		{
			activityEarliestTime = earliestTime[i];
			activityLatestTime = latestTime[tempNode->nodeno] - tempNode->weight;
			
			if (activityEarliestTime == activityLatestTime)
			{
				printf("<v%2d,v%2d>", i, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}


}


