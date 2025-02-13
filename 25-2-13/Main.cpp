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
        // ��������ջ��ȡ��һ�����Ϸ���λ��
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && nums[stack.top()] > nums[i]) {
                l = min(l, stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        cout << l << " ";
        // �������Ԫ��
        while (!stack.empty()) {
            stack.pop();
        }

        // �����ݼ�ջ��ȡ��һ���治�Ϸ���λ��
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
            // �ϱ߽������ϣ�������С
            t++;

            // t -> b
            for (int i = t; i <= b; i++) Matrix[i][r] = num++;
            // �ұ߽������ϣ�������С
            r--;

            // r -> l
            for (int i = r; i >= l; i--) Matrix[b][i] = num++;
            // �±߽������ϣ�������С
            b--;

            // b -> t
            for (int i = b; i >= t; i--) Matrix[i][l] = num++;
            // ��߽������ϣ�������С
            l++;
        }

        return Matrix;
    }
};