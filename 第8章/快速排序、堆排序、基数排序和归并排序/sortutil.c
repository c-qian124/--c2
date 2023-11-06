#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortutil.h"
// 创建用于排序的一维数组
SortArray* CreateSortArray(int num) {
	SortArray *sortArray = (SortArray*)malloc(sizeof(SortArray));
	sortArray->cnt = num;
	sortArray->recordArray 
		= (RecordType *)malloc(sizeof(RecordType) * sortArray->cnt);
	return sortArray;
}
// 创建用于排序的一维数组,同时生成随机数放入数组中
SortArray*  CreateSortArrayRandData(int num, int range_min, int range_max){
	int i;
	//分配空间，并赋值 
	SortArray *sortArray = (SortArray*)malloc(sizeof(SortArray));
	sortArray->cnt = num;
	sortArray->recordArray 
		= (RecordType *)malloc(sizeof(RecordType) * sortArray->cnt);
	srand( (unsigned)time( NULL ) );
	for (i = 0; i <sortArray->cnt; i++){
		sortArray->recordArray[i].key = range_min
			+(double)rand()/(RAND_MAX+1)*(range_max-range_min);
	}//end for (i = 0; i <sortArray->cnt; i++){
	return sortArray;
}
// 输出一维数组中的元素
void PrintSortArray(SortArray* sortArray){
	int i = 0;
	for (i = 0; i < sortArray->cnt; i++){
		if (i%10 == 0){ // 10个元素，换一行
			printf("\n");
		}
		printf("%d\t", sortArray->recordArray[i]);
	}
	printf("\n");
}
// 交换一维数组中两个元素的值
void  Swap(SortArray* sortArray, int i, int j){
	KeyType temp;
	temp = sortArray->recordArray[i].key;
	sortArray->recordArray[i].key= sortArray->recordArray[j].key;
	sortArray->recordArray[j].key = temp;
}
