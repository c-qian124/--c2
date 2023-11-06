#include "sort.h"
//函数功能：快速排序，升序
void QuickSort(SortArray* sortArray, int left, int right){
	int i,j;
	KeyType temp;
	if (left >= right) //只有一个记录无需排序
		return;
	i = left;
	j = right;
	temp = sortArray->recordArray[i].key; //将最左边的元素做为基准
	while(i != j) {//寻找基准应存放的最终位置
		//从右向左扫描
		while(sortArray->recordArray[j].key >= temp  && j > i)
			j--;
		//如果arr[j]<temp
		if (i < j) {
			sortArray->recordArray[i].key = sortArray->recordArray[j].key;
			i++;
		}
		else
			break;
		//从左向右扫描
		while(sortArray->recordArray[i].key <= temp  && j>i)
			i++;
		//如果arr[i]>temp
		if (i < j){
			sortArray->recordArray[j].key = sortArray->recordArray[i].key;
			j--;
		}
		else
			break;
	}//end while(i != j)
	//找到基准需要存放的位置，此时该位置左边的值都比基准小，右边值比基准大
	sortArray->recordArray[i].key = temp;
	QuickSort(sortArray, left, i-1);
	QuickSort(sortArray, i+1, right);
}
//函数功能：调整构成大根堆
void HeapAdjust(SortArray *sortArray, int father, int size){
	int lchild;
	int rchild;
	int max;
	//将father中的值放到堆中正确的位置上！
	while (father < size){
		lchild = father * 2 + 1;
		rchild = lchild + 1;
		if( lchild >= size)
			break;
		//寻找father,lchild,rchild中最大的
		//若该点不是father，则与father的值做交换！
		max = lchild;
		//右孩子的下标不要越界了！
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
//函数功能：  堆排序，升序
void HeapSort(SortArray *sortArray,int size){
	int i;
	//先要形成堆，从树最下方开始调整
	for(i = size/2 - 1; i >= 0; i--)
		HeapAdjust(sortArray,i,size);
	//每次取树根那个元素跟未排序尾部交换，之后，再重新调整堆。
	//由于是从小往大排序，因此根放最大的*/
	for (i = size - 1; i >= 1; i--){
		Swap(sortArray, 0, i); //交换
		//重新调整一个元素的位置就可以了（刚调整到树根位置的那个值）
		HeapAdjust(sortArray, 0, i);
	}
}
//函数功能：基数排序
void RadixSort(SortArray* record){
	int i,j;
	int maxValue = record->recordArray[0].key;
	int maxDigit = 0;
	//record->cnt个桶，这里类型跟等待排序数据类型一样，方便数据移动
	RecordType *bucket = (RecordType*)malloc(sizeof(RecordType)*record->cnt);
	//保存每个桶中存放数据个数，因此个数也是record->cnt个
	int *count = (int*)malloc(sizeof(int)*record->cnt);
	//为了节约时间，不重复计算，需要保存每个待排序数据当前排序位的值
	int *nowDigit = (int*)malloc(sizeof(int)*record->cnt);
	//用于方便截取每位值的，假设等待排序的数据最大不超过5位数
	int divider[5]={1,10,100,1000,10000};
	for (i=0;i<record->cnt;i++){	
		//1、获取等待排序序列中最大值的位数，比如78是两位数
		//这个数值用于后续分配收集的次数
		//先求最大值
		if (record->recordArray[i].key > maxValue)
			maxValue = record->recordArray[i].key;
		//初始化count数组，所有元素设置为0，方便后面累加
		count[i] = 0;
	}//end for (i=0;i<record->cnt;i++)
	//计算这个最大值的位数
	while(maxValue != 0){
		maxValue = maxValue/10;
		maxDigit++;
	}
	//2、进行分配收集工作，需要循环maxDigit次
	//从右往左进行处理
	for (i=0; i<maxDigit; i++){
		for (j=0; j<record->cnt; j++){
			//计算待排序数据，当前排序位数上的值
			nowDigit[j] = (record->recordArray[j].key /divider[i])%10;
			//清空统计桶中数据个数的count数组
			count[j] = 0;
		}
		//循环访问nowDigit数组中的每个元素，初步计算count数组的值
		//做完这一步count数组存放的是每个桶中的数据个数
		for (j=0; j<record->cnt; j++)
			count[nowDigit[j]]++;
		//最终count数组应该是元素放入桶中后，每个桶的右边界索引
		//因此还需要更新计算
		for (j=1; j<record->cnt; j++)
			count[j] = count[j-1]+count[j];
		//将数据依次放入桶中
		//这里需要从右向左扫描，先入桶的，先出来
		for (j=record->cnt-1; j>=0; j--){
			bucket[count[nowDigit[j]]-1] = record->recordArray[j];
			count[nowDigit[j]]--;
		}//end for (j=0; j<record->cnt; j++)
		//3、把桶里面的数据放回原来的数组，为下一轮基数排序准备
		for (j=0; j<record->cnt; j++)
			record->recordArray[j] = bucket[j];
	}//end for (i=0; i<maxDigit; i++)
}
//函数功能：  合并两个有序序列
void Merge(SortArray* sortArray, SortArray *sortArray1,
	int low, int m, int high) {
		// 有序文件1
		// sortArray->recordArray[low]到sortArray->recordArray[m] 
		//有序文件2：
		//sortArray->recordArray[m+1]到sortArray->recordArray[high]
		int i,j,k;
		i=low;
		j=m+1;  
		k=low;
		while( (i<=m) && (j<=high) ) {  
			//从两个有序文件中的第一个记录中选出小的记录，放入结果序列中 
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
		//复制第一个文件的剩余记录，到结果序列
		while (i <= m)  {
			sortArray1->recordArray[k].key = sortArray->recordArray[i].key;	     k++;
			i++;
		}
		//复制第二个文件的剩余记录，到结果序列
		while (j <= high)  {
			sortArray1->recordArray[k].key = sortArray->recordArray[j].key;	     k++;
			j++;
		}
}
//函数功能：一趟归并，结果放r1中 ， length为本趟归并的有序子文件的长度 
void MergePass(SortArray *sortArray, SortArray *sortArray1,
	int n, int length){	
		int j,  i=0;
		// 归并长度为length的两个子文件
		while(i + 2 * length - 1 < n)  {
			Merge(sortArray, sortArray1, i, i+length-1, i+2*length-1);
			i += 2*length;
		}//end while(i+2*length-1<n)
		//假如剩下两个子文件，其中一个长度小于 length 
		if(i+length-1 < n-1)  
			Merge(sortArray, sortArray1, i, i+length-1, n-1);
		else{	
			// 假如只剩下一个子文件，则将最后一个子文件复制到数组r1中
			for(j=i; j<n; j++){
				sortArray1->recordArray[j].key = sortArray->recordArray[j].key;
			}
		}//end if(i+length-1<n-1) 
}
//函数功能：二路归并排序
void MergeSort(SortArray* record, int num){
	SortArray *record1 = CreateSortArray(num);
	int length =1;
	while(length < num){
		//一趟归并，结果放在record1中
		MergePass(record, record1, num, length);	
		length *= 2;
		//一趟归并，结果放在record中 
		MergePass(record1, record, num, length);	
		length *= 2;
	}
}
