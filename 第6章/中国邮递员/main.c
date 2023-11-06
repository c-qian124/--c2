#include "linkstack.h"
#include "graphmatrixutil.h"
#include <stdlib.h>
#include <stdio.h>

#define graph_size 12
#define infinity 1000

int a[20],v[20],n;//����ϱ���Сֵʱ�õ�
int oddDist[graph_size][graph_size] = {0};//Ϊ��ֱ�ӳ�ʼ��Ϊ0����ʵӦ�ó�ʼ��Ϊ������á��ö�ά����֪ʶΪ�˱���ÿһ����ȵ㵽����������·��
int oddDistPre[graph_size][graph_size] = {0};//·��ǰ�����
int oddArray[graph_size] = {0};//���ڴ���������ı�ţ�
int minDist = infinity;
int oddArrayChoose[graph_size] = {0};//��ŵ��Ǿ������С������
int cntOdd = 0;//ͳ����Ƚ��ĸ���

void DFS(int dep){
   int i;
   int j;
   int sum;
  if (dep==n)
  {
     //����ѵ�һ��������������һ���ǲ�����Сֵ
     sum = 0;
     for(i=1;i<=cntOdd/2;i++)
     {
        // printf("oddDist1=%d\n",oddDist[oddArray[a[i*2-1]-1]][oddArray[a[i*2]-1]]);

         sum = sum + oddDist[oddArray[a[i*2-1]-1]][oddArray[a[i*2]-1]];

     }//end for(i=0;i<cntOdd/2;i++)
         if(sum<minDist)
         {
             minDist = sum;
           //  printf("mintest=%d\n",minDist);
            
             for(j = 0 ;j<cntOdd;j++)
             {
                 oddArrayChoose[j]=oddArray[a[j+1]-1];
                 //oddArrayChoose[j]=a[j+1];
             }
         }//end if(sum<min)
  }

	dep++; //���ҵ�ǰҪ����λ
	for (i=1;i<=n;i++) 
	{ //ö�ٵ�ǰλ
		if (v[i]) 
			continue; //��������֮ǰ��ѡ��������
		v[i]=1; //ѡ�е�ǰλ
		a[dep]=i;//����ǰλ��������
		DFS(dep);//������һλ
		v[i]=0;//ȡ��ѡ�е�ǰλ
	}
}

//�����·��
void set_distances(int source,int distance[],int distPre[],GraphMatrix* graphMatrix)
/*
Post: The array distance gives the minimal path
weight from vertex source
to each vertex of the Digraph.
*/
{
    int v, w;
    int i;
    int found[graph_size]; // Vertices found in S
    for (v = 0; v < graph_size; v++)
    {
        found[v] = 0;
        distance[v] = graphMatrix->graph[source][v];
        if(distance[v] == infinity)
        {
            distPre[v] =  -1;
        }
        else
        {
            distPre[v] = source;
        }
    }
    found[source] = 1; //Դ�����㼯S��
    distance[source] = 0;

    for (i = 0; i < graph_size; i++)
    {
        // Add one vertex v to S on each pass.
        int min = infinity;//#define infinity 10000
        for (w = 0; w < graph_size; w++)
        {
            if (!found[w])
            {
                if (distance[w] < min)
                {
                    v = w;
                    min = distance[w];
                }
            }//end if (!found[w])
        }//end for (w = 0; w < graph_size; w++)

        found[v] = 1;
        for (w = 0; w < graph_size; w++)
        {
            if (!found[w])
            {
                if (min + graphMatrix->graph[v][w] < distance[w])
                {
                    distance[w] = min + graphMatrix->graph[v][w];
                    distPre[w] = v;
                }
            }//end if (!found[w])
        }//end for (w = 0; w < graph_size; w++)
    }//end for (int i = 0; i < graph_size; i++)
}//end function


void dfs(int x, LinkStack linkStack, int edgeRunCnt[][graph_size])
{
	int i;
	Push_link(linkStack, x);
	for(i = 0; i < graph_size; i++)
	{
		if(edgeRunCnt[x][i] >= 1)
		{
			edgeRunCnt[x][i]--;
			edgeRunCnt[i][x]--;
			dfs(i,linkStack, edgeRunCnt);
			break;
		}
	}
}

void euler(int x, int edgeRunCnt[][graph_size])
{
	int i;
	int k;
	int temp;
	LinkStack linkStack = SetNullStack_Link();
	//�����ջ
	Push_link(linkStack, x);

	while(!IsNullStack_link(linkStack))
	{
		k = 0;
		//�ж��Ƿ������չ
		temp = Top_link(linkStack);
		for(i = 0; i < graph_size; i++)//�ж��Ƿ����չ
		{
			if(edgeRunCnt[temp][i] >= 1)//������һ����ans[top]�����ı�  ��ô���ǿ���չ
			{
				k = 1; 
				break;
			}
		}
		if(k == 0)//�õ�xû�������ı߿��������ˣ���������չ���� ��ô�������
		{
			printf("%c ", 'A'+temp);
			Pop_link(linkStack);
		}
		else if(k == 1)//�����չ�� ��dfs����չ������·��
		{
			Pop_link(linkStack);
			//��չ
			dfs(temp, linkStack, edgeRunCnt);
		}

	}//end while(!IsNullStack_link(linkStack))
}




