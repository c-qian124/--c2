/** 
* @file dfs_graphlist.cpp
* @brief 图的深度优先遍历算法，用邻接表表示的图                                                          
*/

#include "dfs_graphlist.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * @brief  图的深度优先遍历递归算法，邻接表表示图
  * @param[in]   graphList    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void DFS(GraphList* graphList, int * visited, int i)
{
	int j;
	GraphListNode *tempNode = NULL;
	visited[i] = 1;
	printf("%d ", i);

	//for(j = 0; j < graphList->size; j++)
	tempNode = graphList->graphListArray[i].next;
	while(tempNode != NULL)
	{
		if(!visited[tempNode->nodeno])
			DFS(graphList, visited, tempNode->nodeno);
		tempNode = tempNode->next;
	}
}

/**
  * @brief  深度遍历，邻接表表示图
  * @param[in]   graphList    图
  */
void DFSGraphList(GraphList* graphList)
{
	int i;
	/** 用于记录图中哪些结点已经被访问了 */
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	/** 初始化为点都没有被访问 */
	for(i = 0; i < graphList->size; i++)
		visited[i] = 0; 

	for(i = 0; i < graphList->size; i++)
		if(!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */ 
			DFS(graphList, visited, i);
}
