#include <stdio.h>
#include "merkletree.h"

int main()
{
	MerkleTree * merkleTree = NULL;
	MerkleTree *merkleTreeCompare = NULL;
	int dataNum;
	int childNum;

	//������ײ����ݽ������Լ�ÿ������·�������
	printf("������ײ����ݽ�����");
	scanf("%d", &dataNum);
	printf("������ÿ������·���������������>=2����ֵ");
	scanf("%d", &childNum);
	merkleTree = CreateMerkleTree(dataNum, childNum);

	//����merkle��tree��ÿ�����
	printf("����merkle tree������£�\n");
	trevelMerkleTree(merkleTree, childNum);

	//�Ƚ�����merkle tree������
	printf("��������һ�������бȽ�\n");
	merkleTreeCompare = CreateMerkleTree(dataNum, childNum);
	printf("�������ڱȽϵ�merkle tree������£�\n");
	trevelMerkleTree(merkleTreeCompare, childNum);
	printf("�ȽϽ�����£�\n");
	diffMerkleTree(merkleTree, merkleTreeCompare, childNum);

	return 0;
}