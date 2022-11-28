#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLT;

void SLtPrint(SLT*phead);

void SLtPushBack(SLT** pphead, SLTDataType x);

void SLtPushFront(SLT** pphead, SLTDataType x);

void SLtPopBack(SLT** pphead);

void SLtPopFront(SLT** pphead);

SLT* SListFind(SLT* plist, SLTDataType x);