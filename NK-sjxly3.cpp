/*K
题目描述

汽车导航系统引导驾驶员沿着地图上规划的路线行驶。我们使用平面的标准方向，其中正 x 轴指向东，正 y 轴指向北。

路线是一个包含 n 个路点 P1, P2, …, Pn 的序列，每个路点都有整数坐标。汽车沿直线段行驶，始终向前移动：首先从 P1 到 P2，然后从 P2 到 P3，依此类推，直到到达 Pn。

每次汽车经过中间路点 Pi（2 ≤ i ≤ n−1）时，系统会播报驾驶员在该处的转向情况。它会比较汽车到达时的方向（从 Pi−1 到 Pi）与离开时的方向（从 Pi 到 Pi+1）：

如果离开方向是通过将到达方向逆时针旋转一个严格介于 0° 和 180° 之间的角度得到的，则驾驶员向左转弯，系统播报 LEFT；

如果离开方向是通过将到达方向顺时针旋转一个严格介于 0° 和 180° 之间的角度得到的，则驾驶员向右转弯，系统播报 RIGHT；

如果方向完全没有改变，则汽车继续直行，系统播报 STRAIGHT。

保证汽车永远不会掉头，因此离开方向永远不会与到达方向完全相反。因此，在每个中间路点处，三种播报中恰好有一种适用。

给定路线，按顺序输出每个中间路点的播报。

输入描述

每个测试文件包含多个测试用例。第一行包含测试用例数 T（1 ≤ T ≤ 500）。接下来是每个测试用例的描述。

每个测试用例的第一行包含一个整数 n（3 ≤ n ≤ 10^5），表示路线上路点的数量。

接下来的 n 行，每行包含两个整数 xi 和 yi（−10^9 ≤ xi, yi ≤ 10^9），表示第 i 个路点 Pi 的坐标，按汽车访问的顺序列出。
保证每两个连续的路点都是不同的（对于所有 1 ≤ i ≤ n−1，Pi ≠ Pi+1），并且汽车永远不会掉头（对于所有 2 ≤ i ≤ n−1，从 Pi 到 Pi+1 的方向不会与从 Pi−1 到 Pi 的方向完全相反）。

对于每个测试文件，保证所有测试用例的 n 之和不超过 2·10^5。

输出描述

对于每个测试用例，输出中间路点 P2, P3, …, Pn−1 的播报。每个播报是字符串 LEFT、RIGHT 或 STRAIGHT 之一。

示例1
输入
text
2
4
0 0
1 0
1 1
0 1
4
0 0
2 0
4 0
4 -2

输出
text
LEFT LEFT
STRAIGHT RIGHT

备注
在第一个测试用例中，汽车从原点开始逆时针绕单位正方形行驶。
在 P2 = (1,0) 处，它原本向东行驶，然后转向向北，这是左转；
在 P3 = (1,1) 处，它原本向北行驶，然后转向向西，这又是左转。
所以答案是 LEFT LEFT。

在第二个测试用例中，汽车首先从 (0,0) 向东行驶到 (2,0)，然后继续向东行驶到 (4,0)，因此在 P2 = (2,0) 处它保持直行。
在 P3 = (4,0) 处，它原本向东行驶，然后转向向南，这是右转。
所以答案是 STRAIGHT RIGHT。

#include<iostream>
using namespace std;
int main()
{
    long long t,n,h,a[3][2];
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
        for(int i=2;i<n;i++)
        {
            cin>>a[i%3][0]>>a[i%3][1];
            h=(a[(i-1)%3][0]-a[(i-2)%3][0])*(a[i%3][1]-a[(i-2)%3][1])-(a[(i-1)%3][1]-a[(i-2)%3][1])*(a[i%3][0]-a[(i-2)%3][0]);
            if(h==0)
                cout<<"STRAIGHT"<<' ';
            else if(h<0)
                cout<<"RIGHT"<<' ';
            else
                cout<<"LEFT"<<' ';
        }
        cout<<endl;
    }

    return 0;
}
*/

