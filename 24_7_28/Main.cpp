#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

#define NUM 256
#define SEP " "
char* UsrCommand[NUM];


void GetUsrCommand() {
	// ��ȡ�û�������ָ��
	string line;
	std::getline(cin, line);
	
	// ��ȡָ���ַ���, ȥ��ĩβ��\n
	char* str = new char[line.size() + 1];
	strcpy(str, line.c_str());
	// str[strlen(str) - 1] = '\0';
	
	// ��ȡ��ʽ
	int i = 0;
	UsrCommand[i++] = strtok(str, SEP);
	while ((UsrCommand[i++] = strtok(NULL, SEP)));

	delete[] str;
}


int main() {
	GetUsrCommand();
	for (int i = 0; UsrCommand[i]; i++) {
		cout << UsrCommand[i] << endl;
	}

	return 0;
}