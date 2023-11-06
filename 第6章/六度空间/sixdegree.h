/** 
* @file sixdegree.h
* @brief ʹ��bfs��֤���ȿռ�˼��                                                           
*/

#ifndef SIXDEGREE_H_
#define SIXDEGREE_H_

#include "graphmatrixutil.h"

/**
  * @brief  ʹ��bfs��֤���ȿռ�˼�룬�����ǶԵ����ڵ����̽��
  * @param[in]   source    ���
  * @param[in]   graphMatrix    ͼ
  * @return    �������ȿռ�Ľڵ����
  */
int  BFS( int source,GraphMatrix *graphMatrix);

/**
  * @brief  ��ͼ�����нڵ�������ȿռ�˼�� ��֤�������
  * @param[in]   graphMatrix    ͼ
  */
void  SixDegreeofSeperation( GraphMatrix *graphMatrix);

#endif