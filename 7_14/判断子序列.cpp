//#include <iostream>
//using namespace std;
//
//const int N = 100010;
//int a[N], b[N];
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < m; i++) {
//        cin >> b[i];
//    }
//
//    int j = 0;
//    for (int i = 0; i < m; i++) {
//        if (j == n) break;
//        if (b[i] == a[j]) j++;
//    }
//
//    if (j == n) cout << "Yes" << endl;
//    else cout << "No" << endl;
//
//    return 0;
//}