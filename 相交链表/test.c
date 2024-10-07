#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int lenA = 1;
    int lenB = 1;

    while (tailA->next)
    {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next)
    {
        tailB = tailB->next;
        lenB++;
    }

    if (tailA != tailB)
    {
        return NULL;
    }

    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (lenA < lenB)
    {
       longlist = headB;
       shortlist = headA;
    }

    int gap = abs(lenA - lenB);
    while (gap--)
    {
        longlist = longlist->next;
    }

    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));


    n1->val = 1;
    n2->val = 2;
    n3->val = 4;
    n4->val = 5;
    n5->val = 6;


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    struct ListNode* m1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* m2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* m3 = (struct ListNode*)malloc(sizeof(struct ListNode));

    m1->val = 2;
    m2->val = 3;
    m3->val = 4;

    m1->next = m2;
    m2->next = m3;
    m3->next = n3;

    struct ListNode* cur = getIntersectionNode(n1, m1);
}