//class Solution {
//public:
//    string minWindow(string s, string t) {
//        if (s.size() < t.size()) {
//            return "";
//        }
//
//        // 记录字符种类以及个数
//        int cnt = 0;
//        unordered_map<char, int> map;
//        for (char c : t) {
//            if (map[c] == 0) {
//                cnt += 1;
//            }
//            map[c] += 1;
//        }
//
//        int l = 0, n = s.size();
//        int ans_left = -1, ans_right = n;
//        for (int r = 0; r < n; r++) {
//            char c = s[r];
//            map[c] -= 1;
//
//            if (map[c] == 0) {
//                cnt -= 1;
//            }
//            // 覆盖
//            while (cnt == 0) {
//                // 更新
//                if (ans_right - ans_left > r - l) {
//                    ans_left = l;
//                    ans_right = r;
//                }
//                if (map[s[l]] == 0) {
//                    cnt += 1;
//                }
//                map[s[l]] += 1;
//                l += 1;
//            }
//        }
//        return ans_right == n ? "" : s.substr(ans_left, ans_right - ans_left + 1);
//    }
//};
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
//            ans = max(ans, nums[i]);
//        }
//
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    unordered_set<int> set;
//
//    // int findNext(int n) {
//    //     if (set.find(n + 1) == set.end()) {
//    //         return n + 1;
//    //     }
//    //     return findNext(n + 1);
//    // }
//
//    int firstMissingPositive(vector<int>& nums) {
//        int max = INT_MIN;
//        for (int& n : nums) {
//            set.insert(n);
//            if (n >= 0 && n > max) {
//                max = n;
//            }
//        }
//
//        if (max <= 0) {
//            return 1;
//        }
//
//        for (int i = 1; i <= max; i++) {
//            if (set.find(i) == set.end()) {
//                return i;
//            }
//        }
//        return max + 1;
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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* head = new ListNode(-1, l1);
//        ListNode* cur = head;
//
//        int carry = 0;
//        while (l1 != nullptr && l2 != nullptr) {
//            // 相加过程
//            int val = l1->val + l2->val + carry;
//            carry = val / 10;
//            l1->val = val % 10;
//            // 遍历
//            l1 = l1->next;
//            l2 = l2->next;
//            cur = cur->next;
//        }
//
//        ListNode* l3 = (l1 == nullptr ? l2 : l1);
//        while (l3 != nullptr) {
//            int val = l3->val + carry;
//            carry = val / 10;
//            l3->val = val % 10;
//
//            cur->next = l3;
//            cur = cur->next;
//            l3 = l3->next;
//        }
//
//        // 还剩一个余数
//        if (carry != 0) {
//            cur->next = new ListNode(carry);
//        }
//
//        return head->next;
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
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummyNode = new ListNode(-1, head);
//        ListNode* fast = head;
//        ListNode* slow = dummyNode;
//        for (int i = 0; i < n; i++) {
//            fast = fast->next;
//        }
//
//        while (fast != nullptr) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        slow->next = slow->next->next;
//
//        return dummyNode->next;
//    }
//};