//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// 全局互斥量
//HANDLE mutex;
//
//// 线程执行函数
//unsigned int __stdcall Fun(void* param) {
//    int* pValue = static_cast<int*>(param); // 将 void* 转换为 int*
//
//    // 确保参数有效
//    if (pValue) {
//        // 等待互斥量，防止其他线程同时访问
//        WaitForSingleObject(mutex, INFINITE);
//        int value = *pValue; // 获取参数的值
//        ReleaseMutex(mutex); // 释放互斥量
//
//        Sleep(50); // 模拟线程调度切换
//
//        // 再次等待互斥量，递增变量并输出
//        WaitForSingleObject(mutex, INFINITE);
//        value++; // 递增变量值
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//        ReleaseMutex(mutex); // 释放互斥量
//    }
//
//    return 0; // 线程执行完成
//}
//
//int main() {
//    const int THREAD_COUNT = 10; // 线程数量
//    HANDLE threadHandles[THREAD_COUNT]; // 保存线程句柄
//    int indices[THREAD_COUNT]; // 用于存储传入线程的参数
//
//    // 创建互斥量
//    mutex = CreateMutex(nullptr, FALSE, nullptr);
//    if (mutex == nullptr) {
//        std::cerr << "Failed to create mutex" << std::endl;
//        return 1;
//    }
//
//    // 创建线程
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        indices[i] = i; // 将当前循环变量保存到数组中
//        threadHandles[i] = (HANDLE)_beginthreadex(
//            nullptr,            // 默认安全属性
//            0,                  // 默认堆栈大小
//            Fun,                // 线程执行函数
//            &indices[i],        // 传递当前变量的地址
//            0,                  // 默认创建标志
//            nullptr             // 不需要线程 ID
//        );
//
//        if (!threadHandles[i]) {
//            std::cerr << "Failed to create thread " << i << std::endl;
//        }
//    }
//
//    // 等待所有线程完成
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        WaitForSingleObject(threadHandles[i], INFINITE); // 等待线程结束
//        CloseHandle(threadHandles[i]); // 关闭线程句柄
//    }
//
//    // 关闭互斥量
//    CloseHandle(mutex);
//
//    std::cout << "All threads have completed." << std::endl;
//
//    return 0;
//}
