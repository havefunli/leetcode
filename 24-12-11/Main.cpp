//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        if (s.size() == 0) {
//            return;
//        }
//
//        int l = 0, r = s.size() - 1;
//        while (l < r) {
//            swap(s[l++], s[r--]);
//        }
//        return;
//    }
//};
//
//
//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        int fast = 0, slow = 0;
//        while (true) {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//            if (fast == slow) {
//                break;
//            }
//        }
//
//        int begin = 0;
//        while (true) {
//            slow = nums[slow];
//            begin = nums[begin];
//            if (begin == slow) {
//                break;
//            }
//        }
//        return slow;
//    }
//};
//
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        unordered_map<string, vector<string>> map;
//        for (auto str : strs) {
//            string sort_str = str;
//            sort(sort_str.begin(), sort_str.end());
//            map[sort_str].push_back(str);
//        }
//
//        vector<vector<string>> ans;
//        for (auto pair : map) {
//            ans.push_back(pair.second);
//        }
//        return ans;
//    }
//};