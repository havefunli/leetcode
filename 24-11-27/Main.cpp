#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void Updata(int h, int len, map<int, int>& map)
    {
        len = min(len, h);
        for (int i = 1; i < len; i++)
        {
            map[i]++;
        }
    }

    int hIndex(const vector<int>& citations) {
        int len = citations.size();
        map<int, int> map;
        for (int i = 0; i < citations.size(); i++)
        {
            Updata(citations[i], len, map);
        }

        int MaxH = 0;
        for (auto& pair : map)
        {
            if (pair.second >= pair.first) {
                cout << pair.first << " " << pair.second << endl;
                MaxH = pair.first;
            }
        }

        return MaxH;
    }
};

int main()
{
    Solution s;
    s.hIndex({ 3,0,6,1,5 });
    return 0;
}