#include <stdlib.h>
#include "kruskal.h"

/**
  * @brief  kruskal�㷨
  * @param[in]   graphMatrix    ͼ
  * @return    ��С������
  */
GraphMatrix*  kruskal( GraphMatrix *graphMatrix)
{
	int i,j,k;
	int edgeNum = 0;
	Edge *edge = NULL;
	Edge tempEdge;//��������ʱ�����ʱ����
	int pos;//��¼��ӵ���������
	int *group;//��¼���Ƿ�����ͬһ��ͨ����
	int changeGroup;//��¼Ҫ�仯����ֵͨ

	/**��Ž����ͼ*/
	GraphMatrix* tree = InitGraph(graphMatrix->size);
	group = (int*)malloc(sizeof(int)*graphMatrix->size);
	//��ʼ��
	for (i=0;i<graphMatrix->size;i++)
	{
		//��֮�����ڶ�û����ͨ
		group[i] = i;
 	}

	//�����ж������ߣ���ʵ�ڶ������ݵ�ʱ��Ϳ��Խ��б�������ͳ��
	//���ﲻԸ��ı�ԭ��graph�ļ������ݣ����Ҳ�Ը������ռ�
	//���������˷�ʱ�����һ��
	for (i=0; i<graphMatrix->size; i++)
	{
		for (j=i+1; j<graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edgeNum++;
			}
		}
	}//end for (i=0; i<graphMatrix->size; i++)

	//���ݸոռ�������ıߵ�����������ռ�
	edge = (Edge*)malloc(sizeof(Edge)*edgeNum);

	k = 0;//���߸�ֵ��ʱ����
	//���߸�ֵ
	for (i=0; i<graphMatrix->size; i++)
	{
		for (j=i+1; j<graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = graphMatrix->graph[i][j] ;

				k++;
			}
		}
	}//end for (i=0; i<graphMatrix->size; i++)

	//��������
	for (i=0;i<edgeNum;i++)
	{
		for (j=i+1;j<edgeNum;j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				tempEdge = edge[i];
				edge[i] = edge[j];
				edge[j] = tempEdge;
			}
		}
	}

	//ÿ�δӱ�������ȡ����С��һ���ߣ��ж��Ƿ�����ӵ���С��������
	//��������ʱ�Ѿ��ź�˳����
	for (i=0;i<edgeNum;i++)
	{
		//ֻ����յ���������������ͬ��ͨ�����ı�
		if (group[edge[i].begin] != group[edge[i].end])
		{
			//��ӵ�����
			tree->graph[edge[i].begin][edge[i].end] = edge[i].weight;
			tree->graph[edge[i].end][edge[i].begin] = edge[i].weight;
			//�������и��յ�����ͬһ��ͨ�����ĵ����ֵͨ
			changeGroup = group[edge[i].end];
			for (j=0;j<edgeNum;j++)
			{
				if (group[j] == changeGroup)
				{
					group[j] = group[edge[i].begin];
				}
			}//end for (j=0;j<edgeNum;j++)	
		}//end if (group[edge[i].begin] != group[edge[i].end])
	}//end for (i=0;i<edgeNum;i++)

	return tree;
}