#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct QList {
    struct QList* prev;
    struct QList* next;
    int val;
} QList;


typedef struct {
    QList* front;
    QList* rear;
    int size;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL)
    {
        perror("malloc fail:");
    }
    obj->front = NULL;
    obj->size = 0;
    obj->capacity = k;

    while (k--)
    {
        QList* newone = (QList*)malloc(sizeof(QList));
        if (obj->front == NULL)
        {
            obj->front = newone;
            obj->front->next = obj->front;
            obj->front->prev = obj->front;
            obj->rear = obj->front;
        }

        QList* prev = obj->front->prev;
        newone->next = prev->next;
        obj->front->prev = newone;
        prev->next = newone;
        newone->prev = prev;
    }

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);

    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);

    if (myCircularQueueIsFull(obj))
        return 0;
    else
    {
        if (obj->front == obj->rear)
            obj->rear->val = value;
        else
        {
            obj->rear->val = value;
        }
        obj->rear = obj->rear->next;
        obj->size++;
    }

    return 1;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return 0;
    else
    {
        obj->front = obj->front->next;
        obj->size--;
    }

    return 1;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return 0;
    else
    {
        return obj->front->val;
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return 0;
    else
    {
        return obj->rear->prev->val;
    }
}

void QLDestroy(QList* cur)
{
    assert(cur);

    QList* ps = cur->next;

    while (ps != cur)
    {
        QList* next = ps->next;
        free(ps);
        ps = next;
    }
    free(ps);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    QLDestroy(obj->front);

    free(obj);
}

int main()
{
    MyCircularQueue* obj = myCircularQueueCreate(6);
    bool result1 = myCircularQueueEnQueue(obj, 1);
    int a = myCircularQueueRear(obj);
    int b = myCircularQueueRear(obj);
    bool result2 = myCircularQueueDeQueue(obj);
    bool result3 = myCircularQueueEnQueue(obj, 5);
    int c = myCircularQueueRear(obj);
    bool result4 = myCircularQueueDeQueue(obj);
    int num = myCircularQueueFront(obj);
}