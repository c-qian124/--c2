/** 
* @file prim.h
* @brief 最小生成树prim算法                                                            
*/

#ifndef PRIM_H_
#define PRIM_H_

#include "graphmatrixutil.h"

/**
  * @brief  prim算法
  * @param[in]   source    起点
  * @param[in]   graphMatrix    图
  * @return    最小生成树
  */
GraphMatrix*  prim( int source,GraphMatrix *graphMatrix);

#endif