#include "myHead.h"

const int N = 1010;
int arr[N][N];

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // 初始化前缀和数组
    int temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> temp;
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + temp; // 更新规则
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}