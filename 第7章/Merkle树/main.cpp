#include <stdio.h>
#include "merkletree.h"

int main()
{
	MerkleTree * merkleTree = NULL;
	MerkleTree *merkleTreeCompare = NULL;
	int dataNum;
	int childNum;

	//输入最底层数据结点个数以及每个结点下方结点个数
	printf("请输入底层数据结点个数");
	scanf("%d", &dataNum);
	printf("请输入每个结点下方结点个数，请输入>=2的数值");
	scanf("%d", &childNum);
	merkleTree = CreateMerkleTree(dataNum, childNum);

	//遍历merkle　tree的每个结点
	printf("遍历merkle tree结果如下：\n");
	trevelMerkleTree(merkleTree, childNum);

	//比较两棵merkle tree的区别
	printf("请再输入一棵树进行比较\n");
	merkleTreeCompare = CreateMerkleTree(dataNum, childNum);
	printf("遍历用于比较的merkle tree结果如下：\n");
	trevelMerkleTree(merkleTreeCompare, childNum);
	printf("比较结果如下：\n");
	diffMerkleTree(merkleTree, merkleTreeCompare, childNum);

	return 0;
}