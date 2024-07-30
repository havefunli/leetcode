#include "MyHead.h"

typedef pair<int, int> PII;

vector<PII> secs;

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        int l, r;
        cin >> l >> r;
        // 记录区间
        secs.push_back({ l, r });
    }

    // 将区间按照左端点排序
    auto Less = [](const PII& left, const PII& right) { return left.first < right.first; }; // Lambda 表达式
    sort(secs.begin(), secs.end(), Less);

    int cnt = 1; // 区间计数
    int Min = secs[0].first;
    int Max = secs[0].second;
    for (int i = 1; i < secs.size(); i++) {
        // 没有交集
        if (Max < secs[i].first) {
            cnt++;
            // 更新最小最大值
            Min = secs[i].first;
            Max = secs[i].second;
        }
        // 有交集
        else {
            Max = max(Max, secs[i].second);
        }
    }

    cout << cnt << endl;

    return 0;
}