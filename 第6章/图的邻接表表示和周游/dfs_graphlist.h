/** 
* @file dfs_graphlist.h
* @brief ͼ��������ȱ������ڽӱ��ʾͼ                                                              
*/

#ifndef DFS_GRAPHLIST_H
#define DFS_GRAPHLIST_H

#include "graphlistutil.h"

/**
  * @brief  ͼ��������ȱ����ݹ��㷨���ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void DFS(GraphList* graphList, int * visited, int i);

/**
  * @brief  ��ȱ������ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  */
void DFSGraphList(GraphList* graphList);

#endif