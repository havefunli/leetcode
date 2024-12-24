//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// ȫ�ֻ�����
//HANDLE mutex;
//
//// �߳�ִ�к���
//unsigned int __stdcall Fun(void* param) {
//    int* pValue = static_cast<int*>(param); // �� void* ת��Ϊ int*
//
//    // ȷ��������Ч
//    if (pValue) {
//        // �ȴ�����������ֹ�����߳�ͬʱ����
//        WaitForSingleObject(mutex, INFINITE);
//        int value = *pValue; // ��ȡ������ֵ
//        ReleaseMutex(mutex); // �ͷŻ�����
//
//        Sleep(50); // ģ���̵߳����л�
//
//        // �ٴεȴ����������������������
//        WaitForSingleObject(mutex, INFINITE);
//        value++; // ��������ֵ
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//        ReleaseMutex(mutex); // �ͷŻ�����
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
//    // ����������
//    mutex = CreateMutex(nullptr, FALSE, nullptr);
//    if (mutex == nullptr) {
//        std::cerr << "Failed to create mutex" << std::endl;
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
//    // �رջ�����
//    CloseHandle(mutex);
//
//    std::cout << "All threads have completed." << std::endl;
//
//    return 0;
//}
