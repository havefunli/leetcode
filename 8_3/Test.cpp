#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> push_que;
    queue<int> pop_que;

    MyStack() {
    }

    void push(int x) {
        push_que.push(x);
    }

    int pop() {
        int size = push_que.size() - 1;
        while (size--) {
            pop_que.push(push_que.front());
            push_que.pop();
        }

        int ret = push_que.front();
        push_que.pop();
        push_que = pop_que;
        while (!pop_que.empty()) {
            pop_que.pop();
        }

        return ret;
    }

    int top() {
        return push_que.back();
    }

    bool empty() {
        return push_que.empty() && pop_que.empty();
    }
};


bool isValid(string s) {
    stack<char> stack;
    int len = 0;

    while (len < s.size()) {
        if (s[len] == '{' || s[len] == '[' || s[len] == '(') {
            stack.push(s[len]);
        }
        else if (s[len] == '}' || s[len] == ']' || s[len] == ')') {
            if (stack.size() == 0)
                return false;
            char ch = stack.top();
            if ((ch == '{' && s[len] == '}')
                || (ch == '[' && s[len] == ']')
                || (ch == '(' && s[len] == ')'))
                stack.pop();
            else
                return false;
        }

        len++;
    }

    return stack.empty();
}

string removeDuplicates(string s) {
    stack<char> stack1;
    stack<char> stack2;
    for (auto ch : s) {
        stack1.push(ch);
    }

    while (!stack1.empty()) {
        if (!stack2.empty() && stack1.top() == stack2.top()) {
            stack1.pop();
            stack2.pop();
        }
        else {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    s.clear();
    while (!stack2.empty()) {
        s += stack2.top();
        stack2.pop();
    }

    reverse(s.begin(), s.end());
    return s;
}

long long toNum(const string& s) {
    long long ret = 0;
    int size = 0;
    int flag = 0;

    while (size < s.size()) {
        if (s[size] != '-')
            ret = ret * 10 + s[size] - '0';
        else
            flag = 1;
        size++;
    }

    return flag ? -ret : ret;
}




int evalRPN(vector<string>& tokens) {
    int result = 0;
    stack<long long> stack;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] != "+" && tokens[i] != "-"
            && tokens[i] != "*" && tokens[i] != "/")
            stack.push(toNum(tokens[i]));
        else {
            long long num1 = stack.top();
            stack.pop();
            long long num2 = stack.top();
            stack.pop();

            if (tokens[i] == "+") {
                result = (num1 + num2);
                stack.push(result);
            }

            else if (tokens[i] == "-") {
                result = (num2 - num1);
                stack.push(result);
            }
            else if (tokens[i] == "*") {
                result = (num1 * num2);
                stack.push(result);
            }
            else {
                result = (num2 / num1);
                stack.push(result);
            }
        }
    }

    return stack.top();
}

int main() {
    //cout << isValid("]"); 有效括号
    //cout << removeDuplicates("abbaca");删除字符串中所有相邻重复项
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");


    cout << evalRPN(tokens);


    return 0;
}