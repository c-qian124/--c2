/** 
* @file bfs_graphmatrix.h
* @brief 图的广度优先遍历，邻接矩阵表示图                                                              
*/
#ifndef BFS_GRAPHMATRIX_H_
#define BFS_GRAPHMATRIX_H_

#include "graphmatrixutil.h"

/**
  * @brief  图的广度优先遍历递归算法，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void BFS(GraphMatrix* graphMatrix, int * visited, int i);

/**
  * @brief  图的广度优先遍历，邻接矩阵表示图
  * @param[in]   graphMatrix    图
  */
void BFSGraphMatrix(GraphMatrix* graphMatrix);


#endif
