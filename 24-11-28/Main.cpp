//class Solution {
//public:
//    /*�����������⣬������߳˻� * �ұ߳˻�*/
//    vector<int> productExceptSelf(vector<int>& nums) {
//        if (nums.size() < 2) { return nums; }
//
//        vector<int> ans(nums.size(), 1);
//        // ��߳˻�
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
//        // �ұ߳˻�
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
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param lists ListNode��vector
//     * @return ListNode��
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

        /*������ߵ����ֵ*/
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                leftMax[i] = leftMax[i - 1] + 1;
            }
        }

        int ans = leftMax.back();
        /*�����ұߵ����ֵ*/
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