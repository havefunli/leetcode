#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
    string num1("99");
    string num2("9");

    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    string str;
    int carry = 0;

    while (end1 >= 0 || end2 >= 0) {
        int n1 = end1 >= 0 ? num1[end1] - '0' : 0;
        int n2 = end2 >= 0 ? num2[end2] - '0' : 0;

        str += ((n1 + n2 + carry) % 10 + '0');
        carry = (n1 + n2 + carry) / 10;

        end1--;
        end2--;
    }
    if (carry != 0)
        str += (carry + '0');

    for (int i = 0; i < str.size(); i++)
    {
        if (str.find_first_of(str[i]) == str.find_last_of(str[i]))
            return i;
    }
    return -1;
    reverse(str.begin(), str.end());

    cout << str;
}