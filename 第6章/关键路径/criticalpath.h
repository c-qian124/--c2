/** 
* @file criticalpath.h
* @brief 图的关键路径                                                               
*/
#ifndef CRITICALPATH_H_
#define CRITICALPATH_H_

#include "graphlistutil.h"
#include "graphinverselistutil.h"

/**
  * @brief  事件可能的最早发生时间
  * @param[in]   graphList 用邻接表表示的图   
  * @param[out]   earliestTime    事件可能的最早发生时间
  * @return   是否成功
  */
int eventEarliestTime(GraphList *graphList, int* earliestTime);

/**
  * @brief  事件允许的最迟发生时间
  * @param[in]   graphInverseList    用逆邻接表表示的图
  * @param[out]   latestTime    事件允许的最迟发生时间
  * @return    是否成功
  */
int eventLatestTime(GraphInverseList *graphInverseList, int* latestTime);

/**
  * @brief  关键路径
  * @param[in]   graphList 用邻接表表示的图   
  * @param[in]   graphInverseList    用逆邻接表表示的图
  */
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList);

#endif