#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Solution {
//public:
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        if (nums.size() == 1) {
//            return new TreeNode(nums[0]);
//        }
//
//        int maxValue = 0;
//        int valueIndex = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > maxValue) {
//                maxValue = nums[i];
//                valueIndex = i;
//            }
//        }
//
//        TreeNode* node = new TreeNode(maxValue);
//        if (valueIndex > 0) {
//            vector<int> left_vec(nums.begin(), nums.begin() + valueIndex);
//            node->left = constructMaximumBinaryTree(left_vec);
//        }
//        if (valueIndex < nums.size() - 1) {
//            vector<int> right_vec(nums.begin() + valueIndex + 1, nums.end());
//            node->right = constructMaximumBinaryTree(right_vec);
//        }
//
//        return node;
//    }
//};

//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        if (root1 == nullptr) return root2;
//        if (root2 == nullptr) return root1;
//
//        root1->val += root2->val;
//        root1->left = mergeTrees(root1->left, root2->left);
//        root1->right = mergeTrees(root1->right, root2->right);
//
//        return root1;
//    }
//};

//class Solution {
//public:
//    TreeNode* searchBST(TreeNode* root, int val) {
//        if (root == nullptr) return nullptr;
//
//        if (root->val == val) return root;
//        else if (root->val > val)  return searchBST(root->left, val);
//        else return searchBST(root->right, val);
//    }
//};


//class Solution {
//public:
//    TreeNode* pre = nullptr;
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) return true;
//
//        bool left_tree = isValidBST(root->left);
//        if (pre != nullptr && pre->val >= root->val) return false;
//        pre = root;
//        bool right_tree = isValidBST(root->right);
//
//        return left_tree && right_tree;
//    }
//};

//class Solution {
//public:
//    TreeNode* pre = nullptr;
//    int min = INT_MAX;
//    int getMinimumDifference(TreeNode* root) {
//        if (root == nullptr) return 0;
//
//        getMinimumDifference(root->left);
//        if (pre != nullptr && abs(pre->val - root->val) < min) min = abs(pre->val - root->val);
//        pre = root;
//        getMinimumDifference(root->right);
//
//        return min;
//    }
//};

//class Solution {
//public:
//    vector<int> ret;
//    TreeNode* prev = nullptr;
//    int count = 1;
//    int Max = 0;
//
//    void traversal(TreeNode* root) {
//        if (root == nullptr) return;
//
//        traversal(root->left);
//
//        if (prev == nullptr) {
//        }
//        else if (prev->val == root->val) {
//            count++;
//        }
//        else if (prev->val != root->val) {
//            count = 1;
//        }
//        if (Max == count) ret.push_back(root->val);
//        else if (count > Max) {
//            ret.clear();
//            Max = count;
//            ret.push_back(root->val);
//        }
//        prev = root;
//
//        traversal(root->right);
//    }
//
//    vector<int> findMode(TreeNode* root) {
//        traversal(root);
//
//        return ret;
//    }
//};