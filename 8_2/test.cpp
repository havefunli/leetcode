#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

void Test1() {
    string s("pwwkew");
    unordered_set<int> set;
    int len = 0;

    for (int i = 0; i < s.size(); i++) {
        if (set.find(s[i]) == set.end()) {
            set.insert(s[i]);
            len++;
        }
    }

    //return len;
}


//void Test2() {
//    vector<vector<int>> vv;
//    sort(nums.begin(), nums.end());
//
//    int i = 0;
//    for (i = 0; i < nums.size(); i++) {
//        if (nums[i] > 0)
//            return {};
//
//        if (i != 0 && nums[i] == nums[i - 1])
//            continue;
//
//        int left = i + 1;
//        int right = nums.size() - 1;
//
//        while (left < right) {
//            if (left < right && nums[i] + nums[left] + nums[right] > 0)
//                right--;
//            else if (left < right && nums[i] + nums[left] + nums[right] < 0)
//                left++;
//            else {
//                vv.push_back({ nums[i],nums[left],nums[right] });
//                while (left < right && nums[right] == nums[right - 1]) {
//                    right--;
//                }
//                while (left < right && nums[left] == nums[left + 1]) {
//                    left++;
//                }
//
//                right--;
//                left++;
//            }
//        }
//    }
//}
//
//void Test3() {
//    vector<vector<int>> vv;
//    sort(nums.begin(), nums.end());
//
//    for (int i = 0; i < nums.size(); i++) {
//        //if (nums[i] > target)
//        //    return vv;
//        if (i != 0 && nums[i] == nums[i - 1])
//            continue;
//
//        int n = target - nums[i];
//        for (int j = i + 1; j < nums.size(); j++) {
//            if (j != i + 1 && nums[j] == nums[j - 1])
//                continue;
//
//            int left = j + 1;
//            int right = nums.size() - 1;
//            while (left < right) {
//                if (nums[j] + nums[left] + nums[right] > n)
//                    right--;
//                else if (nums[j] + nums[left] + nums[right] < n)
//                    left++;
//                else {
//                    vv.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
//                    while (left < right && nums[left] == nums[left + 1])
//                        left++;
//                    while (left < right && nums[right] == nums[right - 1])
//                        right--;
//
//                    left++;
//                    right--;
//                }
//            }
//        }
//    }
//
//    return vv;
//}

void Test4() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top();
    cout << st.pop();

}

int main() {
	//Test1();
    //Test2();
    //Test3();
    Test4();


    return 0;
}