#include <stdlib.h>
#include "kruskal.h"

/**
  * @brief  kruskal算法
  * @param[in]   graphMatrix    图
  * @return    最小生成树
  */
GraphMatrix*  kruskal( GraphMatrix *graphMatrix)
{
	int i,j,k;
	int edgeNum = 0;
	Edge *edge = NULL;
	Edge tempEdge;//给边排序时候的临时变量
	int pos;//记录添加到哪条边了
	int *group;//记录点是否属于同一连通分量
	int changeGroup;//记录要变化的连通值

	/**存放结果的图*/
	GraphMatrix* tree = InitGraph(graphMatrix->size);
	group = (int*)malloc(sizeof(int)*graphMatrix->size);
	//初始化
	for (i=0;i<graphMatrix->size;i++)
	{
		//点之间现在都没有连通
		group[i] = i;
 	}

	//分析有多少条边，其实在读入数据的时候就可以进行边数量的统计
	//这里不愿意改变原有graph文件的数据，而且不愿意多分配空间
	//所以这样浪费时间多算一下
	for (i=0; i<graphMatrix->size; i++)
	{
		for (j=i+1; j<graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edgeNum++;
			}
		}
	}//end for (i=0; i<graphMatrix->size; i++)

	//根据刚刚计算出来的边的数量，分配空间
	edge = (Edge*)malloc(sizeof(Edge)*edgeNum);

	k = 0;//给边赋值的时候用
	//给边赋值
	for (i=0; i<graphMatrix->size; i++)
	{
		for (j=i+1; j<graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = graphMatrix->graph[i][j] ;

				k++;
			}
		}
	}//end for (i=0; i<graphMatrix->size; i++)

	//给边排序
	for (i=0;i<edgeNum;i++)
	{
		for (j=i+1;j<edgeNum;j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				tempEdge = edge[i];
				edge[i] = edge[j];
				edge[j] = tempEdge;
			}
		}
	}

	//每次从边数组中取出最小的一条边，判断是否能添加到最小生成树中
	//边数组这时已经排好顺序了
	for (i=0;i<edgeNum;i++)
	{
		//只添加终点和起点属于两个不同连通分量的边
		if (group[edge[i].begin] != group[edge[i].end])
		{
			//添加到树中
			tree->graph[edge[i].begin][edge[i].end] = edge[i].weight;
			tree->graph[edge[i].end][edge[i].begin] = edge[i].weight;
			//更新所有跟终点属于同一连通分量的点的连通值
			changeGroup = group[edge[i].end];
			for (j=0;j<edgeNum;j++)
			{
				if (group[j] == changeGroup)
				{
					group[j] = group[edge[i].begin];
				}
			}//end for (j=0;j<edgeNum;j++)	
		}//end if (group[edge[i].begin] != group[edge[i].end])
	}//end for (i=0;i<edgeNum;i++)

	return tree;
}