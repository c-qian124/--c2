/** 
* @file dfs_graphmatrix.cpp
* @brief ͼ��������ȱ����㷨�����ڽӾ����ʾ��ͼ                                                          
*/

#include "dfs_graphmatrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * @brief  ͼ��������ȱ����ݹ��㷨���ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void DFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j;
	visited[i] = 1;
	printf("%d ", i);

	for(j = 0; j < graphMatrix->size; j++)
	{
		if(graphMatrix->graph[i][j] != INT_MAX && !visited[j])
			DFS(graphMatrix, visited, j);
	}
}

/**
  * @brief  ��ȱ������ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  */
void DFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i;
	/** ���ڼ�¼ͼ����Щ����Ѿ��������� */
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	/** ��ʼ��Ϊ�㶼û�б����� */
	for(i = 0; i < graphMatrix->size; i++)
		visited[i] = 0; 

	for(i = 0; i < graphMatrix->size; i++)
		if(!visited[i]) /* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */ 
			DFS(graphMatrix, visited, i);
}
