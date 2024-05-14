#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//class Solution {
//private:
//    vector<vector<int>> ret;
//    vector<int> combine;
//public:
//    void backtracking(vector<int>& candidates, int target, int index, int sum) {
//        if (sum > target) return;
//        if (sum == target) {
//            ret.push_back(combine);
//            return;
//        }
//
//        for (int i = index; i < candidates.size(); i++) {
//            sum += candidates[i];
//            combine.push_back(candidates[i]);
//            backtracking(candidates, target, i, sum);
//            sum -= candidates[i];
//            combine.pop_back();
//        }
//    }
//
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        backtracking(candidates, target, 0, 0);
//
//        return ret;
//    }
//};

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> combine;
public:
    void backtracking(vector<int>& candidates, int target, int sum, int index, vector<bool>& used) {
        if (sum > target) return;
        if (target == sum) {
            ret.push_back(combine);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1]
                && used[i - 1] == false) continue;
            used[i] = true;
            combine.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            combine.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return ret;
        sort(candidates.begin(), candidates.end());

        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, 0, used);
        return ret;
    }
};

int main() {
    vector<int> candidates(3, 2);
    candidates.push_back(5);
    candidates.push_back(1);
    Solution test;
    test.combinationSum2(candidates, 5);
}