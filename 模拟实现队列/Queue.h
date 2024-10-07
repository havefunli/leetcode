#pragma once

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

void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);
void QueuePush(Queue* ps, QDataType x);
void QueuePop(Queue* ps);
bool QueueEmpty(Queue* ps);
int QueueSize(Queue* ps);
QDataType QueueFront(Queue* ps);
QDataType QueueBack(Queue* ps);


