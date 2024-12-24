//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//#include <vector>
//
//// 线程函数，接受整型变量的地址作为参数
//unsigned int __stdcall ThreadFunction(void* param) {
//    int* pValue = static_cast<int*>(param); // 将 void* 转为 int*
//    if (pValue) {
//        int value = *pValue; // 取得变量的值
//        Sleep(50); // 休眠 50 毫秒
//        value++; // 将变量值递增
//        // 输出线程 ID 和变量值
//        std::cout << "线程ID: " << GetCurrentThreadId() << ", 值: " << value << std::endl;
//    }
//    return 0; // 线程结束
//}
//
//int main() {
//    const int THREAD_COUNT = 10; // 创建的线程数量
//    std::vector<HANDLE> threadHandles; // 保存线程句柄
//    int indices[THREAD_COUNT]; // 用于传入线程的变量
//
//    // 创建 10 个线程
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        indices[i] = i; // 初始化当前循环变量
//        HANDLE threadHandle = (HANDLE)_beginthreadex(
//            nullptr,            // 默认安全属性
//            0,                  // 默认堆栈大小
//            ThreadFunction,     // 线程函数
//            &indices[i],        // 传入参数（循环变量的地址）
//            0,                  // 默认创建标志
//            nullptr             // 不需要线程 ID
//        );
//        if (threadHandle) {
//            threadHandles.push_back(threadHandle); // 保存线程句柄
//        }
//        else {
//            std::cerr << "Failed to create thread \n" << i << std::endl;
//        }
//    }
//
//    // 等待所有线程结束
//    for (HANDLE handle : threadHandles) {
//        WaitForSingleObject(handle, INFINITE); // 等待线程完成
//        CloseHandle(handle); // 关闭线程句柄
//    }
//
//    std::cout << "All threads have completed." << std::endl;
//    return 0;
//}
