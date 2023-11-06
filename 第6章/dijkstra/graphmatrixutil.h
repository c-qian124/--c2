/** 
* @file graphmatrixutil.h
* @brief 图的邻接矩阵表示以及辅助函数                                                               
*/

#ifndef GRAPHMATRIXUTIL_H_
#define GRAPHMATRIXUTIL_H_

/**
 * @brief 图的邻接矩阵表示
 */
typedef struct	GRAPHMATRIX_STRU
{
	int size;/*!< 图中结点的个数 */
	int **graph;/*!<二维数组保存图 */
}GraphMatrix;

/**
  * @brief  初始化图
  * @param[in]   num    图中结点的个数
  * @return    用邻接矩阵表示的图
  */
GraphMatrix* InitGraph(int num);

/**
  * @brief  将数据读入图中
  * @param[in]   graphMatrix    图
  */
void ReadGraph(GraphMatrix* graphMatrix);

/**
  * @brief  将图的结构显示出来
  * @param[in]   graphMatrix    图
  */
void WriteGraph(GraphMatrix* graphMatrix);

#endif

