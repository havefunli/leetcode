//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int characterReplacement(string s, int k) {
//        int ans = 0;
//        int map[26] = { 0 };
//        int maxCnt = 0;
//        int start = 0;
//
//        for (int end = 0; end < s.size(); end++) {
//            map[s[end] - 'A'] += 1;
//            maxCnt = max(maxCnt, map[s[end] - 'A']);
//            // ÅÐ¶ÏÌõ¼þÂú×ã
//            while (end - start + 1 - maxCnt > k) {
//                map[s[start] - 'A'] -= 1;
//                start += 1;
//            }
//            ans = max(ans, end - start + 1);
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        int a = INT_MIN;
//        int b = INT_MIN;
//        for (int& num : nums) {
//            if (num >= a) {
//                b = a;
//                a = num;
//            }
//            else if (num >= b) {
//                b = num;
//            }
//        }
//
//        return (a - 1) * (b - 1);
//    }
//};
//
//int main() {
//    string s = "AAAB";
//    Solution().characterReplacement(s, 0);
//    return 0;
//}