/*
石子游戏

题目描述
两人玩游戏，游戏内容为下：

有 n 个石头，两人每次可以从这 n 个石头中取 p^k 个（ p 是任意质数，k 是任意自然数，p^k 要求不大于当前剩余石头数），谁能取走最后石头，谁就获胜了。

问先手取石头的人，有没有必胜的策略。如果先手有，则输出 first，否则输出 second。

输入描述
输入第一行包含一个正整数 T，表示测试数量。

接下来后面 T 行，每行包含一个正整数 n，表示石头个数。

1≤T≤10^5,1≤n≤10^6。

输出描述
输出共 T 行，每行分别为 first 或 second。

输入输出样例
示例
输入
3
3
6
9

输出
first
second
first
*/
#include <iostream>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (n % 6 ? "first" : "second") << endl;
    }

    return 0;
}