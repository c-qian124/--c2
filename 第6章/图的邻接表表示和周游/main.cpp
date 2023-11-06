#include "bfs_graphlist.h"
#include "dfs_graphlist.h"
#include <stdio.h>

int main(void)
{
	GraphList *graphList = NULL;
	graphList = InitGraph(7);

	ReadGraph(graphList);

	/**ͼ��������ȱ���*/
	printf("ͼ��������ȱ���������£�");
	DFSGraphList(graphList);
	printf("\n");

	/**ͼ�Ĺ�����ȱ���*/
	printf("ͼ�Ĺ�ȶ����ȱ���������£�");
	BFSGraphList(graphList);
	printf("\n");

	return 0;
}