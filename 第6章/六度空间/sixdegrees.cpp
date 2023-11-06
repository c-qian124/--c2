#include "graphmatrixutil.h"
#include <stdlib.h>

#include <queue>
using namespace std;

/**
  * @brief  ʹ��bfs��֤���ȿռ�˼�룬�����ǶԵ����ڵ����̽��
  * @param[in]   source    ���
  * @param[in]   graphMatrix    ͼ
  * @return    �������ȿռ�Ľڵ����
  */
int  BFS( int source,GraphMatrix *graphMatrix)
{
	/**���ڱ�����Ƿ��Ѿ������ʹ�����Ϣ*/
	int* visited = (int *)malloc(sizeof(int)*graphMatrix->size);
	/**��last������һ�������ʵĽڵ㣬��tail����¼��ǰ�����ʽڵ�*/
	int last = source;
	int tail = source;
	/**�ڵ���У�������ȷ���*/
	queue<int> myQueue;
	/**���������ܷ��ʵ��Ľڵ������������ֵ���ڷ��أ�����Ҳ��*/
	int cnt = 1;
	/**���ʲ����������ʲ���>6������Խ���������������㷨*/
	int level = 0;
	/**��ǰ���ʵĽڵ�*/
	int visitNow;
	/**ѭ������*/
	int i;

	/**�Ƚ�����ڵ��Ƿ񱻷��ʵ�������0*/
	
	for(i=0; i<graphMatrix->size; i++)
	{
		visited[i] = 0;
	}


	/**ͼ��Դ��������*/
	myQueue.push(source);
	visited[source] = 1;

	/**�������������*/
	while(!myQueue.empty())
	{
		/**�Ӷ�����ȡ�� һ���ڵ㣬���ڶ�����һ��ڵ���з���*/
		visitNow = myQueue.front();
		myQueue.pop();

		/**����������и�ȡ���Ľڵ�ֱ�������Ľڵ�*/
		for(i=0;i<graphMatrix->size;i++)
		{
			/**��������б�����������û�б����ʹ��������*/
			if(graphMatrix->graph[visitNow][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				myQueue.push(i);
				cnt++;
				
				/**��̬��¼�ڷ��ʹ����У������ʵĽڵ�*/
				tail = i;
			}
		}//end for(i=0;i<graphMatrix->size;i++)

		//���ոմӶ�����ȡ���Ľڵ����һ�㶼���ʺ����жϸմӶ���ȡ���Ľڵ��Ƿ�����һ������ڵ�
		if(visitNow == last)
		{
			last = tail;
			level++;
		}

		if(level == 6)
		{
			break;
		}
	}//end while(!myQueue.empty())

	return cnt;
}

/**
  * @brief  ��ͼ�����нڵ�������ȿռ�˼�� ��֤�������
  * @param[in]   graphMatrix    ͼ
  */
void  SixDegreeofSeperation( GraphMatrix *graphMatrix)
{
	int i;
	int cnt;

	for(i=0; i<graphMatrix->size; i++)
	{
		cnt = BFS(i,graphMatrix);
		printf("%d:%.2f\n", i, cnt*100.0/graphMatrix->size);
		//printf("%d:%d\n", i,cnt);
	}
}