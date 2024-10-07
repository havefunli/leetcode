#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php -> ps = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (php -> ps == NULL)
	{
		perror("malloc_fail:");
	}

	php->size = 0;
	php->capacity = 4;
}

bool HeapEmpty(HP* php)
{
	return php->size == 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	if (!HeapEmpty(php))
	{
		free(php->ps);
		php->capacity = 0;
		php->size = 0;
	}
	free(php);
	php = NULL;
}

void swap(HPDataType* p1, HPDataType p2)
{
	HPDataType* temp = p1;
	p1 = p2;
	p2 = temp;
}

void AdjustUp(HPDataType* a, int child)
{
	assert(a);

	while(child > 0)
	{
		int parent = (child - 1) / 2;
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		HPDataType* ptr = (HPDataType*)realloc(php->ps, sizeof(HPDataType) * 2 * php->capacity);
		if (ptr == NULL)
		{
			perror("realloc_fail:");
			return;
		}
		php->ps = ptr;
		php->capacity *= 2;
	}

	php->ps[php->size] = x;
	php->size++;

	AdjustUp(php->ps, php->size - 1);
}

void AdjustDown(HPDataType* a,int n,int parent)
{
	int child = 2 * parent + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	swap(&php->ps[php->size - 1], &php->ps[0]);
	php->size--;

	AdjustDown(php->ps, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	
	if (!HeapEmpty(php))
		return php->ps[0];
}
int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}