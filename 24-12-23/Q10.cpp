//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// 全局信号量对象
//HANDLE semaphore;
//
//// 线程执行函数
//unsigned int __stdcall Fun(void* param) {
//    int* pValue = static_cast<int*>(param); // 将 void* 转换为 int*
//
//    // 确保参数有效
//    if (pValue) {
//        // 等待信号量
//        WaitForSingleObject(semaphore, INFINITE); // 等待信号量释放
//
//        int value = *pValue; // 获取参数的值
//        value++; // 将值递增
//
//        // 输出当前线程的线程 ID 和变量的值
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//
//        // 模拟线程调度切换
//        Sleep(50);
//
//        // 释放信号量，允许其他线程运行
//        ReleaseSemaphore(semaphore, 1, nullptr);
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
//    // 创建信号量对象，初始计数为 1，最大计数为 1
//    semaphore = CreateSemaphore(
//        nullptr,  // 默认安全属性
//        1,        // 初始计数
//        1,        // 最大计数
//        nullptr   // 匿名信号量
//    );
//
//    if (semaphore == nullptr) {
//        std::cerr << "Failed to create semaphore" << std::endl;
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
//    // 关闭信号量对象
//    CloseHandle(semaphore);
//
//    std::cout << "All threads have completed." << std::endl;
//
//    return 0;
//}
