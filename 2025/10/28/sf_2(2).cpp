/*
2、在一个2k x 2k个方格组成的棋盘中恰有一个方格与其他的不同称为特殊方格，要求利用图1中的四种L型骨牌（每个骨牌可覆盖三个方格）不相互重叠覆盖的将除了特殊方格外的其他方格覆盖。

图1 L型骨牌
给出使用分治法解决棋盘覆盖问题的思路，分析算法的时间复杂度，并用程序实现，给出结果，特殊方格自定。
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int>> N;
int n;

void coverBoard(int a, int b, int size, int x, int y)
{
    if (size == 1) return;
    int h = size / 2, u = a + h, v = b + h;
    if (x < u)
    {
        if (y < v)// 特殊方格在左上象限
        {
            N[u][v - 1] = N[u][v] = N[u - 1][v] = 4;
            coverBoard(a, b, h, x, y);        // 左上
            coverBoard(u, b, h, u, v - 1);    // 右上
            coverBoard(a, v, h, u - 1, v);    // 左下
            coverBoard(u, v, h, u, v);        // 右下
        } 
        else// 特殊方格在左下象限
        {
            N[u - 1][v - 1] = N[u][v - 1] = N[u][v] = 2;
            coverBoard(a, b, h, u - 1, v - 1);// 左上
            coverBoard(u, b, h, u, v - 1);    // 右上
            coverBoard(a, v, h, x, y);        // 左下
            coverBoard(u, v, h, u, v);        // 右下
        }
    }
    else
    {
        if (y < v) // 特殊方格在右上象限
        {
            N[u - 1][v - 1] = N[u - 1][v] = N[u][v] = 3;
            coverBoard(a, b, h, u - 1, v - 1);// 左上
            coverBoard(u, b, h, x, y);        // 右上
            coverBoard(a, v, h, u - 1, v);    // 左下
            coverBoard(u, v, h, u, v);        // 右下
        }
        else// 特殊方格在右下象限
        {
            N[u][v - 1] = N[u - 1][v - 1] = N[u - 1][v] = 1;
            coverBoard(a, b, h, u - 1, v - 1);// 左上
            coverBoard(u, b, h, u, v - 1);    // 右上
            coverBoard(a, v, h, u - 1, v);    // 左下
            coverBoard(u, v, h, x, y);        // 右下
        }
    }
}

int main() {
    int x, y;
    cout << "请输入 K 构建边长 2^K 的棋盘。" << endl;
    cin >> n;
    n = pow(2, n);
    cout << "请输入特殊方格坐标 x , y 。" << endl;
    cin >> x >> y;
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        N.resize(n, vector<int>(n, 0));
        coverBoard(0, 0, n, x, y);
        cout << "棋盘覆盖成功。" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << N[i][j] << " ";

            cout << endl;
        }
    }
    else cout << "特殊方格越界！" << endl;

    return 0;

}



