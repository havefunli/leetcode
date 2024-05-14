#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Alice 和 Bob 打算给花园里的 n 株植物浇水。植物排成一行，从左到右进行标记，编号从 0 到 n - 1 。其中，第 i 株植物的位置是 x = i 。
//
//每一株植物都需要浇特定量的水。Alice 和 Bob 每人有一个水罐，最初是满的 。他们按下面描述的方式完成浇水：
//
//Alice 按 从左到右 的顺序给植物浇水，从植物 0 开始。Bob 按 从右到左 的顺序给植物浇水，从植物 n - 1 开始。他们 同时 给植物浇水。
//无论需要多少水，为每株植物浇水所需的时间都是相同的。
//如果 Alice / Bob 水罐中的水足以 完全 灌溉植物，他们 必须 给植物浇水。否则，他们 首先（立即）重新装满罐子，然后给植物浇水。
//如果 Alice 和 Bob 到达同一株植物，那么当前水罐中水 更多 的人会给这株植物浇水。如果他俩水量相同，那么 Alice 会给这株植物浇水。
//给你一个下标从 0 开始的整数数组 plants ，数组由 n 个整数组成。其中，plants[i] 为第 i 株植物需要的水量。另有两个整数 capacityA 和 capacityB 分别表示 Alice 和 Bob 水罐的容量。返回两人浇灌所有植物过程中重新灌满水罐的 次数 。
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        // 记录装水的次数
        int counts = 0;
        // 记录目前水罐中水的含量
        int A_left = capacityA, B_left = capacityB;
        // 分别从一头一尾开始
        int A = 0, B = plants.size() - 1;

        while (A < B) {
            // 当相遇时
            if (A == B) {
                int Max = max(A_left, B_left);
                if (Max < plants[A]) {
                    counts += 1;
                }
                break;
            }

            if (A_left >= plants[A]) {
                A_left -= plants[A];
            }
            else if (A_left < plants[A]) {
                A_left = capacityA - plants[A];
                counts += 1;
            }

            if (B_left >= plants[B]) {
                B_left -= plants[B];
            }
            else if (B_left < plants[B]) {
                B_left = capacityB - plants[B];
                counts += 1;
            }

            A++;
            B--;
        }

        return counts;
    }
};


class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int counts = 1;
        int back = 0;
        int front = 1;

        while (front < nums.size()) {
            if (nums[front] == nums[back]) {
                counts += 1;
                if (counts < 3) {
                    front += 1;
                }
                else {
                    nums.erase(nums.begin() + front);
                    counts -= 1;
                }
            }
            else if (nums[front] != nums[back]) {
                back = front;
                front += 1;
                counts = 1;
            }
        }

        return nums.size();
    }
};


void ques_1() {
    vector<int> v = { 2, 1, 1 };
    int capacityA = 2, capacityB = 2;

    Solution s1;
    cout << s1.minimumRefill(v, capacityA, capacityB) << endl;
}

void ques_2() {
    vector<int> v = { 1, 1, 1, 2, 2, 3 };

    Solution1 s;
    s.removeDuplicates(v);
}

int main() {
    // ques_1();  
    ques_2();
}