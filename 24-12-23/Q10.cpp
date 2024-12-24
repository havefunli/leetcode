//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// ȫ���ź�������
//HANDLE semaphore;
//
//// �߳�ִ�к���
//unsigned int __stdcall Fun(void* param) {
//    int* pValue = static_cast<int*>(param); // �� void* ת��Ϊ int*
//
//    // ȷ��������Ч
//    if (pValue) {
//        // �ȴ��ź���
//        WaitForSingleObject(semaphore, INFINITE); // �ȴ��ź����ͷ�
//
//        int value = *pValue; // ��ȡ������ֵ
//        value++; // ��ֵ����
//
//        // �����ǰ�̵߳��߳� ID �ͱ�����ֵ
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//
//        // ģ���̵߳����л�
//        Sleep(50);
//
//        // �ͷ��ź��������������߳�����
//        ReleaseSemaphore(semaphore, 1, nullptr);
//    }
//
//    return 0; // �߳�ִ�����
//}
//
//int main() {
//    const int THREAD_COUNT = 10; // �߳�����
//    HANDLE threadHandles[THREAD_COUNT]; // �����߳̾��
//    int indices[THREAD_COUNT]; // ���ڴ洢�����̵߳Ĳ���
//
//    // �����ź������󣬳�ʼ����Ϊ 1��������Ϊ 1
//    semaphore = CreateSemaphore(
//        nullptr,  // Ĭ�ϰ�ȫ����
//        1,        // ��ʼ����
//        1,        // ������
//        nullptr   // �����ź���
//    );
//
//    if (semaphore == nullptr) {
//        std::cerr << "Failed to create semaphore" << std::endl;
//        return 1;
//    }
//
//    // �����߳�
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        indices[i] = i; // ����ǰѭ���������浽������
//        threadHandles[i] = (HANDLE)_beginthreadex(
//            nullptr,            // Ĭ�ϰ�ȫ����
//            0,                  // Ĭ�϶�ջ��С
//            Fun,                // �߳�ִ�к���
//            &indices[i],        // ���ݵ�ǰ�����ĵ�ַ
//            0,                  // Ĭ�ϴ�����־
//            nullptr             // ����Ҫ�߳� ID
//        );
//
//        if (!threadHandles[i]) {
//            std::cerr << "Failed to create thread " << i << std::endl;
//        }
//    }
//
//    // �ȴ������߳����
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        WaitForSingleObject(threadHandles[i], INFINITE); // �ȴ��߳̽���
//        CloseHandle(threadHandles[i]); // �ر��߳̾��
//    }
//
//    // �ر��ź�������
//    CloseHandle(semaphore);
//
//    std::cout << "All threads have completed." << std::endl;
//
//    return 0;
//}
