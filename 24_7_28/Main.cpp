#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

#define NUM 256
#define SEP " "
char* UsrCommand[NUM];


void GetUsrCommand() {
	// 获取用户的输入指令
	string line;
	std::getline(cin, line);
	
	// 获取指令字符串, 去除末尾的\n
	char* str = new char[line.size() + 1];
	strcpy(str, line.c_str());
	// str[strlen(str) - 1] = '\0';
	
	// 获取格式
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