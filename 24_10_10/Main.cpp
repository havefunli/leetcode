//class Foo {
//public:
//    int index;
//    mutex mtx;
//    condition_variable cv;
//    Foo() {
//        index = 0;
//    }
//
//    void first(function<void()> printFirst) {
//
//        // printFirst() outputs "first". Do not change or remove this line.
//        unique_lock<mutex> lck(mtx);
//        cv.wait(lck, [&]() { return index == 0; });
//        index++;
//        printFirst();
//        cv.notify_all();
//    }
//
//    void second(function<void()> printSecond) {
//
//        // printSecond() outputs "second". Do not change or remove this line.
//        unique_lock<mutex> lck(mtx);
//        cv.wait(lck, [&]() { return index == 1; });
//        index++;
//        printSecond();
//        cv.notify_all();
//    }
//
//    void third(function<void()> printThird) {
//
//        // printThird() outputs "third". Do not change or remove this line.
//        unique_lock<mutex> lck(mtx);
//        cv.wait(lck, [&]() { return index == 2; });
//        index++;
//        printThird();
//        cv.notify_all();
//    }
//};


//#include <iostream>
//#include <string>
//#include <algorithm>
//
//int main()
//{
//    int k = 0;
//    std::string s;
//    std::string ans;
//    std::cin >> k >> s;
//
//    int len = s.size();
//    if (k > len)
//    {
//        std::cout << s << std::endl;
//        return 0;
//    }
//
//    std::reverse(s.begin(), s.end());
//    std::reverse(s.begin(), s.begin() + k);
//    std::reverse(s.begin() + k, s.end());
//    std::cout << s << std::endl;
//
//    return 0;
//}


// 如何初始化状态
// 状态如何更新 =》 现有的状态和之前的相关
//class Solution {
//public:
//    int climbStairs(int n) {
//        if (n < 2) return 1;
//        vector<int> ans(n + 1, 0);
//        ans[1] = 1;
//        ans[2] = 2;
//
//        for (int i = 3; i < n + 1; i++)
//        {
//            ans[i] = ans[i - 1] + ans[i - 2];
//        }
//        return ans[n];
//    }
//};


//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        vector<int> dp(cost.size() + 1, 0);
//        dp[0] = 0;
//        dp[1] = 0;
//
//        for (int i = 2; i <= cost.size(); i++)
//        {
//            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//        }
//
//        return dp[cost.size()];
//    }
//};

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>> map(m, vector<int>(n, 0));
//        for (int i = 0; i < n; i++)
//        {
//            map[0][i] = 1;
//        }
//        for (int i = 0; i < m; i++)
//        {
//            map[i][0] = 1;
//        }
//
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                map[i][j] = map[i - 1][j] + map[i][j - 1];
//            }
//        }
//
//        return map[m - 1][n - 1];
//    }
//};


//class Solution {
//public:
//    bool IsObstacle(vector<vector<int>>& obstacleGrid, int i, int j)
//    {
//        return obstacleGrid[i][j];
//    }
//
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//        for (int i = 0; i < n; i++)
//        {
//
//            if (IsObstacle(obstacleGrid, 0, i)) break;
//            dp[0][i] = 1;
//        }
//        for (int i = 0; i < m; i++)
//        {
//            if (IsObstacle(obstacleGrid, i, 0)) break;
//            dp[i][0] = 1;
//        }
//
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                if (!IsObstacle(obstacleGrid, i, j))
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
////};
//
//class Solution {
//public:
//    int numTrees(int n) {
//        vector<int> dp(n + 1, 0);
//        dp[0] = 1;
//
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                dp[i] += dp[j] * dp[i - j - 1];
//            }
//        }
//
//        return dp[n];
//    }
//};