/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode* dummyNode1 = new ListNode(0);  // 存储小于 x 的节点
//        ListNode* dummyNode2 = new ListNode(0);  // 存储大于或等于 x 的节点
//
//        ListNode* cur1 = dummyNode1;  // 指向小于 x 部分的链表
//        ListNode* cur2 = dummyNode2;  // 指向大于等于 x 部分的链表
//
//        while (head) {
//            if (head->val < x) {
//                cur1->next = head;
//                cur1 = cur1->next;
//            }
//            else {
//                cur2->next = head;
//                cur2 = cur2->next;
//            }
//            head = head->next;
//        }
//
//        cur2->next = nullptr;
//        cur1->next = dummyNode2->next;
//
//        return dummyNode1->next;
//    }
//};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& nums, int l, int r) {
//        if (l > r) {
//            return nullptr;
//        }
//
//        int mid = (l + r) / 2;
//        TreeNode* root = new TreeNode(nums[mid]);
//        root->left = buildTree(nums, l, mid - 1);
//        root->right = buildTree(nums, mid + 1, r);
//
//        return root;
//    }
//
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        return buildTree(nums, 0, nums.size() - 1);
//    }
//};

#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit : num) {
            while (stk.size() > 0 && stk.back() > digit && k) {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k) {
            stk.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto& digit : stk) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            ans = max(ans, nums[i]);
        }

        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack;
        int area = 0;

        int n = height.size();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && height[stack.top()] < height[i]) {
                int mid = stack.top();
                stack.pop();

                if (!stack.empty()) {
                    int left = stack.top();

                    int w = i - left - 1;
                    int h = min(height[left], height[i]) - height[mid];
                    area += (h * w);
                }
            }
            stack.push(i);
        }

        return area;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 含义是 row[i][j] 第 i 行是否包含 j
        int row[9][10] = { 0 };
        int col[9][10] = { 0 };
        int box[9][10] = { 0 };

        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                if (row[i][num]) {
                    return false;
                }
                else {
                    row[i][num] = 1;
                }

                if (col[j][num]) {
                    return false;
                }
                else {
                    col[j][num] = 1;
                }

                if (box[j / 3 + (i / 3) * 3][num]) {
                    return false;
                }
                else {
                    box[j / 3 + (i / 3) * 3][num] = 1;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int l = 0, r = matrix[0].size();
        int t = 0, b = matrix.size();

        while (l <= r && t <= b) {
            // 左到右
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            if (++t > b) {
                break;
            }

            // 上到下
            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }

            // 右到左
            for (int i = r; r >= l; r--) {
                ans.push_back(matrix[b][i]);
            }
            if (--b < t) {
                break;
            }

            // 下到上
            for (int i = b; b >= t; b--) {
                ans.push_back(matrix[l][i]);
            }
            if (++l > r) {
                break;
            }
        }

        return ans;
    }
};