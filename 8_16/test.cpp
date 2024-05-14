#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL || root == p || root == q) return root;
//
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//
//        if (left != NULL && right != NULL) return root;
//        else if (left == NULL && right != NULL) return right;
//        else if (left != NULL && right == NULL) return left;
//        else return NULL;
//    }
//};

//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL) return NULL;
//
//        if (root->val > p->val && root->val > q->val) {
//            TreeNode* left = lowestCommonAncestor(root->left, p, q);
//            //if(left != NULL) 
//            return left;
//        }
//        else if (root->val < p->val && root->val < q->val) {
//            TreeNode* right = lowestCommonAncestor(root->right, p, q);
//            return right;
//        }
//
//        return root;
//    }
//};

//class Solution {
//public:
//    void traversal(TreeNode*& root, int val) {
//        if (root == nullptr) root = new TreeNode(val);
//        else if (root->left == nullptr && val < root->val) {
//            root->left = new TreeNode(val);
//            return;
//        }
//        else if (root->right == nullptr && val > root->val) {
//            root->right = new TreeNode(val);
//            return;
//        }
//
//        if (val > root->val) traversal(root->right, val);
//        if (val < root->val) traversal(root->left, val);
//    }
//
//    TreeNode* insertIntoBST(TreeNode* root, int val) {
//        traversal(root, val);
//        return root;
//    }
//};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void test(TreeNode*& node,int val) {
	node = new TreeNode(val);
	cout << node << endl;
}

int main() {
	TreeNode* node = nullptr;

	test(node,5);
	//node = new TreeNode(5);
	cout << node;
}