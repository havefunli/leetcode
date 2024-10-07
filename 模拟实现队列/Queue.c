#define  _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

bool QueueEmpty(Queue* ps)
{
	assert(ps);

	return ps->size == 0;
}

int QueueSize(Queue* ps)
{
	assert(ps);

	return ps->size;
}

void QueueInit(Queue* ps)
{
	assert(ps);

	ps-> head = NULL;
	ps->tail = NULL;
	ps->size = 0;
}

void QueueDesTroy(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	
	while (ps->head)
	{
		QNode* Next = ps->head->next;
		free(ps->head);
		ps->head = Next;
	}
	ps->size = 0;
	ps->head = ps->tail = NULL;
}

void QueuePush(Queue* ps, QDataType x)
{
	assert(ps);

	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if (NewNode == NULL)
	{
		perror("malloc_fail:");
	}
	
	NewNode->val = x;
	NewNode->next = NULL;
	if (ps->head == NULL)
	{
		ps->head = NewNode;
	}
	else
	{
		ps->tail->next = NewNode;
	}
	ps->size++;
}

void QueuePop(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));

	if (ps->head->next == ps->tail)
	{
		free(ps->head);
		ps->head = NULL;
		ps->tail = NULL;
	}
	else
	{
		QNode* Next = ps->head->next;
		free(ps->head);
		ps->head = Next;
	}

	ps->size--;
}

QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));

	return ps->head->val;
}

QDataType QueuePop(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));

	return ps->tail->val;
}