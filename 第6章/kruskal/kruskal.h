#ifndef KRUSKAL_H_
#define KRUSKAL_H_
#include "graphmatrixutil.h"

/**
 * @brief 边的结构
 */
typedef struct	EDGE_STRU
{
	int begin;/*!< 起点 */
	int end;/*!<终点 */
	int weight;/*!<权值 */
}Edge;

/**
  * @brief  kruskal算法
  * @param[in]   graphMatrix    图
  * @return    最小生成树
  */
GraphMatrix*  kruskal( GraphMatrix *graphMatrix);

#endif