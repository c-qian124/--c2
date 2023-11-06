#include "prim.h"
#include "stdlib.h"

/**
  * @brief  prim�㷨
  * @param[in]   source    ���
  * @param[in]   graphMatrix    ͼ
  * @return    ��С������
  */
GraphMatrix*  prim( int source,GraphMatrix *graphMatrix) 
{
	int i,j;
	/**�µ㼯��*/
	int *component = (int*)malloc(sizeof(graphMatrix->size)); 
	/**����*/
	int *distance = (int*)malloc(sizeof(graphMatrix->size)); 
	/**�ھӣ�����neighbor[i]=j��ʾi���ھ���j*/
	int *neighbor = (int*)malloc(sizeof(graphMatrix->size));

	/**��Ž����ͼ*/
	GraphMatrix* tree = InitGraph(graphMatrix->size);

	/**������ʼ������*/
	for (i=0; i<graphMatrix->size; i++)
	{
		component[i] = 0;
		distance[i] = graphMatrix->graph[source][i];
		neighbor[i] = source;
	}
	/**���������µ㼯��*/
	component[source] = 1;

	/**ÿ�����һ����㵽�µ㼯����*/
	for (i=1; i<graphMatrix->size; i++)
	{
		int v;
		int min = INT_MAX;

		/**ѡ�����µ㼯���У��Ҿ����µ㼯����̵��Ǹ���*/
		for (j=0; j<graphMatrix->size; j++)
		{
			if(!component[j])
			{
				/**����Сֵ*/
				if (distance[j] < min)
				{
					v = j;
					min = distance[j];
				}
			}
		}
		/**���ҵ��ĵ�v�����µ㼯�ϣ�������distance*/
		if (min < INT_MAX)
		{
			component[v] = 1;
			tree->graph[v][neighbor[v]] = distance[v];
			tree->graph[neighbor[v]][v] = distance[v];

			/**���·��µ㼯���еĵ㵽�µ㼯�ϵľ���*/
			for (j=0; j<graphMatrix->size; j++)
			{
				if (!component[j])
				{
					if (graphMatrix->graph[v][j]<distance[j])
					{
						distance[j] = graphMatrix->graph[v][j];
						neighbor[j] = v;
					}
				}
			}
		} 
		else
		{
			break;
		}
	}
	return tree;
}

