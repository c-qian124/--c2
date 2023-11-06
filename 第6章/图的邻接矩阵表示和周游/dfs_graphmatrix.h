/** 
* @file dfs_graphmatrix.h
* @brief ͼ��������ȱ������ڽӾ����ʾͼ                                                              
*/

#ifndef DFS_GRAPHMATRIX_H_
#define DFS_GRAPHMATRIX_H_

#include "graphmatrixutil.h"

/**
  * @brief  ͼ��������ȱ����ݹ��㷨���ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void DFS(GraphMatrix* graphMatrix, int * visited, int i);

/**
  * @brief  ��ȱ������ڽӾ����ʾͼ
  * @param[in]   graphMatrix    ͼ
  */
void DFSGraphMatrix(GraphMatrix* graphMatrix);


#endif