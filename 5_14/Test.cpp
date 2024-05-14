#include <iostream>
using namespace std;

class A {
public:
	A(int a = 1) {
		_a = a;
	}

	~A() {
		cout << "~A()" << endl;
	}

private:
	int _a = 1;
};

// new A[]会多开四个字节来记录个数
// 便于在delete时删除指定的个数

// 编译器帮助你实例化你需要的函数或者类，本质是没变的
template<typename T>
void Swap(T& left, T& right) {
	T temp(left);
	left = right;
	right = left;
}

template<typename T1, typename T2>
auto Add(const T1& left, const T2& right) {
	return left + right;
}

int main(){
	//A* p1 = new A[10];
	//delete[] p1;

	//// 对已有空间显式调用构造函数
	//A* p2 = (A*)malloc(sizeof(A));
	//new(p2)A();
	//delete p2;

	int a = 1, b = 0;
	Swap(a, b);

	double c = 1.1, d = 1.2;
	Swap(c, d);

	// 显式实例化
	cout << Add(a, d) << endl;

	return 1;
}