#include "myHead.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> Sum(nums.size() + 1, 0);
        int temp = 0;

        for (size_t i = 1; i <= nums.size(); i++) {
            temp = nums[i - 1];
            Sum[i] = temp + Sum[i - 1];
        }

        int Len = 100000;
        for (size_t i = 1; i < Sum.size(); i++) {
            int l = i;
            int r = Sum.size() - 1;

            while (l < r) {
                int mid = (l + r) / 2;
                 if (Sum[mid] - Sum[i - 1] >= target) {
                    r = mid;
                    Len = Len < mid - i + 1 ? Len : mid - i + 1;
                }
                else l = mid + 1;
            }

            if (l == r) {
                if (Sum[l] - Sum[i - 1] >= target) {
                    Len = Len < l - i + 1 ? Len : l - i + 1;
                }
            }
        }

        return Len == 100000 ? 0 : Len;
    }
};

int main() {
    Solution s1;
    vector<int> v = { 10,7,4,9,2,8 };
    s1.minSubArrayLen(15, v);

    return 0;
}