#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>  
#include "sort.h"
int main(){
	int i;
	int MAXNUM ;
	SortArray* myArrayRand = NULL; // ���������� 
	SortArray* arrQuickSort = NULL;
	SortArray* arrHeapSort = NULL;
	SortArray* arrMergeSort = NULL;
	SortArray* arrRadixSort = NULL;
	srand( (unsigned)time( NULL ) );  
	printf("�������������ݵĶ��٣�");
	scanf("%d", &MAXNUM);
	// ��������Ҫ������ݵ��������ռ�
	myArrayRand= CreateSortArrayRandData(MAXNUM, 0, 500);
	arrQuickSort = CreateSortArray(MAXNUM);	
	arrHeapSort = CreateSortArray(MAXNUM);
	arrMergeSort = CreateSortArray(MAXNUM);
	arrRadixSort = CreateSortArray(MAXNUM);
	//�������ݣ�ʹҪ���������Ϊ�����
	for (i = 0; i < MAXNUM; i++){
		arrQuickSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrHeapSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrMergeSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrRadixSort->recordArray[i].key = myArrayRand->recordArray[i].key;
	}
	printf("����ǰ��\n");
	PrintSortArray(myArrayRand);
	//������
	HeapSort(arrHeapSort, MAXNUM);
	printf("�������\n");
	PrintSortArray(arrHeapSort);
	//�鲢����
	MergeSort(arrMergeSort, MAXNUM);
	printf("�鲢�����\n");
	PrintSortArray(arrMergeSort);
	//��������
	RadixSort(arrRadixSort);
	printf("���������\n");
	PrintSortArray(arrRadixSort);
	//��������
	QuickSort(arrQuickSort, 0, MAXNUM -1 );
	printf("���������\n");
	PrintSortArray(arrQuickSort);
	return 0;
}
