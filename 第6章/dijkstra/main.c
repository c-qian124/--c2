#include "dijkstrashortdistance.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
	//���·������
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
			printf("0�Ž�㵽%d�Ž�����̾���Ϊ%d  \n", i,distance[i]);
		} 
		else
		{
			printf("0�Ž�㵽%d�Ž���޷���ͨ  \n", i);
		}
		
	}

	return 0;
}