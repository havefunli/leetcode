//#include <iostream>
//using namespace std;
// // �������һ�� 1 �Լ�֮���λ��
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