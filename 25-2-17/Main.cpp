class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<bool>> isValid;

    void placeQueue(vector<vector<bool>>& isValid, int r, int c) {
        // 填充一行
        for (int i = 0; i < isValid.size(); i++) {
            isValid[r][i] = false;
        }
        // 填充一列
        for (int i = 0; i < isValid.size(); i++) {
            isValid[i][c] = false;
        }
        // 左对角线
        for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
            isValid[r - i][c - i] = false;
        }
        for (int i = 1; r + i < isValid.size() && c + i < isValid.size(); i++) {
            isValid[r + i][c + i] = false;
        }
        // 右对角线
        for (int i = 1; r - i >= 0 && c + i < isValid.size(); i++) {
            isValid[r - i][c + i] = false;
        }
        for (int i = 1; r + i < isValid.size() && c - i >= 0; i++) {
            isValid[r + i][c - i] = false;
        }
    }

    void dfs(int maxDepth, int depth) {
        if (depth == maxDepth) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < maxDepth; i++) {
            if (isValid[depth][i]) {
                vector<vector<bool>> tmp = isValid; // 备份
                placeQueue(isValid, depth, i);
                path[depth][i] = 'Q';
                dfs(maxDepth, depth + 1);
                path[depth][i] = '.';
                isValid = tmp;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        isValid = vector<vector<bool>>(n, vector<bool>(n, true));
        path = vector<string>(n, string(n, '.'));
        dfs(n, 0);

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isValid(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }

    void dfs(string& s, int startIndex) {
        if (startIndex == s.size()) {
            ans.push_back(path);
        }

        for (int i = startIndex; i < s.size(); i++) {
            // 当前是回文串才分割
            if (isValid(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
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
    TreeNode* find_left_last_node(TreeNode* left) {
        if (left == nullptr || left->right == nullptr) {
            return left;
        }

        return find_left_last_node(left->right);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* lastNode = find_left_last_node(root->left);
        if (lastNode != nullptr) {
            lastNode->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        return;
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
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
    int sumNumbersHelper(TreeNode* root, int val) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return val * 10 + root->val;
        }

        return sumNumbersHelper(root->left, val * 10 + root->val)
            + sumNumbersHelper(root->right, val * 10 + root->val);
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
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
    int ans = INT_MIN;

    int maxPathSumHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftVal = maxPathSumHelper(root->left);
        int rightVal = maxPathSumHelper(root->right);
        // 当前节点为根节点
        int rootVal = root->val + max(0, leftVal) + max(0, rightVal);
        ans = max(ans, rootVal);
        // 传递一个最大的值到上一层次
        int pathVal = root->val + max(0, max(leftVal, rightVal));
        return pathVal;
    }


    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return ans;
    }
};