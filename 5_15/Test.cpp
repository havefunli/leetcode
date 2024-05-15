#include <iostream>
#include <string>
using namespace std;

//class Solution {
//public:
//    int& is_eff_range(int& num) {
//        if (num > pow(2, 31) - 1) num = pow(2, 31) - 1;
//        else if (num < -pow(2, 31)) num = -pow(2, 31);
//        return num;
//    }
//
//    int myAtoi(string str) {
//        getline(cin, str);
//
//        int ret = 0;
//        int flag = 1;
//        auto it = str.begin();
//        while (it != str.end()) {
//            if (*it == '+' || *it == '-' || (*it >= '0' && *it <= '9')) {
//                if (*it == '-') flag = -1;
//                else ret = ret * 10 + (*it - '0');
//            }
//
//            it += 1;
//        }
//
//        return flag * ret;
//    }
//};
//
//void main() {
//    Solution s;
//    cout << s.myAtoi("42") << endl;
//}

#include <string>
using namespace std;

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end_1 = num1.size() - 1;
//        int end_2 = num2.size() - 1;
//        string ret;
//
//        int carry = 0;
//        while (end_1 >= 0 && end_2 >= 0) {
//            int n1 = num1[end_1] - '0';
//            int n2 = num2[end_2] - '0';
//
//            int n = n1 + n2 + carry;
//            if (n >= 10) {
//                ret.insert(0, 1, '0' + n % 10);
//                carry = 1;
//            }
//            else {
//                ret.insert(0, 1, '0' + n % 10);
//                carry = 0;
//            }
//
//            end_1 -= 1;
//            end_2 -= 1;
//        }
//
//        while (end_1 >= 0) {
//            int n = num1[end_1] - '0' + carry;
//            if (n >= 10) {
//                ret.insert(0, 1, '0' + n % 10);
//                carry = 1;
//            }
//            else {
//                ret.insert(0, 1, '0' + n % 10);
//                carry = 0;
//            }
//            end_1 -= 1;
//        }
//
//        while (end_2 >= 0) {
//            int n = num2[end_2] - '0' + carry;
//            if (n >= 10) {
//                ret.insert(0, 1, '0' + n % 10);
//                carry = 1;
//            }
//            else {
//                ret.insert(0, 1, '0' + n % 10);
//                carry = 0;
//            }
//            end_2 -= 1;
//        }
//
//        if (carry == 1) {
//            ret.insert(0, 1, '1');
//        }
//
//        return ret;
//    }
//};

//#include <vector>
//
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int start = 0;
//        int end = s.size() - 1;
//
//        while (start != end) {
//            swap(s[start], s[end]);
//
//            start += 1;
//            end -= 1;
//        }
//    }
//};

class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
                str += s[i];
            }
        }

        for (int left = 0, right = str.size() - 1; left < right; left++, right--) {
            if (str[left] != str[right]) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    s.isPalindrome("0P");

    return 0;
}