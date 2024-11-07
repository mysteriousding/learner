#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string n;
    float m, k = 0, p = 0;
    cout << "一个整数“犯二的程度”定义为该数字中包含2的个数与其位数的比值。\n如果这个数是负数，则程度增加0.5倍；如果还是个偶数，则再增加1倍。\n";
    cout << "例如数字 - 13142223336是个11位数，其中有3个2，并且是负数，也是偶数，则它的犯二程度计算为：\n3 / 11×1.5×2×100 % ，约为81.82 % 。\n";
    cout << "请输入一个整数让我为你计算一个塔到底有多二:\n";
    cin >> n;
    m = n.size();
    for (int i = 0; i < m; i++)
    {
        if (n[i] == '2')k++;
    }
    if (n[0] == '-') { k *= 1.5; m--; p++; }
    k /= m;
    if ((int)n[m - 1 + p] % 2 == 0)k *= 2;
    k *= 100;

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "结果为:\n";
    cout << k << "%" << endl;

    return 0;
}
