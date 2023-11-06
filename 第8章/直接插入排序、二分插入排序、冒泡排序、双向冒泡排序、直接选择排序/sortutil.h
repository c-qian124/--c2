#ifndef SORTSTRUCT_H
#define SORTSTRUCT_H
typedef int KeyType; //�ؼ��ֵ���������
typedef int InfoType; //����������Ϣ����������
//�������¼����������
typedef struct	RECORDTYPE_STRU{
	KeyType key;// �ؼ��� 
	InfoType otherInfo;//����������Ϣ 
}RecordType;
//��Ŷ�����������ݵĽṹ�塣��Ҫ���пռ�����һά����
typedef struct	SORTARRAY_STRU{
	int cnt;// Ҫ����������е�Ԫ�ظ���
	RecordType *recordArray;//ָ��һά�����ָ��
}SortArray;
//�������ܣ��������������һά����
//�������num �� ������һά�����ڰ�����Ԫ�ظ���
//����ֵ��һά����
SortArray* CreateSortArray(int num);
//�������ܣ��������������һά����,ͬʱ������������������У�Ϊ��������
//�������num :������һά�����ڰ�����Ԫ�ظ���
//�������range_min :���ɵ������>=range_min
//�������range_max :���ɵ������<range_max
//����ֵ�� һά����
SortArray*  CreateSortArrayRandData(int num, 
	int range_min, int range_max);
//�������ܣ� ���һά�����е�Ԫ��
void PrintSortArray(SortArray* sortArray);
//�������ܣ�����һά����������Ԫ�ص�ֵ
//�������i��Ҫ����������Ԫ���±�֮һ
//������� j:Ҫ����������Ԫ���±�֮һ
void  Swap(SortArray* sortArray, int i, int j);
#endif
