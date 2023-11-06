#include "dijkstrashortdistance.h"
#include <stdlib.h>

/**
  * @brief  dijkstra算法
  * @param[in]   source    起点
  * @param[in]   graphMatrix    图
  * @return    存放最短路径的一维数组
  */
int*  dijkstra( int source,GraphMatrix *graphMatrix)
{
	int i, j;
	int vex;
	int min;
	/**found数组用于记录哪些点是新点集合的，哪些不是*/
	int* found = (int *)malloc(sizeof(int) * graphMatrix->size); 
	/**距离数组，算法过程中不断更新，最后结果也放在这里*/
	int* distance = (int *)malloc(sizeof(int) * graphMatrix->size); 

	/**初始化*/
	for (i = 0; i < graphMatrix->size; i++) 
	{
		found[i] = 0;
		distance[i] = graphMatrix->graph[source][i];
	}//end for (i = 0; i < graphMatrix->size; i++) 

	/**将起点加入新点集合中*/
	found[source] = 1; 
	distance[source] = 0;

	/**每次加入一个点到新点集合中，规则是当前距离最小的*/
	for (i = 0; i < graphMatrix->size; i++) 
	{ 
		/**找最小值的方式寻找距离最小的点*/
		min = INT_MAX;
		for (j = 0; j < graphMatrix->size; j++) 
		{
			if (!found[j])
			{
				if (distance[j] < min) 
				{
					vex = j;
					min = distance[j];
				}
			}//end if (!found[j])
		}//end for (j = 0; j < graphMatrix->size; j++) 

		/**找到的点加入新点集合*/
		found[vex] = 1;

		/**因为有点加入新点集合，更新距离*/
		for (j = 0; j < graphMatrix->size; j++) 
		{
			if (!found[j] && graphMatrix->graph[vex][j] != INT_MAX)
			{
				if (min + graphMatrix->graph[vex][j] < distance[j])
				{
					distance[j] = min + graphMatrix->graph[vex][j];
				}
			}//end if (!found[j])
		}//end for (j = 0; j < graphMatrix->size; j++) 				
	}//end for (i = 0; i < graphMatrix->size; i++) 
	return distance;
}