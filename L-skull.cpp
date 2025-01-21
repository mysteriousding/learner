﻿/*
 敲打骷髅兵【算法赛】

问题描述
在一个昏暗的地下古墓里，胖子、小哥和你正在面对一只不安分的骷髅兵，这家伙的初始生命值为N。

每当你们用洛阳铲狠狠敲一下骷髅兵的脑袋，它就会消失，然后诡异地冒出两只新的骷髅兵！
这两只新骷髅兵的生命值均为敲打前的骷髅兵的生命值的一半（向下取整）。
例如，如果敲打前的骷髅兵的生命值为 3，那么敲打后就会冒出两只生命值为⌊3/2⌋=1的骷髅兵。
如果敲打前的骷髅兵的生命值为4，那么敲打后就会冒出两只生命值为⌊2/4⌋=2 的骷髅兵。
如果敲打前的骷髅兵的生命值的一半（向下取整）为0，则不会冒出新的骷髅兵。

第一次见到这场面，你吓得差点把铲子掉了！
见状，胖子拍了拍你的肩膀，语气坚定地说：
“伙计，敲脑袋的事就交由你胖爷来。不过，这骷髅兵可不简单！每次你敲它一下，它就会分裂出两只新的，真的是让人想哭啊！”

小哥在旁边插嘴：“是啊！也不知道要敲到什么时候！”

现在，请你计算出使初始以及后来不断冒出来的所有骷髅兵都消失所需要的最少敲打次数。

输入格式
第一行包含一个整数 t(1≤t≤10^5)，表示测试用例的数量。

接下来的 t 行，每行包含一个整数 n(1≤n≤10^9)，表示初始骷髅兵的生命值。

输出格式
对于每个测试用例，输出一行，表示使初始以及后来不断冒出来的所有骷髅兵都消失所需要的最少敲打次数。

样例输入
2
1
2

样例输出
1
3
*/
#include <iostream>
#include <iomanip>
using namespace std;
//long long arr[1000]={0,1};
double dg(int x)
{
    //if(x<1000)return arr[x];
    if (x == 1)return 1;
    return 2 * dg(x / 2) + 1;
}
int main()
{
    // for(int i=2;i<1000;i++)
    // arr[i]=2*arr[i/2]+1;
    int n, m;
    cin >> n;
    cout << setiosflags(ios::fixed) << setprecision(0);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cout << dg(m) << endl;
    }

    return 0;
}