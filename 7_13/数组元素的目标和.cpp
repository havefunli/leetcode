//#include <iostream>
//using namespace std;
//
//const int N = 100010;
//int a[N];
//int b[N];
//
//int main() {
//    int n, m, x;
//    cin >> n >> m >> x;
//
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int j = 0; j < m; j++) {
//        cin >> b[j];
//    }
//
//    for (int i = 0; i < n; i++) {
//
//        int l = 0, r = m - 1;
//        while (l < r) {
//            int mid = (l + r) / 2;
//            if ((a[i] + b[mid]) >= x) r = mid;
//            else l = mid + 1;
//        }
//
//        if (a[i] + b[l] == x) {
//            cout << i << " " << l << endl;
//            break;
//        }
//    }
//
//    return 0;
//}