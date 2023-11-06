#include <stdlib.h>
#include <stdio.h>
#include <functional>//���ڻ��hash����
#include <queue>
#include "merkletree.h"

#define CONTENTSIZE  20

/**
  * @brief  ����MerkleTree
  * @param[in]   num    ���ݸ���
  * @param[in]   childNum    ÿ���������Ӻ��Ӹ���
  * @return    MerkleTree
  */
MerkleTree* CreateMerkleTree(int dataNum, int childNum)
{
	//����һ��һά������ʱ���ÿ���㣬ÿ���㲻���ܳ�����ײ���ԭʼ���ݵĽ�����
	MerkleTreeNode** levelMerkleTreeNodes = NULL;
	MerkleTreeNode* tempTreeNode = NULL;
	//����hash����
	std::hash<char*> ptr_hash;
	size_t hashcode;
	//����ƴ���ַ���
	char* buffer = NULL;
	int i,j;
	//���ڴ��ÿ����ʵ���ݸ�������Ϊ���ÿ����Ŀռ�̶��࣬����ÿ���������һ
	int levelNum = 0;
	//����²������
	int downLevelNum = 0;

	//merkle tree�Ľṹ�����ڴ�������
	MerkleTree* merkleTree = NULL;
	
	//�ȶ������ݵ���ײ�����ݽ����
	levelMerkleTreeNodes = (MerkleTreeNode**)malloc(sizeof(MerkleTreeNode*)*dataNum);
	for (i=0; i<dataNum; i++)
	{	
		levelMerkleTreeNodes[i] = (MerkleTreeNode*)malloc(sizeof(MerkleTreeNode));
		//�ȸ��ַ�������ռ䣬����Ϊ�˼򵥲���ֱ�Ӷ������ݵķ���
		levelMerkleTreeNodes[i]->content = (char*)malloc(sizeof(char)*CONTENTSIZE);
		printf("�������%d������",i+1);
		fflush(stdin);
		gets(levelMerkleTreeNodes[i]->content);
		//��ײ�����ݽ�㲻����С������
		levelMerkleTreeNodes[i]->children = NULL;
		//ָ���ϲ����ָ�������ȳ�ʼ��ΪNULL�������ٸı�
		levelMerkleTreeNodes[i]->parent = NULL;
	}

	levelNum = dataNum;

	//����merkle tree�����������Ϊ1ʱ��˵���Ѿ��Ǹ������
	while(levelNum != 1)
	{
		//���µ�һ������������
		downLevelNum = levelNum;
		levelNum = 0;

		//���²������Ƶ��ϲ�
		for (i=0; i<downLevelNum; )
		{
			tempTreeNode = (MerkleTreeNode*)malloc(sizeof(MerkleTreeNode));
			tempTreeNode->parent = NULL;//�Ժ�ֵ
			tempTreeNode->content = (char*)malloc(sizeof(char)*CONTENTSIZE);
			//�����Ǽ���С����
			tempTreeNode->children = (MerkleTreeNode **)malloc(sizeof(MerkleTreeNode*)*childNum);
			//�����㹻�Ŀռ�����ڴ���ַ�����ʹ���ַ���ƴ��
			buffer = (char*)malloc(sizeof(char)*CONTENTSIZE*childNum);
			buffer[0] = '\0';
			for (j=0; j<childNum ;j++)
			{
				//����²��㻹��
				if (i < downLevelNum)
				{
					strcat(buffer, levelMerkleTreeNodes[i]->content);
					levelMerkleTreeNodes[i]->parent = tempTreeNode;
					tempTreeNode->children[j] = levelMerkleTreeNodes[i];
				} 
				else
				{
					//����²�ʣ���㲻��
					tempTreeNode->children[j] = NULL;
				}
				
				i++;
			}
			//����c++�е�hash��������
			hashcode = ptr_hash(buffer);
			//free(buffer);
			//תΪ�ַ����洢�ڽ����
			_ultoa(hashcode,tempTreeNode->content,10);

			//���½���滻���뱣�����ָ���һά�����У������ϲ㴴��ʹ��
			levelMerkleTreeNodes[levelNum] = tempTreeNode;
			levelNum++;
		}//end for (i=0; i<downLevelNum; )	
	}//end while(levelNum != 1)

	//��������
	 merkleTree = (MerkleTree*)malloc(sizeof(MerkleTree));
	 merkleTree->root = levelMerkleTreeNodes[0];

	 return merkleTree;
}//end MerkleTree* CreateMerkleTree(int dataNum, int childNum)

