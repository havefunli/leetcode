//// 今天学习了完全背包
//// 感觉只要理解了 0-1背包，这个也不是很苦难 哈哈
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//int main()
//{
//    int n = 0, bagsize = 0;
//    std::cin >> n >> bagsize;
//
//    std::vector<int> weight(n, 0);
//    std::vector<int> value(n, 0);
//    for (int i = 0; i < n; i++)
//    {
//        std::cin >> weight[i] >> value[i];
//    }
//
//    std::vector<int> dp(bagsize + 1, 0);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = weight[i]; j <= bagsize; j++)
//        {
//            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
//        }
//    }
//
//    std::cout << dp[bagsize] << std::endl;
//
//
//    return 0;
//}
//
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        vector<uint64_t> dp(amount + 1, 0);
//        dp[0] = 1;
//
//        for (int i = 0; i < coins.size(); i++)
//        {
//            for (int j = coins[i]; j <= amount; j++)
//            {
//                dp[j] += dp[j - coins[i]];
//            }
//        }
//
//        return dp[amount];
//    }
//};
//
//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        vector<uint32_t> dp(target + 1, 0);
//        dp[0] = 1;
//
//        for (int i = 0; i <= target; i++)
//        {
//            for (int j = 0; j < nums.size(); j++)
//            {
//                if (i >= nums[j])
//                    dp[i] += dp[i - nums[j]];
//            }
//        }
//
//        return dp[target];
//    }
//};
//
//#include <iostream>
//#include <vector>
//
//int main()
//{
//    int n = 0, m = 0;
//    std::cin >> n >> m;
//
//    std::vector<uint32_t> dp(n + 1, 0);
//    dp[0] = 1;
//
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 1; j <= m && j <= i; j++)
//        {
//            dp[i] += dp[i - j];
//        }
//    }
//
//    std::cout << dp[n] << std::endl;
//
//    return 0;
//}
//
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        vector<uint32_t> dp(amount + 1, INT_MAX);
//        dp[0] = 0;
//
//        for (int i = 0; i < coins.size(); i++)
//        {
//            for (int j = coins[i]; j <= amount; j++)
//            {
//                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
//            }
//        }
//
//        return dp[amount] == INT_MAX ? -1 : dp[amount];
//    }
//};
//
//class Solution {
//public:
//    int numSquares(int n) {
//        vector<int> value;
//        for (int i = 1; i * i <= n; i++)
//        {
//            value.emplace_back(i * i);
//        }
//
//        vector<int> dp(n + 1, INT_MAX);
//        dp[0] = 0;
//        for (int i = 0; i < value.size(); i++)
//        {
//            for (int j = value[i]; j <= n; j++)
//            {
//                dp[j] = min(dp[j], dp[j - value[i]] + 1);
//            }
//        }
//
//        return dp[n] == INT_MAX ? 0 : dp[n];
//    }
//};