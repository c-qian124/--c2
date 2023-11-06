#include "dijkstrashortdistance.h"
#include <stdlib.h>

/**
  * @brief  dijkstra�㷨
  * @param[in]   source    ���
  * @param[in]   graphMatrix    ͼ
  * @return    ������·����һά����
  */
int*  dijkstra( int source,GraphMatrix *graphMatrix)
{
	int i, j;
	int vex;
	int min;
	/**found�������ڼ�¼��Щ�����µ㼯�ϵģ���Щ����*/
	int* found = (int *)malloc(sizeof(int) * graphMatrix->size); 
	/**�������飬�㷨�����в��ϸ��£������Ҳ��������*/
	int* distance = (int *)malloc(sizeof(int) * graphMatrix->size); 

	/**��ʼ��*/
	for (i = 0; i < graphMatrix->size; i++) 
	{
		found[i] = 0;
		distance[i] = graphMatrix->graph[source][i];
	}//end for (i = 0; i < graphMatrix->size; i++) 

	/**���������µ㼯����*/
	found[source] = 1; 
	distance[source] = 0;

	/**ÿ�μ���һ���㵽�µ㼯���У������ǵ�ǰ������С��*/
	for (i = 0; i < graphMatrix->size; i++) 
	{ 
		/**����Сֵ�ķ�ʽѰ�Ҿ�����С�ĵ�*/
		min = INT_MAX;
		for (j = 0; j < graphMatrix->size; j++) 
		{
			if (!found[j])
			{
				if (distance[j] < min) 
				{
					vex = j;
					min = distance[j];
				}
			}//end if (!found[j])
		}//end for (j = 0; j < graphMatrix->size; j++) 

		/**�ҵ��ĵ�����µ㼯��*/
		found[vex] = 1;

		/**��Ϊ�е�����µ㼯�ϣ����¾���*/
		for (j = 0; j < graphMatrix->size; j++) 
		{
			if (!found[j] && graphMatrix->graph[vex][j] != INT_MAX)
			{
				if (min + graphMatrix->graph[vex][j] < distance[j])
				{
					distance[j] = min + graphMatrix->graph[vex][j];
				}
			}//end if (!found[j])
		}//end for (j = 0; j < graphMatrix->size; j++) 				
	}//end for (i = 0; i < graphMatrix->size; i++) 
	return distance;
}