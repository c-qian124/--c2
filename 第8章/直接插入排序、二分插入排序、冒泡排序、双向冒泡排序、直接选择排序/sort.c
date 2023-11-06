#include "sort.h"
//函数功能：直接插入排序
void InsertSort(SortArray* sortArray){ 
	int i, j;
	RecordType temp;
	for( i = 1; i < sortArray->cnt; i++ ) { 
		//j为认为已经排好顺序的数据最后一个元素下标
		j = i-1;
		//等待插入的数据temp
		temp = sortArray->recordArray[i];
		//从j位置开始，从后向前在已经排好顺序的序列中找到插入位置
		while(temp.key < sortArray->recordArray[j].key && j>=0){
			sortArray->recordArray[j+1] = sortArray->recordArray[j];
			j--;
		}
		//找到待插入位置为j+1
		//如果待插入位置正好就是要插入元素所在位置则可以不进行数据赋值
		if( j+1 != i ) {
			sortArray->recordArray[j+1] = temp;
		}
	}//end for( i = 1; i < sortArray->cnt; i++ ) 
}
//函数功能：二分插入排序
void BinSort(SortArray* sortArray){     
	int i, j;
	int left, mid, right;
	RecordType temp;
	for( i = 1; i < sortArray->cnt; i++ ) {
		temp = sortArray->recordArray[i];
		//二分查找法查找插入位置
		left = 0;  
		right = i-1;  
		while (left <= right) {
			mid = (left + right)/2;      
			if (temp.key < sortArray->recordArray[mid].key)
				right = mid-1;           
			else 
				left = mid+1;            
		}//end while (left <= right) 
		//如果待插入数据正好在还要插入的位置上就不需要插入了
		if (left != i){
			//如果需要挪动数据，空出位置，插入数据
			//找到插入位置后，移动数据，空出地方给数据插入
			for (j = i-1;  j >= left;  j--){
				sortArray->recordArray[j+1] = sortArray->recordArray[j];          
			}
			sortArray->recordArray[left] = temp; //插入数据
		}
	}//end for( i = 1; i < sortArray->cnt; i++ ) 
}
//函数功能： 冒泡排序，升序
void BubbleSort(SortArray* sortArray){
	int i,j; // 循环变量 
	for(i = 1; i < sortArray->cnt ; i++){
		//注意j是从后往前循环 ,数组的下标是0到cnt-1
		for(j = sortArray->cnt - 1; j >= i; j--)  {
			//若前者大于后者
			if(sortArray->recordArray[j-1].key > sortArray->recordArray[j].key) {
				Swap(sortArray, j, j-1); //交换 
			}
		}//end for(j = sortArray->cnt - 1; j >= i; j--)
	}//end for(i = 1; i < sortArray->cnt ; i++)
}
//函数功能： 双向冒泡排序，升序
void BidBubbleSort(SortArray* sortArray){
	int left, right, l, r;
	int j;
	left = 0;
	right = sortArray->cnt -1;
	//双向冒泡算法，能减少循环排序的次数 
	while(left < right){
		l = left + 1;
		r = right - 1;
		//第一次循环将最大的值放到末尾 
		for(j = left; j < right; j++){
			if(sortArray->recordArray[j].key > sortArray->recordArray[j + 1].key){
				Swap(sortArray, j, j+1);
				r = j;
			}
		}//end for(j = left; j < right; j++)
		right = r;

		//第二次循环将最小的值放到开头
		for(j = right; j > left; j--){
			if(sortArray->recordArray[j].key < sortArray->recordArray[j - 1].key){
				Swap(sortArray,j, j-1);
				l = j;
			}
		}//end for(j = right; j > left; j--)
		left = l;
	}//end while(left < right)
}
//函数功能：直接选择排序
void  SelectSort(SortArray *sortArray){
	int i, j;
	int minPos;
	// 做n-1趟选择排序 
	for( i = 0; i < sortArray->cnt-1; i++ ) {  
		minPos= i;
		//在无序区中寻找，记录下最小的值所在的数组下标
		for (j = i+1; j < sortArray->cnt; j++) {
			if (sortArray->recordArray[j].key < sortArray->recordArray[minPos].key){
				minPos = j;
			}
		}//end for (j = i+1; j < sortArray->cnt; j++)
		//如果需要交换再进行数据交换
		if (minPos != i)  
			Swap(sortArray, minPos, i); 
	}//end for( i = 0; i < sortArray->cnt-1; i++ ) 
}
