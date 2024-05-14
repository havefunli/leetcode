#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pri_que;

    for (auto e : nums) {
        pri_que.push(e);
        if (pri_que.size() > k) {
            pri_que.pop();
        }
    }

    return pri_que.top();
}

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> stack;
    vector<int> v;

    if (root)
        stack.push(root);
    while (stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        if (node) v.push_back(node->val);
        if (node->left) stack.push(node->left);
        if (node->right) stack.push(node->right);
    }

    return v;
}


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode* node = root;
    stack<TreeNode*> stack;

    //if(root) stack.push(root);
    while (!stack.empty() || node) {
        if (node) {
            stack.push(node);
            node = node->left;
        }
        else {
            node = stack.top();
            stack.pop();
            ret.push_back(node->val);
            node = node->right;
        }
    }

        return ret;
}

int main() {
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    root.right = &node1;
    node1.left = &node2;

    preorderTraversal(&root);
}