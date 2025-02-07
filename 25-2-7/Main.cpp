#include <stack>
#include <string>
using namespace std;

//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> stack;
//        for (char c : s) {
//            if (c == '(' || c == '{' || c == '[') {
//                stack.push(c);
//            }
//            if (!stack.empty()) {
//                if (c == ')' && stack.top() == '(') {
//                    stack.pop();
//                }
//                else if (c == '}' && stack.top() == '{') {
//                    stack.pop();
//                }
//                else if (c == ']' && stack.top() == '[') {
//                    stack.pop();
//                }
//                else {
//                    return false;
//                }
//            }
//            else {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//
//class MinStack {
//public:
//    MinStack()
//    {}
//
//    void push(int val) {
//        _stack.push(val);
//        // 最小栈
//        if (_minValue.empty()) {
//            _minValue.push(val);
//        }
//        else if (val < _minValue.top()) {
//            _minValue.push(val);
//        }
//        else {
//            _minValue.push(_minValue.top());
//        }
//    }
//
//    void pop() {
//        _stack.pop();
//        _minValue.pop();
//    }
//
//    int top() {
//        return _stack.top();
//    }
//
//    int getMin() {
//        return _minValue.top();
//    }
//private:
//    stack<int> _stack;
//    stack<int> _minValue;
//};
//
///**
// * Your MinStack object will be instantiated and called as such:
// * MinStack* obj = new MinStack();
// * obj->push(val);
// * obj->pop();
// * int param_3 = obj->top();
// * int param_4 = obj->getMin();
// */
//
//class Solution {
//public:
//    string decodeString(string s) {
//        stack<int> nums;
//        stack<string> str;
//        string res = "";   // 表示当前括号内的字符
//        int cnt = 0;   // 表示当前的倍数
//
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] >= 'a' && s[i] <= 'z') {
//                res += s[i];
//            }
//            else if (s[i] >= '0' && s[i] <= '9') {
//                cnt = cnt * 10 + s[i] - '0';
//            }
//            else if (s[i] == '[') {
//                nums.push(cnt); // 倍数记录
//                cnt = 0;
//                str.push(res);  // 记录当前下的字符
//                res = "";
//            }
//            else {
//                // 取出倍数
//                int num = nums.top();
//                nums.pop();
//
//                for (int i = 0; i < num; i++) {
//                    str.top() += res;
//                }
//                // 变为上一个括号的状态
//                res = str.top();
//                str.pop();
//            }
//        }
//        return res;
//    }
//};
//
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        stack<int> stack;
//        vector<int> ans(temperatures.size(), 0);
//
//        for (int i = 0; i < temperatures.size(); i++) {
//            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
//                int index = stack.top();
//                stack.pop();
//                ans[index] = i - index;
//            }
//            stack.push(i);
//        }
//        return ans;
//    }
//};
#include <vector>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        st.push(0);
        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
        return result;
    }
};


int main() {
    vector<int> nums = { 2,1,2 };
    Solution().largestRectangleArea(nums);
    return 0;
}