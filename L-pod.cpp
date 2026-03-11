/*
点和线段关系

题目描述
平面直角坐标系中有一个点 C 和一条线段 AB ,求点 C 和线段 AB 的位置关系。

输入描述
第一行输入一个 T ,代表测试数据量

每组测试数据输入有三行，每行一个实数坐标 (x,y) 分别代表 A,B,C 三个点。

1≤T≤10^3,−10^5≤x,y≤10^5


输出描述
如果点 C 在线段 AB 上， 输出Yes ,否则输出No；

输入输出样例
示例 1
输入
2
0 1
1 0
1 1
0 0
2 2
1 1

输出
No
Yes
*/
#include <iostream>
using namespace std;
int main()
{
    int n, a[6];
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 6; i++)
            cin >> a[i];
        cout << (a[4] == (a[0] + a[2]) / 2 && a[5] == (a[1] + a[3]) / 2 ? "Yes" : "No") << endl;
    }

    return 0;

}

