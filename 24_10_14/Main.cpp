public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if (Sum < abs(target)) return 0;
        if ((Sum + target) % 2 != 0) return 0;

        target = (Sum + target) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& str : strs)
        {
            int onenum = 0, zeronum = 0;
            for (auto c : str)
            {
                if (c == '1') onenum++;
                else zeronum++;
            }

            for (int i = m; i >= zeronum; i--)
            {
                for (int j = n; j >= onenum; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeronum][j - onenum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};