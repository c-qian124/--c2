/** 
* @file bfs_graphmatrix.cpp
* @brief 图的广度优先遍历算法，用邻接矩阵表示的图                                                          
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
#include "bfs_graphmatrix.h"
/**
  * @brief  图的广度优先遍历递归算法，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void BFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j;
	int tempVex;

	LinkQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();

	/** 如果没有访问过，则访问 */
	if (!visited[i])	
	{
		/** 设置标记，表明已经被访问 */
		visited[i] = 1;	
		/** 输出访问的结点编号 */
		printf("%d ", i);
		/** 将刚访问的结点放入队列 */
		EnQueue_link(waitingQueue,i);

		/** 访问结点－广度优先 */
		while(!IsNullQueue_Link(waitingQueue))	
		{
			tempVex = FrontQueue_link(waitingQueue);
			DeQueue_link(waitingQueue);

			for(j=0;j<graphMatrix->size;j++) 
			{ 
				/**如果其它顶点与当前顶点存在边且未访问过  */
				if(graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j]) 
				{ 
					/**做标记*/
					visited[j] = 1;		
					/**入队*/
					EnQueue_link(waitingQueue, j);
					/**输出*/
					printf("%d ", j);	
				} //end if(graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j]) 
			} //end for(j=0;j<graphMatrix->size;j++) 
		}//end while(!waitingQueue.empty())	
	}//end if (!visited[i])	
}

/**
  * @brief  图的广度优先遍历，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  */
void BFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i;

	/** 用于记录图中哪些结点已经被访问了 */
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	/** 设置所有结点都没有被访问，其中1为访问过，0为没有被访问 */
	for(i = 0; i < graphMatrix->size; i++)
		visited[i] = 0;

	/** 从0号结点开始进行广度优先遍历 */
	for(i = 0; i < graphMatrix->size; i++)  
	{
		BFS(graphMatrix, visited, i);
	}//end for(i = 0; i < graphMatrix->size; i++)  
}