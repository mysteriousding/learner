﻿/*
大臣的旅费

题目描述
很久以前，T 王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。

为节省经费，T 国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。
同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。

J 是 T 国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了 J 最常做的事情。
他有一个钱袋，用于存放往来城市间的路费。

聪明的 J 发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第 x 千米到第 x +1 千米这一千米中（ x 是整数），他花费的路费是 x +10 这么多。
也就是说走 1 千米花费 11，走 2 千米要花费 23。

J 大臣想知道：
他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？

输入描述
输入的第一行包含一个整数 n，表示包括首都在内的 T 王国的城市数。

城市从 1 开始依次编号，1 号城市为首都。

接下来 n -1 行，描述 T 国的高速路（ T 国的高速路一定是 n -1 条）。

每行三个整数 Pi,Qi,Di ，表示城市 Pi 和城市 Qi 之间有一条高速路，长度为 Di 千米。

输出描述:
输出一个整数，表示大臣 J 最多花费的路费是多少。

输入输出样例
示例

输入
5
1 2 2
1 3 1
2 4 5
2 5 4

输出
135

样例说明
大臣 J 从城市 4 到城市 5 要花费 135 的路费。
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, a, b, c, max = 0;
    cin >> n;
    vector<vector<int>>N(n, vector<int>(n, 100000));
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        N[a][b] = N[--b][--a] = c;
    }
    for (int t = 1; t < n; t++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (k != i && k != j)
                        if (N[i][j] > N[i][k] + N[k][j])
                            N[i][j] = N[j][i] = N[i][k] + N[k][j];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (max < N[i][j] && N[i][j] != 100000)
                max = N[i][j];
    max = max * (max + 21) / 2;
    cout << max << endl;

    return 0;
}