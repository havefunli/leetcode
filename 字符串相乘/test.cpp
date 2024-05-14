#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2)
{

    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    string str;
    int carry = 0;

    while (end1 >= 0 || end2 >= 0)
    {
        int n1 = end1 >= 0 ? num1[end1] - '0' : 0;
        int n2 = end2 >= 0 ? num2[end2] - '0' : 0;

        str += ((n1 + n2 + carry) % 10 + '0');
        carry = (n1 + n2 + carry) / 10;

        end1--;
        end2--;
    }
    if (carry != 0)
        str += (carry + '0');
    reverse(str.begin(), str.end());

    return str;
}

string mul(string num1, string num2) {
	if (num1 == "0" || num2 == "0") {
		return "0";
	}

    string s("0");
    int len1 = num1.size();
    int len2 = num2.size();

    for (int i = len1 - 1; i >= 0; i--) {
        int n1 = num1[i] - '0';
        int carry = 0;
        string mul;

        for (int j = len1 - 1; j > i; j--) {
            mul += '0';
        }

        for (int k = len2 - 1; k >= 0; k--) {
            int n2 = num2[k] - '0';
            int product = n1 * n2;
            int num = product + carry;
            mul += (num % 10 + '0');
            carry = num / 10;
        }
        if (carry != 0)
            mul += (carry + '0');
        reverse(mul.begin(), mul.end());

        s = addStrings(mul, s);
    }

    return s;
}


int main() {
	string num1, num2;
	cin >> num1 >> num2;
    
	string answer = mul(num1, num2);
    cout << answer;

    return -1;
}