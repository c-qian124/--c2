#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>  
#include "sort.h"
int main(){
	int i; 
	int MAXNUM ;
	SortArray* myArrayRand = NULL; // ����������
	SortArray* arrBubbleSort = NULL;//ð������
	SortArray* arrBidBubbleSort = NULL;//˫��ð������
	SortArray* arrSelectSort = NULL;//ѡ������
	SortArray* arrInsertSort = NULL;//��������
	SortArray* arrBinSort = NULL;
	srand( (unsigned)time( NULL ) );  
	printf("�������������ݵĶ��٣�");
	scanf("%d", &MAXNUM);
	// ��������Ҫ������ݵ��������ռ�
	myArrayRand= CreateSortArrayRandData(MAXNUM, 0, 500);
	arrBubbleSort	= CreateSortArray(MAXNUM);
	arrBidBubbleSort = CreateSortArray(MAXNUM);	
	arrSelectSort = CreateSortArray(MAXNUM);
	arrInsertSort = CreateSortArray(MAXNUM);
	arrBinSort = CreateSortArray(MAXNUM);
	//�������ݣ�ʹҪ���������Ϊͬһϵ�������
	for (i = 0; i < MAXNUM; i++){
		arrBubbleSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrBidBubbleSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrSelectSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrInsertSort->recordArray[i].key = myArrayRand->recordArray[i].key;
		arrBinSort->recordArray[i].key = myArrayRand->recordArray[i].key;
	}
	printf("����ǰ��\n");
	PrintSortArray(myArrayRand);
	//ð������
	BubbleSort(arrBubbleSort);
	printf("ð�������\n");
	PrintSortArray(arrBubbleSort);
	//˫��ð������
	BidBubbleSort(arrBidBubbleSort);
	printf("˫��ð�������\n");
	PrintSortArray(arrBidBubbleSort);
	//ֱ��ѡ������
	SelectSort(arrSelectSort);
	printf("ֱ��ѡ�������\n");
	PrintSortArray(arrSelectSort);
	//ֱ�Ӳ�������
	InsertSort(arrInsertSort);
	printf("ֱ�Ӳ��������\n");
	PrintSortArray(arrInsertSort);
	//���ֲ�������
	BinSort(arrBinSort);
	printf("���ֲ��������\n");
	PrintSortArray(arrBinSort);
	return 0;
}
