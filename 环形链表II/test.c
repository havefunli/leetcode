#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;  
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            struct ListNode* pos1 = head;
            struct ListNode* pos2 = fast;

            while (pos1 != pos2)
            {
                pos1 = pos1->next;
                pos2 = pos2->next;
            }

            return pos1;
        }

    }

    return NULL;
}