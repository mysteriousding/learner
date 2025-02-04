/*
填字母游戏

题目描述
小明经常玩 LOL 游戏上瘾，一次他想挑战 K 大师，不料 K 大师说：

"我们先来玩个空格填字母的游戏，要是你不能赢我，就再别玩 LOL 了"。

K 大师在纸上画了一行 n 个格子，要小明和他交替往其中填入字母。

并且：

轮到某人填的时候，只能在某个空格中填入 L 或 O。

谁先让字母组成了"LOL"的字样，谁获胜。

如果所有格子都填满了，仍无法组成 LOL，则平局。

小明试验了几次都输了，他很惭愧，希望你能用计算机帮他解开这个谜。

输入描述
本题的输入格式为：

第一行，数字 n（ n<10），表示下面有 n 个初始局面。

接下来，n 行，每行一个串，表示开始的局面。

比如："******", 表示有 6 个空格。"L****", 表示左边是一个字母 L，它的右边是 4 个空格。

输出描述
要求输出 n 个数字，表示对每个局面，如果小明先填，当 K 大师总是用最强着法的时候，小明的最好结果。

1 表示能赢；

-1 表示必输；

0 表示可以逼平。

输入输出样例
示例
输入

4
***
L**L
L**L***L
L*****L

输出

0
-1
1
1
*/
//#include <iostream>
//#include<string>
//using namespace std;
//int u,h;
//void dfs(int n,string m)
//{
//  if(u==1||n>h)return;
//  int j=0;
//  while(m[j+2])
//  {
//    if(m[j]=='L') 
//    if(m[j+1]=='O'&&m[j+2]=='L')
//    {
//      if(n%2==1)u=1;
//      return;
//    }
//    j++;
//  }
//  bool v=0;
//  for(int i=0;m[i];i++)
//  if(m[i]=='*')
//  {
//    v=1;
//    m[i]='L';
//    dfs(n+1,m);
//    m[i]='O';
//    dfs(n+1,m);
//    m[i]='*';
//    dfs(n+1,m);
//  }
//  if(u==-1&&!v)u=v;
//}
//int main()
//{
//  int t;
//  string m;
//  cin>>t;
//  for(int k=0;k<t;k++)
//  {
//    cin.ignore();
//    cin>>m;
//    u=-1,h=0;
//    for(int i=0;m[i];i++)
//    if(m[i]=='*')h++;
//    dfs(0,m);
//    cout<<u<<endl;
//  }
//
//  
//  return 0;
//}



//#include <iostream>
//#include<string>
//using namespace std;
//int u, v, h;
////小明先
//void dfs1(int n, string m)
//{
//    if (u == -1 || n > h)return;
//    int j = 0;
//    while (m[j + 2])
//    {
//        if (m[j] == 'L')
//            if (m[j + 1] == 'O' && m[j + 2] == 'L')
//            {
//                if (n % 2 == 0)u = -1;
//                return;
//            }
//        j++;
//    }
//    bool l = 0;
//    for (int i = 0; m[i]; i++)
//        if (m[i] == '*')
//        {
//            l = 1;
//            m[i] = 'L';
//            dfs1(n + 1, m);
//            m[i] = 'O';
//            dfs1(n + 1, m);
//            m[i] = '*';
//            dfs1(n + 1, m);
//        }
//    if (u == 1 && !l)u = l;
//}
////K大师先
//void dfs2(int n, string m)
//{
//    if (v == 1 || n > h)return;
//    int j = 0;
//    while (m[j + 2])
//    {
//        if (m[j] == 'L')
//            if (m[j + 1] == 'O' && m[j + 2] == 'L')
//            {
//                if (n % 2 == 0)v = 1;
//                return;
//            }
//        j++;
//    }
//    bool l = 0;
//    for (int i = 0; m[i]; i++)
//        if (m[i] == '*')
//        {
//            l = 1;
//            m[i] = 'L';
//            dfs2(n + 1, m);
//            m[i] = 'O';
//            dfs2(n + 1, m);
//            m[i] = '*';
//            dfs2(n + 1, m);
//        }
//    if (v == -1 && !l)v = l;
//}
//
//int main()
//{
//    int t;
//    string n, m;
//    cin >> t;
//    for (int k = 0; k < t; k++)
//    {
//        cin.ignore();
//        cin >> m;
//        n = m;
//        u = 1, v = -1, h = 0;
//        for (int i = 0; m[i]; i++)
//            if (m[i] == '*')h++;
//        dfs1(0, m);
//        dfs2(0, n);
//        cout << (u >= v ? u : v) << endl;
//    }
//
//
//    return 0;
//}



#include <iostream>
#include<string>
using namespace std;
int u, v;
void dfs(int n, string m)
{
    int j = 0;
    while (m[j + 2])
    {
        if (m[j] == 'L')
            if (m[j + 1] == 'O' && m[j + 2] == 'L')
            {
                if (n % 2 == 0)u = -1, v = 1;
                return;
            }
        j++;
    }
    bool l = 0;
    for (int i = 0; m[i]; i++)
        if (m[i] == '*')
        {
            l = 1;
            m[i] = 'L';
            dfs(n + 1, m);
            m[i] = 'O';
            dfs(n + 1, m);
            m[i] = '*';
        }
    if (u == 1 && !l)u = 0;
    if (v == -1 && !l)v = 0;
}

int main()
{
    int t;
    string m;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin.ignore();
        cin >> m;
        u = 1, v = -1;
        dfs(0, m);
        cout << (u >= v ? u : v) << endl;
    }

    return 0;
}
