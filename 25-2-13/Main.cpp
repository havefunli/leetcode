#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n - 1, r = 0;

        stack<int> stack;
        // 单调递增栈获取第一个不合法的位置
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && nums[stack.top()] > nums[i]) {
                l = min(l, stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        cout << l << " ";
        // 清除所有元素
        while (!stack.empty()) {
            stack.pop();
        }

        // 单调递减栈获取第一个逆不合法的位置
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && nums[stack.top()] < nums[i]) {
                cout << "max" << " ";
                r = max(r, stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        cout << r << " ";
        return l == n - 1 ? 0 : r - l + 1;
    }
};

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int num = 1;
        int l = 0, r = n - 1, t = 0, b = n - 1;
        vector<vector<int>> Matrix(n, vector<int>(n, 0));

        while (num <= n * n)
        {
            // l -> r
            for (int i = l; i <= r; i++) Matrix[t][i] = num++;
            // 上边界填充完毕，向下缩小
            t++;

            // t -> b
            for (int i = t; i <= b; i++) Matrix[i][r] = num++;
            // 右边界填充完毕，向左缩小
            r--;

            // r -> l
            for (int i = r; i >= l; i--) Matrix[b][i] = num++;
            // 下边界填充完毕，向上缩小
            b--;

            // b -> t
            for (int i = b; i >= t; i--) Matrix[i][l] = num++;
            // 左边界填充完毕，向右缩小
            l++;
        }

        return Matrix;
    }
};