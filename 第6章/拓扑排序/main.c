#include "graphlistutil.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

/**
  * @brief  拓扑排序
  * @param[in]   graphList    邻接表表示的图
  * @return    1：成功 0：失败
  */
int topologicalsort(GraphList *graphList)
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
		/**取栈顶元素v*/
		nodeNum = Top_link(nodeStack);
		printf("%d ", nodeNum);
		Pop_link(nodeStack);
		cnt++;

		/**检查v的出边，将每条出边的终端顶点的入度减1，若该顶点入度为0，入栈*/
		tempNode = graphList->graphListArray[nodeNum].next;
		while(tempNode != NULL)
		{
			inPoint[tempNode->nodeno]--;
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

int main()
{
	GraphList *graphList = InitGraph(8);
	int result = 0;

	ReadGraph(graphList);
	WriteGraph(graphList);

	result = topologicalsort(graphList);
	if (result == 1)
	{
		printf("拓扑排序成功\n");
	} 
	else
	{
		printf("拓扑排序失败\n");
	}

	return 0;
}
