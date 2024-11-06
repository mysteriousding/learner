#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    cout << "一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。\n我将为你验证校验码的有效性，并输出有问题的号码。" << endl;
    cout << "请在第一行输入正整数N（≤100）作为输入身份证号码的个数。\n随后N行，每行给出1个18位身份证号码。" << endl;
    int n, h, l = 0;
    int q[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
    char b[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
    cin >> n;
    vector<string>m(n);
    for (int i = 0; i < n; i++)cin >> m[i];
    for (int k = 0; k < n; k++)
    {
        h = 0;
        for (int j = 0; j < 17; j++)h += (m[k][j] - 48) * q[j];
        h %= 11;
        int p = 0;
        for (int i = 0; i < 11; i++)if (h == i) { p = (m[k][17] == b[i]) ? 0 : 1; break; }
        if (p == 1 && l == 0)cout << "有问题的号码为:" << endl;
        if (p == 1) { cout << m[k] << endl; l++; }
    }
    if (l == 0)cout << "All passed" << endl;

    return 0;
}
