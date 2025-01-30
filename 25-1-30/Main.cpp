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
//class Solution {
//public:
//    TreeNode* head = new TreeNode(-1, nullptr, nullptr);
//    TreeNode* cur = head;
//
//    void preOrder(TreeNode* node) {
//        if (node == nullptr) {
//            return;
//        }
//
//        cout << node->val << " ";
//        cur->right = new TreeNode(node->val, nullptr, nullptr);
//        cur = cur->right;
//        preOrder(node->left);
//        preOrder(node->right);
//    }
//
//    void flatten(TreeNode* root) {
//        preOrder(root);
//        root = head->right;
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
//class Solution {
//public:
//    int cnt = 1;
//    int ans = 0;
//    void inOrder(TreeNode* node, int k) {
//        if (node == nullptr) {
//            return;
//        }
//
//        inOrder(node->left, k);
//        if (cnt == k) {
//            ans = node->val;
//        }
//        cnt += 1;
//        inOrder(node->right, k);
//    }
//
//    int kthSmallest(TreeNode* root, int k) {
//        inOrder(root, k);
//        return ans;
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
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> ans;
//        queue<TreeNode*> queue;
//        int size = 0;
//
//        if (root != nullptr) {
//            queue.push(root);
//            size = queue.size();
//        }
//        while (!queue.empty()) {
//            cout << size << " ";
//            vector<int> res(size, 0);
//            for (int i = 0; i < size; i++) {
//                TreeNode* node = queue.front();
//                queue.pop();
//
//                res[i] = node->val;
//                if (node->left != nullptr) {
//                    queue.push(node->left);
//                }
//                if (node->right != nullptr) {
//                    queue.push(node->right);
//                }
//            }
//            size = queue.size();
//            ans.push_back(res);
//        }
//        return ans;
//    }
//};