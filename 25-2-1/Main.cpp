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
    int maxValue = INT_MIN;

    int traversal(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // ��ȡ�����������ݵ����ֵ
        int left = traversal(root->left);
        int right = traversal(root->right);
        // ��ǰ�ڵ���Ϊ���ڵ�
        int rootValue = root->val + max(left, 0) + max(right, 0);
        // ѡһ��ֵ����·��
        int maxPath = root->val + max(0, max(left, right));
        // ���� maxValue
        maxValue = max(maxValue, rootValue);
        return maxPath;
    }

    int maxPathSum(TreeNode* root) {
        traversal(root);
        return maxValue;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        return root;
    }
};

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
    int nodeSum(TreeNode* node, long long target) {
        if (node == nullptr) {
            return 0;
        }

        int cnt = 0;
        target -= node->val;
        if (target == 0) {
            cnt += 1;
        }
        cnt += nodeSum(node->left, target);
        cnt += nodeSum(node->right, target);
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        // ��ǰ���Ϊ���ڵ����
        int ret = nodeSum(root, targetSum);
        // ��ڵ�Ϊ���ڵ�
        ret += (pathSum(root->left, targetSum));
        ret += (pathSum(root->right, targetSum));
        return ret;
    }
};

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
    TreeNode* findLeftLast(TreeNode* node) {
        if (node == nullptr || node->right == nullptr) {
            return node;
        }
        return findLeftLast(node->right);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        if (root->left == nullptr) {
            return;
        }

        TreeNode* last = findLeftLast(root->left);
        last->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return;
    }
};