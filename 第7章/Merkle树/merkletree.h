#ifndef MERKLETREE_H_
#define MERKLETREE_H_


/**
 * @brief merkle����㣬������Ҫ����Ϣ��hash��
 */
typedef struct	MERKLETREENODE_STRU
{
	char* content;//hash���������������
	struct	MERKLETREENODE_STRU **children;//ָ���ӵ�ָ���ָ�룬������Ҫ���䣬���Ӹ����п��ܻ����2��
	struct	MERKLETREENODE_STRU *parent;//ָ�򸸽ڵ�
}MerkleTreeNode;

/**
 * @brief merkle����
 */
typedef struct	MERKLETREE_STRU
{
	MerkleTreeNode *root;//���������յ���
}MerkleTree;


/**
  * @brief  ����MerkleTree
  * @param[in]   num    ���ݸ���
  * @param[in]   childNum    ÿ���������Ӻ��Ӹ���
  * @return    MerkleTree
  */
MerkleTree* CreateMerkleTree(int dataNum, int childNum);

/**
  * @brief  ����MerkleTree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    ÿ���������Ӻ��Ӹ���
  */
void trevelMerkleTree(MerkleTree* merkletree, int childNum);

/**
  * @brief  �ȶ�����merkletree���ҵ���ͬ��������Ϣ
  * @param[in]   merkletree    merkle tree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    ÿ���������Ӻ��Ӹ���
  * @return    0:��������ͬ��1����������ͬ
  */
int diffMerkleTree(MerkleTree* merkletree1, MerkleTree* merkletree2,int childNum);



#endif