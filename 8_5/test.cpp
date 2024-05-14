#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

//class Solution {
//private:
//    class MyQueue {
//    private:
//        deque<int> queue;
//    public:
//        void pop(int val) {
//            if (!queue.empty() && queue.front() == val) {
//                queue.pop_front();
//            }
//        }
//
//        void push(int val) {
//            while (!queue.empty() && queue.back() < val) {
//                queue.pop_back();
//            }
//
//            queue.push_back(val);
//        }
//
//        int front() {
//            return queue.front();
//        }
//    };
//
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        MyQueue queue;
//        vector<int> ret;
//
//        for (int i = 0; i < k; i++) {
//            queue.push(nums[i]);
//        }
//        ret.push_back(queue.front());
//        for (int i = k; i < nums.size(); i++) {
//            queue.pop(nums[i - k]);
//            queue.push(nums[i]);
//            ret.push_back(queue.front());
//        }
//
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> queue;
//        int size = 0;
//
//        if (root) {
//            queue.push(root);
//            size = 1;
//        }
//        while (!queue.empty()) {
//            vector<int> v;
//            for (int i = 0; i < size; i++) {
//                TreeNode* top = queue.front();
//                queue.pop();
//                v.push_back(top->val);
//
//                if (top->left)
//                    queue.push(top->left);
//                if (top->right)
//                    queue.push(top->right);
//            }
//
//            vv.push_back(v);
//            size = queue.size();
//        }
//
//        return vv;
//    }
//};

class Solution {
public:

    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto n : nums) {
            map[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = pri_que.top().first;
            pri_que.pop();
        }

        return ret;
    }
};

int main() {
	vector<int> v1(3);
	vector<int> v2;


	cout << v1.size() << endl;
	cout << v2.size() << endl;

	return 0;
}