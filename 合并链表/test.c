#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h> 

struct ListNode {
    int val;
    struct ListNode* next;
};

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    else if (list2 == NULL)
//    {
//        return list1;
//    }
//
//    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newhead->next = list1;
//    struct ListNode* ps1 = newhead;
//    struct ListNode* ptr = list2;
//
//    while (list2 && ps1->next)
//    {
//        if (ps1->next->val >= list2->val)
//        {
//            ptr = list2->next;
//            list2->next = ps1->next;
//            ps1->next = list2;
//            list2 = ptr;
//        }
//        else
//        {
//              ps1 = ps1->next;
//        }
//    }
//    if (ps1->next == NULL)
//    {
//        while (list1->next != NULL)
//        {
//            list1 = list1->next;
//        }
//
//        list1->next = list2;
//    }
//
//    return newhead->next;
//}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            if (head == NULL)
            {
                head = list1;
                tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;

        }
        else
        {
            if (head == NULL)
            {
                head = list2;
                tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;

        }
    }

    if (list1 == NULL)
    {
        tail->next = list2;
    }
    if (list2 == NULL)
    {
        tail->next = list1;
    }

    return head;
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
    n3->next = NULL;

    struct ListNode* m1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* m2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* m3 = (struct ListNode*)malloc(sizeof(struct ListNode));


    m1->val = 2;
    m2->val = 3;
    m3->val = 4;


    m1->next = m2;
    m2->next = m3;
    m3->next = NULL;

    struct ListNode* newhead = mergeTwoLists(n1, m1);

    while (newhead)
    {
        printf("%d ", newhead->val);
        newhead = newhead->next;
    }
}