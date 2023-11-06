#ifndef SORT_H_
#define SORT_H_
#include "sortutil.h"
//�������ܣ�������������
//������� sortArray ��   ���ڽ��������һά����
//������� left ��   ��������±�
//�������  right ��   �����ұ��±�
void QuickSort(SortArray* sortArray, int left, int right);
//�������ܣ�  ����������
//������� sortArray  ��  ���ڽ��������һά����
//������� size  ��  ���鳤��
void HeapSort(SortArray *sortArray,int size);
//�������ܣ���������
//�������sortArray  ��  Ҫ���������
void RadixSort(SortArray* record);
//�������ܣ���·�鲢����
//������� sortArray  ��  Ҫ���������
//�������  num  ��  Ҫ��������г���
void MergeSort(SortArray* record, int num);
#endif
