#include <windows.h>
#include <stdio.h>

int main() {
    // 用来存储进程信息
    PROCESS_INFORMATION pi;
    // 用来描述进程的启动信息
    STARTUPINFO si = { sizeof(si) };

    // 创建计算器进程
    BOOL ret = CreateProcessA(
        NULL,             // 应用程序名称 (NULL 使用命令行参数来指定)
        "calc.exe",       // 要启动的程序
        NULL,             // 进程的安全属性
        NULL,             // 线程的安全属性
        FALSE,            // 是否继承句柄
        0,                // 创建标志
        NULL,             // 环境变量
        NULL,             // 当前工作目录
        &si,              // 启动信息
        &pi               // 进程信息
    );

    if (ret) {
        printf("计算器进程启动成功!\n");

        // 等待子进程结束
        WaitForSingleObject(pi.hProcess, INFINITE);

        // 获取子进程的退出码
        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);
        printf("计算器进程结束，退出码是 %ld\n", dwExitCode);

        // 关闭句柄
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
    else {
        printf("计算器进程启动失败!\n");
    }

    return 0;
}
