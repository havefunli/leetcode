#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* pHead, int x)
{
    // write code here
    struct ListNode* greatphead = NULL;
    struct ListNode* smallphead = NULL;
    struct ListNode* greattail = NULL;
    struct ListNode* smalltail = NULL;

    while (pHead) {
        if (pHead->val < x) {
            if (smallphead == NULL) {
                smallphead = pHead;
                smalltail = pHead;
            }
            else {
                smalltail->next = pHead;
                smalltail = smalltail->next;
            }
            pHead = pHead->next;
        }
        else {
            if (greatphead == NULL) {
                greatphead = pHead;
                greattail = pHead;
            }
            else {
                greattail->next = pHead;
                greattail = greattail->next;
            }
            pHead = pHead->next;
        }
    }
    if(greatphead)
        greattail->next = NULL;

    if (smallphead == NULL) {
        return greatphead;
    }
    else {
        smalltail->next = greatphead;
        return smallphead;
    }
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    n1->val = 1;
    n2->val = 1;
    n3->val = 1;
    n4->val = 1;
    n5->val = 1;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    n5->next = NULL;

    struct ListNode* newhead = partition(n1, 5);

    while (newhead)
    {
        printf("%d ", newhead->val);
        newhead = newhead->next;
    }
}

