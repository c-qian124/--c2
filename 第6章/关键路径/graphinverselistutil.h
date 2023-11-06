/** 
* @file graphinverselistutil.h
* @brief 图的逆邻接表表示以及辅助函数                                                               
*/
#ifndef GRAPHINVERSELISTUTIL_H
#define GRAPHINVERSELISTUTIL_H

typedef struct	GRAPHINVERSELISTNODE_STRU
{
	int nodeno;/*!< 图中结点的编号 */
	int weight;/*!< 图中边的权值 */
	struct	GRAPHINVERSELISTNODE_STRU* next;/*!<指向下一个结点的指针 */
}GraphInverseListNode;

typedef struct	GRAPHINVERSELIST_STRU
{
	int size;/*!< 图中结点的个数 */
	GraphInverseListNode* graphInverseListArray;/*!<图的邻接表 */
}GraphInverseList;

/**
  * @brief  初始化图
  * @param[in]   num    图中结点的个数
  * @return    用逆邻接表表示的图
  */
GraphInverseList* InitInverseGraph(int num);

/**
  * @brief  将数据读入图中
  * @param[in]   graphInverseList    图
  */
void ReadInverseGraph(GraphInverseList* graphInverseList);

/**
  * @brief  将图的结构显示出来
  * @param[in]   graphInverseList    图
  */
void WriteInverseGraph(GraphInverseList* graphInverseList);

#endif