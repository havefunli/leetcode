//#include <iostream>
//#include <map>
//using namespace std;
//
//const int N = 100010;
//int a[N];
//
//int main() {
//    int N = 1;
//    int l = 0, r = N - 1;

    //int n = 0;
    //cin >> n;

    //for (int i = 0; i < n; i++) {
    //    cin >> a[i];
    //}

    //int len = 0;
    //map<int, int> map;
    //for (int i = 0, j = 0; i < n; i++) {
    //    map[a[i]]++;

    //    while (map[a[i]] > 1) {
    //        map[a[j]]--;
    //        j++;
    //    }

    //    len = max(len, i - j + 1);
    //}

    //cout << len << endl;
//}

#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int l = 0, r = m - 1;
    while ((a[l] + b[r]) != x) {
        while (a[l] + b[r] > x) {
            r--;
        }
        while (a[l] + b[r] < x) {
            l++;
        }
    }

    cout << l << " " << r << endl;
    return 0;
}
