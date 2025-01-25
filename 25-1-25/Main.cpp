//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int ans = 0;
//
//        stack<int> st;
//        for (int i = 0; i < height.size(); i++) {
//            while (!st.empty() && height[i] > height[st.top()]) {
//                int bottom = height[st.top()];
//                st.pop();
//                if (!st.empty()) {
//                    int l = st.top();
//                    int h = min(height[i], height[l]) - bottom;
//                    ans += (h * (i - l - 1));
//                }
//            }
//            st.push(i);
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        sort(nums.begin(), nums.end());
//
//        for (int i = 0; i < nums.size() - 2; i++) {
//            // 剪枝
//            if (nums[i] > 0) {
//                return ans;
//            }
//            // 去重
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//
//            int target = 0 - nums[i];
//            int l = i + 1, r = nums.size() - 1;
//            while (l < r) {
//                while (l < r && nums[l] + nums[r] < target) {
//                    l += 1;
//                }
//                while (l < r && nums[l] + nums[r] > target) {
//                    r -= 1;
//                }
//                if (l < r && nums[l] + nums[r] == target) {
//                    ans.push_back({ nums[i], nums[l], nums[r] });
//                    // 去重
//                    while (l < r && nums[l] == nums[l + 1]) {
//                        l += 1;
//                    }
//                    l += 1;
//                    while (l < r && nums[r] == nums[r - 1]) {
//                        r -= 1;
//                    }
//                    r -= 1;
//                }
//            }
//        }
//
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int l = 0, r = height.size() - 1;
//
//        int ans = 0;
//        while (l < r) {
//            int w = r - l;
//            int h = min(height[l], height[r]);
//            ans = max(ans, w * h);
//
//            if (height[l] > height[r]) {
//                r--;
//            }
//            else {
//                l++;
//            }
//        }
//        return ans;
//    }
//};