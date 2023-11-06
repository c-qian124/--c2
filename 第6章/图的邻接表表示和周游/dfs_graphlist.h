/** 
* @file dfs_graphlist.h
* @brief 图的深度优先遍历，邻接表表示图                                                              
*/

#ifndef DFS_GRAPHLIST_H
#define DFS_GRAPHLIST_H

#include "graphlistutil.h"

/**
  * @brief  图的深度优先遍历递归算法，邻接表表示图
  * @param[in]   graphList    图
  * @param[in]   visited    做标记的（设置点是否被访问）一维数组
  * @param[in]   i    结点编号
  */
void DFS(GraphList* graphList, int * visited, int i);

/**
  * @brief  深度遍历，邻接表表示图
  * @param[in]   graphList    图
  */
void DFSGraphList(GraphList* graphList);

#endif