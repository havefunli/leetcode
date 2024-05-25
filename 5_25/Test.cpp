#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if ((abs(i - j) >= indexDifference)
                    && (abs(nums[i] - nums[j]) >= valueDifference)) {
                    ret.push_back(i);
                    ret.push_back(j);

                    return ret;
                }
            }
        }

        ret.assign(2, -1);

        return ret;
    }
};

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // 1 的个数不足 k
        if (count(s.begin(), s.end(), '1') < k) {
            return "";
        }
        // 否则一定有解
        for (int size = k;; size++) {
            string ans = "";
            for (int i = size; i <= s.length(); i++) {
                string t = s.substr(i - size, size);
                if ((ans == "" || t < ans) && count(t.begin(), t.end(), '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
    }
};

int main() {
	return 0;
}