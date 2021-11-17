// Heart.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#define PI 3.1415926535
#define MAX_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define MAX_HEIGHT GetSystemMetrics(SM_CXSCREEN)


void Draw(HDC hdc, int x, int y)
{
    double size = rand() % 5 + 1;
    int max = pow(size, 2) * 200;
    COLORREF color = RGB(rand() % 255, rand() % 255, rand() % 255);

    for (int i = 0; i < max; i++) {
        double t = ((double)i / max) * 2 * PI;
        SetPixel(hdc, x + 16 * size* (pow(sin(t), 3)), y - size*(13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)),color);
    }
    return;
}



int main()
{
    srand((unsigned)time(0));
    HWND hwnd;
    HDC hdc;
    hwnd = GetDesktopWindow();
    hdc = GetWindowDC(hwnd);
    for (int i = 0; i < 50; i++) {
        Draw(hdc, rand()%MAX_WIDTH,rand()%MAX_HEIGHT);
    }
    while (1);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
