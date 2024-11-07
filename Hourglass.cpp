#include<iostream>
using namespace std;
int main()
{
    int n, m, i = 0;
    char c;
    cout << "输入在一行给出1个正整数 N 和一个符号，中间以空格分隔。\n我将首先打印出由给定符号组成的最大的沙漏形状，再在最后在一行中输出剩下没用掉的符号数。\n";
    cin >> n >> c;
    while (1)
    {
        if (n >= (2 * i * i) - 1 && n < (2 * (i + 1) * (i + 1)) - 1)
        {
            n -= 2 * i * i - 1;
            m = i;
            break;
        }
        i++;
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < j; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < (m - j) * 2 - 1; i++)
        {
            cout << c;
        }
        cout << endl;
    }
    for (int i = 2; i < m + 1; i++)
    {
        for (int j = 0; j < m - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++)
        {
            cout << c;
        }
        cout << endl;
    }
    cout << n << endl;

    return 0;
}