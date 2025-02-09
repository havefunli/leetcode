//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if (nums.size() == 1) {
//            return nums[0];
//        }
//        else if (nums.size() == 2) {
//            return max(nums[0], nums[1]);
//        }
//
//        vector<int> dp(nums.size(), 0);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//
//        for (int i = 2; i < nums.size(); i++) {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//        return dp.back();
//    }
//};
//
//class Solution {
//public:
//    int numSquares(int n) {
//        vector<int> dp(n + 1, INT_MAX);
//
//        dp[0] = 0;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j * j <= i; j++) {
//                dp[i] = min(dp[i], dp[i - j * j] + 1);
//            }
//        }
//        return dp.back();
//    }
//};
//
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        vector<int> dp(amount + 1, INT_MAX);
//        dp[0] = 0;
//
//        for (int i = 0; i < coins.size(); i++) {
//            for (int j = coins[i]; j <= amount; j++) {
//                // 存在有些面额不能组成
//                if (dp[j - coins[i]] != INT_MAX) {
//                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
//                }
//            }
//        }
//        return dp.back() == INT_MAX ? -1 : dp.back();
//    }
//};
//
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        unordered_set<string> set(wordDict.begin(), wordDict.end());
//
//        vector<bool> dp(s.size() + 1, false);
//        dp[0] = true;
//        for (int i = 0; i <= s.size(); i++) {
//            for (int j = 0; j < i; j++) {
//                string str = s.substr(j, i - j);
//                if (dp[j] && set.find(str) != set.end()) {
//                    dp[i] = true;
//                }
//            }
//        }
//        return dp.back();
//    }
//};