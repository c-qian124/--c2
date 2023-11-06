#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortutil.h"
// �������������һά����
SortArray* CreateSortArray(int num) {
	SortArray *sortArray = (SortArray*)malloc(sizeof(SortArray));
	sortArray->cnt = num;
	sortArray->recordArray 
		= (RecordType *)malloc(sizeof(RecordType) * sortArray->cnt);
	return sortArray;
}
// �������������һά����,ͬʱ�������������������
SortArray*  CreateSortArrayRandData(int num, int range_min, int range_max){
	int i;
	//����ռ䣬����ֵ 
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
// ���һά�����е�Ԫ��
void PrintSortArray(SortArray* sortArray){
	int i = 0;
	for (i = 0; i < sortArray->cnt; i++){
		if (i%10 == 0){ // 10��Ԫ�أ���һ��
			printf("\n");
		}
		printf("%d\t", sortArray->recordArray[i]);
	}
	printf("\n");
}
// ����һά����������Ԫ�ص�ֵ
void  Swap(SortArray* sortArray, int i, int j){
	KeyType temp;
	temp = sortArray->recordArray[i].key;
	sortArray->recordArray[i].key= sortArray->recordArray[j].key;
	sortArray->recordArray[j].key = temp;
}
