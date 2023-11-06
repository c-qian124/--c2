/** 
* @file dijkstrashortdistanc.h
* @brief 图的最短路径dijkstra算法                                                              
*/
#ifndef DIJKSTRASHORTDISTANCE_H_
#define  DIJKSTRASHORTDISTANCE_H_

#include "graphmatrixutil.h"

/**
  * @brief  dijkstra算法
  * @param[in]   source    起点
  * @param[in]   graphMatrix    图
  * @return    存放最短路径的一维数组
  */
int*  dijkstra( int source,GraphMatrix *graphMatrix);

#endif