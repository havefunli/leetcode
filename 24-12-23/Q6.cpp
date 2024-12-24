//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// ����ȫ�ֵ��ٽ�������
//CRITICAL_SECTION criticalSection;
//
//// �߳�ִ�к���
//unsigned int __stdcall ThreadFunction(void* param) {
//    int* pValue = static_cast<int*>(param); // �� void* ת��Ϊ int*
//    if (pValue) {
//        EnterCriticalSection(&criticalSection); // �����ٽ���
//        int value = *pValue; // ��ȡ������ֵ
//        LeaveCriticalSection(&criticalSection); // �뿪�ٽ���
//
//        Sleep(50); // ģ���̵߳����л������� 50 ����
//
//        EnterCriticalSection(&criticalSection); // �ٴν����ٽ���
//        value++; // ��������
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//        LeaveCriticalSection(&criticalSection); // �뿪�ٽ���
//    }
//    return 0; // �߳̽���
//}
//
//// ������
//int main() {
//    const int THREAD_COUNT = 10; // �������߳�����
//    HANDLE threadHandles[THREAD_COUNT]; // �����߳̾��
//    int indices[THREAD_COUNT]; // �洢�����̵߳ı���
//
//    // ��ʼ���ٽ���
//    InitializeCriticalSection(&criticalSection);
//
//    // �����߳�
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        indices[i] = i; // ��ʼ����ǰѭ������
//        threadHandles[i] = (HANDLE)_beginthreadex(
//            nullptr,            // Ĭ�ϰ�ȫ����
//            0,                  // Ĭ�϶�ջ��С
//            ThreadFunction,     // �̺߳���
//            &indices[i],        // ���������ѭ�������ĵ�ַ��
//            0,                  // Ĭ�ϴ�����־
//            nullptr             // ����Ҫ�߳� ID
//        );
//        if (!threadHandles[i]) {
//            std::cerr << "Failed to create thread " << i << std::endl;
//        }
//    }
//
//    // �ȴ������߳̽���
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        WaitForSingleObject(threadHandles[i], INFINITE); // �ȴ��߳����
//        CloseHandle(threadHandles[i]); // �ر��߳̾��
//    }
//
//    // ɾ���ٽ���
//    DeleteCriticalSection(&criticalSection);
//
//    std::cout << "All threads have completed." << std::endl;
//    return 0;
//}
