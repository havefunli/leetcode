//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        vector<int> dp(nums.size(), 1);
//
//        int ans = 1;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = i - 1; j >= 0; j--)
//            {
//                if (nums[j] < nums[i])
//                {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//
//                ans = max(ans, dp[i]);
//            }
//
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int findLengthOfLCIS(vector<int>& nums) {
//        int ans = 1;
//        vector<int> dp(nums.size(), 1);
//
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
//            cout << dp[i - 1] << endl;
//            ans = max(ans, dp[i]);
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> dp(nums1.size(), 0);
//
//        int ans = 0;
//        for (int i = 0; i < nums2.size(); i++)
//        {
//            for (int j = nums1.size() - 1; j >= 0; j--)
//            {
//                if (nums2[i] == nums1[j])
//                {
//                    if (j != 0)
//                    {
//                        dp[j] = dp[j - 1] + 1;
//                    }
//                    else
//                    {
//                        dp[j] = 1;
//                    }
//                }
//                // 为什么需要赋值的操作呢？
//                // 因为dp[i] 的意义的是以 i 结尾的数相同的长度
//                else
//                {
//                    dp[j] = 0;
//                }
//                ans = max(ans, dp[j]);
//            }
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
//
//        for (int i = 1; i <= text1.size(); i++)
//        {
//            for (int j = 1; j <= text2.size(); j++)
//            {
//                if (text1[i - 1] == text2[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp[text1.size()][text2.size()];
//    }
//};
