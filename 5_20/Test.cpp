#include <iostream>
#include <vector>
using namespace std;

void test_1() {

	vector<int>array;

	array.push_back(100);

	array.push_back(300);

	array.push_back(300);

	array.push_back(300);

	array.push_back(300);

	array.push_back(500);

	vector<int>::iterator itor;

	for (itor = array.begin(); itor != array.end(); itor++)

	{

		if (*itor == 300)

		{

			itor = array.erase(itor);

		}

	}

	for (itor = array.begin(); itor != array.end(); itor++)

	{

		cout << *itor << " ";

	}
}

void test_2() {
	vector<int> arr = { 1, 2, 3 };
	cout << arr[3] << endl;
	cout << arr.at(3) << endl;
}

void test_3() {
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sizeof(ar) / sizeof(int);

	vector<int> v(ar, ar + n);

	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(100);

	v.resize(20);

	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(50);

	v.resize(5);

	cout << v.size() << ":" << v.capacity() << endl;
}

//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//
//		int p1 = 0;
//		int p2 = 1;
//		while (p2 < nums.size()) {
//			while ((nums[p1] == nums[p2]) && (p2 < nums.size())) {
//				nums.erase(nums.begin() + p2);
//			}
//			p1 += 1;
//			p2 += 1;
//		}
//
//		return nums.size();
//	}
//};

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		for (int i = 0; i < numRows; i++) {
			ret[i].resize(i + 1);
			ret[i][0] = ret[i][i] = 1;
		}

		if (numRows > 2) {
			for (int i = 2, j = 1; (i < numRows) && (j < i); i++, j++) {
				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
			}
		}
		return ret;
	}
};

void test_4() {
	Solution s;
	s.generate(2);
}

int main(){
	// test_1();
	// test_2();
	// test_3();
	test_4();

	return -1;
}