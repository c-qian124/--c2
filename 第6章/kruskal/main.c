#include "kruskal.h"
#include <stdlib.h>


int main()
{
	//最小生成树测试
	GraphMatrix *graphMatrix = NULL;
	GraphMatrix *tree = NULL;
	graphMatrix = InitGraph(6);

	ReadGraph(graphMatrix);
	tree = kruskal(graphMatrix);
	WriteGraph(tree);

	return 0;
}