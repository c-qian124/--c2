/** 
* @file bfs_graphmatrix.h
* @brief ͼ�Ĺ�����ȱ������ڽӾ����ʾͼ                                                              
*/
#ifndef BFS_GRAPHMATRIX_H_
#define BFS_GRAPHMATRIX_H_

#include "graphmatrixutil.h"

/**
  * @brief  ͼ�Ĺ�����ȱ����ݹ��㷨���ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void BFS(GraphMatrix* graphMatrix, int * visited, int i);

/**
  * @brief  ͼ�Ĺ�����ȱ������ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  */
void BFSGraphMatrix(GraphMatrix* graphMatrix);


#endif
