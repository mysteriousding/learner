/*
试题A：日期统计
本题总分：5分
【问题描述】
小蓝现在有一个长度为100的数组，数组中的每个元素的值都在0到9的范围之内。
数组中的元素从左至右如下所示：
5 6 8 6 9 1 6 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2 7 0 5 8 8 5 7 0 9
9 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3
现在他想要从这个数组中寻找一些满足以下条件的子序列：

1．子序列的长度为8；
2．这个子序列可以按照下标顺序组成一个yyyymmdd格式的日期，并且要求这个日期是2023年中的某一天的日期，例如20230902,20231223。
yyyy 表示年份，mm表示月份，dd表示天数，当月份或者天数的长度只有一位时需要一个前导零补充。
请你帮小蓝计算下按上述条件一共能找到多少个不同的2023年的日期。
对于相同的日期你只需要统计一次即可。
【答案提交】
这是一道结果填空的题，你只需要算出结果后提交即可。
本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。

#include<iostream>
using namespace std;
int main()
{
	int arr[38] = { 1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,1,4,0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3 };
	int arr2[10000], n = 0, m = 0;
	int a, b, c, d, x, y;
	for (int i = 0; i < 38 - 3; i++)
	{
		a = arr[i];
		if (a <= 1)
			for (int j = i + 1; j < 38 - 2; j++)
			{
				b = arr[j];
				if (!(a == 1 && b > 2 || a + b == 0))
					for (int k = j + 1; k < 38 - 1; k++)
					{
						c = arr[k];
						if (c <= 3)
							for (int f = k + 1; f < 38; f++)
							{
								d = arr[f];
								x = a * 10 + b, y = c * 10 + d;
								if ((x == 2 && y > 28) || ((x == 4 || x == 6 || x == 9 || x == 11) && y > 30) || x <= 0 || x > 12 || y <= 0 || y > 31)continue;
								arr2[n++] = x * 100 + y;
							}
					}
				
			}
	}
	int min, k;
	for (int i = 0; i < n; i++)
	{
		min = arr2[i], k = i;
		for (int j = i; j < n; j++)
			if (min > arr2[j])
				min = arr2[j], k = j;
		arr2[k] = arr2[i], arr2[i] = min;
	}
	min = arr2[0], m++;
	for (int i = 0; i < n; i++)
		if (min != arr2[i])
		{
			min = arr2[i];
			m++;
		}
	cout << m << endl;

	return 0;
}

//答: 235
*/

/*
试题 B: 01 串的熵
本题总分：5 分
【问题描述】
对于一个长度为 n 的 01 串 S = x1 x2 x3…xn，香农信息熵的定义为 H(S)= -∑n 1 p(xi)log2(p(xi))
其中 p(0), p(1) 表示在这个 01 串中 0 和 1 出现的占比。
比如，对于 S = 100 来说，信息熵 H(S)= -1/3log2(1/3)-2/3log2(2/3)-2/3log2(2/3)=1.3083。
对于一个长度为 23333333 的 01 串，如果其信息熵为 11625907.5798，且 0 出现次数比 1 少，
那么这个 01 串中 0 出现了多少次？

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double r = 23333333, h = 11625907.5798,n;
	cout << setiosflags(ios::fixed) << setprecision(0);
	for (double i = 0; i <= r / 2; i++)
	{
		n = -1 * i * i / r * (log(i / r) / log(2)) + (r - i) * -1 * (r - i) / r * (log((r - i)/r) / log(2));
		if(fabs(n-h)<1e-4)
			cout << i << endl;
	}	

	return 0;
}

//答: 11027421
*/

