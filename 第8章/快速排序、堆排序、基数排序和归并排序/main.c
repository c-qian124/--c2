#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>  
#include "sort.h"
int main(){
	int i;
	int MAXNUM ;
	SortArray* myArrayRand = NULL; // 辅助的数据 
	SortArray* arrQuickSort = NULL;
	SortArray* arrHeapSort = NULL;
	SortArray* arrMergeSort = NULL;
	SortArray* arrRadixSort = NULL;
	srand( (unsigned)time( NULL ) );  
	printf("请输入排序数据的多少：");
	scanf("%d", &MAXNUM);
	// 给各个需要存放数据的数组分配空间
	myArrayRand= CreateSortArrayRandData(MAXNUM, 0, 500);
	arrQuickSort = CreateSortArray(MAXNUM);	
	arrHeapSort = CreateSortArray(MAXNUM);
	arrMergeSort = CreateSortArray(MAXNUM);
	arrRadixSort = CreateSortArray(MAXNUM);
	//复制数据，使要排序的数据为随机数
	for (i = 0; i < MAXNUM; i++){
		arrQuickSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrHeapSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrMergeSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrRadixSort->recordArray[i].key = myArrayRand->recordArray[i].key;
	}
	printf("排序前：\n");
	PrintSortArray(myArrayRand);
	//堆排序
	HeapSort(arrHeapSort, MAXNUM);
	printf("堆排序后：\n");
	PrintSortArray(arrHeapSort);
	//归并排序
	MergeSort(arrMergeSort, MAXNUM);
	printf("归并排序后：\n");
	PrintSortArray(arrMergeSort);
	//基数排序
	RadixSort(arrRadixSort);
	printf("基数排序后：\n");
	PrintSortArray(arrRadixSort);
	//快速排序
	QuickSort(arrQuickSort, 0, MAXNUM -1 );
	printf("快速排序后：\n");
	PrintSortArray(arrQuickSort);
	return 0;
}
