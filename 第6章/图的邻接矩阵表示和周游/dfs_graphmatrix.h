/** 
* @file dfs_graphmatrix.h
* @brief 图的深度优先遍历，邻接矩阵表示图                                                              
*/

#ifndef DFS_GRAPHMATRIX_H_
#define DFS_GRAPHMATRIX_H_

#include "graphmatrixutil.h"

/**
  * @brief  图的深度优先遍历递归算法，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void DFS(GraphMatrix* graphMatrix, int * visited, int i);

/**
  * @brief  深度遍历，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  */
void DFSGraphMatrix(GraphMatrix* graphMatrix);


#endif