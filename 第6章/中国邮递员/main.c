#include "linkstack.h"
#include "graphmatrixutil.h"
#include <stdlib.h>
#include <stdio.h>

#define graph_size 12
#define infinity 1000

int a[20],v[20],n;//求组合边最小值时用到
int oddDist[graph_size][graph_size] = {0};//为简单直接初始化为0，其实应该初始化为无穷更好。该二维数组知识为了保存每一个奇度点到其它点的最短路径
int oddDistPre[graph_size][graph_size] = {0};//路径前驱结点
int oddArray[graph_size] = {0};//用于存放所有奇点的编号，
int minDist = infinity;
int oddArrayChoose[graph_size] = {0};//存放的是距离和最小的排列
int cntOdd = 0;//统计奇度结点的个数

void DFS(int dep){
   int i;
   int j;
   int sum;
  if (dep==n)
  {
     //如果搜到一个结果输出，测试一下是不是最小值
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

	dep++; //查找当前要处理位
	for (i=1;i<=n;i++) 
	{ //枚举当前位
		if (v[i]) 
			continue; //如果这个数之前被选过就跳过
		v[i]=1; //选中当前位
		a[dep]=i;//将当前位存入数组
		DFS(dep);//搜索下一位
		v[i]=0;//取消选中当前位
	}
}

//求最短路径
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
    found[source] = 1; //源点放入点集S中
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
	//起点入栈
	Push_link(linkStack, x);

	while(!IsNullStack_link(linkStack))
	{
		k = 0;
		//判断是否可以扩展
		temp = Top_link(linkStack);
		for(i = 0; i < graph_size; i++)//判断是否可扩展
		{
			if(edgeRunCnt[temp][i] >= 1)//若存在一条从ans[top]出发的边  那么就是可扩展
			{
				k = 1; 
				break;
			}
		}
		if(k == 0)//该点x没有其他的边可以先走了（即不可扩展）， 那么就输出它
		{
			printf("%c ", 'A'+temp);
			Pop_link(linkStack);
		}
		else if(k == 1)//如可扩展， 则dfs可扩展的哪条路线
		{
			Pop_link(linkStack);
			//扩展
			dfs(temp, linkStack, edgeRunCnt);
		}

	}//end while(!IsNullStack_link(linkStack))
}




int main()
{
	int i, j;
	GraphMatrix *graphMatrix = NULL;
	int degree[graph_size] = {0}; //存放各点度数的一维数组
	int isOdd[graph_size] = {0};//用1表示该点是奇度点
	int cntEdge = 0;//边数

	int edgeRunCnt[graph_size][graph_size]={0};//定义一个二维数组，用于存放每条边会被走多少次

	int beginVex = 0;
	int preBeginVex=-1;

	/**（1）	建立街区无向网的邻接矩阵；*/
	graphMatrix = InitGraph(12);
	ReadGraphMatrix(graphMatrix);
    

    /**（2）	求各顶点的度数   */
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

    /**（3）	求出所有奇度点；设置数组，数组中元素为1，则该元素下标对应顶点为奇数顶点*/
    for(i = 0; i<graph_size; i++)
    {
        if(degree[i]%2 !=0 )
        {
            isOdd[i] = 1;
            oddArray[cntOdd] = i;//将奇度点的编号放入该数组中
            cntOdd++;
        }
    }//end for(i = 0;i<N;i++){

    /**（4）	求出每一个奇度点到其它奇度点的最短路径；
    //方案一：提取出奇度点到奇度点的邻接矩阵，对奇度点之间单独计算最短路径
    //方案二：求每个奇度点到所有点的最短路径，其中就包括了想要的结果，下面采用方案二
//    int oddDist[graph_size][graph_size] = {0};//为简单直接初始化为0，其实应该初始化为无穷更好。该二维数组只是为了保存每一个奇度点到其它点的最短路径
 //   int oddDistPre[graph_size][graph_size] = {0};*/

    //仅仅需要处理奇度点
    for(i = 0; i<graph_size; i++)
    {
        if(isOdd[i] == 1)
        {
            set_distances(i,oddDist[i],oddDistPre[i], graphMatrix);
        }

    }//for(i = 0;i<graph_size;i++){

  //计算原有边数，用于后面一笔画的循环控制  
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
    printf("原来有%d条边\n",cntEdge);
    cntEdge +=cntOdd/2;



    /**（5）	找出距离最短的添加方案；
    //采用dfs算法，先排列组合各个方案，然后从中找到距离最短的方案
    //这个方案是最优解，但是耗时*/
    n = cntOdd;

    DFS(0);
    printf("添加%d条边如下：\n",cntOdd/2);
    for(i=0;i<cntOdd/2;i++)
    {
        //printf("%d---%d ，权值为%d\n",oddArrayChoose[i*2],oddArrayChoose[i*2+1],oddDist[oddArrayChoose[i*2]][oddArrayChoose[i*2+1]]);
		printf("%c---%c ，权值为%d\n",'A'+oddArrayChoose[i*2],'A'+oddArrayChoose[i*2+1],oddDist[oddArrayChoose[i*2]][oddArrayChoose[i*2+1]]);

    }
    printf("\n添加边的权值和为  %d\n",minDist);

    //计算每条边会被走多少次，每条边会走次数＝原始次数＋新添加次数

    //原始要走的
	
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


    //新添加的边
    for(i=0;i<cntOdd/2;i++)
    {
        j = oddArrayChoose[i*2+1];
        //一条一条边添加
       while(oddDistPre[oddArrayChoose[i*2]][j]!=oddArrayChoose[i*2])
        {
           edgeRunCnt[j][oddDistPre[oddArrayChoose[i*2]][j]]++;
           edgeRunCnt[oddDistPre[oddArrayChoose[i*2]][j]][j]++;
		   j = oddDistPre[oddArrayChoose[i*2]][j];
        }//end while(oddDistPre[j]!=oddArrayChoose[i*2])

        edgeRunCnt[j][oddArrayChoose[i*2]]++;
        edgeRunCnt[oddArrayChoose[i*2]][j]++;

    }//end for(i=0;i<cntOdd/2;i++)


    printf("最后要走的路线（多走的点标出次数）\n");
    for(i=0;i<graph_size;i++)
    {
        for(j=0;j<graph_size;j++)
        {
            printf("%d  ",edgeRunCnt[i][j]);
			n = n + edgeRunCnt[i][j];
        }//end for(j=0;j<graph_size;j++)
        printf("\n");
    }//end for(i=0;i<graph_size;i++)

	printf("最终一笔画的路径如下：\n");
   /**（7）	对图进行一笔画，并输出；*/

	euler(0, edgeRunCnt);
    return 0;
}



