///**
// * Definition for singly-linked list.
//
// */
//
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
//class Solution {
//public:
//    ListNode* swapRecursion(ListNode* prev, ListNode* cur) {
//        if (cur == nullptr) {
//            return prev;
//        }
//        // 前后交换
//        ListNode* tmp = cur->next;
//        cur->next = prev;
//        // 递归过程
//        prev->next = (tmp == nullptr ? tmp : swapRecursion(tmp, tmp->next));
//        return cur;
//    }
//
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr) {
//            return head;
//        }
//
//        return swapRecursion(head, head->next);
//    }
//};
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* reverseList(ListNode* prev, ListNode* last) {
//        ListNode* backup = prev->next;
//
//        ListNode* begin = prev->next;
//        ListNode* end = last->next;
//        ListNode* old = end;
//        while (begin != end) {
//            ListNode* tmp = begin->next;
//            begin->next = old;
//            old = begin;
//            begin = tmp;
//        }
//        prev->next = last;
//
//        return backup;
//    }
//
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        ListNode* dummyNode = new ListNode(-1, head);
//
//        ListNode* cur = dummyNode;
//        ListNode* prev = cur;
//        ListNode* last = head;
//        for (int i = 0; cur != nullptr; i++) {
//            cur = cur->next;
//            // 判断是否需要旋转
//            if (cur != nullptr && (i + 1) % k == 0) {
//                last = cur;
//                // 位置会被改变
//                cur = reverseList(prev, last);
//                prev = cur;
//            }
//        }
//        return dummyNode->next;
//    }
//};
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* findMid(ListNode* head) {
//        if (head == nullptr) {
//            return head;
//        }
//
//        ListNode* slow = head;
//        ListNode* fast = head;
//
//        while (fast->next != nullptr && fast->next->next != nullptr) {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        // 断开连接
//        ListNode* mid = slow->next;
//        slow->next = nullptr;
//        return mid;
//    }
//
//    ListNode* mergeList(ListNode* left, ListNode* right) {
//        ListNode* dummyNode = new ListNode(-1);
//        ListNode* cur = dummyNode;
//
//        while (left != nullptr && right != nullptr) {
//            if (left->val < right->val) {
//                cur->next = left;
//                left = left->next;
//            }
//            else {
//                cur->next = right;
//                right = right->next;
//            }
//            cur = cur->next;
//        }
//
//        ListNode* node = (left == nullptr ? right : left);
//        while (node != nullptr) {
//            cur->next = node;
//            node = node->next;
//            cur = cur->next;
//        }
//        return dummyNode->next;
//    }
//
//    ListNode* sortList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        // 寻找分界点
//        // cout << head->val << " ";
//        ListNode* head1 = findMid(head);
//        // 分治
//        head = sortList(head);
//        head1 = sortList(head1);
//        // 合并
//        return mergeList(head, head1);
//    }
//};
//
//int main() {
//    ListNode head;
//    head.val = 4;
//    ListNode tail;
//    tail.val = 1;
//    head.next = &tail;
//
//    Solution().sortList(&head);
//
//    return 0;
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* mergeList(vector<ListNode*>& lists, int l, int r) {
//        if (l >= r) {
//            return lists[l];
//        }
//
//        int mid = (l + r) / 2;
//        // 分治
//        ListNode* left = mergeList(lists, l, mid);
//        ListNode* right = mergeList(lists, mid + 1, r);
//
//        // 合并
//        ListNode* dummyNode = new ListNode(-1);
//        ListNode* cur = dummyNode;
//        while (left != nullptr && right != nullptr) {
//            if (left->val < right->val) {
//                cur->next = left;
//                left = left->next;
//            }
//            else {
//                cur->next = right;
//                right = right->next;
//            }
//            cur = cur->next;
//        }
//        ListNode* node = (left != nullptr ? left : right);
//        while (node != nullptr) {
//            cur->next = node;
//            node = node->next;
//            cur = cur->next;
//        }
//
//        return dummyNode->next;
//    }
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if (lists.empty()) {
//            return nullptr;
//        }
//
//        return mergeList(lists, 0, lists.size() - 1);
//    }
//};