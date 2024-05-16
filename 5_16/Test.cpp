#include <string>
#include <iostream>
using namespace std;

//int main() {
    //string s;
    //getline(cin, s);

    //int counts = 0;
    //int pos = s.rfind(' ');
    //if (pos == string::npos) cout << s.size() << endl;
    //else {
    //    while (pos < s.size()) {
    //        pos += 1;
    //        counts += 1;
    //    }
    //    cout << counts << endl;
    //}
    //return -1;

//    int A = 1;
//    int B = 1;
//    A = B = A + 1;
//}

//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        if (s.size() == 0) return s;
//
//        int counts = 1;
//        int front = 0, back = 0;
//        while (front < s.size() - 1) {
//            if (counts == 2 * k) {
//                counts = 1;
//                reverse(s.begin() + back, s.begin() + back + k);
//                front = back = front + 1;
//            }
//            else {
//                front += 1;
//                counts += 1;
//            };
//        }
//        if (s.size() - back < k) reverse(s.begin() + back, s.end());
//        else reverse(s.begin() + back, s.begin() + back + k);
//
//        return s;
//    }
//};

class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        while (index < s.size()) {
            int pos = s.find(' ');
            if (pos == string::npos) {
                reverse(s.begin() + index, s.end());
                break;
            }
            else {
                reverse(s.begin() + index, s.begin() + pos);
                index = pos + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;

    return -1;
}