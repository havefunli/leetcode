//class Solution {
//public:
//    Solution() {
//        counts += num;
//        num += 1;
//    }
//
//    int Sum_Solution(int n = 5) {
//        Solution s[5];
//        return counts;
//    }
//
//    static int counts;
//    static int num;
//};
//
//int Solution::counts = 0;
//int Solution::num = 1;
//
//
//int main() {
//    Solution s1;
//    s1.Sum_Solution();
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//    int DayofYear() {
//        static int countsDay[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
//        if ((_year % 400 == 0) || ((_year % 4 == 0) && (_year % 100 != 0))) {
//            _day += 1;
//        }
//
//        return countsDay[_month] + _day;
//    }
//
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//private:
//    int _year = 0;
//    int _month = 0;
//    int _day = 0;
//};
//
//
//int main() {
//    int year, month, day;
//    cin >> year >> month >> day;
//    Date D(year, month, day);
//
//    return D.DayofYear();
//}

