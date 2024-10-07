#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct stack
{
    char* a;
    int top;
    int capacity;
}ST;

void STInit(ST* ps)
{
    assert(ps);

    ps->a = (char*)malloc(sizeof(char) * 4);
    if (ps->a == NULL)
    {
        perror("malloc fail:");
    }

    ps->capacity = 4;
    ps->top = -1;
}

void STDestroy(ST* ps)
{
    assert(ps);

    free(ps->a);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = -1;
}

void STPush(ST* ps, char x)
{
    assert(ps);

    if (ps->top == ps->capacity - 1)
    {
        char* ptr = (char*)realloc(ps->a, sizeof(char) * 2 * (ps->capacity));
        if (ptr == NULL)
        {
            perror("realloc fail:");
        }
        ps->a = ptr;
        ps->capacity *= 2;
    }

    ps->top++;
    ps->a[ps->top] = x;
}

bool STEmpty(ST* ps)
{
    return ps->top == -1;
}

void STPop(ST* ps)
{
    assert(ps);
    assert(!STEmpty(ps));

    ps->top--;
}


char STTop(ST* ps)
{
    assert(ps);
    assert(!STEmpty(ps));

    return ps->a[ps->top];
}

typedef struct {
    ST st1;
    ST st2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* Queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (Queue == NULL);
    {
        perror("mmalloc fail:");
    }

    STInit(&Queue->st1);
    STInit(&Queue->st2);

    return Queue;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);

    STPush(&obj->st1, x);
}

int myQueuePop(MyQueue* obj) {
    assert(obj);

    int top = myQueuePeek(obj);

    STPop(&obj->st2);
    return top;
}

int myQueuePeek(MyQueue* obj) {
    int top = 0;

    if (!STEmpty(&obj->st2))
    {
        top = STTop(&obj->st2);
    }
    else
    {
        while (!STEmpty(&obj->st1))
        {
            STPush(&obj->st2, STTop(&obj->st1));
            STPop(&obj->st1);
        }
        top = STTop(&obj->st2);
    }

    return top;
}

bool myQueueEmpty(MyQueue* obj) {
    return STEmpty(&obj->st1) && STEmpty(&obj->st2);
}

void myQueueFree(MyQueue* obj) {
    STDestroy(&obj->st1);
    STDestroy(&obj->st2);
    free(obj);
}