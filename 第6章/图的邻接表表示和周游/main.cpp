#include "bfs_graphlist.h"
#include "dfs_graphlist.h"
#include <stdio.h>

int main(void)
{
	GraphList *graphList = NULL;
	graphList = InitGraph(7);

	ReadGraph(graphList);

	/**图的深度优先遍历*/
	printf("图的深度优先遍历结果如下：");
	DFSGraphList(graphList);
	printf("\n");

	/**图的广度优先遍历*/
	printf("图的广度度优先遍历结果如下：");
	BFSGraphList(graphList);
	printf("\n");

	return 0;
}