int main()
{
	int i, j;
	GraphMatrix *graphMatrix = NULL;
	int degree[graph_size] = {0}; //��Ÿ��������һά����
	int isOdd[graph_size] = {0};//��1��ʾ�õ�����ȵ�
	int cntEdge = 0;//����

	int edgeRunCnt[graph_size][graph_size]={0};//����һ����ά���飬���ڴ��ÿ���߻ᱻ�߶��ٴ�

	int beginVex = 0;
	int preBeginVex=-1;

	/**��1��	�����������������ڽӾ���*/
	graphMatrix = InitGraph(12);
	ReadGraphMatrix(graphMatrix);
    

    /**��2��	�������Ķ���   */
    for(i = 0; i<graph_size; i++)
    {
        for(j = 0; j<graph_size; j++)
        {
            if(graphMatrix->graph[i][j]!=infinity)
            {
                degree[i]++;
            }
        }//end for(j = 0;j<N;j++){
    }//end  for(i = 0;i<N;i++){

    /**��3��	���������ȵ㣻�������飬������Ԫ��Ϊ1�����Ԫ���±��Ӧ����Ϊ��������*/
    for(i = 0; i<graph_size; i++)
    {
        if(degree[i]%2 !=0 )
        {
            isOdd[i] = 1;
            oddArray[cntOdd] = i;//����ȵ�ı�ŷ����������
            cntOdd++;
        }
    }//end for(i = 0;i<N;i++){

    /**��4��	���ÿһ����ȵ㵽������ȵ�����·����
    //����һ����ȡ����ȵ㵽��ȵ���ڽӾ��󣬶���ȵ�֮�䵥���������·��
    //����������ÿ����ȵ㵽���е�����·�������оͰ�������Ҫ�Ľ����������÷�����
//    int oddDist[graph_size][graph_size] = {0};//Ϊ��ֱ�ӳ�ʼ��Ϊ0����ʵӦ�ó�ʼ��Ϊ������á��ö�ά����ֻ��Ϊ�˱���ÿһ����ȵ㵽����������·��
 //   int oddDistPre[graph_size][graph_size] = {0};*/

    //������Ҫ������ȵ�
    for(i = 0; i<graph_size; i++)
    {
        if(isOdd[i] == 1)
        {
            set_distances(i,oddDist[i],oddDistPre[i], graphMatrix);
        }

    }//for(i = 0;i<graph_size;i++){

  //����ԭ�б��������ں���һ�ʻ���ѭ������  
    for(i=0; i<graph_size; i++)
    {
        for(j = 0; j<graph_size; j++)
        {
            if(graphMatrix->graph[i][j]!=infinity)
            {
                cntEdge++;
            }
        }//end for(j = 0; j<graph_size;j++){
    }//end for(i=0;i<graph_size;i

    cntEdge = cntEdge/2;
    printf("ԭ����%d����\n",cntEdge);
    cntEdge +=cntOdd/2;



    /**��5��	�ҳ�������̵���ӷ�����
    //����dfs�㷨����������ϸ���������Ȼ������ҵ�������̵ķ���
    //������������Ž⣬���Ǻ�ʱ*/
    n = cntOdd;

    DFS(0);
    printf("���%d�������£�\n",cntOdd/2);
    for(i=0;i<cntOdd/2;i++)
    {
        //printf("%d---%d ��ȨֵΪ%d\n",oddArrayChoose[i*2],oddArrayChoose[i*2+1],oddDist[oddArrayChoose[i*2]][oddArrayChoose[i*2+1]]);
		printf("%c---%c ��ȨֵΪ%d\n",'A'+oddArrayChoose[i*2],'A'+oddArrayChoose[i*2+1],oddDist[oddArrayChoose[i*2]][oddArrayChoose[i*2+1]]);

    }
    printf("\n��ӱߵ�Ȩֵ��Ϊ  %d\n",minDist);

    //����ÿ���߻ᱻ�߶��ٴΣ�ÿ���߻��ߴ�����ԭʼ����������Ӵ���

    //ԭʼҪ�ߵ�
	
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            if(graphMatrix->graph[i][j]!=infinity)
            {
                edgeRunCnt[i][j]++;
            }//end if(dist[i][j]!=1000)
        }//end for(j=0;j<graph_size;j++)
    }//end for(i=0;i<graph_size;i++)


    //����ӵı�
    for(i=0;i<cntOdd/2;i++)
    {
        j = oddArrayChoose[i*2+1];
        //һ��һ�������
       while(oddDistPre[oddArrayChoose[i*2]][j]!=oddArrayChoose[i*2])
        {
           edgeRunCnt[j][oddDistPre[oddArrayChoose[i*2]][j]]++;
           edgeRunCnt[oddDistPre[oddArrayChoose[i*2]][j]][j]++;
		   j = oddDistPre[oddArrayChoose[i*2]][j];
        }//end while(oddDistPre[j]!=oddArrayChoose[i*2])

        edgeRunCnt[j][oddArrayChoose[i*2]]++;
        edgeRunCnt[oddArrayChoose[i*2]][j]++;

    }//end for(i=0;i<cntOdd/2;i++)


    printf("���Ҫ�ߵ�·�ߣ����ߵĵ���������\n");
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            printf("%d  ",edgeRunCnt[i][j]);
			n = n + edgeRunCnt[i][j];
        }//end for(j=0;j<graph_size;j++)
        printf("\n");
    }//end for(i=0;i<graph_size;i++)

	printf("����һ�ʻ���·�����£�\n");
   /**��7��	��ͼ����һ�ʻ����������*/

	euler(0, edgeRunCnt);
    return 0;
}



