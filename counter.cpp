#include <iostream>
#include <windows.h>
#include <atomic>

// 使用std::atomic确保计数器在线程间的操作是安全的
std::atomic<int> counter(0);

// 模拟中断的线程函数，每秒增加计数器
DWORD WINAPI IncrementCounter(LPVOID lpParam) {
    while (true) {
        Sleep(1000); // 暂停1秒
        counter.fetch_add(1); // 原子操作，计数器加1
    }
    return 0;
}

int main() {
    // 创建一个线程，用于每秒增加计数器
    HANDLE hThread = CreateThread(
        NULL,                   // 默认安全属性
        0,                      // 默认堆栈大小
        IncrementCounter,       // 线程函数
        NULL,                   // 线程参数
        0,                      // 默认创建标志
        NULL                    // 线程标识符
    );

    if (hThread == NULL) {
        std::cerr << "Failed to create thread." << std::endl;
        return 1;
    }

    // 主线程循环显示计数器的值
    std::cout << "Press Ctrl+C to exit." << std::endl;
    while (true) {
        std::cout << "\rCounter: " << counter.load(); // 显示计数器的值
        Sleep(100); // 减少CPU占用
    }

    // 等待线程结束（实际上，这里可能不会到达，因为程序通过Ctrl+C退出）
    WaitForSingleObject(hThread, INFINITE);

    CloseHandle(hThread); // 关闭线程句柄

    return 0;
}