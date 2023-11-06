#include "graphinverselistutil.h"
#include "graphlistutil.h"
#include "criticalpath.h"
#include <stdio.h>

int main()
{
	GraphList *graphList = InitGraph(8);
	GraphInverseList *graphInverseList = InitInverseGraph(8);
	int result = 0;

	ReadGraph(graphList);
	WriteGraph(graphList);
	ReadInverseGraph(graphInverseList);
	WriteInverseGraph(graphInverseList);

	criticalPath(graphList, graphInverseList);
	return 0;
}