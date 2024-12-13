//class Solution {
//public:
//    vector<string> summaryRanges(vector<int>& nums) {
//        if (nums.size() == 0) {
//            return {};
//        }
//
//        // unordered_set<int> set;
//        // for (auto& n : nums) {
//        //     set.insert(n);
//        // }
//
//        vector<string> ans;
//        int l = 0;
//        for (int r = 0; r < nums.size() - 1; r++) {
//            if (nums[r] + 1 != nums[r + 1]) {
//                if (r == l) {
//                    ans.push_back(to_string(nums[l]));
//                }
//                else {
//                    ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
//                }
//                l = r + 1;
//            }
//        }
//        if (l == nums.size() - 1) {
//            ans.push_back(to_string(nums[l]));
//        }
//        else {
//            ans.push_back(to_string(nums[l]) + "->" + to_string(nums.back()));
//        }
//
//        return ans;
//    }
//};


//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(),
//            [](const vector<int>& left, const vector<int>& right) -> bool
//            {
//                return left[0] < right[0];
//            });
//
//        vector<vector<int>> ans;
//        vector<int> res = intervals[0];
//        for (int i = 1; i < intervals.size(); i++) {
//            if (intervals[i][0] >= res[0]
//                && intervals[i][0] <= res[1]) {
//                res[1] = max(intervals[i][1], res[1]);
//            }
//            else {
//                ans.push_back(res);
//                res = intervals[i];
//            }
//        }
//        ans.push_back(res);
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//        vector<vector<int>> ans;
//        int flag = 0;
//        for (int i = 0; i < intervals.size(); i++) {
//            // ÎÞ½»¼¯
//            if (intervals[i][0] > newInterval[1]) {
//                ans.push_back(newInterval);
//                newInterval = intervals[i];
//                flag = 1;
//            }
//            else if (intervals[i][1] < newInterval[0]) {
//                ans.push_back(intervals[i]);
//                flag = 0;
//            }
//            else {
//                newInterval[0] = min(intervals[i][0], newInterval[0]);
//                newInterval[1] = max(intervals[i][1], newInterval[1]);
//            }
//        }
//        if (flag) {
//            ans.push_back(intervals.back());
//        }
//        else {
//            ans.push_back(newInterval);
//        }
//        return ans;
//    }
//};



//class Solution {
//public:
//    bool isValid(string s) {
//        if (s.size() % 2 != 0) {
//            return false;
//        }
//
//        stack<char> stack;
//        for (auto& c : s) {
//            if (c == '(' || c == '[' || c == '{') {
//                stack.push(c);
//            }
//            else {
//                if (stack.empty()) {
//                    return false;
//                }
//                char top = stack.top();
//                if (c == ')' && top != '(') {
//                    return false;
//                }
//                else if (c == ']' && top != '[') {
//                    return false;
//                }
//                else if (c == '}' && top != '{') {
//                    return false;
//                }
//                stack.pop();
//            }
//        }
//        return stack.empty();
//    }
//};


//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        int leftDepth = maxDepth(root->left) + 1;
//        int rightDepth = maxDepth(root->right) + 1;
//
//        return leftDepth > rightDepth ? leftDepth : rightDepth;
//    }
//};