#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#define FALSE 0
#define TRUE 1

typedef int DataType;
struct Node{
	DataType	  data;
	struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *top,*LinkStack;

LinkStack SetNullStack_Link();
int IsNullStack_link(LinkStack top);
void Push_link(LinkStack top, DataType x);
void Pop_link(LinkStack top);
DataType Pop_seq_return(LinkStack top);
DataType Top_link(LinkStack top);
#endif