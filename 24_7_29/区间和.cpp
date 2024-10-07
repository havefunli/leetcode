#include "MyHead.h"

typedef pair<int, int> PII;

vector<int> idx; // 收集需要处理的下标
vector<PII> op, query; // 所有执行的操作，以及访问的区间

const int N = 300010;
int a[N], s[N];

// 映射下标
int Find(int x) {
    int l = 0, r = idx.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (idx[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (n--) {
        int x, c;
        cin >> x >> c;

        op.push_back({ x, c });
        idx.push_back(x);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;

        query.push_back({ l, r });
        idx.push_back(l);
        idx.push_back(r);
    }

    sort(idx.begin(), idx.end()); // 排序
    idx.erase(unique(idx.begin(), idx.end()), idx.end()); // 去重

    // 将对应的操作映射到指定的下标上
    for (auto& item : op) {
        int i = Find(item.first);
        a[i] += item.second;
    }

    // 构造前缀和数组
    for (int i = 1; i <= idx.size(); ++i) {
        s[i] = s[i - 1] + a[i];
    }

    // 访问下标
    for (auto& item : query) {
        int l = Find(item.first);
        int r = Find(item.second);

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
