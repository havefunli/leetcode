#include <iostream>
#include <windows.h>
#include <queue>
#include <process.h> // For _beginthreadex

// ȫ�ֶ��к�ͬ������
std::queue<int> buffer;          // ��������������Դ��
const int BUFFER_SIZE = 5;       // ��������С

HANDLE emptySlots;               // �ź�������ʾ�ղ�λ
HANDLE fullSlots;                // �ź�������ʾ����λ
HANDLE bufferMutex;              // ������������������

// �������̺߳���
unsigned int __stdcall producer(void* param) {
    int producerId = *static_cast<int*>(param);

    for (int i = 0; i < 10; ++i) { // ÿ������������10������
        Sleep(rand() % 100); // ģ������ʱ��

        WaitForSingleObject(emptySlots, INFINITE); // �ȴ��ղ�λ
        WaitForSingleObject(bufferMutex, INFINITE); // �������ʻ�����

        // �������ݲ����뻺����
        int item = rand() % 100; // �����������
        buffer.push(item);
        std::cout << "Producer " << producerId << " produced: " << item << std::endl;

        ReleaseMutex(bufferMutex); // �ͷŻ�����������
        ReleaseSemaphore(fullSlots, 1, nullptr); // ��������λ����
    }

    return 0;
}

// �������̺߳���
unsigned int __stdcall consumer(void* param) {
    int consumerId = *static_cast<int*>(param);

    for (int i = 0; i < 10; ++i) { // ÿ������������10������
        Sleep(rand() % 150); // ģ������ʱ��

        WaitForSingleObject(fullSlots, INFINITE); // �ȴ�����λ
        WaitForSingleObject(bufferMutex, INFINITE); // �������ʻ�����

        // �������ݲ��ӻ������Ƴ�
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << consumerId << " consumed: " << item << std::endl;

        ReleaseMutex(bufferMutex); // �ͷŻ�����������
        ReleaseSemaphore(emptySlots, 1, nullptr); // ���ӿղ�λ����
    }

    return 0;
}

int main() {
    const int PRODUCER_COUNT = 2; // �������߳�����
    const int CONSUMER_COUNT = 2; // �������߳�����

    HANDLE producerThreads[PRODUCER_COUNT]; // �����������߳̾��
    HANDLE consumerThreads[CONSUMER_COUNT]; // �����������߳̾��
    int producerIds[PRODUCER_COUNT]; // �����������߳�ID
    int consumerIds[CONSUMER_COUNT]; // �����������߳�ID

    // ��ʼ���ź����ͻ�����
    emptySlots = CreateSemaphore(nullptr, BUFFER_SIZE, BUFFER_SIZE, nullptr); // �ղ�λ�ź���
    fullSlots = CreateSemaphore(nullptr, 0, BUFFER_SIZE, nullptr);            // ����λ�ź���
    bufferMutex = CreateMutex(nullptr, FALSE, nullptr);                       // ����������������

    // �����������߳�
    for (int i = 0; i < PRODUCER_COUNT; ++i) {
        producerIds[i] = i + 1; // ���������� ID
        producerThreads[i] = (HANDLE)_beginthreadex(
            nullptr, 0, producer, &producerIds[i], 0, nullptr);
    }

    // �����������߳�
    for (int i = 0; i < CONSUMER_COUNT; ++i) {
        consumerIds[i] = i + 1; // ���������� ID
        consumerThreads[i] = (HANDLE)_beginthreadex(
            nullptr, 0, consumer, &consumerIds[i], 0, nullptr);
    }

    // �ȴ������������߳����
    WaitForMultipleObjects(PRODUCER_COUNT, producerThreads, TRUE, INFINITE);
    for (int i = 0; i < PRODUCER_COUNT; ++i) {
        CloseHandle(producerThreads[i]);
    }

    // �ȴ������������߳����
    WaitForMultipleObjects(CONSUMER_COUNT, consumerThreads, TRUE, INFINITE);
    for (int i = 0; i < CONSUMER_COUNT; ++i) {
        CloseHandle(consumerThreads[i]);
    }

    // ����ͬ������
    CloseHandle(emptySlots);
    CloseHandle(fullSlots);
    CloseHandle(bufferMutex);

    std::cout << "All producers and consumers have completed." << std::endl;
    return 0;
}
