//////#include <iostream>
//////
//////
//////// 根据一个成员变量的地址获取整个结构体对象的起始地址
////////typedef struct ListNode
////////{
////////	int _val;
////////	struct ListNode* next;
////////	struct ListNode* prev;
////////} ListNode;
////////
////////
////////int main()
////////{
////////	ListNode node;
////////	node._val = 1;
////////
////////	int offset = (size_t)&(((ListNode*)0)->next);
////////	std::cout << offset << std::endl;
////////	return 0;
////////}
//////
////////#include <iostream>
////////#include <algorithm>
////////#include <vector>
////////
////////int main()
////////{
////////    int m = 0, n = 0;
////////    std::cin >> m >> n;
////////
////////    std::vector<int> weight(m, 0);
////////    for (int i = 0; i < m; i++)
////////    {
////////        std::cin >> weight[i];
////////    }
////////    std::vector<int> value(m, 0);
////////    for (int i = 0; i < m; i++)
////////    {
////////        std::cin >> value[i];
////////    }
////////
////////    std::vector<int> dp(n + 1, 0);
////////    for (int i = 0; i < m; i++)
////////    {
////////        for (int j = n; j >= weight[i]; j--)
////////        {
////////            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
////////        }
////////    }
////////
////////    std::cout << dp[n] << std::endl;
////////
////////    return 0;
////////
//////// }
//////
//////
//////class Solution {
//////public:
//////    bool canPartition(vector<int>& nums) {
//////        int Sum = accumulate(nums.begin(), nums.end(), 0);
//////        if (Sum % 2 != 0) return false;
//////
//////        int target = Sum / 2;
//////        vector<int> dp(target + 1, 0);
//////        for (int i = 0; i < nums.size(); i++)
//////        {
//////            for (int j = target; j >= nums[i]; j--)
//////            {
//////                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//////            }
//////        }
//////
//////        return dp[target] == target ? true : false;
//////    }
//////};
////
////class Solution {
////public:
////    int lastStoneWeightII(vector<int>& stones) {
////        int Sum = accumulate(stones.begin(), stones.end(), 0);
////        int target = Sum / 2;
////
////        vector<int> dp(target + 1, 0);
////        for (int i = 0; i < stones.size(); i++)
////        {
////            for (int j = target; j >= stones[i]; j--)
////            {
////                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
////            }
////        }
////
////        return Sum - 2 * dp[target];
////    }
////};
//
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        int Sum = accumulate(nums.begin(), nums.end(), 0);
//        if (Sum < abs(target) || (Sum + target) % 2 != 0) return 0;
//        int bagsize = (target + Sum) / 2;
//
//        vector<int> dp(bagsize + 1, 0);
//        dp[0] = 1;
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            for (int j = bagsize; j >= nums[i]; j--)
//            {
//                dp[j] += dp[j - nums[i]];
//            }
//        }
//
//        return dp[bagsize];
//    }
//};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& str : strs)
        {
            int zeroNum = 0, oneNum = 0;
            for (auto c : str)
            {
                if (c == '0') zeroNum++;
                else oneNum++;
            }

            for (int i = m; i >= zeroNum; i--)
            {
                for (int j = n; j >= oneNum; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};