#include "sort.h"
//�������ܣ�������������
void QuickSort(SortArray* sortArray, int left, int right){
	int i,j;
	KeyType temp;
	if (left >= right) //ֻ��һ����¼��������
		return;
	i = left;
	j = right;
	temp = sortArray->recordArray[i].key; //������ߵ�Ԫ����Ϊ��׼
	while(i != j) {//Ѱ�һ�׼Ӧ��ŵ�����λ��
		//��������ɨ��
		while(sortArray->recordArray[j].key >= temp  && j > i)
			j--;
		//���arr[j]<temp
		if (i < j) {
			sortArray->recordArray[i].key = sortArray->recordArray[j].key;
			i++;
		}
		else
			break;
		//��������ɨ��
		while(sortArray->recordArray[i].key <= temp  && j>i)
			i++;
		//���arr[i]>temp
		if (i < j){
			sortArray->recordArray[j].key = sortArray->recordArray[i].key;
			j--;
		}
		else
			break;
	}//end while(i != j)
	//�ҵ���׼��Ҫ��ŵ�λ�ã���ʱ��λ����ߵ�ֵ���Ȼ�׼С���ұ�ֵ�Ȼ�׼��
	sortArray->recordArray[i].key = temp;
	QuickSort(sortArray, left, i-1);
	QuickSort(sortArray, i+1, right);
}
//�������ܣ��������ɴ����
void HeapAdjust(SortArray *sortArray, int father, int size){
	int lchild;
	int rchild;
	int max;
	//��father�е�ֵ�ŵ�������ȷ��λ���ϣ�
	while (father < size){
		lchild = father * 2 + 1;
		rchild = lchild + 1;
		if( lchild >= size)
			break;
		//Ѱ��father,lchild,rchild������
		//���õ㲻��father������father��ֵ��������
		max = lchild;
		//�Һ��ӵ��±겻ҪԽ���ˣ�
		if(rchild < size 
			&&  sortArray->recordArray[rchild].key 
		> sortArray->recordArray[lchild].key)
		max = rchild;
		if (sortArray->recordArray[father].key 
			< sortArray->recordArray[max].key){
				Swap(sortArray, father, max);
				father = max;
		}
		else
			break;
	}//end while (father < size)
}
//�������ܣ�  ����������
void HeapSort(SortArray *sortArray,int size){
	int i;
	//��Ҫ�γɶѣ��������·���ʼ����
	for(i = size/2 - 1; i >= 0; i--)
		HeapAdjust(sortArray,i,size);
	//ÿ��ȡ�����Ǹ�Ԫ�ظ�δ����β��������֮�������µ����ѡ�
	//�����Ǵ�С����������˸�������*/
	for (i = size - 1; i >= 1; i--){
		Swap(sortArray, 0, i); //����
		//���µ���һ��Ԫ�ص�λ�þͿ����ˣ��յ���������λ�õ��Ǹ�ֵ��
		HeapAdjust(sortArray, 0, i);
	}
}
//�������ܣ���������
void RadixSort(SortArray* record){
	int i,j;
	int maxValue = record->recordArray[0].key;
	int maxDigit = 0;
	//record->cnt��Ͱ���������͸��ȴ�������������һ�������������ƶ�
	RecordType *bucket = (RecordType*)malloc(sizeof(RecordType)*record->cnt);
	//����ÿ��Ͱ�д�����ݸ�������˸���Ҳ��record->cnt��
	int *count = (int*)malloc(sizeof(int)*record->cnt);
	//Ϊ�˽�Լʱ�䣬���ظ����㣬��Ҫ����ÿ�����������ݵ�ǰ����λ��ֵ
	int *nowDigit = (int*)malloc(sizeof(int)*record->cnt);
	//���ڷ����ȡÿλֵ�ģ�����ȴ������������󲻳���5λ��
	int divider[5]={1,10,100,1000,10000};
	for (i=0;i<record->cnt;i++){	
		//1����ȡ�ȴ��������������ֵ��λ��������78����λ��
		//�����ֵ���ں��������ռ��Ĵ���
		//�������ֵ
		if (record->recordArray[i].key > maxValue)
			maxValue = record->recordArray[i].key;
		//��ʼ��count���飬����Ԫ������Ϊ0����������ۼ�
		count[i] = 0;
	}//end for (i=0;i<record->cnt;i++)
	//����������ֵ��λ��
	while(maxValue != 0){
		maxValue = maxValue/10;
		maxDigit++;
	}
	//2�����з����ռ���������Ҫѭ��maxDigit��
	//����������д���
	for (i=0; i<maxDigit; i++){
		for (j=0; j<record->cnt; j++){
			//������������ݣ���ǰ����λ���ϵ�ֵ
			nowDigit[j] = (record->recordArray[j].key /divider[i])%10;
			//���ͳ��Ͱ�����ݸ�����count����
			count[j] = 0;
		}
		//ѭ������nowDigit�����е�ÿ��Ԫ�أ���������count�����ֵ
		//������һ��count�����ŵ���ÿ��Ͱ�е����ݸ���
		for (j=0; j<record->cnt; j++)
			count[nowDigit[j]]++;
		//����count����Ӧ����Ԫ�ط���Ͱ�к�ÿ��Ͱ���ұ߽�����
		//��˻���Ҫ���¼���
		for (j=1; j<record->cnt; j++)
			count[j] = count[j-1]+count[j];
		//���������η���Ͱ��
		//������Ҫ��������ɨ�裬����Ͱ�ģ��ȳ���
		for (j=record->cnt-1; j>=0; j--){
			bucket[count[nowDigit[j]]-1] = record->recordArray[j];
			count[nowDigit[j]]--;
		}//end for (j=0; j<record->cnt; j++)
		//3����Ͱ��������ݷŻ�ԭ�������飬Ϊ��һ�ֻ�������׼��
		for (j=0; j<record->cnt; j++)
			record->recordArray[j] = bucket[j];
	}//end for (i=0; i<maxDigit; i++)
}
//�������ܣ�  �ϲ�������������
void Merge(SortArray* sortArray, SortArray *sortArray1,
	int low, int m, int high) {
		// �����ļ�1
		// sortArray->recordArray[low]��sortArray->recordArray[m] 
		//�����ļ�2��
		//sortArray->recordArray[m+1]��sortArray->recordArray[high]
		int i,j,k;
		i=low;
		j=m+1;  
		k=low;
		while( (i<=m) && (j<=high) ) {  
			//�����������ļ��еĵ�һ����¼��ѡ��С�ļ�¼�������������� 
			if(sortArray->recordArray[i].key 
				<= sortArray->recordArray[j].key)	{
					sortArray1->recordArray[k].key = sortArray->recordArray[i].key;
					k++;
					i++;
			}
			else  {
				sortArray1->recordArray[k].key = sortArray->recordArray[j].key;
				k++;
				j++;
			}
		}//end 	while( (i<=m) && (j<=high) ) 
		//���Ƶ�һ���ļ���ʣ���¼�����������
		while (i <= m)  {
			sortArray1->recordArray[k].key = sortArray->recordArray[i].key;	     k++;
			i++;
		}
		//���Ƶڶ����ļ���ʣ���¼�����������
		while (j <= high)  {
			sortArray1->recordArray[k].key = sortArray->recordArray[j].key;	     k++;
			j++;
		}
}
//�������ܣ�һ�˹鲢�������r1�� �� lengthΪ���˹鲢���������ļ��ĳ��� 
void MergePass(SortArray *sortArray, SortArray *sortArray1,
	int n, int length){	
		int j,  i=0;
		// �鲢����Ϊlength���������ļ�
		while(i + 2 * length - 1 < n)  {
			Merge(sortArray, sortArray1, i, i+length-1, i+2*length-1);
			i += 2*length;
		}//end while(i+2*length-1<n)
		//����ʣ���������ļ�������һ������С�� length 
		if(i+length-1 < n-1)  
			Merge(sortArray, sortArray1, i, i+length-1, n-1);
		else{	
			// ����ֻʣ��һ�����ļ��������һ�����ļ����Ƶ�����r1��
			for(j=i; j<n; j++){
				sortArray1->recordArray[j].key = sortArray->recordArray[j].key;
			}
		}//end if(i+length-1<n-1) 
}
//�������ܣ���·�鲢����
void MergeSort(SortArray* record, int num){
	SortArray *record1 = CreateSortArray(num);
	int length =1;
	while(length < num){
		//һ�˹鲢���������record1��
		MergePass(record, record1, num, length);	
		length *= 2;
		//һ�˹鲢���������record�� 
		MergePass(record1, record, num, length);	
		length *= 2;
	}
}
