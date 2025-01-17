//class LRUCache {
//public:
//    LRUCache(int capacity)
//        : _capacity(capacity)
//        , _size(0)
//    {}
//
//    list<pair<int, int>>::iterator findValue(const int key) {
//        auto iter = _map.find(key);
//        if (iter != _map.end()) {
//            return iter->second;
//        }
//        return _list.end();
//    }
//
//    int get(int key) {
//        if (_size == 0) {
//            return -1;
//        }
//
//        auto iter = findValue(key);
//        if (iter == _list.end()) {
//            return -1;
//        }
//        else {
//            pair<int, int> pair = *iter;
//            _list.erase(iter); // ɾ����λ��
//            _list.push_front(pair); // ���뵽ǰ��
//            _map[key] = _list.begin(); // ���� map �еĵ�����
//        }
//        return _list.front().second;
//    }
//
//    void put(int key, int value) {
//        // �ж��Ƿ��Ѿ�����
//        auto iter = findValue(key);
//        // ����
//        if (iter != _list.end()) {
//            pair<int, int> pair = *iter;
//            pair.second = value;
//            _list.erase(iter);
//            _list.push_front(pair);
//            _map[key] = _list.begin(); // ���� map �еĵ�����
//            return;
//        }
//        // �����ڣ�ͷ��
//        _list.push_front({ key, value });
//        _map[key] = _list.begin(); // ��ӵ� map ��
//        _size += 1;
//        // �ж�����
//        if (_size > _capacity) {
//            // βɾ������ map ��ɾ��
//            auto last = _list.back();
//            _map.erase(last.first); // ɾ����Ӧ�� key
//            _list.pop_back();
//            _size -= 1;
//        }
//    }
//
//private:
//    int _size;
//    int _capacity;
//    unordered_map<int, list<pair<int, int>>::iterator> _map;
//    list<pair<int, int>> _list;
//};

//#include <iostream>
//#include <string>
//using namespace std;


//bool beEven(string& num) {
//    int index = -1;
//    for (int i = num.size() - 1; i >= 0; i--) {
//        if ((num[i] - '0' % 2) == 0) {
//            if (i == num.size()) {
//                return true;
//            }
//            index = i;
//        }
//    }
//    if (index == -1) {
//        return false;
//    }
//    else {
//        swap(num[index], num[num.size() - 1]);
//        return true;
//    }
//}
//
//int main() {
//    int n = 0;
//    cin >> n;
//
//    while (n--) {
//        string str;
//        cin >> str;
//
//        if (!beEven(str)) {
//            cout << -1 << endl;;
//        }
//        else {
//            cout << str << endl;
//        }
//    }
//}


#include <iostream>
using namespace std;

int n;
int ans = 0;
int arr[12];
bool visited[12] = { false };

void backtracking(int pos) {
    if (pos == n + 1) {
        ans += 1;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        // ����������
        if (visited[arr[i]]) {
            return;
        }

        visited[i] = true;
        backtracking(pos + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    backtracking(1);

    cout << ans;
}
// 64 λ������� printf("%lld")