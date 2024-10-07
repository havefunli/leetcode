#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

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

	ps->head = NULL;
	ps->tail = NULL;
	ps->size = 0;
}

void QueueDesTroy(Queue* ps)
{
	assert(ps);

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
		return;
	}

	NewNode->val = x;
	NewNode->next = NULL;
	if (ps->head == NULL)
	{
		assert(ps->tail == NULL);

		ps->head = NewNode;
		ps->tail = NewNode;
	}
	else
	{
		ps->tail->next = NewNode;
		ps->tail = NewNode;
	}
	ps->size++;
}

void QueuePop(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));

	if (ps->head == ps->tail)
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

QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));

	return ps->tail->val;
}


typedef struct {
	Queue q1;
	Queue q2;

} MyStack;


MyStack* myStackCreate() {
	MyStack* ptr = (MyStack*)malloc(sizeof(MyStack));
	if (ptr == NULL)
	{
		perror("malloc_fail:");
	}

	QueueInit(&(ptr->q1));
	QueueInit(&(ptr->q2));

	return ptr;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		Queue* empty = &obj->q2;
		Queue* nonempty = &obj->q1;
	}

	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}

	int top = QueueFront(nonempty);
	QueuePop(nonempty);

	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2))
	{
		return true;
	}

	return false;
}

void myStackFree(MyStack* obj) {
	QueueDesTroy(&obj->q1);
	QueueDesTroy(&obj->q2);

	free(obj);
	obj = NULL;
}

int main()
{
	MyStack* ps = myStackCreate();
	myStackPush(ps, 1);
	myStackPush(ps, 2);

	int num = myStackTop(ps);
	printf("%d\n", num);

	myStackPop(ps);
	myStackPop(ps);

	myStackEmpty(ps);
}