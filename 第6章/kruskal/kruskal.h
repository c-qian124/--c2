#ifndef KRUSKAL_H_
#define KRUSKAL_H_
#include "graphmatrixutil.h"

/**
 * @brief �ߵĽṹ
 */
typedef struct	EDGE_STRU
{
	int begin;/*!< ��� */
	int end;/*!<�յ� */
	int weight;/*!<Ȩֵ */
}Edge;

/**
  * @brief  kruskal�㷨
  * @param[in]   graphMatrix    ͼ
  * @return    ��С������
  */
GraphMatrix*  kruskal( GraphMatrix *graphMatrix);

#endif