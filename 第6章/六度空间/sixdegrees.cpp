#include "graphmatrixutil.h"
#include <stdlib.h>

#include <queue>
using namespace std;

/**
  * @brief  使用bfs验证六度空间思想，这里是对单个节点进行探查
  * @param[in]   source    起点
  * @param[in]   graphMatrix    图
  * @return    符合六度空间的节点个数
  */
int  BFS( int source,GraphMatrix *graphMatrix)
{
	/**用于保存点是否已经被访问过的信息*/
	int* visited = (int *)malloc(sizeof(int)*graphMatrix->size);
	/**用last保存上一层最后访问的节点，用tail来记录当前最后访问节点*/
	int last = source;
	int tail = source;
	/**节点队列，广度优先访问*/
	queue<int> myQueue;
	/**在六层内能访问到的节点个数，最后这个值用于返回，自身也算*/
	int cnt = 1;
	/**访问层数，当访问层数>6，则可以结束广度优先搜索算法*/
	int level = 0;
	/**当前访问的节点*/
	int visitNow;
	/**循环变量*/
	int i;

	/**先将保存节点是否被访问的数组清0*/
	
	for(i=0; i<graphMatrix->size; i++)
	{
		visited[i] = 0;
	}


	/**图的源点放入队列*/
	myQueue.push(source);
	visited[source] = 1;

	/**广度优先搜索，*/
	while(!myQueue.empty())
	{
		/**从队列中取出 一个节点，用于对其下一层节点进行访问*/
		visitNow = myQueue.front();
		myQueue.pop();

		/**访问与队列中刚取出的节点直接相连的节点*/
		for(i=0;i<graphMatrix->size;i++)
		{
			/**如果两点有边相连，并且没有被访问过，则访问*/
			if(graphMatrix->graph[visitNow][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				myQueue.push(i);
				cnt++;
				
				/**动态记录在访问过程中，最后访问的节点*/
				tail = i;
			}
		}//end for(i=0;i<graphMatrix->size;i++)

		//将刚刚从队列中取出的节点的下一层都访问后，再判断刚从队列取出的节点是否是这一层的最后节点
		if(visitNow == last)
		{
			last = tail;
			level++;
		}

		if(level == 6)
		{
			break;
		}
	}//end while(!myQueue.empty())

	return cnt;
}

/**
  * @brief  对图中所有节点进行六度空间思想 验证，并输出
  * @param[in]   graphMatrix    图
  */
void  SixDegreeofSeperation( GraphMatrix *graphMatrix)
{
	int i;
	int cnt;

	for(i=0; i<graphMatrix->size; i++)
	{
		cnt = BFS(i,graphMatrix);
		printf("%d:%.2f\n", i, cnt*100.0/graphMatrix->size);
		//printf("%d:%d\n", i,cnt);
	}
}