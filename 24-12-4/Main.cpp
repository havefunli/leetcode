#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        sort(nums.begin(), nums.end());
//
//        for (int i = 0; i < nums.size() - 2; i++)
//        {
//            /*¼ôÖ¦*/
//            if (nums[i] > 0) { return ans; }
//            /*È¥ÖØ*/
//            if (i > 0 && nums[i] == nums[i - 1]) { continue; }
//
//            int cnt = 0 - nums[i];
//            int l = i + 1, r = nums.size() - 1;
//            while (l < r)
//            {
//                while (l < r && nums[l] + nums[r] > cnt) { r--; }
//                while (l < r && nums[l] + nums[r] < cnt) { l++; }
//                if (l < r)
//                {
//                    ans.push_back({ nums[i], nums[l], nums[r] });
//                    while (l < r && nums[l] == nums[l + 1]) { l++; }
//                    while (l < r && nums[r] == nums[r - 1]) { r--; }
//
//                    l++;
//                    r--;
//                }
//            }
//        }
//        return ans;
//    }
//};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++)
        {
            int num = target - numbers[i];
            int l = i + 1, r = numbers.size() - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (numbers[mid] > num) { r = mid - 1; }
                else { l = mid; }
            }
            if (numbers[l] == num) { return { i, l }; }
        }
        return { -1, -1 };
    }
};

int main()
{
    vector<int> nums = { 2,7,11,15 };
    Solution().twoSum(nums, 9);
    return 0;
}