//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//
//    vector<int> nums(n, 0);
//    for (int i = 0; i < n; i++) {
//        cin >> nums[i];
//    }
//
//    int ans = 1;
//    int curDiff = 0, oldDiff = 0;
//    for (int i = 1; i < n; i++) {
//        curDiff = nums[i] - nums[i - 1];
//        if ((curDiff > 0 && oldDiff < 0) || (curDiff > 0 && oldDiff < 0)) {
//            ans += 1;
//        }
//        oldDiff = curDiff;
//    }
//
//    cout << ans;
//}
//
//#include <iostream>
//using namespace std;
//
//int func(int num) {
//    int ans = 0;
//    int a = 1;
//    while (num) {
//        num -= a;
//        if (num % (2 * a) == 0) {
//            a *= 2;
//        }
//        ans++;
//    }
//
//    return ans;
//}
//
//int main() {
//    int n = 0;
//    cin >> n;
//
//    while (n--) {
//        int num;
//        cin >> num;
//        cout << func(num) << endl;
//    }
//}

//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ��������ϸ����������еĳ���
//     * @param a int����vector ����������
//     * @return int����
//     */
//    int LIS(vector<int>& a) {
//        // write code here
//
//        vector<int> dp(a.size(), 1);
//        int ans = 1;
//        for (int i = 1; i < a.size(); i++) {
//            for (int j = 0; j < i; j++) {
//                if (a[i] > a[j]) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                    ans = max(ans, dp[i]);
//                }
//            }
//        }
//
//        return ans;
//    }
//};