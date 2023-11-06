#include "prim.h"
#include "stdlib.h"

/**
  * @brief  prim算法
  * @param[in]   source    起点
  * @param[in]   graphMatrix    图
  * @return    最小生成树
  */
GraphMatrix*  prim( int source,GraphMatrix *graphMatrix) 
{
	int i,j;
	/**新点集合*/
	int *component = (int*)malloc(sizeof(graphMatrix->size)); 
	/**距离*/
	int *distance = (int*)malloc(sizeof(graphMatrix->size)); 
	/**邻居，例如neighbor[i]=j表示i的邻居是j*/
	int *neighbor = (int*)malloc(sizeof(graphMatrix->size));

	/**存放结果的图*/
	GraphMatrix* tree = InitGraph(graphMatrix->size);

	/**先做初始化工作*/
	for (i=0; i<graphMatrix->size; i++)
	{
		component[i] = 0;
		distance[i] = graphMatrix->graph[source][i];
		neighbor[i] = source;
	}
	/**将起点放入新点集合*/
	component[source] = 1;

	/**每次添加一个结点到新点集合中*/
	for (i=1; i<graphMatrix->size; i++)
	{
		int v;
		int min = INT_MAX;

		/**选择不是新点集合中，且距离新点集合最短的那个点*/
		for (j=0; j<graphMatrix->size; j++)
		{
			if(!component[j])
			{
				/**找最小值*/
				if (distance[j] < min)
				{
					v = j;
					min = distance[j];
				}
			}
		}
		/**将找到的点v加入新点集合，并更新distance*/
		if (min < INT_MAX)
		{
			component[v] = 1;
			tree->graph[v][neighbor[v]] = distance[v];
			tree->graph[neighbor[v]][v] = distance[v];

			/**更新非新点集合中的点到新点集合的距离*/
			for (j=0; j<graphMatrix->size; j++)
			{
				if (!component[j])
				{
					if (graphMatrix->graph[v][j]<distance[j])
					{
						distance[j] = graphMatrix->graph[v][j];
						neighbor[j] = v;
					}
				}
			}
		} 
		else
		{
			break;
		}
	}
	return tree;
}

