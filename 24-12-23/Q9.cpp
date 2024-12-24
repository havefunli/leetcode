//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// 全局事件对象
//HANDLE eventHandle;
//
//// 线程执行函数
//unsigned int __stdcall Fun(void* param) {
//    int* pValue = static_cast<int*>(param); // 将 void* 转换为 int*
//
//    // 确保参数有效
//    if (pValue) {
//        // 等待事件触发
//        WaitForSingleObject(eventHandle, INFINITE); // 等待事件信号
//
//        int value = *pValue; // 获取参数的值
//        value++; // 将值递增
//
//        // 输出当前线程的线程 ID 和变量的值
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//
//        // 重置事件为无信号状态，准备下一次使用
//        ResetEvent(eventHandle);
//
//        // 模拟调度切换
//        Sleep(50);
//
//        // 设置事件为有信号状态，让其他线程运行
//        SetEvent(eventHandle);
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
//    // 创建事件对象，初始为无信号状态
//    eventHandle = CreateEvent(
//        nullptr,  // 默认安全属性
//        TRUE,     // 手动重置事件
//        FALSE,    // 初始无信号状态
//        nullptr   // 匿名事件
//    );
//
//    if (eventHandle == nullptr) {
//        std::cerr << "Failed to create event" << std::endl;
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
//    // 设置事件为有信号状态，让第一个线程运行
//    SetEvent(eventHandle);
//
//    // 等待所有线程完成
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        WaitForSingleObject(threadHandles[i], INFINITE); // 等待线程结束
//        CloseHandle(threadHandles[i]); // 关闭线程句柄
//    }
//
//    // 关闭事件对象
//    CloseHandle(eventHandle);
//
//    std::cout << "All threads have completed." << std::endl;
//
//    return 0;
//}
