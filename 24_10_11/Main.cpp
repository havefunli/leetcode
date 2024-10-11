#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//int main()
//{
//    int m, n;
//    std::cin >> m >> n;
//
//    std::vector<int> weight(m, 0);
//    for (int i = 0; i < m; i++)
//    {
//        std::cin >> weight[i];
//    }
//    std::vector<int> value(m, 0);
//    for (int i = 0; i < m; i++)
//    {
//        std::cin >> value[i];
//    }
//
//    std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1, 0));
//    for (int i = weight[0]; i <= n; i++)
//    {
//        dp[0][i] = value[0];
//    }
//
//    for (int i = 1; i < m; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            if (j >= weight[i])
//            {
//                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//            }
//            else
//            {
//                dp[i][j] = dp[i - 1][j];
//            }
//        }
//    }
//
//    std::cout << dp[m - 1][n] << std::endl;
//
//    return 0;
//}

//int main()
//{
//	std::cout << 3 / 2 * 2 << std::endl;
//	return 0;
//}

//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int target = 0;
//        for (int i = 0; i < nums.size(); i++) target += nums[i];
//        if (target % 2 == 1) return false;
//        target /= 2;
//
//        vector<int> dp(target + 1, 0);
//        for (int i = 0; i < nums.size(); i++)
//        {
//            for (int j = target; j >= nums[i]; j--)
//            {
//                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//            }
//        }
//
//        return dp[target] == target;
//    }
//};
//
//class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones) {
//        int Sum = accumulate(stones.begin(), stones.end(), 0);
//        int target = Sum / 2;
//
//        vector<int> dp(target + 1, 0);
//        for (int i = 0; i < stones.size(); i++)
//        {
//            for (int j = target; j >= stones[i]; j--)
//            {
//                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
//            }
//        }
//
//        return Sum - 2 * dp[target];
//    }
//};