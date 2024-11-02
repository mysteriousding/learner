#include<iostream>
using namespace std;
int main()
{
    int n, h, k = 0;
    int x[10] = { 0,0,0,0,0,0,0,0,0,0 };
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        for (;;)
        {
            x[h % 10]++;
            h /= 10;
            if (h == 0)break;

        }
    }
    for (int i = 0; i < 9; i++)
    {
        /*if (x[i] < x[i + 1])k = x[i + 1];*/
        cout << " " << x[i];
    }
    /*cout << k << ":";
    for (int i = 0; i < 10; i++)
    {
        if (x[i] == k)cout << " " << i;
    }
    cout << endl;*/

    return 0;
}