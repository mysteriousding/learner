/*
求解 01 背包问题

题目描述
实现一个算法求解 01 背包问题。背包问题的介绍如下：

已知一个容量为 totalweight 的背包，有不同重量不同价值的物品，问怎样在背包容量限制下达到利益最大化。
01 背包问题要求每个物品只有一个，可以选择放入或者不放入背包。
背包问题求解方法的介绍如下：

用符号 Vi 表示第 i 个物品的价值，Wi 表示第 i 个物品的体积，Vi,j 表示当前背包容量为 j 时，前 i 个物品最佳组合对应的价值。

对于当前第 i 个商品，如果包的容量比该物品体积小，即 j<Wi 。
那么此时的价值与前 i−1 个的价值是一样的，即 Vi,j = Vi−1,j 。

对于当前第 i 个商品，如果包的容量能够装下该物品，即 Wi ≤j 。
此时需要判断装或者不装这个物品的价值对比，选择使价值更大的情况，即 Vi,j=max(Vi+Vi−1,j−Wi，Vi−1,j)。

通过最优解回溯法找到解的组成：

当 Vi,j = Vi−1,j 时，说明没有选择第 i 个物品。
当 Vi,j = Vi−1,j−Wi时，说明装了第 i 个商品。
从 i，j 的最大值一直遍历到 i＝0 ，则找到了所有解。

输入描述
第一行为两个数字 totalweight、N，均不超过 1000。
totalweight含义见题干，N 为物品数量。

接下来 N 行，每行两个数字 Wi、Vi ，均不超过 1000。
含义见题干。

输出描述
输出一行，为在背包容量限制下的最大化利益。

输入输出样例
示例
输入

8 5
3 4
5 5
1 2
2 1
2 3

输出

*/
// 1 - dfs递归
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define N 1010
// int v[N],w[N];
// int n,m;
// int dfs(int x,int V)
// {
//   if(x>n)return 0;
//   if(V<v[x])return dfs(x+1,V);
//   else return max(dfs(x+1,V),dfs(x+1,V-v[x])+w[x]);
// }

// int main()
// {
//   cin>>m>>n;
//   for(int i=1;i<=n;i++)
//   cin>>v[i]>>w[i];
//   int res=dfs(1,m);
//   cout<<res<<endl;

//   return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;
#define N 1010
int v[N], w[N];
int mem[N][N];
int n, m;
int dfs(int x, int V)
{
	if (mem[x][V]) return mem[x][V];

	int sum;
	if (x > n)sum = 0;
	if (V < v[x])sum = dfs(x + 1, V);
	else sum = max(dfs(x + 1, V), dfs(x + 1, V - v[x]) + w[x]);
	mem[x][V] = sum;
	return sum;
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	int res = dfs(1, m);
	cout << res << endl;

	return 0;
}


// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define N 1010
// int v[N],w[N];
// int n,m;

// int main()
// {
//   cin>>m>>n;
//   for(int i=1;i<=n;i++)
//   cin>>w[i]>>v[i];



//   return 0;
// }