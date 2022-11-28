#include"SList.h"

//	�����ڵ�
SLT* CreatListNode(SLTDataType x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//  ��ӡ
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

//	β��
void SLtPushBack(SLT** pphead, SLTDataType x)
{
	//	��β�ڵ�
	/*SLT* newnode = (SLT*)malloc(sizeof(SLTDataType));
	newnode->data = x;
	newnode->next = NULL; */	// ֱ�ӷ�װ��һ������

	SLT* newnode = CreatListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;	// ������
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

//	ͷ��
void SLtPushFront(SLT** pphead, SLTDataType x)
{
	SLT* newnode = CreatListNode(x); // �����½ڵ㣬ֵx�Ѿ�����newnode
	newnode->next = *pphead; // ��ԭ��ͷ�ĵ�ַ�����½ڵ��next
	*pphead = newnode;		//	���½ڵ���Ϊ�µ�ͷ
}

//	βɾ
void SLtPopBack(SLT** pphead)
{
	//1 .ֱ��Ϊ��
	assert(*pphead != NULL);

	//2	.ֻ��һ�����(�ڶ���Ϊ��)
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3	.��� >= 3
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

//	ͷɾ
void SLtPopFront(SLT** pphead)
{
	assert(*pphead != NULL);

	SLT* head = (*pphead)->next;
	free(*pphead);
	*pphead = head;
}

//	����
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