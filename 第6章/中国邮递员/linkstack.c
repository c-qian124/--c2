#include<stdio.h>
#include<stdlib.h>
#include "linkstack.h"

LinkStack SetNullStack_Link() /*创建带有头结点的空链栈*/
{
	LinkStack top = (LinkStack)malloc(sizeof(struct Node));
	if (top!= NULL) top->next = NULL;
	else printf("Alloc failure");
	return top; /*返回栈顶指针*/
}

int IsNullStack_link(LinkStack top)//判断一个链栈是否为空
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

void Push_link(LinkStack top, DataType x)//进栈
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node));
	if (p == NULL)
		printf("Alloc failure");
	else
	{
		p->data = x;
		p->next = top->next;
		top->next = p;
	}
}
void Pop_link(LinkStack top)// 删除栈顶元素
{
	PNode p;
	if (top->next == NULL) 
		printf("it is empty stack!");
	else
	{
		p = top->next;
		top->next = p->next;
		free(p);
	}
}
DataType Pop_seq_return(LinkStack top)// 删除栈顶元素
{
	PNode p; DataType temp;
	if (top->next == NULL)
	{
		printf("It is empty stack!");
		return 0;
	}
	else
	{
		p = top->next;
		top->next = p->next;
		temp = p->data;
		free(p);
		return temp;
	}
}
DataType Top_link(LinkStack top)// 求栈顶元素的值
{
	if (top->next == NULL)
	{
		printf("It is empty stack!");
		return 0;
	}
	else
		return top->next->data;
}


