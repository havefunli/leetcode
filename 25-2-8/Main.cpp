class Solution {
public:
    class myCompare {
    public:
        bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
            return left.second > right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        // 统计出现频率
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] += 1;
        }
        // 自定义排序规则创建小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> heap;
        // 建堆
        for (auto& pair : map) {
            heap.push(pair);
            if (heap.size() == k + 1) {
                heap.pop();
            }
        }

        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++) {
            ans[i] = heap.top().first;
            heap.pop();
        }
        return ans;
    }
};

class MedianFinder {
public:
    MedianFinder()
    {}

    void addNum(int num) {
        if (heapLeft.size() == heapRight.size()) {
            heapRight.push(num);
            heapLeft.push(heapRight.top());
            heapRight.pop();
        }
        else {
            heapLeft.push(num);
            heapRight.push(heapLeft.top());
            heapLeft.pop();
        }
    }

    double findMedian() {
        return heapLeft.size() == heapRight.size() ? (heapLeft.top() + heapRight.top()) / double(2)
            : heapLeft.top();
    }
private:
    priority_queue<int> heapLeft; // 大堆
    priority_queue<int, vector<int>, greater<int>> heapRight; // 小堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(2, 0);
        dp[1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[1] + prices[i], dp[0]);
            dp[1] = max(dp[1], -prices[i]);
        }
        return dp[0];
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        // 左右边界
        int l = 0, r = matrix[0].size() - 1;
        // 上下边界
        int t = 0, b = matrix.size() - 1;

        while (l <= r && t <= b) {
            // 左到右
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            if (++t > b) {
                break;
            }

            // 上到下
            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }

            // 右到左
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[b][i]);
            }
            if (--b < t) {
                break;
            }

            // 下到上
            for (int i = b; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    // 使用前缀和
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;  // 特殊情况

        int sum = 0;
        int cnt = 0;
        for (int& n : nums) {
            sum += n;
            // 找到了
            if (map.count(sum - k) != 0) {
                cnt += map[sum - k];
            }
            map[sum] += 1;
        }
        return cnt;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = nums[0];
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndex[26] = { 0 };
        // 记录每一个字符最后出现的位置
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int end = 0;
        int begin = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);
            // 找到当前字符串最后一个字符
            if (end == i) {
                ans.push_back(end - begin + 1);
                begin = i + 1;
            }
        }
        return ans;
    }
};