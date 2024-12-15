#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


//class Solution {
//public:
//    int calculate(string s) {
//        int size = s.size();
//        stack<int> st;
//        int left = 0;
//        char op = '+';
//        for (int i = 0; i < size; i++) {
//
//            if (s[i] == ' ') {
//                continue;
//            }
//            else if (s[i] == '-' || s[i] == '+') {
//                op = s[i];
//            }
//            else if (s[i] == '(') {
//                int nextPos = s.find(')', i + 1);
//                int val = calculate(s.substr(i + 1, nextPos - i - 1));
//                left += val;
//            }
//            else {
//                if (op == '+') {
//                    left += (s[i] - '0');
//                }
//                else {
//                    left -= (s[i] - '0');
//                }
//            }
//        }
//
//        return left;
//    }
//};

//int main() {
//    Solution s;
//    string str = "(1+(4+5+2)-3)+(6+8)";
//    s.calculate(str);
//	return 0;
//}

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        ListNode* dummyNode = new ListNode(-1);
//        dummyNode->next = head;
//        ListNode* cur = dummyNode;
//
//        ListNode* prev = nullptr;
//        ListNode* last = nullptr;
//        for (int cnt = 0; cur != nullptr; cnt++) {
//            if (cnt == left - 1) {
//                prev = cur;
//            }
//            else if (cnt == right) {
//                last = cur;
//            }
//            cur = cur->next;
//        }
//
//        ListNode* start = prev->next;
//        ListNode* end = last->next;
//        ListNode* node = end;
//        while (start != end) {
//            ListNode* next = start->next;
//            start->next = node;
//            node = start;
//            start = next;
//        }
//        prev->next = last;
//
//        return dummyNode->next;
//    }
//};

//class Solution {
//public:
//
//    ListNode* reverseList(ListNode* prev, ListNode* last) {
//        ListNode* backup = prev->next;
//        ListNode* start = prev->next;
//        ListNode* end = last->next;
//        ListNode* old = end;
//        while (start != end) {
//            ListNode* next = start->next;
//            start->next = old;
//            old = start;
//            start = next;
//        }
//        prev->next = last;
//        return backup;
//    }
//
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        ListNode* dummyNode = new ListNode(-1);
//        dummyNode->next = head;
//
//        ListNode* cur = dummyNode;
//        ListNode* prev = cur, * last;
//        for (int i = 0; cur; i++) {
//            cur = cur->next;
//            if (cur != nullptr && (i + 1) % k == 0) {
//                last = cur;
//                cur = reverseList(prev, last);
//                prev = cur;
//            }
//        }
//
//        return dummyNode->next;
//    }
//};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        auto cur = &dummy;
        while (cur->next && cur->next->next) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                while (cur->next && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }

        // 闭环
        int len = 1;
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
            len++;
        }
        cur->next = head;
        // 步数
        int step = len - k % len + len - 1;
        // 找到断开的位置
        cur = head;
        for (int i = 0; i < step; i++) {
            cur = cur->next;
            if (i + 1 == len - k % len) {
                head = cur;
            }
        }
        cur->next = nullptr;
        return head;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;    
    cur->next = new ListNode(4);
    cur = cur->next;    
    cur->next = new ListNode(5);

    Solution().rotateRight(head, 2);

    return 0;
}

