#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        stack<int> st;
//        vector<int> ans(temperatures.size(), 0);
//
//        st.push(0);
//        for (int i = 1; i < temperatures.size(); i++) {
//            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
//                ans[st.top()] = i - st.top();
//                st.pop();
//            }
//            st.push(i);
//        }
//
//        return ans;
//    }
//};


//class Solution {
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> ans(nums1.size(), -1);
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums1.size(); i++) {
//            map[nums1[i]] = i;
//        }
//
//        stack<int> st;
//        for (int i = 0; i < nums2.size(); i++) {
//            while (!st.empty() && nums2[i] > nums1[st.top()]) {
//                ans[st.top()] = nums2[i];
//                st.pop();
//            }
//            if (map.count(nums2[i])) {
//                st.push(map[nums2[i]]);
//            }
//        }
//
//        return ans;
//    }
//};

//int main(){
//    Solution s;
//    vector<int> vec = { 73,74,75,71,69,72,76,73 };
//    s.dailyTemperatures(vec);
//
//    return 0;
//}

//class Solution {
//public:
//    vector<int> nextGreaterElements(vector<int>& nums) {
//        int oldSize = nums.size();
//        for (int i = 0; i < oldSize; i++) {
//            nums.push_back(nums[i]);
//        }
//
//        stack<int> st;
//        vector<int> ans(oldSize, -1);
//        for (int i = 0; i < nums.size(); i++) {
//            while (!st.empty() && nums[i] > nums[st.top()]) {
//                ans[st.top()] = nums[i];
//                st.pop();
//                st.push(i);
//            }
//        }
//
//        return ans;
//    }
//};
//
//
//class Solution {
//public:
//    vector<int> nextGreaterElements(vector<int>& nums) {
//        int oldSize = nums.size();
//        for (int i = 0; i < oldSize; i++) {
//            nums.push_back(nums[i]);
//        }
//
//        stack<int> st;
//        vector<int> ans(oldSize, -1);
//        for (int i = 0; i < nums.size(); i++) {
//            while (!st.empty() && nums[i] > nums[st.top()]) {
//                if (st.top() < oldSize) {
//                    ans[st.top()] = nums[i];
//                }
//                st.pop();
//            }
//            st.push(i);
//        }
//
//        return ans;
//    }
//};

//int trap(vector<int>& height) {
//    stack<int> st;
//    // 找右边比我高的
//    vector<int> hRight(height.size(), -1);
//    for (int i = 0; i < height.size(); i++) {
//        while (!st.empty() && height[i] > height[st.top()]) {
//            hRight[st.top()] = i;
//            st.pop();
//        }
//        st.push(i);
//    }
//
//    while (!st.empty()) {
//        st.pop();
//    }
//
//    // 找左边比我高的
//    vector<int> hLeft(height.size(), -1);
//    for (int i = height.size() - 1; i >= 0; i--) {
//        while (!st.empty() && height[i] > height[st.top()]) {
//            hLeft[st.top()] = i;
//            st.pop();
//        }
//        st.push(i);
//    }
//
//    // 遍历柱子
//    int v = 0;
//    for (int i = 1; i < height.size(); i++) {
//        if (hLeft[i] == -1 || hRight[i] == -1) {
//            continue;
//        }
//        // 计算体积
//        int border = min(height[hLeft[i]], height[hRight[i]]);
//        v += (border - height[i]);
//    }
//
//    return v;
//}

int trap(vector<int>& height) {
    int v = 0;
    stack<int> st;
    st.push(0);

    for (int i = 1; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            // 获取中间元素
            int mid = height[st.top()];
            st.pop();
            if (!st.empty()) {
                int h = min(height[st.top()], height[i]) - mid;
                v += h * (i - st.top() - 1);
            }
        }
        st.push(i);
    }

    return v;
}

int main() {
    vector<int> vec = { 4,2,0,3,2,5 };
    trap(vec);
	return 0;
}