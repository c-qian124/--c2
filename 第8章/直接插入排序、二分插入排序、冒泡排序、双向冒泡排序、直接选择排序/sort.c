#include "sort.h"
//�������ܣ�ֱ�Ӳ�������
void InsertSort(SortArray* sortArray){ 
	int i, j;
	RecordType temp;
	for( i = 1; i < sortArray->cnt; i++ ) { 
		//jΪ��Ϊ�Ѿ��ź�˳����������һ��Ԫ���±�
		j = i-1;
		//�ȴ����������temp
		temp = sortArray->recordArray[i];
		//��jλ�ÿ�ʼ���Ӻ���ǰ���Ѿ��ź�˳����������ҵ�����λ��
		while(temp.key < sortArray->recordArray[j].key && j>=0){
			sortArray->recordArray[j+1] = sortArray->recordArray[j];
			j--;
		}
		//�ҵ�������λ��Ϊj+1
		//���������λ�����þ���Ҫ����Ԫ������λ������Բ��������ݸ�ֵ
		if( j+1 != i ) {
			sortArray->recordArray[j+1] = temp;
		}
	}//end for( i = 1; i < sortArray->cnt; i++ ) 
}
//�������ܣ����ֲ�������
void BinSort(SortArray* sortArray){     
	int i, j;
	int left, mid, right;
	RecordType temp;
	for( i = 1; i < sortArray->cnt; i++ ) {
		temp = sortArray->recordArray[i];
		//���ֲ��ҷ����Ҳ���λ��
		left = 0;  
		right = i-1;  
		while (left <= right) {
			mid = (left + right)/2;      
			if (temp.key < sortArray->recordArray[mid].key)
				right = mid-1;           
			else 
				left = mid+1;            
		}//end while (left <= right) 
		//������������������ڻ�Ҫ�����λ���ϾͲ���Ҫ������
		if (left != i){
			//�����ҪŲ�����ݣ��ճ�λ�ã���������
			//�ҵ�����λ�ú��ƶ����ݣ��ճ��ط������ݲ���
			for (j = i-1;  j >= left;  j--){
				sortArray->recordArray[j+1] = sortArray->recordArray[j];          
			}
			sortArray->recordArray[left] = temp; //��������
		}
	}//end for( i = 1; i < sortArray->cnt; i++ ) 
}
//�������ܣ� ð����������
void BubbleSort(SortArray* sortArray){
	int i,j; // ѭ������ 
	for(i = 1; i < sortArray->cnt ; i++){
		//ע��j�ǴӺ���ǰѭ�� ,������±���0��cnt-1
		for(j = sortArray->cnt - 1; j >= i; j--)  {
			//��ǰ�ߴ��ں���
			if(sortArray->recordArray[j-1].key > sortArray->recordArray[j].key) {
				Swap(sortArray, j, j-1); //���� 
			}
		}//end for(j = sortArray->cnt - 1; j >= i; j--)
	}//end for(i = 1; i < sortArray->cnt ; i++)
}
//�������ܣ� ˫��ð����������
void BidBubbleSort(SortArray* sortArray){
	int left, right, l, r;
	int j;
	left = 0;
	right = sortArray->cnt -1;
	//˫��ð���㷨���ܼ���ѭ������Ĵ��� 
	while(left < right){
		l = left + 1;
		r = right - 1;
		//��һ��ѭ��������ֵ�ŵ�ĩβ 
		for(j = left; j < right; j++){
			if(sortArray->recordArray[j].key > sortArray->recordArray[j + 1].key){
				Swap(sortArray, j, j+1);
				r = j;
			}
		}//end for(j = left; j < right; j++)
		right = r;

		//�ڶ���ѭ������С��ֵ�ŵ���ͷ
		for(j = right; j > left; j--){
			if(sortArray->recordArray[j].key < sortArray->recordArray[j - 1].key){
				Swap(sortArray,j, j-1);
				l = j;
			}
		}//end for(j = right; j > left; j--)
		left = l;
	}//end while(left < right)
}
//�������ܣ�ֱ��ѡ������
void  SelectSort(SortArray *sortArray){
	int i, j;
	int minPos;
	// ��n-1��ѡ������ 
	for( i = 0; i < sortArray->cnt-1; i++ ) {  
		minPos= i;
		//����������Ѱ�ң���¼����С��ֵ���ڵ������±�
		for (j = i+1; j < sortArray->cnt; j++) {
			if (sortArray->recordArray[j].key < sortArray->recordArray[minPos].key){
				minPos = j;
			}
		}//end for (j = i+1; j < sortArray->cnt; j++)
		//�����Ҫ�����ٽ������ݽ���
		if (minPos != i)  
			Swap(sortArray, minPos, i); 
	}//end for( i = 0; i < sortArray->cnt-1; i++ ) 
}
