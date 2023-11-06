#ifndef SORT_H_
#define SORT_H_
#include "sortutil.h"
//函数功能：直接插入排序
//输入参数 sortArray  ：  要排序的数组
void InsertSort(SortArray* sortArray);
//函数功能：二分插入排序
//输入参数sortArray ：   要排序的数组
void BinSort(SortArray* sortArray);
//函数功能： 冒泡排序，升序
//输入参数sortArray  ：  用于进行排序的一维数组
void BubbleSort(SortArray* sortArray);
//函数功能： 双向冒泡排序，升序
//输入参数 sortArray  ：  用于进行排序的一维数组
void BidBubbleSort(SortArray* sortArray);
//函数功能：直接选择排序
//输入参数  sortArray ：   要排序的数组
void  SelectSort(SortArray *sortArray);
#endif
