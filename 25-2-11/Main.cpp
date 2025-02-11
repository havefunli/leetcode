//
//template <class T>
//T add(T left, T right) {
//	return left + right;
//}
//
//class Person{
//public:
//	int age = 1;
//};
//
//class Student : virtual public Person{
//public:
//	int score = 2;
//};
//
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        vector<int> dp(s.size(), 0);
//
//        int ans = 0;
//        for (int i = 1; i < s.size(); i++) {
//            // 只有 ）结尾才能形成括号
//            if (s[i] == ')') {
//                // ...()...
//                if (s[i - 1] == '(') {
//                    // dp[i] = dp[i - 2] + 2;
//                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//                }
//                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
//                    // ...(())...
//                    dp[i] = dp[i - 1]
//                        + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0)
//                        + 2;
//                }
//            }
//            ans = max(ans, dp[i]);
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//        // 初始列
//        for (int i = 0; i < m; i++) {
//            dp[i][0] = 1;
//        }
//        // 初始行
//        for (int i = 0; i < n; i++) {
//            dp[0][i] = 1;
//        }
//
//        // 遍历
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
//};
//
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        for (int i = 1; i < grid.size(); i++) {
//            grid[i][0] += grid[i - 1][0];
//        }
//        for (int j = 1; j < grid[0].size(); j++) {
//            grid[0][j] += grid[0][j - 1];
//        }
//
//        for (int i = 1; i < grid.size(); i++) {
//            for (int j = 1; j < grid[0].size(); j++) {
//                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
//            }
//        }
//        return grid.back().back();
//    }
//};
//
//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        int size1 = text1.size();
//        int size2 = text2.size();
//        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
//
//        for (int i = 1; i <= size1; i++) {
//            for (int j = 1; j <= size2; j++) {
//                if (text1[i - 1] == text2[j - 1]) {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp.back().back();
//    }
//};
//
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int ans = 0;
//        for (auto& n : nums) {
//            ans ^= n;
//        }
//        int n = nums.size();
//        for (int i = 0; i <= n; i++) {
//            ans ^= i;
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    int countSubstrings(string s) {
//        int size = s.size();
//        vector<vector<int>> dp(size, vector<int>(size, 0));
//
//        int ans = 0;
//        for (int i = size - 1; i >= 0; i--) {
//            for (int j = i; j < size; j++) {
//                if (s[i] == s[j]) {
//                    if (j - i < 2) {
//                        dp[i][j] = 1;
//                        ans += 1;
//                    }
//                    else if (dp[i + 1][j - 1] == 1) {
//                        dp[i][j] = 1;
//                        ans += 1;
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//};
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0;
        int left = 0;
        int right = 0;
        int len = 1;
        int maxLen = 0;

        // 中心扩散法
        for (int i = 0; i < s.size(); i++) {
            len = 1;
            left = i - 1;
            right = i + 1;

            // 向左扩散
            while (left >= 0 && s[left] == s[i]) {
                left -= 1;
                len += 1;
            }
            // 向右扩散
            while (right < s.size() && s[right] == s[i]) {
                right += 1;
                len += 1;
            }
            // 左右扩散
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left -= 1;
                right += 1;
                len += 2;
            }

            if (maxLen < len) {
                maxLen = len;
                begin = left;
            }
        }

        return s.substr(begin + 1, maxLen);
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0;
        int two = 0;
        for (auto& n : nums) {
            if (n == 1) {
                one += 1;
            }
            else if (n == 2) {
                two += 1;
            }
        }

        int index = 0;
        // 红色
        for (int i = 0; i < nums.size() - one - two; i++) {
            nums[index] = 0;
            index += 1;
        }
        // 白色
        for (int i = 0; i < one; i++) {
            nums[index] = 1;
            index += 1;
        }
        // 蓝色
        for (int i = 0; i < two; i++) {
            nums[index] = 2;
            index += 1;
        }
    }
};
