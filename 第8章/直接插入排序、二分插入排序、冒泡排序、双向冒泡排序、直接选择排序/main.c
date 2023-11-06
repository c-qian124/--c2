#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>  
#include "sort.h"
int main(){
	int i; 
	int MAXNUM ;
	SortArray* myArrayRand = NULL; // 辅助的数据
	SortArray* arrBubbleSort = NULL;//冒泡排序
	SortArray* arrBidBubbleSort = NULL;//双向冒泡排序
	SortArray* arrSelectSort = NULL;//选择排序
	SortArray* arrInsertSort = NULL;//插入排序
	SortArray* arrBinSort = NULL;
	srand( (unsigned)time( NULL ) );  
	printf("请输入排序数据的多少：");
	scanf("%d", &MAXNUM);
	// 给各个需要存放数据的数组分配空间
	myArrayRand= CreateSortArrayRandData(MAXNUM, 0, 500);
	arrBubbleSort	= CreateSortArray(MAXNUM);
	arrBidBubbleSort = CreateSortArray(MAXNUM);	
	arrSelectSort = CreateSortArray(MAXNUM);
	arrInsertSort = CreateSortArray(MAXNUM);
	arrBinSort = CreateSortArray(MAXNUM);
	//复制数据，使要排序的数据为同一系列随机数
	for (i = 0; i < MAXNUM; i++){
		arrBubbleSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrBidBubbleSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrSelectSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrInsertSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrBinSort->recordArray[i].key = myArrayRand->recordArray[i].key;
	}
	printf("排序前：\n");
	PrintSortArray(myArrayRand);
	//冒泡排序
	BubbleSort(arrBubbleSort);
	printf("冒泡排序后：\n");
	PrintSortArray(arrBubbleSort);
	//双向冒泡排序
	BidBubbleSort(arrBidBubbleSort);
	printf("双向冒泡排序后：\n");
	PrintSortArray(arrBidBubbleSort);
	//直接选择排序
	SelectSort(arrSelectSort);
	printf("直接选择排序后：\n");
	PrintSortArray(arrSelectSort);
	//直接插入排序
	InsertSort(arrInsertSort);
	printf("直接插入排序后：\n");
	PrintSortArray(arrInsertSort);
	//二分插入排序
	BinSort(arrBinSort);
	printf("二分插入排序后：\n");
	PrintSortArray(arrBinSort);
	return 0;
}
