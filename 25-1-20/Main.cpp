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
//    int minDepth(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        else if (root->left == nullptr && root->right == nullptr) {
//            return 1;
//        }
//
//        int leftMin = INT_MAX;
//        if (root->left) {
//            leftMin = minDepth(root->left) + 1;
//        }
//
//        int rightMin = INT_MAX;
//        if (root->right) {
//            rightMin = minDepth(root->right) + 1;
//        }
//
//        return leftMin > rightMin ? rightMin : leftMin;
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

//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<double> averageOfLevels(TreeNode* root) {
//        vector<double> vec;
//        queue<TreeNode*> queue;
//
//        queue.push(root);
//        while (!queue.empty()) {
//            int size = queue.size();
//            double sum = 0;
//            for (int i = 0; i < size; i++) {
//                TreeNode* node = queue.front();
//                queue.pop();
//                // 加上当前的值
//                sum += node->val;
//                // 放入左右节点
//                if (node->left) {
//                    queue.push(node->left);
//                }
//                if (node->right) {
//                    queue.push(node->right);
//                }
//            }
//            vec.push_back(sum / (double)size);
//        }
//
//        return vec;
//    }
//};

#include <vector>
#include <string>
#include <iostream>

class MyString {
public:
    MyString(const std::string& str) : data(str) {
        std::cout << "Copy Constructor called\n";
    }

    MyString(std::string&& str) : data(std::move(str)) {
        std::cout << "Move Constructor called\n";
    }

    MyString(const MyString& other) : data(other.data) {
        std::cout << "MyString Copy Constructor called\n";
    }

    MyString(MyString&& other) noexcept : data(std::move(other.data)) {
        std::cout << "MyString Move Constructor called\n";
    }



private:
    std::string data;
};

int main() {
    std::vector<MyString> vec;

    MyString str("Hello");
    vec.push_back(str);          // 拷贝构造
    //vec.push_back(std::move(str)); // 移动构造

    //vec.emplace_back("World");    // 原地构造
    return 0;
}
