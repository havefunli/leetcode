#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void minus_one(int start, vector<int>& battery) {
        int end = battery.size();
        while (start < end) {
            battery[start] = max(battery[start] - 1, 0);
            start += 1;
        }
    }

    int countTestedDevices(vector<int>& batteryPercentages) {
        int counts = 0;
        int start = 0;
        int end = batteryPercentages.size();

        while (start < end) {
            if (batteryPercentages[start] >= 1) {
                minus_one(start, batteryPercentages);
                counts += 1;
            }

            start += 1;
        }

        return counts;
    }
};

int main(){}