#include "kruskal.h"
#include <stdlib.h>


int main()
{
	//��С����������
	GraphMatrix *graphMatrix = NULL;
	GraphMatrix *tree = NULL;
	graphMatrix = InitGraph(6);

	ReadGraph(graphMatrix);
	tree = kruskal(graphMatrix);
	WriteGraph(tree);

	return 0;
}