/** 
* @file dfs_graphmatrix.cpp
* @brief 图的深度优先遍历算法，用邻接矩阵表示的图                                                          
*/

#include "dfs_graphmatrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * @brief  图的深度优先遍历递归算法，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void DFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j;
	visited[i] = 1;
	printf("%d ", i);

	for(j = 0; j < graphMatrix->size; j++)
	{
		if(graphMatrix->graph[i][j] != INT_MAX && !visited[j])
			DFS(graphMatrix, visited, j);
	}
}

/**
  * @brief  深度遍历，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  */
void DFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i;
	/** 用于记录图中哪些结点已经被访问了 */
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	/** 初始化为点都没有被访问 */
	for(i = 0; i < graphMatrix->size; i++)
		visited[i] = 0; 

	for(i = 0; i < graphMatrix->size; i++)
		if(!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */ 
			DFS(graphMatrix, visited, i);
}
