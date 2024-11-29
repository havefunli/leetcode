//class Solution {
//public:
//    /*除了自身以外，就是左边乘积 * 右边乘积*/
//    vector<int> productExceptSelf(vector<int>& nums) {
//        if (nums.size() < 2) { return nums; }
//
//        vector<int> ans(nums.size(), 1);
//        // 左边乘积
//        for (int i = 1; i < nums.size(); i++)
//        {
//            ans[i] *= (nums[i - 1] * ans[i - 1]);
//        }
//        for (auto& num : ans)
//        {
//            cout << num << ' ';
//        }
//        cout << endl;
//        int tmp = 1;
//        // 右边乘积
//        for (int j = nums.size() - 2; j >= 0; j--)
//        {
//            tmp *= nums[j + 1];
//            ans[j] *= tmp;
//        }
//
//        return ans;
//    }
//};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//
//    ListNode* MergeSort(vector<ListNode*>& lists, int l, int r)
//    {
//        if (l >= r) { return lists[l]; }
//
//        int mid = (l + r) / 2;
//        ListNode* left = MergeSort(lists, l, mid);
//        ListNode* right = MergeSort(lists, mid + 1, r);
//
//        ListNode* tmp = new ListNode(1);
//        ListNode* cur = tmp;
//
//        while (left && right)
//        {
//            if (left->val < right->val)
//            {
//                cur->next = left;
//                left = left->next;
//            }
//            else
//            {
//                cur->next = right;
//                right = right->next;
//            }
//
//            cur = cur->next;
//        }
//
//        while (left)
//        {
//            cur->next = left;
//            left = left->next;
//            cur = cur->next;
//        }
//        while (right)
//        {
//            cur->next = right;
//            right = right->next;
//            cur = cur->next;
//        }
//
//        return tmp->next;
//    }
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if (lists.size() == 0) { return nullptr; }
//
//        int l = 0, r = lists.size() - 1;
//        return MergeSort(lists, l, r);
//    }
//};

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(const vector<int>& ratings) {
        vector<int> leftMax(ratings.size(), 1);
        vector<int> righttMax(ratings.size(), 1);

        /*更新左边的最大值*/
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                leftMax[i] = leftMax[i - 1] + 1;
            }
        }

        int ans = leftMax.back();
        /*更新右边的最大值*/
        for (int j = ratings.size() - 2; j >= 0; j--)
        {
            if (ratings[j] > ratings[j + 1])
            {
                righttMax[j] = righttMax[j + 1] + 1;
            }
            ans += max(leftMax[j], righttMax[j]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    s.candy({ 1,2,2 });
    return 0;
}