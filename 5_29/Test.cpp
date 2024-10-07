#include <iostream>
#include <list>
using namespace std;

void test_1() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);

	auto it = lt.begin();
	auto it1 = ++lt.begin();
	lt.pop_front();
	cout << *it1 << endl;
}

int main() {
	test_1();
	return -1;
}