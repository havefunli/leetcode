//#include <iostream>
//using namespace std;
//
//const int N = 100010;
//int a[N];
//
//// 神之一手
//void insert(int l, int r, int val) {
//    a[l] += val;
//    a[r + 1] -= val;
//}
//
//int main() {
//    int m, n;
//    scanf("%d%d", &n, &m);
//
//    for (int i = 1; i <= n; ++i) {
//        int val;
//        cin >> val;
//        insert(i, i, val);
//    }
//
//    while (m--) {
//        int l, r, c;
//        cin >> l >> r >> c;
//
//        insert(l, r, c);
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        a[i] += a[i - 1];
//        cout << a[i] << " ";
//    }
//
//    return 0;
//}