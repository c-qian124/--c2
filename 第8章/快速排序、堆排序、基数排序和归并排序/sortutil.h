#ifndef SORTSTRUCT_H
#define SORTSTRUCT_H
typedef int KeyType; //关键字的数据类型
typedef int InfoType; //其余数据信息的数据类型
//待排序记录的数据类型
typedef struct	RECORDTYPE_STRU{
	KeyType key;// 关键字 
	InfoType otherInfo;//其余数据信息 
}RecordType;
//存放多个待排序数据的结构体。需要进行空间分配的一维数组
typedef struct	SORTARRAY_STRU{
	int cnt;// 要排序的数组中的元素个数
	RecordType *recordArray;//指向一维数组的指针
}SortArray;
//函数功能：创建用于排序的一维数组
//输入参数num ： 创建的一维数组内包含的元素个数
//返回值：一维数组
SortArray* CreateSortArray(int num);
//函数功能：创建用于排序的一维数组,同时生成随机数放入数组中，为了排序用
//输入参数num :创建的一维数组内包含的元素个数
//输入参数range_min :生成的随机数>=range_min
//输入参数range_max :生成的随机数<range_max
//返回值： 一维数组
SortArray*  CreateSortArrayRandData(int num, 
	int range_min, int range_max);
//函数功能： 输出一维数组中的元素
void PrintSortArray(SortArray* sortArray);
//函数功能：交换一维数组中两个元素的值
//输入参数i：要交换的两个元素下标之一
//输入参数 j:要交换的两个元素下标之一
void  Swap(SortArray* sortArray, int i, int j);
#endif
