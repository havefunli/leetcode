//#include "myHead.h"

//�������� nums ���������У������е�ֵ ������ͬ ��
//
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ �����������磬[0, 1, 2, 4, 5, 6, 7] ���±� 3 ������ת����ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2] ��
//
//	���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻� - 1 ��
//
//	��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int l = 0, r = nums.size() - 1;
//
//        while (l <= r) {
//            int mid = (l + r + 1) / 2;
//
//            if (nums[mid] == target) return mid;
//            else {
//                if (nums[l] < nums[mid]) {
//                    if (target >= nums[l] && target <= nums[mid]) r = mid - 1;
//                    else l = mid + 1;
//                }
//                else {
//                    if (target >= nums[mid] && target <= nums[r]) l = mid + 1;
//                    else r = mid - 1;
//                }
//            }
//        }
//
//        return -1;
//    }
//};
