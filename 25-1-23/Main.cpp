#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    void split(string s, vector<string>& strs, char sep) {
//        strs.clear();
//        istringstream iss(s);
//
//        string tmp;
//        while (getline(iss, tmp, sep)) {
//            strs.push_back(tmp);
//        }
//    }
//
//    int longestSubstring(string s, int k) {
//        unordered_set<char> set(s.begin(), s.end());
//        unordered_map<char, int> map;
//        for (char c : s) {
//            map[c] += 1;
//        }
//
//        // 判断出现的 char 是否满足条件
//        for (char c : set) {
//            int ans = 0;
//            vector<string> strs;
//            if (map[c] < k) {
//                // 去除这个字符
//                split(s, strs, c);
//                for (string& str : strs) {
//                    if (str.size() >= k) {
//                        ans = max(ans, longestSubstring(str, k));
//                    }
//                }
//                return ans;
//            }
//        }
//        return s.size();
//    }
//};
//
//int main() {
//    Solution().longestSubstring("aaabb", 3);
//    return 0;
//}

//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<int> path;
//
//    void backtracking(int startIndex, int n, int k) {
//        if (path.size() == k) {
//            ans.push_back(path);
//            return;
//        }
//
//        for (int i = startIndex; i <= n; i++) {
//            path.push_back(i);
//            backtracking(i + 1, n, k);
//            path.pop_back();
//        }
//    }
//
//    vector<vector<int>> combine(int n, int k) {
//        backtracking(1, n, k);
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<int> path;
//
//    void backtracking(int start, int k, int n) {
//        if (path.size() == k) {
//            if (0 == n) {
//                ans.push_back(path);
//            }
//            return;
//        }
//
//        for (int i = start; i <= 9 && i <= n; i++) {
//            path.push_back(i);
//            n -= i;
//            backtracking(i + 1, k, n);
//            n += i;
//            path.pop_back();
//        }
//
//    }
//
//    vector<vector<int>> combinationSum3(int k, int n) {
//        backtracking(1, k, n);
//        return ans;
//    }
//};

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int>& nums, int target, int index) {
        if (target <= 0) {
            if (target == 0) {
                ans.push_back(path);
            }
        }

        for (int i = index; i < nums.size() && target >= 0; i++) {
            path.push_back(nums[i]);
            target -= nums[i];
            backtracking(nums, target, i);
            target += nums[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return ans;
    }
};


int main() {
    vector<int> nums = { 2,3,6,7 };
    Solution().combinationSum(nums, 9);
    return 0;
}
