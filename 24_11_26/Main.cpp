//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        vector<int> tmp = nums;
//
//        int len = nums.size();
//        for (int i = 0; i < nums.size(); i++)
//        {
//            tmp[(i + k) % len] = nums[i];
//        }
//
//        nums = tmp;
//    }
//};
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<int> dp(2, 0);
//        dp[1] = -prices[0];
//
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[0] = max(dp[0], dp[1] + prices[i]);
//            dp[1] = max(dp[1], -prices[i]);
//        }
//        return dp[0];
//    }
//};
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        vector<int> dp(2, 0);
//        dp[1] = -prices[0];
//
//        for (int i = 1; i < prices.size(); i++)
//        {
//            int money = dp[0];
//            dp[0] = max(dp[0], dp[1] + prices[i]);
//            dp[1] = max(dp[1], money - prices[i]);
//        }
//
//        return dp[0];
//    }
//};
//
//class Solution {
//public:
//    void Jump(vector<bool>& jump, int begin, int step)
//    {
//        for (int i = 1; i <= step; i++)
//        {
//            if (begin + i >= jump.size()) { return; }
//            jump[begin + i] = true;
//        }
//    }
//
//    bool canJump(vector<int>& nums) {
//        if (nums.size() == 0 || nums.size() == 1) { return true; }
//
//        vector<bool> jump(nums.size());
//        jump[0] = true;
//
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            int num = nums[i];
//            if (!jump[i]) { continue; }
//            Jump(jump, i, num);
//        }
//
//        return jump.back();
//    }
//};
//
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        if (nums.size() == 0 || nums.size() == 1) { return 0; }
//
//        vector<int> dp(nums.size(), INT_MAX);
//        dp[0] = 0;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = i - 1; j >= 0; j--)
//            {
//                if (nums[j] >= (i - j))
//                {
//                    dp[i] = min(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        return dp.back();
//    }
//};


int main()
{
	return 0;
}