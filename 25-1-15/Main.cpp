#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](const int& left, const int& right) { return left > right; });
        list<int> list(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = list.front();
                list.pop_front();
            }
            else {
                nums[i] = list.back();
                list.pop_back();
            }
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
    vector<vector<int>> ans;
    vector<int> path;

    void traversal(TreeNode* node, int targetSum) {
        if (node == nullptr) {
            return;
        }

        path.push_back(node->val);
        targetSum -= node->val;
        if (node->left == nullptr && node->right == nullptr && targetSum == 0) {
            ans.push_back(path);
        }

        traversal(node->left, targetSum);
        traversal(node->right, targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traversal(root, targetSum);
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
    vector<int> vec;

    void traversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }

    TreeNode* buildTree(vector<int>& vec, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(vec[mid]);

        node->left = buildTree(vec, left, mid - 1);
        node->right = buildTree(vec, mid + 1, right);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        traversal(root);

        return buildTree(vec, 0, vec.size() - 1);
    }
};

class Solution {

    class myCompare
    {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> queue;
        for (auto& pair : map) {
            queue.push(pair);
            if (queue.size() > k) {
                queue.pop();
            }
        }

        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = queue.top().first;
            queue.pop();
        }

        return ans;
    }
};

int main() {
    vector<int> vec = { 3,5,2,1,6,4 };
    Solution().wiggleSort(vec);
	return 0;
}