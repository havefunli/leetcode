////class Solution {
////public:
////    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
////        vector<int> inDegree(numCourses); // 记录入度
////        unordered_map<int, vector<int>> map; // 记录指向关系
////
////        for (int i = 0; i < prerequisites.size(); i++) {
////            inDegree[prerequisites[i][0]] += 1; // 入度加一
////            map[prerequisites[i][1]].push_back(prerequisites[i][0]); // 记录指向
////        }
////
////        queue<int> queue;
////        // 记录初始入度为 0
////        for (int i = 0; i < numCourses; i++) {
////            if (inDegree[i] == 0) {
////                // cout << i << " ";
////                queue.push(i);
////            }
////        }
////
////        int cnt = 0;
////        while (!queue.empty()) {
////            int index = queue.front();
////            queue.pop();
////            // cout << index << " ";
////            cnt += 1;
////
////            if (map.find(index) == map.end()) {
////                // cout << "continue" << " ";
////                continue;
////            }
////
////            // 让 index 指向的入度减一
////            for (int i = 0; i < map[index].size(); i++) {
////                // cout << map[index][i] << " ";
////                // 入度减一
////                inDegree[map[index][i]] -= 1;
////                // 入度为零
////                if (inDegree[map[index][i]] == 0) {
////                    // cout << map[index][i] << " ";
////                    queue.push(map[index][i]);
////                }
////            }
////        }
////        return cnt == numCourses;
////    }
////};
////
////class Solution {
////public:
////    vector<int> path;
////    vector<vector<int>> ans;
////    vector<bool> isVisited;
////
////    void dfs(vector<int>& nums) {
////        if (path.size() == nums.size()) {
////            ans.push_back(path);
////            return;
////        }
////
////        for (int i = 0; i < nums.size(); i++) {
////            if (!isVisited[i]) {
////                path.push_back(nums[i]);
////                isVisited[i] = true;
////                dfs(nums);
////                path.pop_back();
////                isVisited[i] = false;
////            }
////        }
////    }
////
////    vector<vector<int>> permute(vector<int>& nums) {
////        isVisited.resize(nums.size(), false);
////        dfs(nums);
////        return ans;
////    }
////};
//
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<int> path;
//
//    void dfs(vector<int>& nums, int startIndex) {
//
//        ans.push_back(path);
//
//        if (startIndex >= nums.size()) {
//            return;
//        }
//
//        for (int i = startIndex; i < nums.size(); i++) {
//            path.push_back(nums[i]);
//            dfs(nums, i + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<vector<int>> subsets(vector<int>& nums) {
//        dfs(nums, 0);
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    unordered_map<char, string> map{
//        {'0', ""},
//        {'1', ""},
//        {'2', "abc"},
//        {'3', "def"},
//        {'4', "ghi"},
//        {'5', "jkl"},
//        {'6', "mno"},
//        {'7', "pqrs"},
//        {'8', "tuv"},
//        {'9', "wxyz"}
//    };
//
//    vector<string> ans;
//    string path;
//
//    void dfs(string& digits, int startIndex) {
//        if (path.size() == digits.size()) {
//            ans.push_back(path);
//            return;
//        }
//
//        string str = map[digits[startIndex]];
//        for (int i = 0; i < str.size(); i++) {
//            path.push_back(str[i]);
//            dfs(digits, startIndex + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<string> letterCombinations(string digits) {
//        if (digits.empty()) {
//            return ans;
//        }
//
//        dfs(digits, 0);
//        return ans;
//    }
//};
//
//int main() {
//    vector<int> nums = { 1, 2 };
//    Solution().subsets(nums);
//    return 0;
//}