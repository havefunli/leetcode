//#include <iostream>
//using namespace std;
// // 返回最后一个 1 以及之后的位置
//int low_bit(int n) {
//    return n & -n;
//}
//
//int main() {
//    int n = 0;
//    cin >> n;
//
//    int num = 0;
//    while (n--) {
//        int cnt = 0;
//        cin >> num;
//        while (num) {
//            num -= low_bit(num);
//            cnt++;
//        }
//        cout << cnt << " ";
//    }
//    cout << endl;
//
//    return 0;
//}