//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode* biger = new ListNode(-1);
//        ListNode* smaller = new ListNode(-1);
//
//        ListNode* big = biger;
//        ListNode* small = smaller;
//        while (head) {
//            if (head->val < x) {
//                small->next = head;
//                small = head;
//            }
//            else {
//                big->next = head;
//                big = head;
//            }
//            head = head->next;
//        }
//        big->next = nullptr; // 避免成环
//        small->next = biger->next;
//        return smaller->next;
//    }
//};

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct LinkNode {
        LinkNode()
            : _prev(nullptr), _next(nullptr)
            , _key(-1), _val(-1)
        {}

        LinkNode(int key, int val)
            : _prev(nullptr), _next(nullptr)
            , _key(key), _val(val)
        {}

        LinkNode* _prev;
        LinkNode* _next;
        int _key, _val;
    };

    class List {
    public:
        List()
            : _head(new LinkNode())
        {
            _head->_next = _head;
            _head->_prev = _head;
        }

        LinkNode* addToHead(int key, int val) {
            LinkNode* newnode = new LinkNode(key, val);
            // 和头节点相连
            newnode->_next = _head->_next;
            newnode->_prev = _head;
            _head->_next->_prev = newnode;
            _head->_next = newnode;
            return newnode;
        }

        void moveToHead(LinkNode* node) {
            // 前后相连
            node->_prev->_next = node->_next;
            node->_next->_prev = node->_prev;
            // 和头节点相连
            node->_next = _head->_next;
            node->_prev = _head;
            _head->_next->_prev = node;
            _head->_next = node;
        }

        int removeNode() {
            int key = _head->_prev->_key;

            LinkNode* target = _head->_prev;
            LinkNode* prev = target->_prev;
            prev->_next = target->_next;
            target->_next->_prev = prev;
            delete target;

            return key;
        }

    private:
        LinkNode* _head;
    };

    LRUCache(int capacity)
        : _link(List()), _size(0), _capacity(capacity)
    {}

    int get(int key) {
        auto it = _map.find(key);
        if (it == _map.end()) {
            return -1;
        }
        LinkNode* node = it->second;
        _link.moveToHead(node);
        return node->_val;
    }

    void put(int key, int value) {
        auto it = _map.find(key);
        if (it != _map.end()) {
            LinkNode* node = it->second;
            node->_val = value;
            _link.moveToHead(node);  // 将更新后的节点移到头部
            return;
        }
        if (_size == _capacity) {
            int key = _link.removeNode();
            _map.erase(key);
            _size--;
        }
        LinkNode* node = _link.addToHead(key, value);
        _map[key] = node;
        _size++;
    }

private:
    unordered_map<int, LinkNode*> _map;
    List _link;
    int _size;
    int _capacity;
};




int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
    return 0;
}


//class Solution {
//public:
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//        if (p == nullptr && q == nullptr) {
//            return true;
//        }
//        if (p == nullptr || q == nullptr) {
//            return false;
//        }
//        if (p->val != q->val) {
//            return false;
//        }
//
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//    }
//};

//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == nullptr) {
//            return root;
//        }
//        swap(root->left, root->right);
//        invertTree(root->left);
//        invertTree(root->right);
//
//        return root;
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
//    bool checkLeftRight(TreeNode* left, TreeNode* right) {
//        if (left == nullptr && right == nullptr) {
//            return true;
//        }
//        else if (left == nullptr || right == nullptr) {
//            return false;
//        }
//        if (left->val != right->val) {
//            return false;
//        }
//        return checkLeftRight(left->left, right->right) && checkLeftRight(left->right, right->left);
//    }
//    bool isSymmetric(TreeNode* root) {
//        return checkLeftRight(root->left, root->right);
//    }
//};

//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int line = matrix.size();
//        int row = matrix[0].size();
//
//        int m = 0, n = row - 1;
//        while (m < line && n >= 0) {
//            if (target > matrix[m][n]) {
//                m++;
//            }
//            else if (target < matrix[m][n]) {
//                n--;
//            }
//            else {
//                return true;
//            }
//        }
//        return false;
//    }
//};
