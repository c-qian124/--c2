#ifndef OPENADDRESSHASH_H_
#define OPENADDRESSHASH_H_

typedef int KeyType;
typedef char ElementType;

//�����㷨�м������йؼ���key���Ǵ���0������
#define unoccupied -1
#define isdelete  -2

/**
 * @brief hash table�е�һ��Ԫ��
 */
typedef struct	ELEMENT_STRU
{
	KeyType key;//�ؼ���
	ElementType element;//����
}Element;

/**
 * @brief hash table
 */
typedef struct HASHTABLE_STRU
{
	int size;//��ϣ������洢����
	Element *data;//����ռ��Ϊһά����
}HashTable;

/**
  * @brief  ��ϣ����
  * @param[in]   key    �ؼ���
  * @param[in]   size    ��ϣ��ĳ���
  * @return    ��ϣ����λ��
  */
int h(KeyType key, int size);

/**
  * @brief  ������ϣ��
  * @param[in]   num    ���洢�ռ�
  * @return    ��ϣ��
  */
HashTable* CreateHashTable(int num);

/**
  * @brief  ���ҹ�ϣ��
  * @param[in]   hashTable    ��ϣ��
  * @param[in]   key    ���ڲ��ҵĹؼ���
  * @return     0��û���ҵ���1:�ҵ�
  */
int SearchHashTable(HashTable* hashTable, KeyType key, int* position);

/**
  * @brief  Ԫ�ز����ϣ��
  * @param[in]   hashTable    ��ϣ��
  * @param[in]   element    ��Ҫ�����Ԫ��
  * @return    1���ɹ����룬0������ʧ��
  */
int InsertHashTable(HashTable* hashTable, Element element);

/**
  * @brief  �ӹ�ϣ����ɾ��Ԫ��
  * @param[in]   hashTable    ��ϣ��
  * @param[in]   key    ����ɾ���Ĺؼ���
  * @return    1���ɹ�ɾ����0��ɾ��ʧ��
  */
int DeleteHashTable(HashTable* hashTable, KeyType key);

/**
  * @brief  ��ʾ��ϣ��������
  * @param[in]   hashTable    ��ϣ��
  */
void PrintHashTable(HashTable* hashTable);

#endif