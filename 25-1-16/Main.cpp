#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
using namespace std;

//int main() {
//    int n = 0;
//    cin >> n;
//
//    int target = 0;
//    vector<int> nums(n, 0);
//    for (int i = 0; i < n; i++) {
//        cin >> nums[i];
//        target += nums[i];
//    }
//
//    if (target % 2 != 0) {
//        cout << "false";
//        return 1;
//    }
//    target /= 2;
//
//    vector<int> dp(target + 1, 0);
//    for (int i = 0; i < n; i++) {
//        for (int j = target; j >= nums[i]; j--) {
//            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//        }
//    }
//
//    if (dp[target] == target) {
//        cout << "true";
//    }
//    else {
//        cout << "false";
//    }
//
//    return 0;
//}


//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<int> path;
//
//    void backTracking(int n, int k, int startIndex) {
//        if (path.size() == k) {
//            ans.push_back(path);
//            return;
//        }
//
//        for (int i = startIndex; i <= n; i++) {
//            path.push_back(i);
//            backTracking(n, k, i + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<vector<int>> combine(int n, int k) {
//        backTracking(n, k, 1);
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<int> path;
//
//    void backTracking(int n, int k, int startIndex) {
//        if (k == path.size()) {
//            if (n == 0) {
//                ans.push_back(path);
//            }
//            return;
//        }
//
//        for (int i = startIndex; n > 0 && i <= 9 - (k - path.size()) + 1; i++) {
//            n -= i;
//            path.push_back(i);
//            cout << i << " ";
//            backTracking(n, k, i + 1);
//            n += i;
//            path.pop_back();
//        }
//    }
//
//    vector<vector<int>> combinationSum3(int k, int n) {
//        backTracking(n, k, 1);
//        return ans;
//    }
//};

class Solution {
public:
    unordered_map<char, string> map{
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;
    string path;

    void backTracking(const std::string& digits, int startIndex) {
        if (startIndex == digits.size()) {
            ans.push_back(path);
            return;
        }

        string str = map[digits[startIndex]];
        for (int j = 0; j < str.size(); j++) {
            path.push_back(str[j]);
            backTracking(digits, startIndex + 1);
            path.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) {
            backTracking(digits, 0);
        }
        return ans;
    }
};

int main() {
    Solution().letterCombinations("23");
    return 0;
}