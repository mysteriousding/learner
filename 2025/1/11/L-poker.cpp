/*
拉马车

题目描述
小的时候，你玩过纸牌游戏吗？

有一种叫做"拉马车"的游戏，规则很简单，却很吸引小朋友。

其规则简述如下：

假设参加游戏的小朋友是A 和B ，游戏开始的时候，他们得到的随机的纸牌序列如下：
A 方：[K,8,X,K,A,2,A,9,5,A]

B 方：[2,7,K,5,J,5,Q,6,K,4]

其中的X 表示 "10"，我们忽略了纸牌的花色。

从 A 方开始，A、B双方轮流出牌。

当轮到某一方出牌时，他从自己的纸牌队列的头部拿走一张，放到桌上，并且压在最上面一张纸牌上（如果有的话）。

此例中，游戏过程：

A 出 K，B 出 2，A 出 8，B 出 7，A 出 X，此时桌上的序列为：

K,2,8,7,X

当轮到 B 出牌时，他的牌 K 与桌上的纸牌序列中的 K 相同，则把包括 K 在内的以及两个 K 之间的纸牌都赢回来，放入自己牌的队尾。
注意：为了操作方便，放入牌的顺序是与桌上的顺序相反的。

此时，A、B双方的手里牌为：

A 方：[K,A,2,A,9,5,A]

B 方：[5,J,5,Q,6,K,4,K,X,7,8,2,K]

赢牌的一方继续出牌。也就是 B 接着出 5， A 出 K，B 出 J，A 出 A，B 出 5，又赢牌了。
此时桌上的序列为：

5,K,J,A,5

此时双方手里牌：

A 方：[2,A,9,5,A]

B 方：[Q,6,K,4,K,X,7,8,2,K,5,A,J,K,5]

注意：更多的时候赢牌的一方并不能把桌上的牌都赢走，而是拿走相同牌点及其中间的部分。
但无论如何，都是赢牌的一方继续出牌，有的时候刚一出牌又赢了，也是允许的。

当某一方出掉手里最后一张牌，但无法从桌面上赢取牌时，游戏立即结束。

对于本例的初始手牌情况下，最后 A 会输掉，而 B 最后的手里牌为：9K2A62KAX58K57KJ5

本题的任务就是已知双方初始牌序，计算游戏结束时，赢的一方手里的牌序。当游戏无法结束时，输出 -1。

输入描述
输入为 2 行，2 个串，分别表示A、B 双方初始手里的牌序列。我们约定，输入的串的长度不超过 30。2J9A7QA6Q6889977

输出描述
输出为 1 行，1 个串，表示A 先出牌，最后赢的一方手里的牌序。

输入输出样例
示例
输入

96J5A898QA
6278A7Q973

输出

2J9A7QA6Q6889977
*/
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
void tj(string& m, queue<char>& n, int k)
{
    for (int i = m.size() - 1; i >= k; i--)
    {
        n.push(m[i]);
        m.erase(i);
    }
}
bool pd(string& a, char b, queue<char>& c)
{
    for (int i = 0; a[i + 1] != '\0'; i++)
        if (b == a[i])
        {
            tj(a, c, i);
            return 1;
        }
    return 0;
}
void yx(queue<char>* m, string& n)
{
    char h;
    do
    {
        h = (*m).front();
        (*m).pop();
        n += h;
    } while (pd(n, h, *m));
}
int main()
{
    string s;
    queue<char>x, y, * p;
    stack<char>z;
    char h;
    int i = 0;
    getline(cin, s);
    while (s[i] != '\0')x.push(s[i++]);
    i = 0;
    getline(cin, s);
    while (s[i] != '\0')y.push(s[i++]);
    s = "", i = 0;
    int u = 1;
    while (!x.empty() && !y.empty())
    {
        p = u ? &x : &y;
        yx(p, s);
        u = !u;
    }

    while (!x.empty())
    {
        cout << x.front();
        x.pop();
    }
    while (!y.empty())
    {
        cout << y.front();
        y.pop();
    }
    cout << endl;

    return 0;
}
