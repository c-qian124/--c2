#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "openaddresshash.h"

int main()
{
	
	HashTable *hashTable = NULL;
	int i;
	Element tempElement;

	hashTable = CreateHashTable(6);

	srand( (unsigned)time( NULL ) );

	//生成5个1－20之间的随机数进行插入检测
	for (i=0;i<5;i++)
	{
		tempElement.key = rand()%20+1;

		printf("\n第%d次插入%d\n",i+1,tempElement.key);
		InsertHashTable(hashTable,tempElement);

		PrintHashTable(hashTable);
	}

	//随机删除2个元素，再次进行插入检测
	for (i=0;i<2;i++)
	{
		tempElement.key = rand()%20+1;

		printf("\n第%d次删除%d\n",i+1,tempElement.key);
		DeleteHashTable(hashTable,tempElement.key);
		PrintHashTable(hashTable);
	}

	//再次随机插入3个元素
	//生成3个1－20之间的随机数进行插入检测
	for (i=0;i<3;i++)
	{
		tempElement.key = rand()%20+1;

		printf("\n第%d次插入%d\n",i+1,tempElement.key);
		InsertHashTable(hashTable,tempElement);

		PrintHashTable(hashTable);
	}


	return 0;
}