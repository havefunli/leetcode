#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Alice �� Bob �������԰��� n ��ֲ�ｽˮ��ֲ���ų�һ�У������ҽ��б�ǣ���Ŵ� 0 �� n - 1 �����У��� i ��ֲ���λ���� x = i ��
//
//ÿһ��ֲ�ﶼ��Ҫ���ض�����ˮ��Alice �� Bob ÿ����һ��ˮ�ޣ���������� �����ǰ����������ķ�ʽ��ɽ�ˮ��
//
//Alice �� ������ ��˳���ֲ�ｽˮ����ֲ�� 0 ��ʼ��Bob �� ���ҵ��� ��˳���ֲ�ｽˮ����ֲ�� n - 1 ��ʼ������ ͬʱ ��ֲ�ｽˮ��
//������Ҫ����ˮ��Ϊÿ��ֲ�ｽˮ�����ʱ�䶼����ͬ�ġ�
//��� Alice / Bob ˮ���е�ˮ���� ��ȫ ���ֲ����� ���� ��ֲ�ｽˮ���������� ���ȣ�����������װ�����ӣ�Ȼ���ֲ�ｽˮ��
//��� Alice �� Bob ����ͬһ��ֲ���ô��ǰˮ����ˮ ���� ���˻������ֲ�ｽˮ���������ˮ����ͬ����ô Alice �������ֲ�ｽˮ��
//����һ���±�� 0 ��ʼ���������� plants �������� n ��������ɡ����У�plants[i] Ϊ�� i ��ֲ����Ҫ��ˮ���������������� capacityA �� capacityB �ֱ��ʾ Alice �� Bob ˮ�޵��������������˽�������ֲ����������¹���ˮ�޵� ���� ��
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        // ��¼װˮ�Ĵ���
        int counts = 0;
        // ��¼Ŀǰˮ����ˮ�ĺ���
        int A_left = capacityA, B_left = capacityB;
        // �ֱ��һͷһβ��ʼ
        int A = 0, B = plants.size() - 1;

        while (A < B) {
            // ������ʱ
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