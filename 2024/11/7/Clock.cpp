#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, m;
    char o;
    cout << "微博上有个自称“大笨钟V”的家伙，每天敲钟催促码农们爱惜身体早点睡觉。不过由于笨钟自己作息也不是很规律，所以敲钟并不定时。\n";
    cout << "一般敲钟的点数是根据敲钟时间而定的，如果正好在某个整点敲，那么“当”数就等于那个整点数；如果过了整点，就敲下一个整点数。\n";
    cout << "另外，虽然一天有24小时，钟却是只在后半天敲 1 - 12 下。\n例如在23:00敲钟，就是“当当当当当当当当当当当”，而到了23 : 01就会是“当当当当当当当当当当当当”。\n";
    cout << "在午夜00: 00到中午12 : 00期间（端点时间包括在内），笨钟是不敲的。\n";
    cout << "按照hh : mm的格式输入当前时间。其中hh是小时，在00到23之间；mm是分钟，在00到59之间。\n";
    cin >> n >> o >> m;
    if (n >= 0 && n <= 12)
    {
        cout << "Only ";
        if (n < 10)cout << "0";
        cout << n << ":";
        if (m < 10)cout << "0";
        cout << m << ".  Too early to Dang." << endl;
    }
    else
    {
        n -= 12;
        if (m != 0)n++;
        for (int i = 0; i < n; i++)
        {
            cout << "Dang";
            if (i == n - 1)cout << endl;
        }
    }

    return 0;
}
