
#ifndef PLINKLQUEUE_H
#define PLINKLQUEUE_H
typedef int DataType;
struct Node
{
	DataType data;
	struct Node	*link;
};
typedef struct Node *PNode;
struct Queue
{	PNode		f;
	PNode		r;
};
typedef struct Queue *LinkQueue;

LinkQueue SetNullQueue_Link();
int IsNullQueue_Link(LinkQueue lqueue);
void EnQueue_link(LinkQueue lqueue, DataType x);
void DeQueue_link(LinkQueue lqueue);
DataType  FrontQueue_link(LinkQueue lqueue);

#endif