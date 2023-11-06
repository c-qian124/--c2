#ifndef OPENADDRESSHASH_H_
#define OPENADDRESSHASH_H_

typedef int KeyType;
typedef char ElementType;

//后面算法中假设所有关键字key都是大于0的整数
#define unoccupied -1
#define isdelete  -2

/**
 * @brief hash table中的一个元素
 */
typedef struct	ELEMENT_STRU
{
	KeyType key;//关键码
	ElementType element;//数据
}Element;

/**
 * @brief hash table
 */
typedef struct HASHTABLE_STRU
{
	int size;//哈希表的最大存储容量
	Element *data;//分配空间后为一维数组
}HashTable;

/**
  * @brief  哈希函数
  * @param[in]   key    关键字
  * @param[in]   size    哈希表的长度
  * @return    哈希表中位置
  */
int h(KeyType key, int size);

/**
  * @brief  创建哈希表
  * @param[in]   num    最大存储空间
  * @return    哈希表
  */
HashTable* CreateHashTable(int num);

/**
  * @brief  查找哈希表
  * @param[in]   hashTable    哈希表
  * @param[in]   key    用于查找的关键字
  * @return     0：没有找到，1:找到
  */
int SearchHashTable(HashTable* hashTable, KeyType key, int* position);

/**
  * @brief  元素插入哈希表
  * @param[in]   hashTable    哈希表
  * @param[in]   element    需要插入的元素
  * @return    1：成功插入，0：插入失败
  */
int InsertHashTable(HashTable* hashTable, Element element);

/**
  * @brief  从哈希表中删除元素
  * @param[in]   hashTable    哈希表
  * @param[in]   key    用于删除的关键字
  * @return    1：成功删除，0：删除失败
  */
int DeleteHashTable(HashTable* hashTable, KeyType key);

/**
  * @brief  显示哈希表中数据
  * @param[in]   hashTable    哈希表
  */
void PrintHashTable(HashTable* hashTable);

#endif