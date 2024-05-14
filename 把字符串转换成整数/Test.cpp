#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
    string str("+11");
    long num = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '+' && str[i] != '-'&& (str[i] >= '9'|| str[i] <= '0')) {
            cout<< 0;
        }
    }
    if (str[0] == '+' || str[0] == '-') {
        for (int m = 1; m < str.size(); m++) {
            num += num * 10 + (str[m] - '0');
        }
        if (str[0] == '+')
            cout << num;
        else
            cout << -num;
    }
    else {
        for (int m = 0; m < str.size(); m++) {
            num = num * 10 + (str[m] - '0');
        }
        cout << num;
    }
}