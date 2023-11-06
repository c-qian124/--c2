/** 
* @file sixdegree.h
* @brief 使用bfs验证六度空间思想                                                           
*/

#ifndef SIXDEGREE_H_
#define SIXDEGREE_H_

#include "graphmatrixutil.h"

/**
  * @brief  使用bfs验证六度空间思想，这里是对单个节点进行探查
  * @param[in]   source    起点
  * @param[in]   graphMatrix    图
  * @return    符合六度空间的节点个数
  */
int  BFS( int source,GraphMatrix *graphMatrix);

/**
  * @brief  对图中所有节点进行六度空间思想 验证，并输出
  * @param[in]   graphMatrix    图
  */
void  SixDegreeofSeperation( GraphMatrix *graphMatrix);

#endif