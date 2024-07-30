#include "MyHead.h"

typedef pair<int, int> PII;

vector<PII> secs;

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        int l, r;
        cin >> l >> r;
        // ��¼����
        secs.push_back({ l, r });
    }

    // �����䰴����˵�����
    auto Less = [](const PII& left, const PII& right) { return left.first < right.first; }; // Lambda ���ʽ
    sort(secs.begin(), secs.end(), Less);

    int cnt = 1; // �������
    int Min = secs[0].first;
    int Max = secs[0].second;
    for (int i = 1; i < secs.size(); i++) {
        // û�н���
        if (Max < secs[i].first) {
            cnt++;
            // ������С���ֵ
            Min = secs[i].first;
            Max = secs[i].second;
        }
        // �н���
        else {
            Max = max(Max, secs[i].second);
        }
    }

    cout << cnt << endl;

    return 0;
}