//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        unordered_map<char, int> map;
//        for (auto ch : s)
//        {
//            map[ch]++;
//        }
//
//        for (auto ch : t)
//        {
//            map[ch]--;
//        }
//
//        for (auto& pair : map)
//        {
//            if (pair.second != 0) return false;
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        sort(s.begin(), s.end());
//        sort(t.begin(), t.end());
//
//        return s == t ? true : false;
//    }
//};

//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set<int> set1(nums1.begin(), nums1.end());
//        unordered_set<int> set2(nums2.begin(), nums2.end());
//
//        vector<int> ans;
//        for (auto val : set1)
//        {
//            if (set2.find(val) != set2.end()) ans.push_back(val);
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int SumOfSquares(int num)
//    {
//        int result = 0;
//        while (num)
//        {
//            result += pow(num % 10, 2);
//            num /= 10;
//        }
//        return result;
//    }
//
//    bool isHappy(int n) {
//        unordered_set<int> backup;
//
//        while (true)
//        {
//            backup.insert(n);
//            n = SumOfSquares(n);
//            if (n == 1) return true;
//            else if (backup.find(n) != backup.end()) return false;
//        }
//    }
//};

//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            auto iter = map.find(target - nums[i]);
//            if (iter != map.end()) return { iter->second, i };
//
//            map[nums[i]] = i;
//        }
//
//        return {};
//    }
//};

//class Solution {
//public:
//    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//        unordered_map<int, int> left;
//        unordered_map<int, int> right;
//        for (int i = 0; i < nums1.size(); i++)
//        {
//            for (int j = 0; j < nums1.size(); j++)
//            {
//                left[nums1[i] + nums2[j]]++;
//                right[nums3[i] + nums4[j]]++;
//            }
//        }
//
//        int cnt = 0;
//        for (auto pair : left)
//        {
//            auto iter = right.find(0 - pair.first);
//            if (iter != right.end())
//                cnt += ((pair.second) * (iter->second));
//        }
//        return cnt;
//    }
//};


//class Solution {
//public:
//    bool canConstruct(string ransomNote, string magazine) {
//        if (ransomNote.size() > magazine.size()) return false;
//
//        unordered_map<char, int> map;
//        for (auto ch : magazine)
//        {
//            map[ch]++;
//        }
//
//        for (auto ch : ransomNote)
//        {
//            map[ch]--;
//            if (map[ch] < 0) return false;
//        }
//
//        return true;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        // 长度不i满足
//        if (nums.size() < 3) return ans;
//
//        sort(nums.begin(), nums.end()); // 排序
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] > 0) return ans; // 最小元素都大于 0，直接退出
//            if (i > 0 && nums[i - 1] == nums[i]) continue; // 去重
//
//            int cnt = 0 - nums[i];
//            int left = i + 1, right = nums.size() - 1;
//            while (left < right)
//            {
//                if (nums[left] + nums[right] > cnt) right--;
//                else if (nums[left] + nums[right] < cnt) left++;
//                else
//                {
//                    ans.push_back({ nums[i], nums[left], nums[right] });
//                    while (left < right && nums[left] == nums[left + 1]) left++;
//                    while (left < right && nums[right] == nums[right - 1])right--;
//
//                    left++;
//                    right--;
//                }
//            }
//        }
//
//        return ans;
//    }
//};


//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        vector<vector<int>> ans;
//        if (nums.size() < 4) return ans;
//
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size() - 3; i++)
//        {
//            if (nums[i] > target && target >= 0) return ans;
//            if (i > 0 && nums[i] == nums[i - 1]) continue;
//
//            for (int j = i + 1; j < nums.size() - 2; j++)
//            {
//                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//
//                int left = j + 1, right = nums.size() - 1;
//                while (left < right)
//                {
//                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
//                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
//                    else
//                    {
//                        ans.push_back({ nums[i], nums[j], nums[left], nums[right] });
//                        while (left < right && nums[left] == nums[left + 1]) left++;
//                        while (left < right && nums[right] == nums[right - 1]) right--;
//
//                        left++;
//                        right--;
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//};