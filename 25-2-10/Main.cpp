class Solution {
public:
    void cal(stack<int>& stack, auto func) {
        int right = stack.top();
        stack.pop();
        int left = stack.top();
        stack.pop();

        stack.push(func(left, right));
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        int left, right;
        for (auto& c : tokens) {
            if (c == "+") {
                cal(stack, [](int left, int right) { return left + right; });
            }
            else if (c == "-") {
                cal(stack, [](int left, int right) { return left - right; });
            }
            else if (c == "*") {
                cal(stack, [](int left, int right) { return left * right; });
            }
            else if (c == "/") {
                cal(stack, [](int left, int right) { return left / right; });
            }
            else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};

class Solution {
public:
    int cntBits(int n) {
        int cnt = 0;
        while (n) {
            if (n & 1) {
                cnt += 1;
            }
            n = n >> 1;
        }
        return cnt;
    }

    bool isUnique(string astr) {
        int bits = 0;
        for (char c : astr) {
            bits |= (1 << (c - 'a')); // 标记出现位置
        }
        return astr.size() == cntBits(bits);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int minPro = nums[0];
        int maxPro = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                // 让 maxPro 尝试大的
                // 让 min 更小
                swap(minPro, maxPro);
            }

            // 维持之前的序列还是从当前开始
            minPro = min(nums[i], nums[i] * minPro);
            maxPro = max(nums[i], nums[i] * maxPro);
            ans = max(ans, maxPro);
        }

        return ans;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (auto& n : nums) {
            target += n;
        }
        // 是否是偶数
        if (target % 2 != 0) {
            return false;
        }

        target /= 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp.back() == target;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int ans = 0;
        for (auto& n : nums) {
            if (vote == 0) {
                ans = n;
            }
            ans == n ? vote++ : vote--;
        }
        return ans;
    }
};