/** 
* @file bfs_graphmatrix.cpp
* @brief ͼ�Ĺ�����ȱ����㷨�����ڽӾ����ʾ��ͼ                                                          
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
#include "bfs_graphmatrix.h"
/**
  * @brief  ͼ�Ĺ�����ȱ����ݹ��㷨���ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void BFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j;
	int tempVex;

	LinkQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();

	/** ���û�з��ʹ�������� */
	if (!visited[i])	
	{
		/** ���ñ�ǣ������Ѿ������� */
		visited[i] = 1;	
		/** ������ʵĽ���� */
		printf("%d ", i);
		/** ���շ��ʵĽ�������� */
		EnQueue_link(waitingQueue,i);

		/** ���ʽ�㣭������� */
		while(!IsNullQueue_Link(waitingQueue))	
		{
			tempVex = FrontQueue_link(waitingQueue);
			DeQueue_link(waitingQueue);

			for(j=0;j<graphMatrix->size;j++) 
			{ 
				/**������������뵱ǰ������ڱ���δ���ʹ�  */
				if(graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j]) 
				{ 
					/**�����*/
					visited[j] = 1;		
					/**���*/
					EnQueue_link(waitingQueue, j);
					/**���*/
					printf("%d ", j);	
				} //end if(graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j]) 
			} //end for(j=0;j<graphMatrix->size;j++) 
		}//end while(!waitingQueue.empty())	
	}//end if (!visited[i])	
}

/**
  * @brief  ͼ�Ĺ�����ȱ������ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  */
void BFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i;

	/** ���ڼ�¼ͼ����Щ����Ѿ��������� */
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	/** �������н�㶼û�б����ʣ�����1Ϊ���ʹ���0Ϊû�б����� */
	for(i = 0; i < graphMatrix->size; i++)
		visited[i] = 0;

	/** ��0�Ž�㿪ʼ���й�����ȱ��� */
	for(i = 0; i < graphMatrix->size; i++)  
	{
		BFS(graphMatrix, visited, i);
	}//end for(i = 0; i < graphMatrix->size; i++)  
}