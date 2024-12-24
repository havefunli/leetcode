//#include <iostream>
//#include <windows.h>
//#include <process.h> // For _beginthreadex
//
//// 定义全局的临界区变量
//CRITICAL_SECTION criticalSection;
//
//// 线程执行函数
//unsigned int __stdcall ThreadFunction(void* param) {
//    int* pValue = static_cast<int*>(param); // 将 void* 转换为 int*
//    if (pValue) {
//        EnterCriticalSection(&criticalSection); // 进入临界区
//        int value = *pValue; // 获取变量的值
//        LeaveCriticalSection(&criticalSection); // 离开临界区
//
//        Sleep(50); // 模拟线程调度切换，休眠 50 毫秒
//
//        EnterCriticalSection(&criticalSection); // 再次进入临界区
//        value++; // 递增变量
//        std::cout << "Thread ID: " << GetCurrentThreadId() << ", Value: " << value << std::endl;
//        LeaveCriticalSection(&criticalSection); // 离开临界区
//    }
//    return 0; // 线程结束
//}
//
//// 主函数
//int main() {
//    const int THREAD_COUNT = 10; // 创建的线程数量
//    HANDLE threadHandles[THREAD_COUNT]; // 保存线程句柄
//    int indices[THREAD_COUNT]; // 存储传入线程的变量
//
//    // 初始化临界区
//    InitializeCriticalSection(&criticalSection);
//
//    // 创建线程
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        indices[i] = i; // 初始化当前循环变量
//        threadHandles[i] = (HANDLE)_beginthreadex(
//            nullptr,            // 默认安全属性
//            0,                  // 默认堆栈大小
//            ThreadFunction,     // 线程函数
//            &indices[i],        // 传入参数（循环变量的地址）
//            0,                  // 默认创建标志
//            nullptr             // 不需要线程 ID
//        );
//        if (!threadHandles[i]) {
//            std::cerr << "Failed to create thread " << i << std::endl;
//        }
//    }
//
//    // 等待所有线程结束
//    for (int i = 0; i < THREAD_COUNT; ++i) {
//        WaitForSingleObject(threadHandles[i], INFINITE); // 等待线程完成
//        CloseHandle(threadHandles[i]); // 关闭线程句柄
//    }
//
//    // 删除临界区
//    DeleteCriticalSection(&criticalSection);
//
//    std::cout << "All threads have completed." << std::endl;
//    return 0;
//}
