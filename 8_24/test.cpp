#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//private:
//    vector<vector<int>> ret;
//    vector<int> path;
//
//public:
//    void combine(int n, int k, int start) {
//        if ((k - path.size()) + start - 1 > n)
//            return;
//
//        if (k == path.size()) {
//            ret.push_back(path);
//        }
//
//        for (int i = start; i <= n; i++) {
//            path.push_back(i);
//            combine(n, k, i + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<vector<int>> combine(int n, int k) {
//        int start = 1;
//        combine(n, k, start);
//
//        return ret;
//    }
//};

//class Solution {
//private:
//    vector<vector<int>> ret;
//    vector<int> com;
//public:
//    void combine(int k, int n, int start, int sum) {
//        if (sum == n && com.size() == k) {
//            ret.push_back(com);
//            return;
//        }
//
//        if (com.size() >= k) {
//            return;
//        }
//
//        for (int i = start; i <= 9; i++) {
//            com.push_back(i);
//            sum += i;
//            combine(k, n, i + 1, sum);
//            com.pop_back();
//            sum -= i;
//        }
//    }
//
//    vector<vector<int>> combinationSum3(int k, int n) {
//        combine(k, n, 1, 0);
//
//        return ret;
//    }
//};
//
//class Solution {
//private:
//    string lettermap[10] = {
//        "",
//        "",
//        "abc",
//        "def",
//        "ghi",
//        "jkl",
//        "mno",
//        "pqrs",
//        "tuv",
//        "wxyz"
//    };
//    vector<string> ret;
//    string s;
//
//public:
//    void backtracking(const string& digits, int index) {
//        if (index == digits.size()) {
//            ret.push_back(s);
//            return;
//        }
//
//        int digit = digits[index] - '0';
//        string letter = lettermap[digit];
//
//        for (int i = 0; i < letter.size(); i++) {
//            s += letter[i];
//            backtracking(digits, index + 1);
//            s.pop_back();
//        }
//    }
//
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0) return ret;
//        backtracking(digits, 0);
//
//        return ret;
//    }
//};

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> combine;
public:
    void backtracking(vector<int>& candidates, int target, int sum) {
        if (sum > target) return;
        if (sum == target) {
            ret.push_back(combine);
        }

        for (int i = 0; i < candidates.size(); i++) {
            sum += candidates[i];
            combine.push_back(candidates[i]);
            backtracking(candidates, target, sum);
            sum -= candidates[i];
            combine.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);

        return ret;
    }
};

int main() {
    int arr[3] = {2, 3, 5};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(int));
    int target = 7;

    Solution test;
    test.combinationSum(candidates, target);
}