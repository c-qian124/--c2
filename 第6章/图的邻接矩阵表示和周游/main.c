#include "bfs_graphmatrix.h"
#include "dfs_graphmatrix.h"
#include <stdio.h>

int main(void)
{
	GraphMatrix *graphMatrix = NULL;
	graphMatrix = InitGraph(7);

	ReadGraph(graphMatrix);

	/**ͼ��������ȱ���*/
	printf("ͼ��������ȱ���������£�");
	DFSGraphMatrix(graphMatrix);
	printf("\n");

	/**ͼ�Ĺ�����ȱ���*/
	printf("ͼ�Ĺ�ȶ����ȱ���������£�");
	BFSGraphMatrix(graphMatrix);
	printf("\n");

	return 0;
}