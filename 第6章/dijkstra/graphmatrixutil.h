/** 
* @file graphmatrixutil.h
* @brief ͼ���ڽӾ����ʾ�Լ���������                                                               
*/

#ifndef GRAPHMATRIXUTIL_H_
#define GRAPHMATRIXUTIL_H_

/**
 * @brief ͼ���ڽӾ����ʾ
 */
typedef struct	GRAPHMATRIX_STRU
{
	int size;/*!< ͼ�н��ĸ��� */
	int **graph;/*!<��ά���鱣��ͼ */
}GraphMatrix;

/**
  * @brief  ��ʼ��ͼ
  * @param[in]   num    ͼ�н��ĸ���
  * @return    ���ڽӾ����ʾ��ͼ
  */
GraphMatrix* InitGraph(int num);

/**
  * @brief  �����ݶ���ͼ��
  * @param[in]   graphMatrix    ͼ
  */
void ReadGraph(GraphMatrix* graphMatrix);

/**
  * @brief  ��ͼ�Ľṹ��ʾ����
  * @param[in]   graphMatrix    ͼ
  */
void WriteGraph(GraphMatrix* graphMatrix);

#endif

