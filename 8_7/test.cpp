#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class stack {
public:
	void push(int val) {
		v.push_back(val);
	}

private:
	vector<int> v;
};

//class Solution {
//public:
//	void reverse_tree(TreeNode* root) {
//		if (root == nullptr)
//			return;
//
//		swap(root->left, root->right);
//		invertTree(root->left);
//		invertTree(root->right);
//	}
//
//
//	TreeNode* invertTree(TreeNode* root) {
//		reverse_tree(root);
//
//		return root;
//	}
//};

int main() {
	//stack s1;
	//s1.push(1);
	//s1.push(2);
	//s1.push(3);
	//s1.push(4);

	//stack s2(s1);
	//s1.push(5);
	//cout << &(s1) << endl;
	//cout << &(s2) << endl;

	//int a = 1;
	//int* a1 = &a;
	//int* a2;;
	//a2 = a1;
	//cout << a1 << " " << a2;

}