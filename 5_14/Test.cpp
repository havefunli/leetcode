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

// new A[]��࿪�ĸ��ֽ�����¼����
// ������deleteʱɾ��ָ���ĸ���

// ������������ʵ��������Ҫ�ĺ��������࣬������û���
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

	//// �����пռ���ʽ���ù��캯��
	//A* p2 = (A*)malloc(sizeof(A));
	//new(p2)A();
	//delete p2;

	int a = 1, b = 0;
	Swap(a, b);

	double c = 1.1, d = 1.2;
	Swap(c, d);

	// ��ʽʵ����
	cout << Add(a, d) << endl;

	return 1;
}