//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//
//        int ans = 1;
//        vector<int> res(nums.size(), 1);
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i - 1] == nums[i] - 1) {
//                res[i] += 1;
//                ans = ans > res[i] ? ans : res[i];
//            }
//            else if (nums[i - 1] == nums[i]) {
//                res[i] = res[i - 1];
//            }
//        }
//        for (auto& n : res) {
//            cout << n << " ";
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    bool isIsomorphic(string s, string t) {
//        unordered_map<char, char> s_map;
//        unordered_map<char, char> t_map;
//
//        for (int i = 0; i < s.size(); i++) {
//            char c = s[i];
//            char x = t[i];
//            if (s_map.count(c) != 0 && s_map[c] != x ||
//                t_map.count(x) != 0 && t_map[x] != c) {
//                return false;
//            }
//            s_map[c] = x;
//            t_map[x] = c;
//        }
//        return true;
//    }
//};
//
//class Solution {
//public:
//    int sumOfN(int n) {
//        int ret = 0;
//        while (n) {
//            ret += (pow(n % 10, 2));
//            n /= 10;
//        }
//        return ret;
//    }
//
//    bool isHappy(int n) {
//        unordered_map<int, int> map;
//        while (true) {
//            int num = 0;
//            num = sumOfN(n);
//            if (num == 1) {
//                return true;
//            }
//            else {
//                if (map.count(num) == 1) {
//                    return false;
//                }
//                map[num]++;
//                n = num;
//            }
//        }
//        return false;
//    }
//};
//
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        int m = s.size();
//        int ans_left = -1, ans_rigth = m;
//
//        int less = 0; // 记录当前子串中少于所需字符的个数
//        int t_map[128] = { 0 };
//        for (auto c : t) {
//            if (t_map[c] == 0) {
//                less++;
//            }
//            t_map[c]++;
//        }
//
//        int l = 0;
//        for (int r = 0; r < m; r++) {
//            char c = s[r];
//            t_map[c]--;
//            if (t_map[c] == 0) {
//                less--;
//            }
//
//            while (0 == less) {
//                // 更新
//                if (ans_rigth - ans_left > r - l) {
//                    ans_left = l;
//                    ans_rigth = r;
//                }
//                if (t_map[s[l]] == 0) {
//                    less++;
//                }
//                t_map[s[l]]++;
//                l++;
//            }
//        }
//
//        return ans_left < 0 ? "" : s.substr(ans_left, ans_rigth - ans_left + 1);
//    }
//};
//
//
//int main() {
//    Solution s;
//    vector<int> tmp = { 100,4,200,1,3,2 };
//    s.longestConsecutive(tmp);
//    return 0;
//}