/*G
题目描述

给定一个 n×m 的数字网格，每个格子包含一个正整数。

如果存在两个格子 (r1, c1) 和 (r2, c2)，满足 r1 < r2 且 c1 < c2，并且这两个格子中的数字相等，那么所有满足 r1 ≤ r ≤ r2 且 c1 ≤ c ≤ c2 的格子 (r, c) 都会被标记。

输出整个网格的最终标记状态。

输入描述

每个测试文件只有一个测试用例。

第一行包含两个整数 n, m（1 ≤ n, m，且 n×m ≤ 1,000,000）。

接下来 n 行，每行包含 m 个整数；第 i 行包含 ai,1, ai,2, …, ai,m（1 ≤ ai,j ≤ n×m），描述数字网格。

输出描述

输出 n 行，每行一个长度为 m 的字符串，由字符 0 和 1 组成。

第 i 行第 j 个字符为 1 表示格子 (i, j) 最终被标记，否则为 0。

示例1

输入

text
2 6
1 2 3 4 5 6
7 8 9 3 4 10
输出

text
001110
001110
备注

在样例中，第 1 行第 3 列的格子和第 2 行第 4 列的格子都包含数字 3，因此它们标记了两行中第 3 列到第 4 列的区域。
第 1 行第 4 列的格子和第 2 行第 5 列的格子都包含数字 4，因此它们标记了两行中第 4 列到第 5 列的区域。
两个矩形的并集即为最终答案。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    int n[2], m[2], val, c1, c2;
    bool v = 0;
    cin >> n[0] >> m[0];
    if (n[0] > m[0])
        v = 1, n[1] = m[0], m[1] = n[0];

    vector<vector<int>> grid(n[v], vector<int>(m[v]));
    vector<unordered_map<int, int>> min_col(n[v]), max_col(n[v]);
    vector<vector<int>> diff(n[v] + 1, vector<int>(m[v] + 1, 0));
    for (int i[2] = { 0 }; i[0] < n[0]; i[0]++)
        for (i[1] = 0; i[1] < m[0]; i[1]++)
            cin >> grid[i[v]][i[!v]];

    for (int i = 0; i < n[v]; i++)
    {
        min_col[i].reserve(m[v]);
        max_col[i].reserve(m[v]);
        for (int j = 0; j < m[v]; j++)
        {
            val = grid[i][j];
            if (min_col[i].find(val) == min_col[i].end())
            {
                min_col[i][val] = j;
                max_col[i][val] = j;
            }
            else
            {
                if (j < min_col[i][val]) min_col[i][val] = j;
                if (j > max_col[i][val]) max_col[i][val] = j;
            }
        }
    }

    for (int r1 = 0; r1 < n[v]; r1++)
        for (int r2 = r1 + 1; r2 < n[v]; r2++)
            for (auto& p : min_col[r1])
            {
                val = p.first;
                c1 = p.second;
                auto it = min_col[r2].find(val);
                if (it != min_col[r2].end())
                {
                    c2 = max_col[r2][val];
                    if (c1 < c2)
                    {
                        diff[r1][c1] += 1;
                        diff[r2 + 1][c1] -= 1;
                        diff[r1][c2 + 1] -= 1;
                        diff[r2 + 1][c2 + 1] += 1;
                    }
                }
            }

    for (int i = 0; i <= n[v]; i++)
        for (int j = 1; j <= m[v]; j++)
            diff[i][j] += diff[i][j - 1];

    for (int j = 0; j <= m[v]; j++)
        for (int i = 1; i <= n[v]; i++)
            diff[i][j] += diff[i - 1][j];

    for (int i[2] = { 0 }; i[0] < n[0]; i[0]++)
    {
        for (i[1] = 0; i[1] < m[0]; i[1]++)
            cout << (diff[i[v]][i[!v]] > 0 ? '1' : '0');
        cout << endl;
    }

    return 0;
}