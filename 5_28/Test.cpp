#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if (minst.empty() || minst.top() >= val) minst.push(val);
    }

    void pop() {
        if (st.top() == minst.top()) {
            st.pop();
            minst.pop();
        }
        else {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }
private:
    stack<int> st;
    stack<int> minst;
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        stack<int> st;
        int i = 0, j = 0;
        while ((i < pushV.size()) && (j < popV.size())) {
            if (pushV[i] == popV[j]) {
                i++;
                j++;
            }
            else if (!st.empty() && (st.top() == popV[j])) {
                st.pop();
                j++;
            }
            else {
                st.push(pushV[i]);
                i++;
            }
        }

        while (!st.empty()) {
            if (popV[j] == st.top()) {
                j++;
                st.pop();
            }
            else return false;
        }
        return true;
    }
};

class Solution_1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num1 = 0, num2 = 0;
        for (auto& e : tokens) {
            if (e == "+") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                st.push(num1 + num2);
            }
            else if (e == "-") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            }
            else if (e == "*") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                st.push(num1 * num2);
            }
            else if (e == "/") {
                num1 = st.top();
                st.pop();
                num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            }
            else {
                st.push(atoi(e.c_str()));
            }
        }
        return st.top();
    }
};

int main() {
    return 1;
}