//class Solution {
//public:
//    vector<vector<bool>> isValid;
//
//    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
//        // 找到了
//        if (index == word.size()) {
//            return true;
//        }
//        // 越界问题
//        if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0) {
//            return false;
//        }
//        // 访问过了
//        if (isValid[row][col]) {
//            return false;
//        }
//        // 不符合单词
//        if (word[index] != board[row][col]) {
//            return false;
//        }
//
//        isValid[row][col] = true;
//        if (dfs(board, row - 1, col, word, index + 1)
//            || dfs(board, row + 1, col, word, index + 1)
//            || dfs(board, row, col - 1, word, index + 1)
//            || dfs(board, row, col + 1, word, index + 1)) {
//            return true;
//        }
//        isValid[row][col] = false;
//        return false;
//    }
//
//    bool exist(vector<vector<char>>& board, string word) {
//        int m = board.size();
//        int n = board[0].size();
//        isValid = vector<vector<bool>>(m, vector<bool>(n, false));
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (dfs(board, i, j, word, 0)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class BSTIterator {
//private:
//    void insertAllLeft(TreeNode* leftNode) {
//        while (leftNode) {
//            stack.push(leftNode);
//            leftNode = leftNode->left;
//        }
//    }
//public:
//    BSTIterator(TreeNode* root) {
//        insertAllLeft(root);
//    }
//
//    int next() {
//        TreeNode* node = stack.top();
//        stack.pop();
//        insertAllLeft(node->right);
//        return node->val;
//    }
//
//    bool hasNext() {
//        return !stack.empty();
//    }
//private:
//    stack<TreeNode*> stack;
//};
//
//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        return 1 + countNodes(root->left) + countNodes(root->right);
//    }
//};
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == nullptr) {
//            return root;
//        }
//        if (root == p) {
//            return p;
//        }
//        else if (root == q) {
//            return q;
//        }
//
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//
//        if (left != nullptr && right != nullptr) {
//            return root;
//        }
//        else if (left == nullptr && right != nullptr) {
//            return right;
//        }
//        else {
//            return left;
//        }
//    }
//};
//
//class RangeFreqQuery {
//public:
//    RangeFreqQuery(vector<int>& arr) {
//        int n = arr.size();
//        for (int i = 0; i < n; i++) {
//            map[arr[i]].push_back(i);
//        }
//    }
//
//    int query(int left, int right, int value) {
//        if (map.find(value) == map.end()) {
//            return 0;
//        }
//
//        vector<int>& index = map[value];
//        auto l = lower_bound(index.begin(), index.end(), left);
//        auto r = upper_bound(index.begin(), index.end(), right);
//
//        return r - l;
//    }
//
//private:
//    unordered_map<int, vector<int>> map; // 记录数据每一个下标出现的位置
//};

#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	std::vector<int> nums = { 1, 2, 3, 4, 5 };
	auto it = std::lower_bound(nums.begin(), nums.end(), 4);
	std::cout << *it << std::endl;
	return 0;
}