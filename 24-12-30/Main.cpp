#include <vector>
#include <string>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    string printBin(double num) {
//        string ans = "0.";
//
//        int cnt = 0;
//        while (num && cnt <= 6) {
//            num *= 2;
//
//            if (num >= 1) {
//                num -= 1;
//                ans += '1';
//            }
//            else {
//                ans += '0';
//            }
//            cnt += 1;
//        }
//
//        return cnt == 6 ? "ERROR" : ans;
//    }
//};

//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int totalSum = 0;
//        int curSum = 0;
//        int ans = 0;
//        for (int i = 0; i < gas.size(); i++) {
//            curSum += (gas[i] - cost[i]);
//            totalSum += (gas[i] - cost[i]);
//
//            if (curSum < 0) {
//                ans = i + 1;
//                curSum = 0;
//            }
//        }
//
//        if (totalSum < 0) {
//            return -1;
//        }
//        else {
//            return ans;
//        }
//    }
//};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> charge(3, 0);

        for (auto& money : bills) {
            // 1. 第一种情况
            if (money == 5) {
                charge[0]++;
            }
            else if (money == 10) {
                if (charge[0] == 0) {
                    return false;
                }
                charge[0]--;
                charge[1]++;
            }
            else {
                if (charge[0] > 0 && charge[1] > 0) {
                    charge[0]--;
                    charge[1]--;
                }
                else if (charge[0] >= 3) {
                    charge[0] -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> bill = { 5,5,5,10,20 };
    s.lemonadeChange(bill);
	return 0;
}