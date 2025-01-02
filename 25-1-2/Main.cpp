#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& left, const vector<int>& right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }
            return left[0] > right[0];
            });

        list<vector<int>> list;
        for (int i = 0; i < people.size(); i++) {
            int pos = people[i][1];

            std::list<vector<int>>::iterator it = list.begin();
            while (pos--) {
                it++;
            }
            list.insert(it, people[i]);
        }
        return vector<vector<int>>(list.begin(), list.end());
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] < right[0];
            });

        int ans = 1;
        vector<int> curRange = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (curRange[1] >= points[i][0]) {
                curRange[0] = points[i][0];
                curRange[1] = min(curRange[1], points[i][1]);
            }
            else {
                ans += 1;
                curRange = points[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] < right[0];
            });

        int ans = 0;
        int border = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (border > intervals[i][0]) {
                ans += 1;
                border = min(border, intervals[i][1]);
            }
            else {
                border = intervals[i][1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndex[26];
        // 更新最后一次出现的下标
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            end = max(lastIndex[s[i] - 'a'], end);
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] < right[0];
            });

        vector<int> curRange = intervals[0];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (curRange[1] >= intervals[i][0]) {
                curRange[1] = max(curRange[1], intervals[i][1]);
            }
            else {
                ans.push_back(curRange);
                curRange = intervals[i];
            }
        }
        ans.push_back(curRange);

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec = { {5, 0}, {5, 1}, {3, 1} };
    s.reconstructQueue(vec);
    return 0;
}