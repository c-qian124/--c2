/** 
* @file bfs_graphlist.h
* @brief ͼ�Ĺ�����ȱ������ڽӱ��ʾͼ                                                              
*/
#ifndef BFS_GRAPHLIST_H
#define BFS_GRAPHLIST_H

#include "graphlistutil.h"

/**
  * @brief  ͼ�Ĺ�����ȱ����ݹ��㷨���ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  * @param[in]   visited    ����ǵģ����õ��Ƿ񱻷��ʣ�һά����
  * @param[in]   i    �����
  */
void BFS(GraphList* graphList, int * visited, int i);

/**
  * @brief  ͼ�Ĺ�����ȱ������ڽӱ��ʾͼ
  * @param[in]   graphList    ͼ
  */
void BFSGraphList(GraphList* graphList);

#endif