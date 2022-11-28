#include"SList.h"

//	创建节点
SLT* CreatListNode(SLTDataType x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//  打印
void SLtPrint(SLT* phead)
{
	SLT* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//	尾插
void SLtPushBack(SLT** pphead, SLTDataType x)
{
	//	找尾节点
	/*SLT* newnode = (SLT*)malloc(sizeof(SLTDataType));
	newnode->data = x;
	newnode->next = NULL; */	// 直接封装成一个函数

	SLT* newnode = CreatListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;	// 解引用
	}
	else
	{
		SLT* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//	头插
void SLtPushFront(SLT** pphead, SLTDataType x)
{
	SLT* newnode = CreatListNode(x); // 创建新节点，值x已经传入newnode
	newnode->next = *pphead; // 将原来头的地址放入新节点的next
	*pphead = newnode;		//	将新节点作为新的头
}

//	尾删
void SLtPopBack(SLT** pphead)
{
	//1 .直接为空
	assert(*pphead != NULL);

	//2	.只有一个结点(第二个为空)
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3	.结点 >= 3
	else
	{
		SLT* tail = *pphead;
		SLT* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

		//SLT* tail = *pphead;
		//while (tail->next->next)
		//{
		//	tail = tail->next;
		//}
		//free(tail->next);
		//tail->next = NULL;
	}
}

//	头删
void SLtPopFront(SLT** pphead)
{
	assert(*pphead != NULL);

	SLT* head = (*pphead)->next;
	free(*pphead);
	*pphead = head;
}

//	查找
SLT* SListFind(SLT* phead, SLTDataType x)
{
	SLT* cur = phead;
	while (cur)
	{
		while(cur->data != x)
		{
			cur = cur->next;
		}
		return cur;
		//if (cur->data == x)
		//{
		//	return cur;
		//}
		//else
		//{
		//	cur = cur->next;
		//}
	}
	return NULL;
}