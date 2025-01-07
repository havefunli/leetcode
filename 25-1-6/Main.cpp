#include <iostream>
#include <vector>
using namespace std;


//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        vector<vector<int>> dp = grid;
//        // 初始行
//        for (int i = 1; i < grid[0].size(); i++) {
//            grid[0][i] += grid[0][i - 1];
//            cout << grid[0][i] << " ";
//        }
//        cout << endl;
//        // 初始列
//        for (int j = 1; j < grid.size(); j++) {
//            grid[j][0] += grid[j - 1][0];
//            cout << grid[j][0] << " ";
//        }
//        cout << endl;
//
//        for (int i = 1; i < grid.size(); i++) {
//            for (int j = 1; j < grid[0].size(); j++) {
//                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//        return dp.back().back();
//    }
//};


class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> bulb(n, false);
        for (int i = 1; i <= bulb.size(); i++) {
            for (int j = -1; j + i < bulb.size();) {
                bulb[j + i] = !bulb[j + i];
                cout << bulb[j + i] << " ";
                j += i;
            }
            cout << endl;
        }

        int cnt = 0;
        for (int i = 0; i < bulb.size(); i++) {
            if (bulb[i]) {
                cnt += 1;
            }
        }

        return cnt;
    }
};

int main() {
    vector<vector<int>> vec = { {1, 2, 3}, {4, 5, 6} };
    Solution().bulbSwitch(3);
	return 0;
}