/**
  * @brief  ����MerkleTree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    ÿ���������Ӻ��Ӹ���
  */
void trevelMerkleTree(MerkleTree* merkletree, int childNum)
{
	//����merkletree��ÿ����㣬�����õ�c++ stl�еĶ���
	std::queue<MerkleTreeNode*> trevelQueue;
	MerkleTreeNode *tempTreeNode = NULL;
	int i;

	trevelQueue.push(merkletree->root);

	while(!trevelQueue.empty())
	{
		tempTreeNode = trevelQueue.front();
		trevelQueue.pop();

		//���ʣ�����ֻ�Ǽ򵥵����
		printf("%s\n", tempTreeNode->content);
		
		if (tempTreeNode->children != NULL)
		{
			//�ҵ��ǿ�С���ӽ�㣬���д���
			for (i=0;i<childNum;i++)
			{
				if (tempTreeNode->children[i] != NULL)
				{

					//������У������������
					trevelQueue.push(tempTreeNode->children[i]);
				}
			}//end for (i=0;i<childNum;i++)
		}//end if (tempTreeNode->children != NULL)
		
		
	}//end while(!trevelQueue.empty())

}


/**
  * @brief  �ȶ�����merkletree���ҵ���ͬ��������Ϣ
  * @param[in]   merkletree    merkle tree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    ÿ���������Ӻ��Ӹ���
  * @return    0:��������ͬ��1����������ͬ
  */
int diffMerkleTree(MerkleTree* merkletree1, MerkleTree* merkletree2,int childNum)
{
	//����merkletree��ÿ����㣬�����õ�c++ stl�еĶ���
	std::queue<MerkleTreeNode*> trevelQueue1;
	std::queue<MerkleTreeNode*> trevelQueue2;
	MerkleTreeNode *tempTreeNode1 = NULL;
	MerkleTreeNode *tempTreeNode2 = NULL;
	int i;

	if (strcmp(merkletree1->root->content, merkletree2->root->content) != 0)
	{
		trevelQueue1.push(merkletree1->root);
		trevelQueue2.push(merkletree2->root);

		while(!trevelQueue1.empty() && !trevelQueue2.empty())
		{
			tempTreeNode1 = trevelQueue1.front();
			trevelQueue1.pop();

			tempTreeNode2 = trevelQueue2.front();
			trevelQueue2.pop();

			//ֻ������content����ȵĽ���С��������У����к�������
			if (strcmp(tempTreeNode1->content, tempTreeNode2->content) != 0)
			{
				//���ʣ�����ֻ�Ǽ򵥵����
				printf("����:%s\n", tempTreeNode1->content);
				printf("������%s\n", tempTreeNode2->content);

				//��������
				if (tempTreeNode1->children != NULL)
				{
					//�ҵ��ǿ�С���ӽ�㣬���д���
					for (i=0;i<childNum;i++)
					{
						if (tempTreeNode1->children[i] != NULL)
						{

							//������У������������
							trevelQueue1.push(tempTreeNode1->children[i]);
						}
					}//end for (i=0;i<childNum;i++)
				}//end if (tempTreeNode1->children != NULL)

				//������2
				if (tempTreeNode2->children != NULL)
				{
					//�ҵ��ǿ�С���ӽ�㣬���д���
					for (i=0;i<childNum;i++)
					{
						if (tempTreeNode2->children[i] != NULL)
						{

							//������У������������
							trevelQueue2.push(tempTreeNode2->children[i]);
						}
					}//end for (i=0;i<childNum;i++)
				}//end if (tempTreeNode2->children != NULL)
			}//end if (strcmp(tempTreeNode1->content, tempTreeNode2->content) != 0)
		}//end while(!trevelQueue1.empty() && !trevelQueue2.empty())

		return 1;//��ͬ
	} //end if (strcmp(merkletree1->root->content, merkletree2->root->content) != 0)
	
	return 0;

}


