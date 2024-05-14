#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k = 2;
    int n = 4;

    vector<vector<int>> vv;

    for (int i = 1; i <= k; i++) {
        vector<int> v;
        for (int m = i; m + k - 1 <= n; m++) {
            v.push_back(m);
        }
        vv.push_back(v);

        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    //for (int i = 0; i < 10; i++) {
    //    for (int n = i; n < 10; n++) {
    //        cout << "test" << endl;
    //    }
    //}


    return 0;
}