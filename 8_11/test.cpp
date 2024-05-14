#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Solution {
//public:
//    bool isSame(TreeNode* left_node, TreeNode* right_node) {
//        if (left_node == nullptr && right_node == nullptr)
//            return true;
//        else if (left_node == nullptr && right_node != nullptr)
//            return false;
//        else if (left_node != nullptr && right_node == nullptr)
//            return false;
//        else if (left_node->val != right_node->val)
//            return false;
//
//        return isSame(left_node->left, right_node->right)
//            && isSame(left_node->right, right_node->left);
//    }
//
//
//
//    bool isSymmetric(TreeNode* root) {
//        if (root == nullptr)
//            return true;
//
//        return isSame(root->left, root->right);
//    }
//};

//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        int left = maxDepth(root->left) + 1;
//        int right = maxDepth(root->right) + 1;
//        return left > right ? left : right;
//    }
//};

//class Solution {
//public:
//    int find_way(TreeNode* node) {
//        if (node == nullptr)
//            return 1000000;
//        if (node->left == nullptr && node->right == nullptr)
//            return 1;
//
//        int n1 = 1000000;
//        int n2 = 1000000;
//        if (node->left)
//            n1 = find_way(node->left) + 1;
//        if (node->right)
//            n2 = find_way(node->right) + 1;
//
//        return n1 < n2 ? n1 : n2;
//    }
//
//    int minDepth(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        if (root->left == nullptr && root->right == nullptr)
//            return 1;
//
//        int min_left = find_way(root->left) + 1;
//        int min_right = find_way(root->right) + 1;
//
//        return min_left < min_right ? min_left : min_right;
//    }
//};

//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//
//        int left = countNodes(root->left);
//        int right = countNodes(root->right);
//
//        return left + right + 1;
//    }
//};

int main() {	
}