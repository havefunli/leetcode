//#include <iostream>
//#include <vector>
//#include <cmath>
//
//
//void InitVec(std::vector<int>& vec)
//{
//    for (int i = 0; i < vec.size(); i++)
//    {
//        std::cin >> vec[i];
//    }
//}
//
//int main()
//{
//    int bagsize = 0, n = 0;
//    std::cin >> bagsize >> n;
//
//    std::vector<int> weight(n, 0);
//    InitVec(weight);
//    std::vector<int> value(n, 0);
//    InitVec(value);
//    std::vector<int> nums(n, 0);
//    InitVec(nums);
//
//
//    for (int i = 0; i < n; i++)
//    {
//        while (nums[i] > 1)
//        {
//            weight.push_back(weight[i]);
//            value.push_back(value[i]);
//            nums[i]--;
//        }
//    }
//
//    std::vector<int> dp(bagsize + 1, 0);
//    for (int i = 0; i < weight.size(); i++)
//    {
//        for (int j = bagsize; j >= weight[i]; j--)
//        {
//            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
//        }
//    }
//
//    std::cout << dp[bagsize] << std::endl;
//
//    return 0;
//}
//
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if (nums.size() == 1) return nums[0];
//
//        vector<int> dp(nums.size(), 0);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//
//        for (int i = 2; i < nums.size(); i++)
//        {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//
//        return dp[nums.size() - 1];
//    }
//};
