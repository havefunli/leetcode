/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode* dummyNode1 = new ListNode(0);  // 存储小于 x 的节点
//        ListNode* dummyNode2 = new ListNode(0);  // 存储大于或等于 x 的节点
//
//        ListNode* cur1 = dummyNode1;  // 指向小于 x 部分的链表
//        ListNode* cur2 = dummyNode2;  // 指向大于等于 x 部分的链表
//
//        while (head) {
//            if (head->val < x) {
//                cur1->next = head;
//                cur1 = cur1->next;
//            }
//            else {
//                cur2->next = head;
//                cur2 = cur2->next;
//            }
//            head = head->next;
//        }
//
//        cur2->next = nullptr;
//        cur1->next = dummyNode2->next;
//
//        return dummyNode1->next;
//    }
//};
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
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& nums, int l, int r) {
//        if (l > r) {
//            return nullptr;
//        }
//
//        int mid = (l + r) / 2;
//        TreeNode* root = new TreeNode(nums[mid]);
//        root->left = buildTree(nums, l, mid - 1);
//        root->right = buildTree(nums, mid + 1, r);
//
//        return root;
//    }
//
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        return buildTree(nums, 0, nums.size() - 1);
//    }
//};

#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit : num) {
            while (stk.size() > 0 && stk.back() > digit && k) {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k) {
            stk.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto& digit : stk) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            ans = max(ans, nums[i]);
        }

        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack;
        int area = 0;

        int n = height.size();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && height[stack.top()] < height[i]) {
                int mid = stack.top();
                stack.pop();

                if (!stack.empty()) {
                    int left = stack.top();

                    int w = i - left - 1;
                    int h = min(height[left], height[i]) - height[mid];
                    area += (h * w);
                }
            }
            stack.push(i);
        }

        return area;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 含义是 row[i][j] 第 i 行是否包含 j
        int row[9][10] = { 0 };
        int col[9][10] = { 0 };
        int box[9][10] = { 0 };

        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                if (row[i][num]) {
                    return false;
                }
                else {
                    row[i][num] = 1;
                }

                if (col[j][num]) {
                    return false;
                }
                else {
                    col[j][num] = 1;
                }

                if (box[j / 3 + (i / 3) * 3][num]) {
                    return false;
                }
                else {
                    box[j / 3 + (i / 3) * 3][num] = 1;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;

        while (l <= r && t <= b) {
            // 左到右
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            if (++t > b) {
                break;
            }

            // 上到下
            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }

            // 右到左
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[b][i]);
            }
            if (--b < t) {
                break;
            }

            // 下到上
            for (int i = b; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }

        return ans;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp = matrix;

        int col = 0;
        int n = matrix.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                tmp[j][col] = matrix[i][j];
            }
            col += 1;
        }
        matrix = tmp;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 记录行列情况
        vector<int> row(matrix.size(), false);
        vector<int> col(matrix[0].size(), false);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    void affect(vector<vector<int>>& count, int i, int j) {
        int dx[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
        int dy[] = { -1, -1, -1,  0, 0,  1, 1, 1 };

        for (int k = 0; k < 8; k++) {
            if (i + dx[k] >= 0 && i + dx[k] < count.size()
                && j + dy[k] >= 0 && j + dy[k] < count[0].size()) {
                count[i + dx[k]][j + dy[k]] += 1;
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> count(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // 只有活细胞才会影响周围细胞
                if (board[i][j] == 1) {
                    affect(count, i, j);
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << count[i][j] << " ";
                if (count[i][j] == 3) {
                    board[i][j] = 1;
                }
                else if (count[i][j] == 2) {
                    continue;
                }
                else {
                    board[i][j] = 0;
                }
            }
            cout << endl;
        }
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
    unordered_map<int, int> map;

    TreeNode* buildTreeHelper(vector<int>& preorder, int left1, int right1, vector<int>& inorder, int left2, int right2) {
        if (left1 > right1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[left1]);
        // 找到中序出现的位置
        int mid = map[preorder[left1]];
        // 左数长度
        int left_tree_size = mid - left2;
        // 左右子树
        root->left = buildTreeHelper(preorder, left1 + 1, left1 + left_tree_size, inorder, left2, mid - 1);
        root->right = buildTreeHelper(preorder, left1 + left_tree_size + 1, right1, inorder, mid + 1, right2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 映射中序每一个数出现的地方
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
    unordered_map<int, int> map;

    TreeNode* buildTreeHelper(vector<int>& inorder, int left1, int right1, vector<int>& postorder, int left2, int right2) {
        if (left1 > right1) {
            return nullptr;
        }

        int mid = map[postorder[right2]];
        int left_tree_size = mid - left1;

        // cout << postorder[right2] << endl;
        TreeNode* root = new TreeNode(postorder[right2]);
        root->left = buildTreeHelper(inorder, left1, mid - 1, postorder, left2, left2 + left_tree_size - 1);
        root->right = buildTreeHelper(inorder, mid + 1, right1, postorder, left2 + left_tree_size, right2 - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectHelper(vector<Node*> nodes) {
        for (int i = 1; i < nodes.size(); i++) {
            nodes[i - 1]->next = nodes[i];
        }
        nodes.back()->next = nullptr;
    }

    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        // 层序遍历
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            vector<Node*> nodes(size, nullptr);
            for (int i = 0; i < size; i++) {
                Node* node = queue.front();
                queue.pop();

                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }

                nodes[i] = node;
            }
            connectHelper(nodes);
        }

        return root;
    }
};