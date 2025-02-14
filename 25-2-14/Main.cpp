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
class Solution {
public:
    int findIndex(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1 > r1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[l1]);
        int index = findIndex(inorder, preorder[l1]);

        int left_tree_size = index - l2;

        root->left = buildTreeHelper(preorder, l1 + 1, l1 + left_tree_size, inorder, l2, index - 1);
        root->right = buildTreeHelper(preorder, l1 + left_tree_size + 1, r1, inorder, index + 1, r2);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};