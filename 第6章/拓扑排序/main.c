#include "graphlistutil.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

/**
  * @brief  ��������
  * @param[in]   graphList    �ڽӱ��ʾ��ͼ
  * @return    1���ɹ� 0��ʧ��
  */
int topologicalsort(GraphList *graphList)
{
	int i;
	int cnt;
	int nodeNum;
	int success = 1;

	LinkStack nodeStack = NULL;
	GraphListNode *tempNode = NULL;
	int *inPoint = (int *)malloc(sizeof(int) * graphList->size);
	nodeStack = SetNullStack_Link();

	for (i=0; i<graphList->size; i++)
	{
		inPoint[i] = 0;
	}
	/**���������*/
	for (i=0; i<graphList->size; i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while(tempNode != NULL)
		{
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;
		}
	}
	/**�����Ϊ0�Ķ�����ջ*/
	for(i=0; i<graphList->size; i++)
	{
		if (inPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}
	/**�����¼����ջ��Ϊ��*/
	cnt = 0;
	while(!IsNullStack_link(nodeStack))
	{
		/**ȡջ��Ԫ��v*/
		nodeNum = Top_link(nodeStack);
		printf("%d ", nodeNum);
		Pop_link(nodeStack);
		cnt++;

		/**���v�ĳ��ߣ���ÿ�����ߵ��ն˶������ȼ�1�����ö������Ϊ0����ջ*/
		tempNode = graphList->graphListArray[nodeNum].next;
		while(tempNode != NULL)
		{
			inPoint[tempNode->nodeno]--;
			if (inPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}

	if (cnt != graphList->size)
	{
		success = 0;
	} 

	return success;
}

int main()
{
	GraphList *graphList = InitGraph(8);
	int result = 0;

	ReadGraph(graphList);
	WriteGraph(graphList);

	result = topologicalsort(graphList);
	if (result == 1)
	{
		printf("��������ɹ�\n");
	} 
	else
	{
		printf("��������ʧ��\n");
	}

	return 0;
}
