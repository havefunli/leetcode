#include <iostream>
#include <windows.h>
#include <queue>
#include <process.h> // For _beginthreadex

// 全局队列和同步对象
std::queue<int> buffer;          // 缓冲区（共享资源）
const int BUFFER_SIZE = 5;       // 缓冲区大小

HANDLE emptySlots;               // 信号量：表示空槽位
HANDLE fullSlots;                // 信号量：表示满槽位
HANDLE bufferMutex;              // 互斥量：保护缓冲区

// 生产者线程函数
unsigned int __stdcall producer(void* param) {
    int producerId = *static_cast<int*>(param);

    for (int i = 0; i < 10; ++i) { // 每个生产者生成10个数据
        Sleep(rand() % 100); // 模拟生产时间

        WaitForSingleObject(emptySlots, INFINITE); // 等待空槽位
        WaitForSingleObject(bufferMutex, INFINITE); // 加锁访问缓冲区

        // 生产数据并放入缓冲区
        int item = rand() % 100; // 生成随机数据
        buffer.push(item);
        std::cout << "Producer " << producerId << " produced: " << item << std::endl;

        ReleaseMutex(bufferMutex); // 释放缓冲区互斥量
        ReleaseSemaphore(fullSlots, 1, nullptr); // 增加满槽位计数
    }

    return 0;
}

// 消费者线程函数
unsigned int __stdcall consumer(void* param) {
    int consumerId = *static_cast<int*>(param);

    for (int i = 0; i < 10; ++i) { // 每个消费者消费10个数据
        Sleep(rand() % 150); // 模拟消费时间

        WaitForSingleObject(fullSlots, INFINITE); // 等待满槽位
        WaitForSingleObject(bufferMutex, INFINITE); // 加锁访问缓冲区

        // 消费数据并从缓冲区移除
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << consumerId << " consumed: " << item << std::endl;

        ReleaseMutex(bufferMutex); // 释放缓冲区互斥量
        ReleaseSemaphore(emptySlots, 1, nullptr); // 增加空槽位计数
    }

    return 0;
}

int main() {
    const int PRODUCER_COUNT = 2; // 生产者线程数量
    const int CONSUMER_COUNT = 2; // 消费者线程数量

    HANDLE producerThreads[PRODUCER_COUNT]; // 保存生产者线程句柄
    HANDLE consumerThreads[CONSUMER_COUNT]; // 保存消费者线程句柄
    int producerIds[PRODUCER_COUNT]; // 保存生产者线程ID
    int consumerIds[CONSUMER_COUNT]; // 保存消费者线程ID

    // 初始化信号量和互斥量
    emptySlots = CreateSemaphore(nullptr, BUFFER_SIZE, BUFFER_SIZE, nullptr); // 空槽位信号量
    fullSlots = CreateSemaphore(nullptr, 0, BUFFER_SIZE, nullptr);            // 满槽位信号量
    bufferMutex = CreateMutex(nullptr, FALSE, nullptr);                       // 互斥量保护缓冲区

    // 创建生产者线程
    for (int i = 0; i < PRODUCER_COUNT; ++i) {
        producerIds[i] = i + 1; // 设置生产者 ID
        producerThreads[i] = (HANDLE)_beginthreadex(
            nullptr, 0, producer, &producerIds[i], 0, nullptr);
    }

    // 创建消费者线程
    for (int i = 0; i < CONSUMER_COUNT; ++i) {
        consumerIds[i] = i + 1; // 设置消费者 ID
        consumerThreads[i] = (HANDLE)_beginthreadex(
            nullptr, 0, consumer, &consumerIds[i], 0, nullptr);
    }

    // 等待所有生产者线程完成
    WaitForMultipleObjects(PRODUCER_COUNT, producerThreads, TRUE, INFINITE);
    for (int i = 0; i < PRODUCER_COUNT; ++i) {
        CloseHandle(producerThreads[i]);
    }

    // 等待所有消费者线程完成
    WaitForMultipleObjects(CONSUMER_COUNT, consumerThreads, TRUE, INFINITE);
    for (int i = 0; i < CONSUMER_COUNT; ++i) {
        CloseHandle(consumerThreads[i]);
    }

    // 清理同步对象
    CloseHandle(emptySlots);
    CloseHandle(fullSlots);
    CloseHandle(bufferMutex);

    std::cout << "All producers and consumers have completed." << std::endl;
    return 0;
}
