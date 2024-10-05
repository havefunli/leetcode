#include <iostream>
#include <vector>

//class Solution
//{
//public:
//    int search(vector<int>& nums, int target)
//    {
//        if (nums.size() == 0) return -1;
//
//        int l = 0, r = nums.size() - 1;
//        while (l < r)
//        {
//            int mid = (l + r) / 2;
//            if (nums[mid] >= target) r = mid;
//            else l = mid + 1;
//        }
//
//        if (nums[l] == target) return l;
//        else return -1;
//    }
//};

//class Solution
//{
//public:
//    int mySqrt(int x)
//    {
//        if (x == 0) return 0;
//
//        long long l = 0, r = x;
//        while (l < r)
//        {
//            long long mid = (l + r) / 2;
//            if (mid * mid >= x) r = mid;
//            else l = mid + 1;
//        }
//
//        return l * l > x ? l - 1 : l;
//    }
//};

//
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        if (nums.size() == 0) return 0;
//
//        int l = 0, r = nums.size() - 1;
//        while (l <= r)
//        {
//            while (l < nums.size() && nums[l] != val) l++;
//            while (r >= 0 && nums[r] == val) r--;
//
//            if (l < r) swap(nums[l], nums[r]);
//        }
//
//        return l;
//    }
//};


//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        int l = 0, r = nums.size() - 1;
//
//        int index = nums.size() - 1;
//        vector<int> result(nums.size(), 0);
//        while (l <= r)
//        {
//            if (nums[l] * nums[l] > nums[r] * nums[r])
//            {
//                result[index--] = nums[l] * nums[l];
//                l++;
//            }
//            else
//            {
//                result[index--] = nums[r] * nums[r];
//                r--;
//            }
//        }
//
//        return result;
//    }
//};


//class Solution
//{
//public:
//    int minSubArrayLen(int target, vector<int>& nums)
//    {
//        int result = INT32_MAX, cnt = 0;
//        int start = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            cnt += nums[i];
//            while (cnt >= target)
//            {
//                int len = i - start + 1;
//                result = result > len ? len : result;
//
//                cnt -= nums[start++];
//            }
//        }
//
//        return result == INT32_MAX ? 0 : result;
//    }
//};


//#include <iostream>
//#include <vector>
//
//int main()
//{
//    int n = 0;
//    std::cin >> n;
//
//    int val = 0;
//    std::vector<int> Sum(n + 1, 0);
//    for (int i = 1; i <= n; i++)
//    {
//        std::cin >> val;
//        Sum[i] = val + Sum[i - 1];
//    }
//
//    int l = 0, r = 0;
//    while (scanf("%d %d", &l, &r) != EOF)
//    {
//        std::cout << Sum[r + 1] - Sum[l] << std::endl;
//    }
//
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <climits>
///*暴力求解*/
//
//int main()
//{
//    int result = INT_MAX;
//    int n = 0, m = 0;
//    std::cin >> n >> m;
//
//    int sum = 0;
//    std::vector<std::vector<int>> Area(n, std::vector<int>(m, 0));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            std::cin >> Area[i][j];
//            sum += Area[i][j];
//        }
//    }
//
//
//    // 遍历所有行的可能
//    int lineval = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            lineval += Area[i][j];
//
//            // 行结束需要判断
//            if (j == m - 1)
//            {
//                result = result < std::abs((sum - lineval) - lineval) ?
//                    result : std::abs((sum - lineval) - lineval);
//            }
//        }
//    }
//
//    // 遍历所有列的可能
//    int rowval = 0;
//    for (int j = 0; j < m; j++)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            rowval += Area[i][j];
//
//            // 列结束需要判断
//            if (i == n - 1)
//            {
//                result = result < std::abs((sum - rowval) - rowval) ?
//                    result : std::abs((sum - rowval) - rowval);
//            }
//        }
//    }
//
//    std::cout << result << std::endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <cmath>
#include <climits>


///*尝试使用前缀和*/
//
//
//int main()
//{
//    int result = INT_MAX;
//    int n = 0, m = 0;
//    std::cin >> n >> m;
//
//    std::vector<std::vector<int>> Sum(n + 1, std::vector<int>(m + 1, 0));
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            int val = 0;
//            std::cin >> val;
//            Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + val;
//        }
//    }
//
//
//    for (int i = 1; i < n; i++)
//    {
//        result = std::min(result, std::abs(Sum[n][m] - 2 * Sum[i][m]));
//    }
//
//    for (int i = 1; i < m; i++)
//    {
//        result = std::min(result, std::abs(Sum[n][m] - 2 * Sum[n][i]));
//    }
//
//    std::cout << result << std::endl;
//
//    return 0;
//}

//class Solution
//{
//public:
//    int minSubArrayLen(int target, vector<int>& nums)
//    {
//        vector<int> Sum(nums.size() + 1, 0);
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            Sum[i] = Sum[i - 1] + nums[i - 1];
//        }
//
//        int ans = INT_MAX;
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            int l = i, r = nums.size();
//            while (l < r)
//            {
//                int mid = (l + r) / 2;
//                if (Sum[mid] - Sum[i - 1] >= target) r = mid;
//                else l = mid + 1;
//            }
//
//            if (Sum[l] - Sum[i - 1] >= target)
//            {
//                ans = min(ans, (l - i + 1));
//            }
//            else if (i == 1) return 0;
//        }
//
//        return ans == INT_MAX ? 0 : ans;
//    }
//};

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