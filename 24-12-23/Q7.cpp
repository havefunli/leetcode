//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//#include <vector>
//
//// �̺߳������������ͱ����ĵ�ַ��Ϊ����
//unsigned int __stdcall ThreadFunction(void* param) {
//    int* pValue = static_cast<int*>(param); // �� void* תΪ int*
//    if (pValue) {
//        int value = *pValue; // ȡ�ñ�����ֵ
//        Sleep(50); // ���� 50 ����
//        value++; // ������ֵ����
//        // ����߳� ID �ͱ���ֵ
//        std::cout << "�߳�ID: " << GetCurrentThreadId() << ", ֵ: " << value << std::endl;
//    }
//    return 0; // �߳̽���
//}
//
//int main() {
//    const int THREAD_COUNT = 10; // �������߳�����
//    std::vector<HANDLE> threadHandles; // �����߳̾��
//    int indices[THREAD_COUNT]; // ���ڴ����̵߳ı���
//
//    // ���� 10 ���߳�
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        indices[i] = i; // ��ʼ����ǰѭ������
//        HANDLE threadHandle = (HANDLE)_beginthreadex(
//            nullptr,            // Ĭ�ϰ�ȫ����
//            0,                  // Ĭ�϶�ջ��С
//            ThreadFunction,     // �̺߳���
//            &indices[i],        // ���������ѭ�������ĵ�ַ��
//            0,                  // Ĭ�ϴ�����־
//            nullptr             // ����Ҫ�߳� ID
//        );
//        if (threadHandle) {
//            threadHandles.push_back(threadHandle); // �����߳̾��
//        }
//        else {
//            std::cerr << "Failed to create thread \n" << i << std::endl;
//        }
//    }
//
//    // �ȴ������߳̽���
//    for (HANDLE handle : threadHandles) {
//        WaitForSingleObject(handle, INFINITE); // �ȴ��߳����
//        CloseHandle(handle); // �ر��߳̾��
//    }
//
//    std::cout << "All threads have completed." << std::endl;
//    return 0;
//}
