//class Solution {
//public:
//    // ’“ΩªºØ
//    int findMinArrowShots(vector<vector<int>>& points) {
//        sort(points.begin(), points.end(),
//            [](const vector<int>& left, const vector<int>& right)
//            {
//                return left[0] < right[0];
//            });
//
//        int ans = 0;
//        vector<int> res = points[0];
//        for (int i = 1; i < points.size(); i++) {
//            if (points[i][0] <= res[1]) {
//                res[0] = max(res[0], points[i][0]);
//                res[1] = min(res[1], points[i][1]);
//            }
//            else {
//                ans++;
//                res = points[i];
//            }
//        }
//        return ans + 1;
//    }
//};


//
//class Solution {
//public:
//    string simplifyPath(string path) {
//        string str;
//        vector<string> stack;
//        for (int i = 0; i < path.size(); i++) {
//            if (path[i] == '/') {
//                if (str.empty()) {
//                    continue;
//                }
//                if (str == ".." && !stack.empty()) {
//                    stack.pop_back();
//                }
//                else {
//                    if (str != "." && str != "..") {
//                        stack.push_back(str);
//                    }
//                }
//                str = "";
//            }
//            else {
//                str += path[i];
//            }
//
//        }
//        if (str == "..") {
//            if (!stack.empty()) {
//                stack.pop_back();
//            }
//        }
//        else {
//            if (str != "" && str != ".") {
//                stack.push_back(str);
//            }
//        }
//
//        string ans;
//        for (auto& str : stack) {
//            ans += ("/" + str);
//        }
//        return ans.empty() ? "/" : ans;
//    }
//};
//
//
//class MinStack {
//public:
//    MinStack()
//    {}
//
//    void push(int val) {
//        _st.push(val);
//        if (_minValue.empty()) {
//            _minValue.push(val);
//        }
//        else {
//            int top = _minValue.top();
//            if (top < val) {
//                _minValue.push(top);
//            }
//            else {
//                _minValue.push(val);
//            }
//        }
//    }
//
//    void pop() {
//        _st.pop();
//        _minValue.pop();
//    }
//
//    int top() {
//        return _st.top();
//    }
//
//    int getMin() {
//        return _minValue.top();
//    }
//
//private:
//    stack<int> _st;
//    stack<int> _minValue;
//};

#include <stack>
#include <vector>
#include <string>
using namespace std;

//class Solution {
//public:
//    void getLeftRight(stack<int>& st, int& left, int& right) {
//        right = st.top();
//        st.pop();
//        left = st.top();
//        st.pop();
//    }
//
//    int evalRPN(vector<string>& tokens) {
//        stack<int> st;
//        int left = 0, right = 0;
//        for (auto& token : tokens) {
//            if (token == "+") {
//                getLeftRight(st, left, right);
//                st.push(left + right);
//            }
//            else if (token == "*") {
//                getLeftRight(st, left, right);
//                st.push(left * right);
//            }
//            else if (token == "-") {
//                getLeftRight(st, left, right);
//                st.push(left - right);
//            }
//            else if (token == "/") {
//                getLeftRight(st, left, right);
//                st.push(left / right);
//            }
//            else {
//                st.push(stoi(token));
//            }
//        }
//
//        return st.top();
//    }
//};

//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == nullptr) {
//            return nullptr;
//        }
//
//        Node* cur = head;
//        Node* newHead = new Node(0);
//        Node* node = newHead;
//        unordered_map<Node*, Node*> map1;
//        unordered_map<Node*, Node*> map2;
//        while (cur) {
//            Node* newNode = new Node(cur->val);
//            node->next = newNode;
//            node = newNode;
//            map1[node] = cur;
//            map2[cur] = node;
//            cur = cur->next;
//        }
//        cur = head;
//        node = newHead->next;
//        while (cur) {
//            Node* random = map2[map1[node]->random];
//            node->random = random;
//            cur = cur->next;
//			  node = node->next;
//        }
//
//        return newHead->next;
//    }
//};