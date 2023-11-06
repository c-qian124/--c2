/** 
* @file dfs_graphlist.cpp
* @brief ͼ��������ȱ����㷨�����ڽӱ��ʾ��ͼ                                                          
*/

#include "dfs_graphlist.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * @brief  ͼ��������ȱ����ݹ��㷨���ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void DFS(GraphList* graphList, int * visited, int i)
{
	int j;
	GraphListNode *tempNode = NULL;
	visited[i] = 1;
	printf("%d ", i);

	//for(j = 0; j < graphList->size; j++)
	tempNode = graphList->graphListArray[i].next;
	while(tempNode != NULL)
	{
		if(!visited[tempNode->nodeno])
			DFS(graphList, visited, tempNode->nodeno);
		tempNode = tempNode->next;
	}
}

/**
  * @brief  ��ȱ������ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  */
void DFSGraphList(GraphList* graphList)
{
	int i;
	/** ���ڼ�¼ͼ����Щ����Ѿ��������� */
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	/** ��ʼ��Ϊ�㶼û�б����� */
	for(i = 0; i < graphList->size; i++)
		visited[i] = 0; 

	for(i = 0; i < graphList->size; i++)
		if(!visited[i]) /* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */ 
			DFS(graphList, visited, i);
}
