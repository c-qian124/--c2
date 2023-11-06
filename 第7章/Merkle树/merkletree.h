#ifndef MERKLETREE_H_
#define MERKLETREE_H_


/**
 * @brief merkle树结点，其中重要的信息是hash码
 */
typedef struct	MERKLETREENODE_STRU
{
	char* content;//hash码或者是数据内容
	struct	MERKLETREENODE_STRU **children;//指向孩子的指针的指针，根据需要分配，孩子个数有可能会大于2个
	struct	MERKLETREENODE_STRU *parent;//指向父节点
}MerkleTreeNode;

/**
 * @brief merkle树根
 */
typedef struct	MERKLETREE_STRU
{
	MerkleTreeNode *root;//树根，最终的码
}MerkleTree;


/**
  * @brief  创建MerkleTree
  * @param[in]   num    数据个数
  * @param[in]   childNum    每个结点最多子孩子个数
  * @return    MerkleTree
  */
MerkleTree* CreateMerkleTree(int dataNum, int childNum);

/**
  * @brief  遍历MerkleTree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    每个结点最多子孩子个数
  */
void trevelMerkleTree(MerkleTree* merkletree, int childNum);

/**
  * @brief  比对两个merkletree，找到不同的数据信息
  * @param[in]   merkletree    merkle tree
  * @param[in]   merkletree    merkle tree
  * @param[in]   childNum    每个结点最多子孩子个数
  * @return    0:两棵树相同，1：两棵树不同
  */
int diffMerkleTree(MerkleTree* merkletree1, MerkleTree* merkletree2,int childNum);



#endif