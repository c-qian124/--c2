#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

LinkQueue  SetNullQueue_Link()
{ 
	LinkQueue lqueue;
	lqueue = (LinkQueue)malloc(sizeof(struct Queue));
	if (lqueue != NULL)
	{	
		lqueue->f = NULL;
		lqueue->r = NULL;
	}
   	else	
		printf("Alloc failure! \n");
	return  lqueue;
 }

int IsNullQueue_Link(LinkQueue lqueue)
{    	
	return (lqueue->f == NULL);
}

void EnQueue_link(LinkQueue lqueue, DataType x)
{ 	
	PNode  p;
	p = (PNode)malloc(sizeof(struct Node));
	if (p == NULL)
		printf("Alloc failure!");
	else{	
			p->data = x;
			p->link = NULL;
			if (lqueue->f == NULL) //空队列的特殊处理
			{ 	
				lqueue->f = p;
				lqueue->r = p;
			}
	  		else
			{ 	
				lqueue->r->link = p;
				lqueue->r = p;
			}
		}
} 
void DeQueue_link(LinkQueue lqueue)
{	
	struct Node  * p;
	if (lqueue->f == NULL)
		printf( "It is empty queue!\n ");
  	else
	{ 	
		p = lqueue->f;
		lqueue->f = lqueue->f->link;
		free(p);
	}
}
DataType  FrontQueue_link(LinkQueue lqueue)
{       	
	if (lqueue->f == NULL)
	{
		printf("It is empty queue!\n");
		return 0;
	}
	else
		return (lqueue->f->data);
}