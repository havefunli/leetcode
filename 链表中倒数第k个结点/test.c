#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    if (pListHead == NULL)
    {
        return pListHead;
    }

    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;
    while (k--)
    {
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
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
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    struct ListNode* target = FindKthToTail(n1, 1);

    printf("%d \n", target->val);

    return 0;
}