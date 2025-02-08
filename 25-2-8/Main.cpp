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
        // ͳ�Ƴ���Ƶ��
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] += 1;
        }
        // �Զ���������򴴽�С����
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> heap;
        // ����
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
    priority_queue<int> heapLeft; // ���
    priority_queue<int, vector<int>, greater<int>> heapRight; // С��
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
        // ���ұ߽�
        int l = 0, r = matrix[0].size() - 1;
        // ���±߽�
        int t = 0, b = matrix.size() - 1;

        while (l <= r && t <= b) {
            // ����
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            if (++t > b) {
                break;
            }

            // �ϵ���
            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }

            // �ҵ���
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[b][i]);
            }
            if (--b < t) {
                break;
            }

            // �µ���
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
    // ʹ��ǰ׺��
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;  // �������

        int sum = 0;
        int cnt = 0;
        for (int& n : nums) {
            sum += n;
            // �ҵ���
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
        // ��¼ÿһ���ַ������ֵ�λ��
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int end = 0;
        int begin = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);
            // �ҵ���ǰ�ַ������һ���ַ�
            if (end == i) {
                ans.push_back(end - begin + 1);
                begin = i + 1;
            }
        }
        return ans;
    }
};