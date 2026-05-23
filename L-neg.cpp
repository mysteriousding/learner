/*
谈判

题目描述
在很久很久以前，有 n 个部落居住在平原上，依次编号为 1 到 n。
第 i 个部落的人数为 ti。

有一年发生了灾荒。年轻的政治家小蓝想要说服所有部落一同应对灾荒，他能通过谈判来说服部落进行联合。

每次谈判，小蓝只能邀请两个部落参加，花费的金币数量为两个部落的人数之和，谈判的效果是两个部落联合成一个部落（人数为原来两个部落的人数之和）。

输入描述
输入的第一行包含一个整数 n，表示部落的数量。

第二行包含 n 个正整数，依次表示每个部落的人数。

其中，1≤n≤1000，1≤ti≤10^4。

输出描述
输出一个整数，表示最小花费。

输入输出样例
示例 1
输入
4
9 1 3 5

输出
31
*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m, z = 0;
    priority_queue<int>q;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m, q.push(m);
    while (1)
    {
        m = q.top();
        q.pop();
        m += q.top();
        q.pop();
        if (q.empty())
            break;
        else z += m;
        q.push(m);
    }
    cout << (z ? z : m) << endl;

    return 0;
}
