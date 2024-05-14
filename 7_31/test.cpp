#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1() {
	int M;
	cin >> M;

	int i = 1;
	int k = i;
	int sum = 0;
	while (i <= M / 2) {
		if (sum < M) {
			sum += k;
			k++;
		}
		else if (sum > M) {
			sum -= i;
			i++;
		}
		else {
			cout << i << " " << k - 1 << endl;
			/*i++;*/
			sum += k;
			k++;
			//k = i;
			//sum = 0;
		}
	}
}

bool test2() {
	string s("anagram");
	string t("nagaram");
	int hash[26] = { 0 };

	for (int i = 0; i < s.size(); i++) {
		hash[s[i] - 'a']++;
	}
	for (int j = 0; j < t.size(); j++) {
		hash[t[j] - 'a']--;
	}
	for (int k = 0; k < 26; k++) {
		if (hash[k] != 0)
			return false;
	}

	return true;
}

void test3(){
	vector<int> ret;
	vector<int> nums1(10, 1);
	vector<int> nums2(10, 1);

	int index = 0;

	for (int i = 0; i < nums1.size(); i++) {
		for (int j = 0; j < nums2.size(); j++) {
			if (nums1[i] == nums2[j])
			ret.push_back(nums1[i]);
			break;
		}
	}
	sort(ret.begin(), ret.end());
	
	vector<int>::iterator fast = ret.begin();
	vector<int>::iterator slow = ret.begin();

	while (fast != ret.end()) {
		if (*fast != *slow) {

		}
	}

}

int main() {
	//test1();
	//cout << (test2() ? "true" : "false");
	test3();

	return 0;
}