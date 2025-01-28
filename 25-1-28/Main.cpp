//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int col = matrix[0].size() - 1, row = 0;
//        while (row < matrix.size() && col >= 0) {
//            if (matrix[row][col] > target) {
//                col -= 1;
//            }
//            else if (matrix[row][col] < target) {
//                row += 1;
//            }
//            else {
//                return true;
//            }
//        }
//        return false;
//    }
//};
//
//class Solution {
//public:
//    void beZero(vector<vector<int>>& matrix, int row, int col) {
//        for (int i = 0; i < matrix[0].size(); i++) {
//            matrix[row][i] = 0;
//        }
//        for (int i = 0; i < matrix.size(); i++) {
//            matrix[i][col] = 0;
//        }
//    }
//
//    void setZeroes(vector<vector<int>>& matrix) {
//        vector<pair<int, int>> indexes;
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix[i].size(); j++) {
//                if (matrix[i][j] == 0) {
//                    indexes.emplace_back(i, j);
//                }
//            }
//        }
//
//        for (auto& pair : indexes) {
//            beZero(matrix, pair.first, pair.second);
//        }
//    }
//};
//
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        int n = matrix.size(), m = matrix[0].size();
//        int left = 0, right = m - 1;
//        int top = 0, bottom = n - 1;
//
//        vector<int> ans;
//        while (left <= right && top <= bottom) {
//            // 从左到右
//            for (int col = left; col <= right; col++) {
//                ans.push_back(matrix[top][col]);
//            }
//            if (++top > bottom) {
//                break;
//            }
//
//            // 上到下
//            for (int row = top; row <= bottom; row++) {
//                ans.push_back(matrix[row][right]);
//            }
//            if (--right < left) {
//                break;
//            }
//
//            // 右到左
//            for (int col = right; col >= left; col--) {
//                ans.push_back(matrix[bottom][col]);
//            }
//            if (--bottom < top) {
//                break;
//            }
//
//            // 下到上
//            for (int row = bottom; row >= top; row--) {
//                ans.push_back(matrix[row][left]);
//            }
//            if (++left > right) {
//                break;
//            }
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    void rotate(vector<vector<int>>& matrix) {
//        int n = matrix.size();
//        vector<vector<int>> helper(n, vector<int>(n));  // 初始化 helper 矩阵
//
//        int col = 0;  // 重置 col 为 0
//
//        for (int i = n - 1; i >= 0; i--) {
//            for (int j = 0; j < n; j++) {
//                helper[j][col] = matrix[i][j];
//            }
//            col += 1;
//        }
//
//        matrix = helper;  // 更新 matrix
//    }
//};