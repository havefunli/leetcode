#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;


//class Solution {
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        int area = 0;
//        heights.insert(heights.begin(), 0); // 避免元素过少情况
//        heights.push_back(0); // 避免升序
//        stack<int> st;
//
//        for (int i = 0; i < heights.size(); i++) {
//            while (!st.empty() && heights[i] < heights[st.top()]) {
//                int mid = st.top();
//                st.pop();
//                if (!st.empty()) {
//                    // 获取左边界
//                    int left = st.top();
//                    // 获取长度
//                    int width = (i - left - 1);
//                    area = max(area, (width * heights[mid]));
//                }
//            }
//            st.push(i);
//        }
//        return area;
//    }
//};


//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//
//        int ans = 0;
//        int index = s.size() - 1;
//        for (int i = g.size() - 1; i >= 0; i--) {
//            if (index >= 0 && s[index] >= g[i]) {
//                ans++;
//                index--;
//            }
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        if (nums.size() == 1) {
//            return 1;
//        }
//
//        // 计算差数组
//        vector<int> diff;
//        for (int i = 1; i < nums.size(); i++) {
//            diff.push_back(nums[i] - nums[i - 1]);
//        }
//
//        // dp 遍历
//        int maxLen = 1;
//        vector<int> dp(diff.size(), 1);
//        for (int i = 1; i < diff.size(); i++) {
//            if (diff[i] * diff[i - 1] < 0) {
//                dp[i] = dp[i - 1] + 1;
//                maxLen = max(maxLen, dp[i]);
//            }
//        }
//
//        return maxLen;
//    }
//};

//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        int cnt = 0;
//        int diff = 0;
//        int flag = 1;
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i - 1] == nums[i]) {
//                continue;
//            }
//            else {
//                if (flag == 1) {
//                    diff = nums[i] - nums[i - 1];
//                    cnt += 1;
//                    flag = 0;
//                }
//                else {
//                    int n = nums[i] - nums[i - 1];
//                    if (diff * n < 0) {
//                        diff = n;
//                        cnt += 1;
//                    }
//                }
//            }
//        }
//
//        return cnt + 1;
//    }
//};


//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int cover = 0;
//        for (int i = 0; i <= cover; i++) {
//            cover = max(cover, i + nums[i]);
//            cout << cover << " ";
//            if (cover >= nums.size() - 1) {
//                return true;
//            }
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        vector<int> dp(nums.size(), INT_MAX);
//
//        dp[0] = 0;
//        for (int i = 1; i < nums.size(); i++) {
//            for (int j = 0; j < i; j++) {
//                if (j + nums[j] >= i) {
//                    dp[i] = min(dp[i], dp[j] + 1);
//                }
//            }
//        }
//
//        return dp.back();
//    }
//};

//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        if (nums.size() == 1) {
//            return 0;
//        }
//
//        int ans = 0;
//        int curCover = 0;
//        int nextCover = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            nextCover = max(nextCover, i + nums[i]);
//            if (i == curCover) {
//                ans += 1;
//                curCover = nextCover;
//                if (nextCover >= nums.size() - 1) {
//                    break;
//                }
//            }
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        // 按照绝对值排序
//        sort(nums.begin(), nums.end(), [](const int& left, const int& right) {
//            return abs(left) > abs(right);
//            });
//        // 将负值变为正值
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] < 0 && k > 0) {
//                nums[i] *= -1;
//                k--;
//            }
//        }
//
//        if (k % 2 == 1) {
//            nums[nums.size() - 1] *= -1;
//        }
//
//        int ans = 0;
//        for (auto& n : nums) {
//            ans += n;
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int n = gas.size();
//
//        for (int i = 0; i < n; ) {
//            // 记录最远距离
//            int step = 0;
//            int gasLeft = 0;
//            while (step < n) {
//                int next = (i + step) % n;
//                gasLeft += (gas[next] - cost[next]);
//                if (gasLeft < 0) {
//                    break;
//                }
//                step++;
//            }
//            if (step == n) {
//                return i;
//            }
//            else {
//                i = i + step + 1;
//            }
//        }
//        return -1;
//    }
//};
//
//int main() {
//    vector<int> vec = { 1,7,4,9,2,5 };
//    Solution().wiggleMaxLength(vec);
//	return 0;
//}