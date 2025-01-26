////#include <iostream>
////#include <vector>
////#include <string>
////#include <unordered_map>
////using namespace std;
////
//////class Solution {
//////public:
//////    vector<int> findAnagrams(string s, string p) {
//////        if (s.size() < p.size()) {
//////            return {};
//////        }
//////
//////        vector<int> ans;
//////        unordered_map<char, int> map;
//////        for (char c : p) {
//////            map[c] += 1;
//////        }
//////
//////        int l = 0, n = s.size();
//////        for (int r = 0; r < n; r++) {
//////            char c = s[r];
//////            map[c] -= 1;
//////
//////            // 收缩左区间
//////            while (map[c] < 0) {
//////                map[s[l]] += 1;
//////                l += 1;
//////            }
//////
//////            // 长度满足
//////            if (r - l + 1 == p.size()) {
//////                ans.push_back(l);
//////            }
//////        }
//////
//////        return ans;
//////    }
//////};
////
////
////class Solution {
////public:
////    int lengthOfLongestSubstring(string s) {
////        if (s.empty()) {
////            return 0;
////        }
////
////        // 统计窗口出现的字符
////        unordered_map<char, int> map;
////
////        int ans = 0;
////        int l = 0;
////        for (int r = 0; r < s.size(); r++) {
////            char c = s[r];
////            map[c] += 1;
////            // 判断是否重复了
////            if (map[c] != 1) {
////                // 窗口收缩
////                while (map[c] != 1) {
////                    map[s[l]] -= 1;
////                    l++;
////                }
////            }
////            ans = max(ans, r - l + 1);
////        }
////        return ans;
////    }
////};
////
////class Solution {
////public:
////    int subarraySum(vector<int>& nums, int k) {
////        unordered_map<int, int> map;
////        map[0] = 1;
////
////        int sum = 0, cnt = 0;
////        for (int& num : nums) {
////            sum += num;
////
////            int target = sum - k;
////            if (map.find(target) != map.end()) {
////                // 目标为 target 的前缀和不止一个
////                cnt += map[target];
////            }
////            map[sum] += 1;
////        }
////
////        return cnt;
////    }
////};
////
////int main() {
////    Solution().subarraySum({1, 1, 1}, 2);
////    return 0;
////}
//
//
////class Solution {
////public:
////    int subarraySum(vector<int>& nums, int k) {
////        unordered_map<int, int> map;
////        map[0] = 1;
////
////        int sum = 0, cnt = 0;
////        for (int& num : nums) {
////            sum += num;
////
////            int target = sum - k;
////            if (map.find(target) != map.end()) {
////                // 目标为 target 的前缀和不止一个
////                cnt += map[target];
////            }
////            map[sum] += 1;
////        }
////
////        return cnt;
////    }
////};
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
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* dummyNode = new ListNode(-1, nullptr);
//
//        ListNode* cur = dummyNode;
//        while (list1 != nullptr && list2 != nullptr) {
//            if (list1->val < list2->val) {
//                cur->next = list1;
//                list1 = list1->next;
//            }
//            else {
//                cur->next = list2;
//                list2 = list2->next;
//            }
//            cur = cur->next;
//        }
//
//        cur->next = list1 == nullptr ? list2 : list1;
//
//        return dummyNode->next;
//    }
//};