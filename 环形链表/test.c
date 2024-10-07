#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
    struct ListNode* fast = head->next;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        if (fast == slow)
            return true;
        fast = fast->next->next;
        slow = slow->next;
    }

    return false;
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));


    n1->val = 1;
    n2->val = 2;
    n3->val = 4;

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    bool result = hasCycle(n1);

    printf("%d \n", result);
}