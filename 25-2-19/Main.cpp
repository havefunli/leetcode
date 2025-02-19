class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = arrays[0][0], mx = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            ans = max(ans, max(mx - arrays[i][0], arrays[i].back() - mn));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }

        return ans;
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        // 层次遍历
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> res(size, 0);
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                res[i] = node->val;
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
            ans.push_back(res.back());
        }

        return ans;
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vec;
        queue<TreeNode*> queue;

        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                // 加上当前的值
                sum += node->val;
                // 放入左右节点
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            vec.push_back(sum / (double)size);
        }

        return vec;
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
    void left_to_right(queue<TreeNode*>& queue, vector<int>& res) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = queue.front();
            queue.pop();

            res[i] = node->val;
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }

    void right_to_left(queue<TreeNode*>& queue, vector<int>& res) {
        int size = queue.size();
        for (int i = size - 1; i >= 0; i--) {
            TreeNode* node = queue.front();
            queue.pop();

            res[i] = node->val;
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        bool flag = true;  // true：左到右；false：右到左
        while (!queue.empty()) {
            vector<int> res(queue.size(), 0);
            if (flag) {
                left_to_right(queue, res);
            }
            else {
                right_to_left(queue, res);
            }
            flag = flag ? false : true;
            ans.push_back(res);
        }
        return ans;
    }
};

class Solution {
public:
    int ans = INT_MAX;
    int prev = INT_MIN / 2;

    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        getMinimumDifference(root->left);
        ans = min(ans, root->val - prev);
        prev = root->val;
        getMinimumDifference(root->right);

        return ans;
    }
};

class Solution {
public:
    int ans = 0;

    void inOrder(TreeNode* node, int& k) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left, k);
        if (--k == 0) {
            ans = node->val;
            return;
        }
        inOrder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};