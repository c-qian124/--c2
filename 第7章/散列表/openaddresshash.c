#include <stdio.h>
#include <stdlib.h>

#include "openaddresshash.h"


/**
  * @brief  ��ϣ����
  * @param[in]   key    �ؼ���
  * @param[in]   size    ��ϣ��ĳ���
  * @return    ��ϣ����λ��
  */
int h(KeyType key, int size)
{
	return key%size;
}

/**
  * @brief  ������ϣ��
  * @param[in]   num    ���洢�ռ�
  * @return    ��ϣ��
  */
HashTable* CreateHashTable(int num)
{
	HashTable *hashTable = NULL;
	int i;
	//����ռ�
	hashTable = (HashTable*)malloc(sizeof(HashTable));
	hashTable->size = num;
	hashTable->data =(Element*) malloc(sizeof(Element)*num);
	//��ʼ��������ϣ���и���Ԫ������Ϊû�б�ռ�õ�״̬
	for (i=0; i<hashTable->size; i++)
	{
		hashTable->data[i].key = unoccupied;
	}

	return hashTable;
}


/**
  * @brief  ���ҹ�ϣ��
  * @param[in]   hashTable    ��ϣ��
  * @param[in]   key    ���ڲ��ҵĹؼ���
  * @return     0��û���ҵ���1:�ҵ�
  */
int SearchHashTable(HashTable* hashTable, KeyType key, int* position)
{
	int i;//ѭ������
	int pos;//λ��
	int tryPos;//��̽λ��
	int cnt = 0;//��̽����
	int returnValue = 0;//�������ݣ����ó�ֵΪû���ҵ�״̬0
	//��¼��һ��unoccupiedλ�ú͵�һ��isdeleteλ��
	//���������λ���������Ϊpositionֵ
	int firstUnoccupied = -1;
	int firstIsdelete = -1;
	//���ҹ������Ƿ�����ɾ��λ
	int setFirstDelete = 0;

	//�ȼ���Ƿ�ֱ�����ҵ�
	pos = h(key, hashTable->size);

	//������ɢ�б��С��
	while(cnt < hashTable->size)
	{
		//������̽��λ�ã�ѭ�����
		tryPos = (pos+cnt)%hashTable->size;
		//�ܼ�⵽
		if (hashTable->data[tryPos].key == key)
		{
			*position = tryPos;
			returnValue = 1;
			break;//�ҵ���Ҫ�˳�ѭ��
		}
		//�ҵ���һ������λ�ã�˵��Ҫ���ҵ����ݿ϶�����ɢ�б���
		else if (hashTable->data[tryPos].key == unoccupied) 
		{
			firstUnoccupied = tryPos;
			break;//û���ҵ�Ҫ�˳�ѭ��
		}
		//����ҵ�һ��ɾ��λ����Ҫ���ҵ����ݿ��ܻ��ڱ�����
		else if (hashTable->data[tryPos].key == isdelete)
		{
			//ֻ���õ�һ����������Ϊɾ���������µ�λ��
			if (!setFirstDelete)
			{
				firstIsdelete = tryPos;
				setFirstDelete = 1;
			}
		}
		//������һ��Ԫ��
		cnt++;
	}//end while(cnt < hashTable->size)

	if (cnt < hashTable->size)
	{
		//����ǹ�ϣ��û�в����꣬����ѭ���������
		//1���ҵ���Ҫ���ҵ����ݣ���ʱreturnValue ֵΪ 1
		//2������û���ҵ����ݣ��϶��ǿ���unoccupiedλ����
		if (returnValue == 0)
		{
			//����Ǿ���һЩ��ɾ���������µ�λ�ã�isdelete���󣬷���unoccupiedλ��
			if (setFirstDelete)
			{
				*position = firstIsdelete;
			}
			//�����ֱ�ӷ���unoccupiedλ�õ�
			else
			{
				*position = firstUnoccupied;
			}
		} //if (returnValue == 0)
	} 
	else
	{
		//��ϣ��������Ԫ�ض��Ѿ������ϣ�û�з��ֹؼ�����Ȼ���unoccupiedλ��
		//����ҵ���isdeleteλ��Ҳ�ǿ��Բ������ݵ�
		if (setFirstDelete)
		{
			*position = firstIsdelete;
		} 
		else
		{
			//�����isdeleteλ�ö�û�У�˵����ϣ������
			*position = -1;
		}
		
	}//end if (cnt < hashTable->size)
	
	return returnValue;
}

/**
  * @brief  �����ϣ��
  * @param[in]   hashTable    ��ϣ��
  * @param[in]   element    ��Ҫ�����Ԫ��
  * @return    1���ɹ����룬0������ʧ��
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
		printf("��Ԫ���Ѿ����ڣ�����ʧ��\n");
	} 
	else if(pos == -1)
	{
		printf("��ϣ�����Ѿ���λ�ã�����ʧ��\n");
	}
	else
	{
		hashTable->data[pos] = element;
		returnValue = 1;
	}
	return returnValue;
}


/**
  * @brief  �ӹ�ϣ����ɾ��Ԫ��
  * @param[in]   hashTable    ��ϣ��
  * @param[in]   key    ����ɾ���Ĺؼ���
  * @return    1���ɹ�ɾ����0��ɾ��ʧ��
  */
int DeleteHashTable(HashTable* hashTable, KeyType key)
{
	int find;
	int pos = -1;
	int returnValue = 0;

	find = SearchHashTable(hashTable, key, &pos);

	if (find == 1)
	{
		//ɾ������
		hashTable->data[pos].key = isdelete;
		returnValue = 1;
	} 
	else 
	{
		printf("��ϣ�����޴�Ԫ�أ�ɾ��ʧ��\n");
	}

	return returnValue;
}

/**
  * @brief  ��ʾ��ϣ��������
  * @param[in]   hashTable    ��ϣ��
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


