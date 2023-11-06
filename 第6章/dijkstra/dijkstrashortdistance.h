/** 
* @file dijkstrashortdistanc.h
* @brief ͼ�����·��dijkstra�㷨                                                              
*/
#ifndef DIJKSTRASHORTDISTANCE_H_
#define  DIJKSTRASHORTDISTANCE_H_

#include "graphmatrixutil.h"

/**
  * @brief  dijkstra�㷨
  * @param[in]   source    ���
  * @param[in]   graphMatrix    ͼ
  * @return    ������·����һά����
  */
int*  dijkstra( int source,GraphMatrix *graphMatrix);

#endif