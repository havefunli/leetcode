#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };


struct ListNode* find_target(struct ListNode* head, struct ListNode* pos)
{
    if (head == pos)
        return head;
    while (head->next != pos)
    {
        head = head->next;
    }
    struct ListNode* target = head;
    return target;
}


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    struct ListNode* ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    struct ListNode* Newhead = ptr->next;
    Newhead->next = ptr;

    while (1)
    {
        struct ListNode* target = find_target(head, ptr);
        if (target == head)
        {
            ptr->next = head;
            head->next = NULL;
            break;
        }
        ptr->next = target;
        ptr = target;
    }

    return Newhead;

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

    struct ListNode*head = reverseList(n1);

    while (head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL");
}