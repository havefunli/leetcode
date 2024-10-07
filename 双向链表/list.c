#define  _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newone = (LTNode*)malloc(sizeof(LTNode));
	if (newone == NULL)
	{
		perror("BuyListNode_malloc:");
		exit(-1);
	}

	newone->prev = NULL;
	newone->next = NULL;
	newone->val = x;
	
	return newone;
}

LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);

	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("<=phead=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
	
	printf("\n");
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTInsert(phead, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;

	free(tail);
	tail = NULL;
}

void LTPushFront(LTNode* phead,LTDataType x)
{
	assert(phead);

	LTInsert(phead->next, x);
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTNode* target = phead->next;
	LTNode* next = target->next;

	phead->next = next;
	next->prev = phead;

	free(target);
	target = NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newone = BuyListNode(x);

	newone->next = prev->next;
	pos->prev = newone;
	prev->next = newone;
	newone->prev = prev;
}