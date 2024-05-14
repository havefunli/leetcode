#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int record_diff(TreeNode* node, int& flag) {
//        if (node == nullptr)
//            return 0;
//
//        int left = record_diff(node->left, flag) + 1;
//        int right = record_diff(node->right, flag) + 1;
//        if (abs(left - right) > 1) flag = 1;
//
//        return left > right ? left : right;
//    }
//
//
//    bool isBalanced(TreeNode* root) {
//        int flag = 0;
//        record_diff(root, flag);
//
//        return flag ? false : true;
//    }
//};

//class Solution {
//public:
//    void find_left(TreeNode* node, int flag, int& sum) {
//        if (node == nullptr)
//            return;
//        if (flag == 1
//            && node->left == nullptr && node->right == nullptr) {
//            sum += node->val;
//        }
//
//        find_left(node->left, 1, sum);
//        find_left(node->right, 0, sum);
//    }
//
//
//    int sumOfLeftLeaves(TreeNode* root) {
//        int flag = 0;
//        int sum = 0;
//
//        find_left(root, flag, sum);
//        return sum;
//    }
//};

//class Solution {
//public:
//    int maxDepth = 0;
//    int ret;
//
//    void traversal(TreeNode* node, int level) {
//        if (node == nullptr)
//            return;
//
//        if (node->left == nullptr && node->right == nullptr) {
//            if (level > maxDepth) {
//                ret = node->val;
//                maxDepth = level;
//            }
//        }
//
//        traversal(node->left, level + 1);
//        traversal(node->right, level + 1);
//    }
//
//
//    int findBottomLeftValue(TreeNode* root) {
//        int level = 1;
//        traversal(root, level);
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    bool sumOfpaths(TreeNode* node, int sum, int targetSum) {
//        if (node->left == nullptr && node->right == nullptr) {
//            sum += (node->val);
//            return sum == targetSum ? true : false;
//        }
//
//        sum += (node->val);
//        bool sumOfleft = false;
//        if (node->left) sumOfleft = sumOfpaths(node->left, sum, targetSum);
//        bool sumOfright = false;
//        if (node->right) sumOfright = sumOfpaths(node->right, sum, targetSum);
//
//        return sumOfleft || sumOfright;
//    }
//
//    bool hasPathSum(TreeNode* root, int targetSum) {
//        if (root == nullptr)
//            return false;
//
//        return sumOfpaths(root, 0, targetSum);
//    }
//};

//class Solution {
//public:
//    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
//        if (postorder.size() == 0) return nullptr;
//
//        int node_value = postorder.back();
//        TreeNode* node = new TreeNode(node_value);
//
//        if (postorder.size() == 1) return node;
//
//        int Boundary;
//        for (Boundary = 0; Boundary < inorder.size(); Boundary++) {
//            if (inorder[Boundary] == node_value) break;
//        }
//        vector<int>
//
//    }
//
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
//        return traversal(inorder, postorder);
//    }
//};

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	cout << v.back();
}