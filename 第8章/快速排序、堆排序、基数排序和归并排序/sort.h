#ifndef SORT_H_
#define SORT_H_
#include "sortutil.h"
//函数功能：快速排序，升序
//输入参数 sortArray ：   用于进行排序的一维数组
//输入参数 left ：   数组左边下标
//输入参数  right ：   数组右边下标
void QuickSort(SortArray* sortArray, int left, int right);
//函数功能：  堆排序，升序
//输入参数 sortArray  ：  用于进行排序的一维数组
//输入参数 size  ：  数组长度
void HeapSort(SortArray *sortArray,int size);
//函数功能：基数排序
//输入参数sortArray  ：  要排序的数组
void RadixSort(SortArray* record);
//函数功能：二路归并排序
//输入参数 sortArray  ：  要排序的数组
//输入参数  num  ：  要排序的序列长度
void MergeSort(SortArray* record, int num);
#endif
