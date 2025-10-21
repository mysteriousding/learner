/*
第1关：袋鼠过河问题

本关任务：编写一个袋鼠过河问题的小程序。

题目描述
一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩，每隔一米就有一个，每个桩上面有一个弹簧，袋鼠跳到弹簧上就可以跳得更远。
每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，就表示袋鼠下一跳最多能够跳5米；如果为0，就表示会陷进去无法继续跳跃。
河流一共n米宽，袋鼠初始在第一个弹簧上面，若跳到最后一个弹簧就算过河了。
给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。
如果无法到达，输出-1。

编程要求
根据提示，在右侧编辑器 Begin-End 补充代码，完成袋鼠过河问题。

测试说明
平台会对你编写的代码进行测试：

输入描述：输入分两行，第1行是数组长度n(1<=n<=10000)，第2行是每一项的值，用空格分隔。
输出描述：输出最少的跳数，若无法到达输出-1。

测试输入：

5
2 0 1 1 1
预期输出：
4

开始你的任务吧，祝你成功！
*/
#include <iostream>

/********* Begin *********/
#include <vector>
using namespace std;
int n;
vector<int>a;
vector <vector<int >> arr;
int dg(int x, int y)
{
    if (x >= n)return y;
    if (!a[x])
        return -1;
    int min = 1e5, f;
    for (int i = x + 1; i <= x + a[x]; i++)
    {
        f = dg(i, y + 1);
        if (f != -1 && f < min)
            min = f;
    }
    return min != 1e5 ? min : -1;
}
int main()
{
    cin >> n;
    a.resize(n);
    arr.resize(n + 1);
    arr[n].resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        arr[i].resize(n + 1);
    }
    int num = dg(0, 0);
    cout << num << endl;

    return 0;
}
/********* End *********/

/*
#include <iostream>

/********* Begin *********
#include <vector>
using namespace std;
int n;
vector<int>a;
vector<int>dp;

int main() {
    cin >> n;
    a.resize(n);
    dp.resize(n, 1e5);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        if (a[i])
            for (int j = i + 1; j <= i + a[i] && j < n; j++)
                if (dp[i] > dp[j] + 1)
                    dp[i] = dp[j] + 1;

    cout << (dp[0] == 1e5 ? -1 : dp[0]) << endl;
    return 0;
}
/********* End *********

*/



