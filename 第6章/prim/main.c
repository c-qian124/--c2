#include "prim.h"
#include <stdlib.h>


int main()
{
	//��С����������
	GraphMatrix *graphMatrix = NULL;
	GraphMatrix *tree = NULL;
	graphMatrix = InitGraph(6);

	ReadGraph(graphMatrix);
	tree = prim(0, graphMatrix);
	WriteGraph(tree);

	return 0;
}