/*
试题 C: 冶炼金属
时间限制: 1.0s 内存限制: 256.0MB 本题总分：10 分

【问题描述】
小蓝有一个神奇的炉子用于将普通金属 O 冶炼成为一种特殊金属 X。
这个炉子有一个称作转换率的属性 V，V 是一个正整数，这意味着消耗 V 个普通金属 O 恰好可以冶炼出一个特殊金属 X，当普通金属 O 的数目不足 V 时，无法继续冶炼。
现在给出了 N 条冶炼记录，每条记录中包含两个整数 A 和 B，这表示本次投入了 A 个普通金属 O，最终冶炼出了 B 个特殊金属 X。
每条记录都是独立的，这意味着上一次没消耗完的普通金属 O 不会累加到下一次的冶炼当中。
根据这 N 条冶炼记录，请你推测出转换率 V 的最小值和最大值分别可能是多少，题目保证评测数据不存在无解的情况。

【输入格式】
第一行一个整数 N，表示冶炼记录的数目。
接下来输入 N 行，每行两个整数 A、B，含义如题目所述。

【输出格式】
输出两个整数，分别表示 V 可能的最小值和最大值，中间用空格分开。

【样例输入】

3
75 3
53 2
59 2

【样例输出】

20 25

【样例说明】
当 V = 20 时，有：⌊75/20⌋ = 3, ⌊53/20⌋ = 2，⌊59/20⌋ = 2，可以看到符合所有冶炼记录。
当 V = 25 时，有：⌊75/25⌋ = 3，⌊53/25⌋ = 2，⌊59/25⌋ = 2，可以看到符合所有冶炼记录。
且再也找不到比 20 更小或者比 25 更大的符合条件的 V 值了。

【评测用例规模与约定】
对于 30% 的评测用例，1 ≤ N ≤ 10^2。
对于 60% 的评测用例，1 ≤ N ≤ 10^3。
对于 100% 的评测用例，1 ≤ N ≤ 10^4，1 ≤ B ≤ A ≤ 10^9。

#include<iostream>
using namespace std;
int main()
{
	int n, a, b;
	int min, max, h;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		h = a / b;
		if (i == 0 || max > h)max = h;
		h = a / (b + 1) + 1;
		if (i == 0 || min < h)min = h;
	}
	cout << min << " " << max << endl;

	return 0;
}
*/

/*
试题 D: 飞机降落
时间限制: 2.0s 内存限制: 256.0MB 本题总分：10 分

【问题描述】

N 架飞机准备降落到某个只有一条跑道的机场。
其中第 i 架飞机在 Ti 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间，
即它最早可以于 Ti 时刻开始降落，最晚可以于 Ti + Dii时刻开始降落。降落过程需要 Li个单位时间。
一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
请你判断 N 架飞机是否可以全部安全降落。

【输入格式】
输入包含多组数据。
第一行包含一个整数 T，代表测试数据的组数。
对于每组数据，第一行包含一个整数 N。
以下 N 行，每行包含三个整数：Ti，Di 和 Li。

【输出格式】
对于每组数据，输出 YES 或者 NO，代表是否可以全部安全降落。

【样例输入】

2
3
0 100 10
10 10 10
0 2 20
3
0 10 20
10 10 20
20 10 20
【样例输出】

YES
NO

【样例说明】
对于第一组数据，可以安排第 3 架飞机于 0 时刻开始降落，20 时刻完成降落。
安排第 2 架飞机于 20 时刻开始降落，30 时刻完成降落。
安排第 1 架飞机于 30 时刻开始降落，40 时刻完成降落。
对于第二组数据，无论如何安排，都会有飞机不能及时降落。

【评测用例规模与约定】
对于 30% 的数据，N ≤ 2。
对于 100% 的数据，1 ≤ T ≤ 10，1 ≤ N ≤ 10，0 ≤ Ti, Di, Li ≤ 10^5。

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct f
//{
//	int t;
//	int d;
//	int l;
//	int s;
//	friend istream& operator >> (istream& in, f& h);
//};
//istream& operator >> (istream& in, f& h)
//{
//	in >> h.t >> h.d >> h.l;
//	h.s = h.t + h.d;
//	return in;
//}
//bool pd(f& a, f& b)
//{
//	if (a.s != b.s)return a.s < b.s;
//	return a.l < b.l;
//}
//int main()
//{
//	int t, n, sum;
//	bool u;
//	vector<f>m;
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		u = 1;
//		cin >> n;
//		m.resize(n);
//		for (int j = 0; j < n; j++)
//			cin >> m[j];
//		sort(m.begin(), m.end(), pd);
//		sum = m[0].t;
//		for (int j = 0; j < n - 1; j++)
//			if (sum + m[j].l <= m[j + 1].s)sum += m[j].l;
//			else
//			{
//				cout << "NO" << endl;
//				u = 0;
//				break;
//			}
//		if (u)cout << "YES" << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<cstring>
#include<bits/stdc++.h>
using namespace std;
struct f
{
	int t;
	int d;
	int l;
	friend istream& operator>>(istream& in, f& a);
}arr[11];
istream& operator>>(istream& in, f& a)
{
	in >> a.t >> a.d >> a.l;
	return in;
}
int n, m;
bool live[11];
bool dfs(int u, int time)
{
	if (u == m)return 1;
	for (int i = 0; i < m; i++)
	{
		if (!live[i] && arr[i].t + arr[i].d >= time)
		{
			int t = max(time, arr[i].t) + arr[i].l;
			live[i] = 1;
			if (dfs(u + 1, t))return 1;
			live[i] = 0;
		}
	}
	return 0;
}

int main()
{
	bool u;
	cin >> n;
	while (n--)
	{
		cin >> m;
		memset(live, 0, sizeof(live));
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		u = dfs(0, 0);
		cout << (u ? "YES" : "NO") << endl;
	}

	return 0;
}
*/


