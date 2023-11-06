#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skiplist.h"

int main()
{
	SkipList zrxSkipList;
	zrxSkipList = SetNullSkipList(3);
	SkipListInsert(zrxSkipList, 1);
	SkipListInsert(zrxSkipList, 20);
	SkipListInsert(zrxSkipList, 13);
	SkipListInsert(zrxSkipList, 5);
	SkipListInsert(zrxSkipList, 8);
	SkipListInsert(zrxSkipList, 4);
	SkipListInsert(zrxSkipList, 7);
	SkipListInsert(zrxSkipList, 21);
	SkipListInsert(zrxSkipList, 34);
	SkipListInsert(zrxSkipList, 55);
	SkipListInsert(zrxSkipList, 89);
	printf("%d\n", zrxSkipList->num);
	SkipListDelete(zrxSkipList, 4);
	printf("%d\n", zrxSkipList->num);
	SkipListDelete(zrxSkipList, 10);
	printf("%d\n", zrxSkipList->num);
	SkipListSearch(zrxSkipList, 13);
	return 0;
}