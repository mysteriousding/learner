#include <windows.h>

int wmain(int argc, wchar_t** argv)
{
    // 查找窗口
    HWND hWnd = FindWindow(0, argv[0]);
    if (hWnd != NULL) {
        // 隐藏窗口
        ShowWindow(hWnd, SW_HIDE);
    }

    // 显示消息框
    int a = MessageBoxW(0, L"你喜欢我吗？", L"消息", MB_YESNO);
    if (a == IDNO) {
        do {
            a = MessageBoxW(0, L"你真的不喜欢我吗？", L"消息", MB_YESNO);
        } while (a == IDYES); // 循环直到用户选择“否”
    }

    // 最后的消息框
    MessageBoxW(0, L"我也喜欢你", L"消息", MB_OK);

    return 0;
}
