/** 
* @file graphlistutil.h
* @brief 图的邻接表表示以及辅助函数                                                               
*/
#ifndef GRAPHLISTUTIL_H
#define GRAPHLISTUTIL_H

typedef struct	GRAPHLISTNODE_STRU
{
	int nodeno;/*!< 图中结点的编号 */
	struct	GRAPHLISTNODE_STRU* next;/*!<指向下一个结点的指针 */
}GraphListNode;

typedef struct	GRAPHLIST_STRU
{
	int size;/*!< 图中结点的个数 */
	GraphListNode* graphListArray;/*!<图的邻接表 */
}GraphList;

/**
  * @brief  初始化图
  * @param[in]   num    图中结点的个数
  * @return    用邻接表表示的图
  */
GraphList* InitGraph(int num);

/**
  * @brief  将数据读入图中
  * @param[in]   graphList    图
  */
void ReadGraph(GraphList* graphList);

/**
  * @brief  将图的结构显示出来
  * @param[in]   graphList    图
  */
void WriteGraph(GraphList* graphList);

#endif

