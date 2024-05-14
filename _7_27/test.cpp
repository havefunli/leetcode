#define  _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Test1() {
	int arr[5] = {1,2,3,4,5};
	vector<int> v(arr, arr + 5);

	find(v.begin(), v.end(), 5);
}

void Test2() {
    int arr[5] = { 3,2,2,3 };
	vector<int> nums;
    nums.push_back(1);
    int val = 1;

    int size = nums.size();
    int front = 0;
    int back = nums.size();

    while (front < back) {
        while (front < back && val != nums[front] ) {
            front++;
        }

        while (front < back && val == nums[back - 1]) {
            back--;
            size--;
        }

        if (front < back) {
            swap(nums[front], nums[back - 1]);
            front++;
            back--;
            size--;
        }

    }

   cout << size;
}

void Test3() {
    int n;
    int num = 1;
    cin >> n;
    vector<vector<int>> vv(n, vector<int>(n, 0));

    int startx = 0, starty = 0;
    int set = 1;
    int loop = n / 2;

    while (loop--) {
        int i = startx;
        int j = starty;

        for (j; j < starty + n - set; j++) {
            vv[i][j] = num++;
        }

        for (i; i < startx + n - set; i++) {
            vv[i][j] = num++;
        }

        for (j; j >starty; j--) {
            vv[i][j] = num++;
        }

        for (i; i > startx; i--) {
            vv[i][j] = num++;
        }

        startx++;
        starty++;
        set += 2;
    }

    if (n % 2) {
        vv[n / 2][n / 2] = num;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
	//Test1();
	//Test2();
    Test3();

	return -1;
}