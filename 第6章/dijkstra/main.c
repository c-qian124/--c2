#include "dijkstrashortdistance.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
	//最短路径测试
	GraphMatrix *graphMatrix = NULL;
	int *distance = NULL;
	int i;

	graphMatrix = InitGraph(6);
	ReadGraph(graphMatrix);

	distance = dijkstra(0, graphMatrix);

	for (i = 0; i<graphMatrix->size; i++)
	{
		if (distance[i]<INT_MAX)
		{
			printf("0号结点到%d号结点的最短距离为%d  \n", i,distance[i]);
		} 
		else
		{
			printf("0号结点到%d号结点无法联通  \n", i);
		}
		
	}

	return 0;
}