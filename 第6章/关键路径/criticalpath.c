/** 
* @file criticalpath.C
* @brief ͼ�Ĺؼ�·��                                                               
*/

#include "graphlistutil.h"
#include "graphinverselistutil.h"
#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * @brief  �¼����ܵ����緢��ʱ��
  * @param[in]   graphList ���ڽӱ��ʾ��ͼ   
  * @param[out]   earliestTime    �¼����ܵ����緢��ʱ��
  * @return   �Ƿ�ɹ�
  */
int eventEarliestTime(GraphList *graphList, int* earliestTime)
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
		/**ȡջ��Ԫ�أ���ñߵ���㣬���¼��Ŀ������緢��ʱ���Ѿ��ܶ���*/
		nodeNum = Top_link(nodeStack);
		Pop_link(nodeStack);
		cnt++;

		/**���v�ĳ��ߣ���ÿ�����ߵ��ն˶������ȼ�1�����ö������Ϊ0����ջ*/
		tempNode = graphList->graphListArray[nodeNum].next;
		while(tempNode != NULL)
		{
			/**ȥ�����*/
			inPoint[tempNode->nodeno]--;
			/**Ϊÿ�����ߵ��յ��¼����¿��ܵ����緢��ʱ��*/
			if (earliestTime[tempNode->nodeno] < earliestTime[nodeNum] + tempNode->weight)
			{
				earliestTime[tempNode->nodeno] = earliestTime[nodeNum] + tempNode->weight;
			}
			/**��ջ*/
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

/**
  * @brief  �¼��������ٷ���ʱ��
  * @param[in]   graphInverseList    �����ڽӱ��ʾ��ͼ
  * @param[out]   latestTime    �¼��������ٷ���ʱ��
  * @return    �Ƿ�ɹ�
  */
int eventLatestTime(GraphInverseList *graphInverseList, int* latestTime)
{
	int i;
	int cnt;
	int nodeNum;
	int success = 1;

	LinkStack nodeStack = NULL;
	GraphInverseListNode *tempNode = NULL;
	int *outPoint = (int *)malloc(sizeof(int) * graphInverseList->size);
	nodeStack = SetNullStack_Link();

	for (i=0; i<graphInverseList->size; i++)
	{
		outPoint[i] = 0;
	}
	/**�����ĳ���*/
	for (i=0; i<graphInverseList->size; i++)
	{
		tempNode = graphInverseList->graphInverseListArray[i].next;

		while(tempNode != NULL)
		{
			outPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;
		}
	}
	/**������Ϊ0�Ķ�����ջ*/
	for(i=0; i<graphInverseList->size; i++)
	{
		if (outPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}
	/**�����¼����ջ��Ϊ��*/
	cnt = 0;
	while(!IsNullStack_link(nodeStack))
	{
		/**ȡջ��Ԫ�أ���ñߵ��յ㣬���¼���������ٷ���ʱ���Ѿ��ܶ���*/
		nodeNum = Top_link(nodeStack);
		Pop_link(nodeStack);
		cnt++;

		/**���v����ߣ���ÿ����ߵ��ն˶���ĳ��ȼ�1�����ö������Ϊ0����ջ*/
		tempNode = graphInverseList->graphInverseListArray[nodeNum].next;
		while(tempNode != NULL)
		{
			/**ȥ������*/
			outPoint[tempNode->nodeno]--;
			/**Ϊÿ����ߵ�����¼�����������ٷ���ʱ��*/
			if (latestTime[tempNode->nodeno] > latestTime[nodeNum] - tempNode->weight)
			{
				latestTime[tempNode->nodeno] = latestTime[nodeNum] - tempNode->weight;
			}
			/**���ȥ�����ߺ󣬳���Ϊ0�������ջ*/
			if (outPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}

	if (cnt != graphInverseList->size)
	{
		success = 0;
	} 

	return success;
}

/**
  * @brief  �ؼ�·��
  * @param[in]   graphList ���ڽӱ��ʾ��ͼ   
  * @param[in]   graphInverseList    �����ڽӱ��ʾ��ͼ
  */
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)
{
	int i;
	int max;

	int* earliestTime = (int*)malloc(sizeof(int) * graphList->size);
	int* latestTime = (int*)malloc(sizeof(int) * graphInverseList->size);
	int activityEarliestTime;
	int activityLatestTime;

	GraphListNode *tempNode = NULL;
	
	/**��ʼ�������¼����ܵ����緢��ʱ��Ϊ0*/
	for(i=0; i<graphList->size; i++)
	{
		earliestTime[i] = 0;
	}

	/**���¼����ܵ����緢��ʱ��*/
	eventEarliestTime(graphList, earliestTime);

	/**���¼����緢��ʱ������ֵ��������������¼�������ٷ���ʱ��ĳ�ֵ*/
	max = earliestTime[0];
	for (i=0; i<graphList->size; i++)
	{
		if (max < earliestTime[i])
		{
			max = earliestTime[i];
		}
	}

	/**��ʼ�������¼��������ٷ���ʱ��Ϊ���ֵ*/
	for(i=0; i<graphInverseList->size; i++)
	{
		latestTime[i] = max;
	}

	eventLatestTime(graphInverseList, latestTime);


	/**����ÿ���ߣ���ÿ���ߵ����翪ʼʱ�������ʼʱ�䣬���Աȣ������Ϊ�ؼ�·���ϵı�*/
	for (i=0; i<graphList->size; i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while(tempNode != NULL)
		{
			activityEarliestTime = earliestTime[i];
			activityLatestTime = latestTime[tempNode->nodeno] - tempNode->weight;
			
			if (activityEarliestTime == activityLatestTime)
			{
				printf("<v%2d,v%2d>", i, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}


}


