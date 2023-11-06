/** 
* @file criticalpath.h
* @brief ͼ�Ĺؼ�·��                                                               
*/
#ifndef CRITICALPATH_H_
#define CRITICALPATH_H_

#include "graphlistutil.h"
#include "graphinverselistutil.h"

/**
  * @brief  �¼����ܵ����緢��ʱ��
  * @param[in]   graphList ���ڽӱ��ʾ��ͼ   
  * @param[out]   earliestTime    �¼����ܵ����緢��ʱ��
  * @return   �Ƿ�ɹ�
  */
int eventEarliestTime(GraphList *graphList, int* earliestTime);

/**
  * @brief  �¼��������ٷ���ʱ��
  * @param[in]   graphInverseList    �����ڽӱ��ʾ��ͼ
  * @param[out]   latestTime    �¼��������ٷ���ʱ��
  * @return    �Ƿ�ɹ�
  */
int eventLatestTime(GraphInverseList *graphInverseList, int* latestTime);

/**
  * @brief  �ؼ�·��
  * @param[in]   graphList ���ڽӱ��ʾ��ͼ   
  * @param[in]   graphInverseList    �����ڽӱ��ʾ��ͼ
  */
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList);

#endif