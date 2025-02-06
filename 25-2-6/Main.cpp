//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int l = 0, r = nums.size() - 1;
//        while (l <= r) {
//            int mid = (l + r + 1) / 2;
//
//            if (nums[mid] == target) {
//                return mid;
//            }
//            // 左边有序数组
//            if (nums[mid] > nums[l]) {
//                if (nums[l] <= target && nums[mid] > target) {
//                    r = mid - 1;
//                }
//                else {
//                    l = mid + 1;
//                }
//            }
//            else {
//                if (nums[mid] < target && target <= nums[r]) {
//                    l = mid + 1;
//                }
//                else {
//                    r = mid - 1;
//                }
//            }
//        }
//        return -1;
//    }
//};
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int row = 0, col = matrix[0].size() - 1;
//        while (row < matrix.size() && col >= 0) {
//            if (matrix[row][col] < target) {
//                row += 1;
//            }
//            else if (matrix[row][col] > target) {
//                col -= 1;
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
//    vector<vector<bool>> isVisited;
//    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
//        // 满足条件
//        if (word.size() == index) {
//            return true;
//        }
//
//        // 越界了
//        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
//            return false;
//        }
//
//        // 没有走过
//        if (isVisited[i][j]) {
//            return false;
//        }
//
//        // 单词不符合
//        if (word[index] != board[i][j]) {
//            return false;
//        }
//
//        isVisited[i][j] = true;
//        if (dfs(board, i + 1, j, word, index + 1) || dfs(board, i - 1, j, word, index + 1)
//            || dfs(board, i, j + 1, word, index + 1) || dfs(board, i, j - 1, word, index + 1)) {
//            return true;
//        }
//
//        isVisited[i][j] = false;
//        return false;
//    }
//
//    bool exist(vector<vector<char>>& board, string word) {
//        isVisited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[0].size(); j++) {
//                if (dfs(board, i, j, word, 0)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};
//
//class Solution {
//public:
//    vector<string> ans;
//    string path;
//
//    void dfs(int n, int left, int right) {
//        if (path.size() == n * 2) {
//            ans.push_back(path);
//            return;
//        }
//
//        // 还可以加入 '('
//        if (left < n) {
//            path += '(';
//            dfs(n, left + 1, right);
//            path.pop_back();
//        }
//        // 还可以加入 ')'
//        if (right < left) {
//            path += ')';
//            dfs(n, left, right + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<string> generateParenthesis(int n) {
//        dfs(n, 0, 0);
//        return ans;
//    }
//};