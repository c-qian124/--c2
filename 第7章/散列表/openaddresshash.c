#include <stdio.h>
#include <stdlib.h>

#include "openaddresshash.h"


/**
  * @brief  哈希函数
  * @param[in]   key    关键字
  * @param[in]   size    哈希表的长度
  * @return    哈希表中位置
  */
int h(KeyType key, int size)
{
	return key%size;
}

/**
  * @brief  创建哈希表
  * @param[in]   num    最大存储空间
  * @return    哈希表
  */
HashTable* CreateHashTable(int num)
{
	HashTable *hashTable = NULL;
	int i;
	//分配空间
	hashTable = (HashTable*)malloc(sizeof(HashTable));
	hashTable->size = num;
	hashTable->data =(Element*) malloc(sizeof(Element)*num);
	//初始化，将哈希表中各个元素设置为没有被占用的状态
	for (i=0; i<hashTable->size; i++)
	{
		hashTable->data[i].key = unoccupied;
	}

	return hashTable;
}


/**
  * @brief  查找哈希表
  * @param[in]   hashTable    哈希表
  * @param[in]   key    用于查找的关键字
  * @return     0：没有找到，1:找到
  */
int SearchHashTable(HashTable* hashTable, KeyType key, int* position)
{
	int i;//循环变量
	int pos;//位置
	int tryPos;//试探位置
	int cnt = 0;//试探次数
	int returnValue = 0;//返回数据，设置初值为没有找到状态0
	//记录第一个unoccupied位置和第一个isdelete位置
	//采用离查找位置最近的做为position值
	int firstUnoccupied = -1;
	int firstIsdelete = -1;
	//查找过程中是否遇到删除位
	int setFirstDelete = 0;

	//先检测是否直接能找到
	pos = h(key, hashTable->size);

	//最多检索散列表大小次
	while(cnt < hashTable->size)
	{
		//计算试探的位置，循环检测
		tryPos = (pos+cnt)%hashTable->size;
		//能检测到
		if (hashTable->data[tryPos].key == key)
		{
			*position = tryPos;
			returnValue = 1;
			break;//找到了要退出循环
		}
		//找到第一个空余位置，说明要查找的数据肯定不在散列表中
		else if (hashTable->data[tryPos].key == unoccupied) 
		{
			firstUnoccupied = tryPos;
			break;//没有找到要退出循环
		}
		//如果找到一个删除位，则要查找的数据可能还在表里面
		else if (hashTable->data[tryPos].key == isdelete)
		{
			//只设置第一个遇到的因为删除数据留下的位置
			if (!setFirstDelete)
			{
				firstIsdelete = tryPos;
				setFirstDelete = 1;
			}
		}
		//看看下一个元素
		cnt++;
	}//end while(cnt < hashTable->size)

	if (cnt < hashTable->size)
	{
		//如果是哈希表都没有查找完，结束循环两种情况
		//1、找到需要查找的数据，这时returnValue 值为 1
		//2、发现没有找到数据，肯定是看到unoccupied位置了
		if (returnValue == 0)
		{
			//如果是经过一些被删除数据留下的位置（isdelete）后，发现unoccupied位置
			if (setFirstDelete)
			{
				*position = firstIsdelete;
			}
			//如果是直接发现unoccupied位置的
			else
			{
				*position = firstUnoccupied;
			}
		} //if (returnValue == 0)
	} 
	else
	{
		//哈希表中所有元素都已经检测完毕，没有发现关键字相等或者unoccupied位置
		//如果找到有isdelete位，也是可以插入数据的
		if (setFirstDelete)
		{
			*position = firstIsdelete;
		} 
		else
		{
			//如果连isdelete位置都没有，说明哈希表满了
			*position = -1;
		}
		
	}//end if (cnt < hashTable->size)
	
	return returnValue;
}

/**
  * @brief  插入哈希表
  * @param[in]   hashTable    哈希表
  * @param[in]   element    需要插入的元素
  * @return    1：成功插入，0：插入失败
  */
int InsertHashTable(HashTable* hashTable, Element element)
{
	int find;
	int pos = -1;
	int key = element.key;
	int returnValue = 0;

	find = SearchHashTable(hashTable, key, &pos);

	if (find == 1)
	{
		printf("该元素已经存在，插入失败\n");
	} 
	else if(pos == -1)
	{
		printf("哈希表中已经无位置，插入失败\n");
	}
	else
	{
		hashTable->data[pos] = element;
		returnValue = 1;
	}
	return returnValue;
}


/**
  * @brief  从哈希表中删除元素
  * @param[in]   hashTable    哈希表
  * @param[in]   key    用于删除的关键字
  * @return    1：成功删除，0：删除失败
  */
int DeleteHashTable(HashTable* hashTable, KeyType key)
{
	int find;
	int pos = -1;
	int returnValue = 0;

	find = SearchHashTable(hashTable, key, &pos);

	if (find == 1)
	{
		//删除数据
		hashTable->data[pos].key = isdelete;
		returnValue = 1;
	} 
	else 
	{
		printf("哈希表中无此元素，删除失败\n");
	}

	return returnValue;
}

/**
  * @brief  显示哈希表中数据
  * @param[in]   hashTable    哈希表
  */
void PrintHashTable(HashTable* hashTable)
{
	int i;

	for (i=0;i<hashTable->size;i++)
	{
		if (hashTable->data[i].key == unoccupied)
		{
			printf("null\t");
		}
		else if (hashTable->data[i].key == isdelete)
		{
			printf("deleted\t");
		}
		else
		{
			printf("%d\t", hashTable->data[i].key);
		}	
	}//end for (i=0;i<hashTable->size;i++)
}


