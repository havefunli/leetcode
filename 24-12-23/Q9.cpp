//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// ȫ���¼�����
//HANDLE eventHandle;
//
//// �߳�ִ�к���
//unsigned int __stdcall Fun(void* param) {
//    int* pValue = static_cast<int*>(param); // �� void* ת��Ϊ int*
//
//    // ȷ��������Ч
//    if (pValue) {
//        // �ȴ��¼�����
//        WaitForSingleObject(eventHandle, INFINITE); // �ȴ��¼��ź�
//
//        int value = *pValue; // ��ȡ������ֵ
//        value++; // ��ֵ����
//
//        // �����ǰ�̵߳��߳� ID �ͱ�����ֵ
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//
//        // �����¼�Ϊ���ź�״̬��׼����һ��ʹ��
//        ResetEvent(eventHandle);
//
//        // ģ������л�
//        Sleep(50);
//
//        // �����¼�Ϊ���ź�״̬���������߳�����
//        SetEvent(eventHandle);
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
//    // �����¼����󣬳�ʼΪ���ź�״̬
//    eventHandle = CreateEvent(
//        nullptr,  // Ĭ�ϰ�ȫ����
//        TRUE,     // �ֶ������¼�
//        FALSE,    // ��ʼ���ź�״̬
//        nullptr   // �����¼�
//    );
//
//    if (eventHandle == nullptr) {
//        std::cerr << "Failed to create event" << std::endl;
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
//    // �����¼�Ϊ���ź�״̬���õ�һ���߳�����
//    SetEvent(eventHandle);
//
//    // �ȴ������߳����
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        WaitForSingleObject(threadHandles[i], INFINITE); // �ȴ��߳̽���
//        CloseHandle(threadHandles[i]); // �ر��߳̾��
//    }
//
//    // �ر��¼�����
//    CloseHandle(eventHandle);
//
//    std::cout << "All threads have completed." << std::endl;
//
//    return 0;
//}
