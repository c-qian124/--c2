/** 
* @file bfs_graphlist.h
* @brief 图的广度优先遍历，邻接表表示图                                                              
*/
#ifndef BFS_GRAPHLIST_H
#define BFS_GRAPHLIST_H

#include "graphlistutil.h"

/**
  * @brief  图的广度优先遍历递归算法，邻接表表示图
  * @param[in]   graphList    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void BFS(GraphList* graphList, int * visited, int i);

/**
  * @brief  图的广度优先遍历，邻接表表示图
  * @param[in]   graphList    图
  */
void BFSGraphList(GraphList* graphList);

#endif