/*
E: 接龙数列
时间限制: 1.0s 内存限制: 256.0MB 本题总分：15 分
问题描述
对于一个长度为 K 的整数数列：A1 , A2 , ... , AK ，我们称之为接龙数列当且仅当 Ai 的首位数字恰好等于 Ai-1 的末位数字(2≤i≤K)。

例如 12 , 23 , 35 , 56 , 61 , 11 是接龙数列；
12 , 23 , 34 , 56 不是接龙数列，因为 56 的首位数字不等于 34 的末位数字。
所有长度为 1 的整数数列都是接龙数列。

现在给定一个长度为 N 的数列 A1 , A2 , ... , AN ，请你计算最少从中删除多少个数，可以使剩下的序列是接龙序列？

【输入格式】
第一行包含一个整数 N 。
第二行包含 N 个整数 A1 , A2 , ... , AN 。

【输出格式】
一个整数代表答案

【样例输入】
5
11 121 22 12 2023

【样例输出】
1

【样例说明】
删除 22 ，剩余11 , 121 , 12 , 2023 是接龙数列。

【评测用例规模与约定】
对于 20% 的评测用例，1 ≤ N ≤ 20 。
对于 50% 的评测用例，1 ≤ N ≤ 10000 。
对于 100% 的评测用例，1 ≤ N ≤ 10^5 ，1 ≤ Ai ≤ 10^9 。所有 Ai 保证不包含前导 0 。
*/

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//struct zhi
//{
//	int z;
//	int q;
//	int h;
//};
//istream& operator>>(istream& in, zhi& a)
//{
//	in >> a.z;
//	a.h = a.z % 10;
//	a.q = to_string(a.z)[0] - '0';
//	return in;
//}
//int main()
//{
//	int n, x, y;
//	cin >> n;
//	vector<zhi>m(n);
//	for (int i = 0; i < n; i++)
//		cin >> m[i];
//	int sum, max = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum = 0, x = i, y = i + 1;
//		while (y < n)
//		{
//			if (m[x].h != m[y].q)sum++, y++;
//			else x = y, y++;
//		}
//		if (max < sum)max = sum;
//	}
//
//	cout << max << endl;
//
//	return 0;
//}



//#include<bits/stdc++.h>
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//struct zhi
//{
//	int z;
//	int q;
//	int h;
//};
//istream& operator>>(istream& in,zhi& a)
//{
//	in>>a.z;
//	a.h=a.z%10;
//	a.q=to_string(a.z)[0]-'0';
//	return in;
//}
//int main()
//{
//	int n,x,y;
//	cin>>n;
//	vector<zhi>m(n);
//	vector<vector<int>>N(n+1,vector<int>(n+1,0));
//	for(int i=0;i<n;i++)
//		cin>>m[i];
//    for(int i=1;i<=n;i++)
//    for(int j=1;j<=n;j++)
//    if(m[i-1].h==m[j-1].q)N[i][j]=N[i-1][j-1]+1;
//    else N[i][j]=max(N[i-1][j],N[i][j-1]);
//    
//	cout<<n-N[n][n]<<endl;
//	
//	return 0;
//}



#include<iostream>
#include<string>
using namespace std;
int dp[10];
int main()
{
	int n, m, x, y, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		x = to_string(m)[0] - '0', y = m % 10;
		dp[y] = max(dp[x] + 1, dp[y]);
		k = max(k, dp[y]);
	}
	cout << n - k << endl;

	return 0;
}