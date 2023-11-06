#include "sixdegree.h"
#include <stdio.h>

int main()
{
	GraphMatrix *graphMatrix = NULL;
	graphMatrix = InitGraph(10);
	ReadGraph(graphMatrix);

	SixDegreeofSeperation( graphMatrix);
	return 0;
}