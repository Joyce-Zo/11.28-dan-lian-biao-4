#include"SList.h"

//int main()
//{
//	int* p1 = malloc(sizeof(int) * 12);
//	int* p2 = realloc(p1, sizeof(int) * 22222222);
//	if (p1 = p2)
//		printf("=");
//	else
//		printf("!=");
//	return 0;
//}


void test1()
{
	SLT* plist = NULL;
	SLtPushBack(&plist, 1);
	SLtPushBack(&plist, 2);
	SLtPushBack(&plist, 3);
	SLtPushBack(&plist, 4);

	SLtPrint(plist);

	SLtPushFront(&plist, 11);
	SLtPushFront(&plist, 22);
	SLtPushFront(&plist, 33);
	SLtPushFront(&plist, 44);

	SLtPrint(plist);
}

void test2()
{
	SLT* plist = NULL;

	SLtPushFront(&plist, 11);
	SLtPushFront(&plist, 22);
	SLtPushFront(&plist, 33);
	SLtPushFront(&plist, 44);

	SLtPrint(plist);
}

void test3()
{
	SLT* plist = NULL;

	//SLtPushFront(&plist, 11);
	//SLtPushFront(&plist, 22);
	//SLtPushFront(&plist, 33);
	//SLtPushFront(&plist, 44);
	SLtPrint(plist);

	//SLtPopBack(&plist);
	//SLtPopBack(&plist);
	//SLtPopBack(&plist);
	//SLtPopBack(&plist);
	//SLtPopBack(&plist);

	SLtPopFront(&plist);

	SLtPrint(plist);
}

void test4()
{
	SLT* plist = NULL;

	SLtPushFront(&plist, 11);
	SLtPushFront(&plist, 22);
	SLtPushFront(&plist, 22);
	SLtPushFront(&plist, 33);
	SLtPushFront(&plist, 22);
	SLtPushFront(&plist, 44);
	SLtPushFront(&plist, 22);
	SLtPrint(plist);

	SLT* pos = SListFind(plist, 22);
	int i = 1;
	while (pos)
	{
		printf("��%d��ret�ڵ�:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 22);
	}

	pos = SListFind(plist, 33);
	if (pos)
	{
		pos->data = 333;
	}
	SLtPrint(plist);
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}