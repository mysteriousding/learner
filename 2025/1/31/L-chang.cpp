/*
分考场

题目描述 n 个人参加某项特殊考试。

为了公平，要求任何两个认识的人不能分在同一个考场。

求是少需要分几个考场才能满足条件。

输入描述
输入格式：

第一行，一个整数 n ( 1≤n≤100)，表示参加考试的人数。

第二行，一个整数 m，表示接下来有 m 行数据。

以下 m 行每行的格式为：两个整数 a,b，用空格分开 ( 1≤a,b≤n )表示第 a 个人与第 b 个人认识。

输出描述
输出一行一个整数，表示最少分几个考场。

输入输出样例
示例
输入

5
8
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5

输出

4
*/

//#include <iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct E
//{
//    int q;
//    int h;
//};
//int main()
//{
//    int n, m, k = 0, h;
//    cin >> n >> m;
//    vector<int>v(n + 1, -1);
//    vector<E>e(m + 1);
//    for (int i = 1; i <= m; i++)
//        cin >> e[i].q >> e[i].h;
//    for (int i = 1; i <= m; i++)
//    {
//        if (v[e[i].q] == -1 && v[e[i].h] == -1)
//            v[e[i].q] = v[e[i].h] = k++;
//        else if (v[e[i].q] != -1 && v[e[i].h] != -1)
//        {
//            if (v[e[i].q] == v[e[i].h])continue;
//            h = v[e[i].q];
//            for (int j = 1; j <= n; j++)
//                if (v[j] != -1 && v[j] == h)
//                    v[j] = v[e[i].h];
//        }
//        else
//        {
//            if (v[e[i].q] == -1)v[e[i].q] = v[e[i].h];
//            else v[e[i].h] = v[e[i].q];
//        }
//    }
//    sort(v.begin() + 1, v.end());
//    k = 1, h = v[1];
//    for (int i = 2; i <= n; i++)
//        if (v[i] == -1 || h != v[i])
//            h = v[i], k++;
//    cout << k << endl;
//
//    return 0;
//}



//#include <iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int a[100] = { 0 };
//struct E
//{
//    int q;
//    int h;
//};
//int main()
//{
//    int n, m, k = 0, h;
//    cin >> n >> m;
//    vector<int>v(n + 1, -1);
//    vector<E>e(m + 1);
//    for (int i = 1; i <= m; i++)
//        cin >> e[i].q >> e[i].h;
//    for (int i = 1; i <= m; i++)
//    {
//        if (v[e[i].q] == -1 && v[e[i].h] == -1)
//            v[e[i].q] = v[e[i].h] = k++, a[k - 1] += 2;
//        else if (v[e[i].q] != -1 && v[e[i].h] != -1)
//        {
//            if (v[e[i].q] == v[e[i].h])continue;
//            h = v[e[i].q];
//            a[v[e[i].h]] += a[h], a[h] = 0;
//            for (int j = 1; j <= n; j++)
//                if (v[j] != -1 && v[j] == h)
//                    v[j] = v[e[i].h];
//        }
//        else
//        {
//            if (v[e[i].q] == -1)v[e[i].q] = v[e[i].h], a[v[e[i].h]]++;
//            else v[e[i].h] = v[e[i].q], a[v[e[i].q]]++;
//        }
//    }
//    h = 0;
//    for (int i = 0; i < k; i++)
//        if (h < a[i])h = a[i];
//    cout << h << endl;
//
//    return 0;
//}



//#include <iostream>
//#include<vector>
//using namespace std;
//int a[100] = { 0 };
//struct E
//{
//	int q;
//	int h;
//};
//int main()
//{
//	int n, m, k = 0, h = 0;
//	cin >> n >> m;
//	vector<int>v(n + 1, -1);
//	vector<E>e(m + 1);
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> e[i].q >> e[i].h;
//		a[e[i].q]++;
//		a[e[i].h]++;
//	}
//
//	for (int i = 0; i < n; i++)
//		if (h < a[i])h = a[i];
//	cout << h << endl;
//
//	return 0;
//}



#include <iostream>
using namespace std;
int a[105][105] = { 0 }, l[105][105] = { 0 };
int n, m, sum = 105;
void dfs(int x, int num)
{
    if (num >= sum)return;
    if (x > n)
    {
        sum = num;
        return;
    }
    for (int i = 1; i <= num; i++)
    {
        int j = 1;
        while (l[i][j] && !a[x][l[i][j]])
            j++;
        if (!l[i][j])
        {
            l[i][j] = x;
            dfs(x + 1, num);
            l[i][j] = 0;
        }
    }
    l[num + 1][1] = x;
    dfs(x + 1, num + 1);
    l[num + 1][1] = 0;
}
int main()
{
    int k, h;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> h;
        a[k][h] = a[h][k] = 1;
    }
    dfs(1, 1);
    cout << sum << endl;

    return 0;
}
