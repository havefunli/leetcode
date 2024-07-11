#include "myHead.h"

vector<int> Add(vector<int>& left, vector<int>& right) {
    vector<int> ret;
    int m = left.size();
    int n = right.size();

    int add = 0, carry = 0;
    for (int i = 0; i < m || i < n; ++i) {
        if (i < m) add += left[i];
        if (i < n) add += right[i];
        add += carry;

        ret.push_back(add % 10);
        carry = add / 10;
        add = 0;
    }

    if (carry) ret.push_back(1);

    return ret;
}

//int main() {
//    string a, b;
//    cin >> a >> b;
//
//    vector<int> left;
//    vector<int> right;
//
//    for (int i = a.size() - 1; i >= 0; --i) {
//        left.push_back(a[i] - '0');
//    }
//    for (int i = b.size() - 1; i >= 0; --i) {
//        right.push_back(b[i] - '0');
//    }
//
//    vector<int> ret = Add(left, right);
//    for (int i = ret.size() - 1; i >= 0; --i) {
//        cout << ret[i];
//    }
//    cout << endl;
//
//    return 0;
//}