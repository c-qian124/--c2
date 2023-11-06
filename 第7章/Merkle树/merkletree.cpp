#include <stdlib.h>
#include <stdio.h>
#include <functional>//用于获得hash函数
#include <queue>
#include "merkletree.h"

#define CONTENTSIZE  20

/**
  * @brief  创建MerkleTree
  * @param[in]   num    数据个数
  * @param[in]   childNum    每个结点最多子孩子个数
  * @return    MerkleTree
  */
MerkleTree* CreateMerkleTree(int dataNum, int childNum)
{
	//采用一个一维数组临时存放每层结点，每层结点不可能超过最底层存放原始数据的结点个数
	MerkleTreeNode** levelMerkleTreeNodes = NULL;
	MerkleTreeNode* tempTreeNode = NULL;
	//用于hash函数
	std::hash<char*> ptr_hash;
	size_t hashcode;
	//用于拼接字符串
	char* buffer = NULL;
	int i,j;
	//用于存放每层真实数据个数，因为存放每层结点的空间固定多，但是每层结点个数不一
	int levelNum = 0;
	//存放下层结点个数
	int downLevelNum = 0;

	//merkle tree的结构，用于存放最后结果
	MerkleTree* merkleTree = NULL;
	
	//先读入数据到最底层的数据结点中
	levelMerkleTreeNodes = (MerkleTreeNode**)malloc(sizeof(MerkleTreeNode*)*dataNum);
	for (i=0; i<dataNum; i++)
	{	
		levelMerkleTreeNodes[i] = (MerkleTreeNode*)malloc(sizeof(MerkleTreeNode));
		//先给字符串分配空间，这里为了简单采用直接读入数据的方法
		levelMerkleTreeNodes[i]->content = (char*)malloc(sizeof(char)*CONTENTSIZE);
		printf("请输入第%d个数据",i+1);
		fflush(stdin);
		gets(levelMerkleTreeNodes[i]->content);
		//最底层的数据结点不会有小孩子了
		levelMerkleTreeNodes[i]->children = NULL;
		//指向上层结点的指针现在先初始化为NULL，后面再改变
		levelMerkleTreeNodes[i]->parent = NULL;
	}

	levelNum = dataNum;

	//构造merkle tree，当层结点个数为1时，说明已经是根结点了
	while(levelNum != 1)
	{
		//对新的一层数据做处理
		downLevelNum = levelNum;
		levelNum = 0;

		//从下层数据推到上层
		for (i=0; i<downLevelNum; )
		{
			tempTreeNode = (MerkleTreeNode*)malloc(sizeof(MerkleTreeNode));
			tempTreeNode->parent = NULL;//以后赋值
			tempTreeNode->content = (char*)malloc(sizeof(char)*CONTENTSIZE);
			//看看是几个小孩子
			tempTreeNode->children = (MerkleTreeNode **)malloc(sizeof(MerkleTreeNode*)*childNum);
			//分配足够的空间好用于存放字符串，使用字符串拼接
			buffer = (char*)malloc(sizeof(char)*CONTENTSIZE*childNum);
			buffer[0] = '\0';
			for (j=0; j<childNum ;j++)
			{
				//如果下层结点还有
				if (i < downLevelNum)
				{
					strcat(buffer, levelMerkleTreeNodes[i]->content);
					levelMerkleTreeNodes[i]->parent = tempTreeNode;
					tempTreeNode->children[j] = levelMerkleTreeNodes[i];
				} 
				else
				{
					//如果下层剩余结点不够
					tempTreeNode->children[j] = NULL;
				}
				
				i++;
			}
			//调用c++中的hash函数进行
			hashcode = ptr_hash(buffer);
			//free(buffer);
			//转为字符串存储在结点中
			_ultoa(hashcode,tempTreeNode->content,10);

			//把新结点替换放入保存层结点指针的一维数组中，方便上层创建使用
			levelMerkleTreeNodes[levelNum] = tempTreeNode;
			levelNum++;
		}//end for (i=0; i<downLevelNum; )	
	}//end while(levelNum != 1)

	//设置树根
	 merkleTree = (MerkleTree*)malloc(sizeof(MerkleTree));
	 merkleTree->root = levelMerkleTreeNodes[0];

	 return merkleTree;
}//end MerkleTree* CreateMerkleTree(int dataNum, int childNum)

/**
  * @brief  遍历MerkleTree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    每个结点最多子孩子个数
  */
void trevelMerkleTree(MerkleTree* merkletree, int childNum)
{
	//访问merkletree的每个结点，这里用到c++ stl中的队列
	std::queue<MerkleTreeNode*> trevelQueue;
	MerkleTreeNode *tempTreeNode = NULL;
	int i;

	trevelQueue.push(merkletree->root);

	while(!trevelQueue.empty())
	{
		tempTreeNode = trevelQueue.front();
		trevelQueue.pop();

		//访问，这里只是简单的输出
		printf("%s\n", tempTreeNode->content);
		
		if (tempTreeNode->children != NULL)
		{
			//找到非空小孩子结点，进行处理
			for (i=0;i<childNum;i++)
			{
				if (tempTreeNode->children[i] != NULL)
				{

					//放入队列，方便后续处理
					trevelQueue.push(tempTreeNode->children[i]);
				}
			}//end for (i=0;i<childNum;i++)
		}//end if (tempTreeNode->children != NULL)
		
		
	}//end while(!trevelQueue.empty())

}


/**
  * @brief  比对两个merkletree，找到不同的数据信息
  * @param[in]   merkletree    merkle tree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    每个结点最多子孩子个数
  * @return    0:两棵树相同，1：两棵树不同
  */
int diffMerkleTree(MerkleTree* merkletree1, MerkleTree* merkletree2,int childNum)
{
	//访问merkletree的每个结点，这里用到c++ stl中的队列
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

			//只把两者content不相等的结点的小孩放入队列，进行后续访问
			if (strcmp(tempTreeNode1->content, tempTreeNode2->content) != 0)
			{
				//访问，这里只是简单的输出
				printf("树１:%s\n", tempTreeNode1->content);
				printf("树２：%s\n", tempTreeNode2->content);

				//处理树１
				if (tempTreeNode1->children != NULL)
				{
					//找到非空小孩子结点，进行处理
					for (i=0;i<childNum;i++)
					{
						if (tempTreeNode1->children[i] != NULL)
						{

							//放入队列，方便后续处理
							trevelQueue1.push(tempTreeNode1->children[i]);
						}
					}//end for (i=0;i<childNum;i++)
				}//end if (tempTreeNode1->children != NULL)

				//处理树2
				if (tempTreeNode2->children != NULL)
				{
					//找到非空小孩子结点，进行处理
					for (i=0;i<childNum;i++)
					{
						if (tempTreeNode2->children[i] != NULL)
						{

							//放入队列，方便后续处理
							trevelQueue2.push(tempTreeNode2->children[i]);
						}
					}//end for (i=0;i<childNum;i++)
				}//end if (tempTreeNode2->children != NULL)
			}//end if (strcmp(tempTreeNode1->content, tempTreeNode2->content) != 0)
		}//end while(!trevelQueue1.empty() && !trevelQueue2.empty())

		return 1;//不同
	} //end if (strcmp(merkletree1->root->content, merkletree2->root->content) != 0)
	
	return 0;

}


