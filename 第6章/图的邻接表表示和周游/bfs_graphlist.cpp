/** 
* @file bfs_graphlist.cpp
* @brief 图的广度优先遍历算法，用邻接表表示的图                                                          
*/

#include "bfs_graphlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/**
  * @brief  图的广度优先遍历递归算法，邻接表表示图
  * @param[in]   graphList    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void BFS(GraphList* graphList, int * visited, int i)
{
	int tempVex;
	GraphListNode *tempNode = NULL;
	/** 广度优先遍历使用的队列是c++的STL中的queue */
	queue<int> waitingQueue;

	/** 如果没有访问过，则访问 */
	if (!visited[i])	
	{
		/** 设置标记，表明已经被访问 */
		visited[i] = 1;	
		/** 输出访问的结点编号 */
		printf("%d ", i);
		/** 将刚访问的结点放入队列 */
		waitingQueue.push(i);

		/** 访问结点－广度优先 */
		while(!waitingQueue.empty())	
		{
			tempVex = waitingQueue.front();
			waitingQueue.pop();

			/**依次访问与当前结点相邻的点*/ 
			tempNode = graphList->graphListArray[tempVex].next;
			while(tempNode != NULL)
			{ 
				/**如果其它顶点与当前顶点存在边且未访问过  */
				if(!visited[tempNode->nodeno]) 
				{ 
					/**做标记*/
					visited[tempNode->nodeno] = 1;		
					/**入队*/
					waitingQueue.push(tempNode->nodeno);
					/**输出*/
					printf("%d ", tempNode->nodeno);	

				} //end if(!visited[tempNode->nodeno]) 
				/**移动到下一个结点*/
				tempNode = tempNode->next;
			} //end while(tempNode != NULL)
		}//end while(!waitingQueue.empty())	
	}//end if (!visited[i])	
}


/**
  * @brief  图的广度优先遍历，邻接表表示图
  * @param[in]   graphList    图
  */
void BFSGraphList(GraphList* graphList)
{
	int i;

	/** 用于记录图中哪些结点已经被访问了 */
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	/** 设置所有结点都没有被访问，其中1为访问过，0为没有被访问 */
	for(i = 0; i < graphList->size; i++)
		visited[i] = 0;

	/** 从0号结点开始进行广度优先遍历 */
	for(i = 0; i < graphList->size; i++)  
	{
		BFS(graphList, visited, i);
	}//end for(i = 0; i < graphList->size; i++)  
}