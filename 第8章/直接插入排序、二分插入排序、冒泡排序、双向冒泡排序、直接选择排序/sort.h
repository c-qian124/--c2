#ifndef SORT_H_
#define SORT_H_
#include "sortutil.h"
//�������ܣ�ֱ�Ӳ�������
//������� sortArray  ��  Ҫ���������
void InsertSort(SortArray* sortArray);
//�������ܣ����ֲ�������
//�������sortArray ��   Ҫ���������
void BinSort(SortArray* sortArray);
//�������ܣ� ð����������
//�������sortArray  ��  ���ڽ��������һά����
void BubbleSort(SortArray* sortArray);
//�������ܣ� ˫��ð����������
//������� sortArray  ��  ���ڽ��������һά����
void BidBubbleSort(SortArray* sortArray);
//�������ܣ�ֱ��ѡ������
//�������  sortArray ��   Ҫ���������
void  SelectSort(SortArray *sortArray);
#endif
