//////class Solution {
//////public:
//////    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//////        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//////
//////        for (int i = 1; i <= nums1.size(); i++)
//////        {
//////            for (int j = 1; j <= nums2.size(); j++)
//////            {
//////                if (nums1[i - 1] == nums2[j - 1])
//////                    dp[i][j] = dp[i - 1][j - 1] + 1;
//////                else
//////                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//////            }
//////        }
//////
//////        return dp[nums1.size()][nums2.size()];
//////    }
//////};
////
////
////class Solution {
////public:
////    int maxSubArray(vector<int>& nums) {
////        vector<int> dp(nums);
////
////        int ans = dp[0];
////        for (int i = 1; i < nums.size(); i++)
////        {
////            dp[i] = max(dp[i], dp[i - 1] + dp[i]);
////            ans = max(dp[i], ans);
////        }
////
////        return ans;
////    }
////};
//
//class Solution {
//public:
//    bool isSubsequence(string s, string t) {
//        if (s == t) return true;
//
//        int pos = 0;
//        for (auto ch : s)
//        {
//            pos = t.find(ch, pos);
//            if (pos == string::npos) return false;
//            pos++;
//        }
//
//        return true;
//    }
//};