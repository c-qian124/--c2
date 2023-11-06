#include "bfs_graphmatrix.h"
#include "dfs_graphmatrix.h"
#include <stdio.h>

int main(void)
{
	GraphMatrix *graphMatrix = NULL;
	graphMatrix = InitGraph(7);

	ReadGraph(graphMatrix);

	/**图的深度优先遍历*/
	printf("图的深度优先遍历结果如下：");
	DFSGraphMatrix(graphMatrix);
	printf("\n");

	/**图的广度优先遍历*/
	printf("图的广度度优先遍历结果如下：");
	BFSGraphMatrix(graphMatrix);
	printf("\n");

	return 0;
}