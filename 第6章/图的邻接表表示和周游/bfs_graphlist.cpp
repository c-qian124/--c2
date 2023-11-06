/** 
* @file bfs_graphlist.cpp
* @brief ͼ�Ĺ�����ȱ����㷨�����ڽӱ��ʾ��ͼ                                                          
*/

#include "bfs_graphlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/**
  * @brief  ͼ�Ĺ�����ȱ����ݹ��㷨���ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void BFS(GraphList* graphList, int * visited, int i)
{
	int tempVex;
	GraphListNode *tempNode = NULL;
	/** ������ȱ���ʹ�õĶ�����c++��STL�е�queue */
	queue<int> waitingQueue;

	/** ���û�з��ʹ�������� */
	if (!visited[i])	
	{
		/** ���ñ�ǣ������Ѿ������� */
		visited[i] = 1;	
		/** ������ʵĽ���� */
		printf("%d ", i);
		/** ���շ��ʵĽ�������� */
		waitingQueue.push(i);

		/** ���ʽ�㣭������� */
		while(!waitingQueue.empty())	
		{
			tempVex = waitingQueue.front();
			waitingQueue.pop();

			/**���η����뵱ǰ������ڵĵ�*/ 
			tempNode = graphList->graphListArray[tempVex].next;
			while(tempNode != NULL)
			{ 
				/**������������뵱ǰ������ڱ���δ���ʹ�  */
				if(!visited[tempNode->nodeno]) 
				{ 
					/**�����*/
					visited[tempNode->nodeno] = 1;		
					/**���*/
					waitingQueue.push(tempNode->nodeno);
					/**���*/
					printf("%d ", tempNode->nodeno);	

				} //end if(!visited[tempNode->nodeno]) 
				/**�ƶ�����һ�����*/
				tempNode = tempNode->next;
			} //end while(tempNode != NULL)
		}//end while(!waitingQueue.empty())	
	}//end if (!visited[i])	
}


/**
  * @brief  ͼ�Ĺ�����ȱ������ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  */
void BFSGraphList(GraphList* graphList)
{
	int i;

	/** ���ڼ�¼ͼ����Щ����Ѿ��������� */
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	/** �������н�㶼û�б����ʣ�����1Ϊ���ʹ���0Ϊû�б����� */
	for(i = 0; i < graphList->size; i++)
		visited[i] = 0;

	/** ��0�Ž�㿪ʼ���й�����ȱ��� */
	for(i = 0; i < graphList->size; i++)  
	{
		BFS(graphList, visited, i);
	}//end for(i = 0; i < graphList->size; i++)  
}