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

	//����5��1��20֮�����������в�����
	for (i=0;i<5;i++)
	{
		tempElement.key = rand()%20+1;

		printf("\n��%d�β���%d\n",i+1,tempElement.key);
		InsertHashTable(hashTable,tempElement);

		PrintHashTable(hashTable);
	}

	//���ɾ��2��Ԫ�أ��ٴν��в�����
	for (i=0;i<2;i++)
	{
		tempElement.key = rand()%20+1;

		printf("\n��%d��ɾ��%d\n",i+1,tempElement.key);
		DeleteHashTable(hashTable,tempElement.key);
		PrintHashTable(hashTable);
	}

	//�ٴ��������3��Ԫ��
	//����3��1��20֮�����������в�����
	for (i=0;i<3;i++)
	{
		tempElement.key = rand()%20+1;

		printf("\n��%d�β���%d\n",i+1,tempElement.key);
		InsertHashTable(hashTable,tempElement);

		PrintHashTable(hashTable);
	}


	return 0;
}