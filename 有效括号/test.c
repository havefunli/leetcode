#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

bool isValid(char* s) {
    ST st;
    STInit(&st);

    while (*s)
    {
        if (*s == '[' || *s == '{' || *s == '(')
            STPush(&st, *s);
        else
        {
            if (STEmpty(&st))
            {
                return false;
            }
            char top = STTop(&st);
            STPop(&st);

            if (*s == ')' && top != '(')
            {
                return false;
            }
            else if (*s == ']' && top != '[')
            {
                return false;
            }
            else if (*s == '}' && top != '{')
            {
                return false;
            }

        }
        s++;
    }

    if (!STEmpty(&st))
    {
        return false;
    }
    STDestroy(&st);

    return true;
}

int main()
{
    char* s = "[";
    bool result = isValid(s);

    printf("%d", result);
}