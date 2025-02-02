//class Solution {
//public:
//
//    int dfs(vector<vector<int>>& grid, int i, int j) {
//        // 地址合法
//        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) {
//            return 0;
//        }
//        // 没有遍历的陆地
//        if (grid[i][j] != 1) {
//            return 0;
//        }
//
//        grid[i][j] = 3;
//        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) +
//            dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
//    }
//
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        int ans = 0;
//
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[0].size(); j++) {
//                if (grid[i][j] == 1) {
//                    int res = dfs(grid, i, j);
//                    ans = max(ans, res);
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    int dfs(vector<vector<int>>& grid, int i, int j) {
//        // 越界了，有一条边
//        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
//            return 1;
//        }
//
//        // 海洋，一条边
//        if (grid[i][j] == 0) {
//            return 1;
//        }
//
//        if (grid[i][j] != 1) {
//            return 0;
//        }
//
//        grid[i][j] = 2;
//        return dfs(grid, i - 1, j) + dfs(grid, i + 1, j)
//            + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
//    }
//
//    int islandPerimeter(vector<vector<int>>& grid) {
//        int ans = 0;
//
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[0].size(); j++) {
//                // 只存在一个岛屿
//                if (grid[i][j] == 1) {
//                    return dfs(grid, i, j);
//                }
//            }
//        }
//
//        return ans;
//    }
//};
//
//class Solution {
//public:
//
//    void dfs(vector<vector<char>>& grid, int i, int j) {
//        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
//            return;
//        }
//        if (grid[i][j] != '1') {
//            return;
//        }
//
//        grid[i][j] = '2';
//        dfs(grid, i - 1, j);
//        dfs(grid, i + 1, j);
//        dfs(grid, i, j - 1);
//        dfs(grid, i, j + 1);
//    }
//
//    int numIslands(vector<vector<char>>& grid) {
//        int ans = 0;
//
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[0].size(); j++) {
//                if (grid[i][j] == '1') {
//                    ans += 1;
//                    dfs(grid, i, j);
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    int orangesRotting(vector<vector<int>>& grid) {
//        // 第一次遍历获取新鲜橘子数量和腐烂位置
//        int fresh = 0;
//        queue<pair<int, int>> queue;
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[0].size(); j++) {
//                if (grid[i][j] == 1) {
//                    fresh += 1;
//                }
//                else if (grid[i][j] == 2) {
//                    queue.emplace(i, j);
//                }
//            }
//        }
//
//        int round = 0;
//        int size = 0;
//        while (fresh > 0 && !queue.empty()) {
//            size = queue.size();
//            for (int i = 0; i < size; i++) {
//                // 取出坐标
//                int row = queue.front().first;
//                int col = queue.front().second;
//                queue.pop();
//
//                // 感染四方的橘子
//                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
//                    grid[row - 1][col] = 2;
//                    fresh -= 1;
//                    queue.emplace(row - 1, col);
//                }
//                if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
//                    grid[row + 1][col] = 2;
//                    fresh -= 1;
//                    queue.emplace(row + 1, col);
//                }
//                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
//                    grid[row][col - 1] = 2;
//                    fresh -= 1;
//                    queue.emplace(row, col - 1);
//                }
//                if (col + 1 < grid[0].size() && grid[row][col + 1] == 1) {
//                    grid[row][col + 1] = 2;
//                    fresh -= 1;
//                    queue.emplace(row, col + 1);
//                }
//            }
//            cout << fresh << " ";
//            round += 1;
//        }
//
//        return (fresh == 0) ? round : -1;
//    }
//};