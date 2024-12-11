#include <windows.h>
#include <stdio.h>

int main() {
    // �����洢������Ϣ
    PROCESS_INFORMATION pi;
    // �����������̵�������Ϣ
    STARTUPINFO si = { sizeof(si) };

    // ��������������
    BOOL ret = CreateProcessA(
        NULL,             // Ӧ�ó������� (NULL ʹ�������в�����ָ��)
        "calc.exe",       // Ҫ�����ĳ���
        NULL,             // ���̵İ�ȫ����
        NULL,             // �̵߳İ�ȫ����
        FALSE,            // �Ƿ�̳о��
        0,                // ������־
        NULL,             // ��������
        NULL,             // ��ǰ����Ŀ¼
        &si,              // ������Ϣ
        &pi               // ������Ϣ
    );

    if (ret) {
        printf("���������������ɹ�!\n");

        // �ȴ��ӽ��̽���
        WaitForSingleObject(pi.hProcess, INFINITE);

        // ��ȡ�ӽ��̵��˳���
        DWORD dwExitCode;
        GetExitCodeProcess(pi.hProcess, &dwExitCode);
        printf("���������̽������˳����� %ld\n", dwExitCode);

        // �رվ��
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
    else {
        printf("��������������ʧ��!\n");
    }

    return 0;
}
