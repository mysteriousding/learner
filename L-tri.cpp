#include <iostream>
using namespace std;
int a[21][21] = { 0 };
int main()
{
    int n, j = 1;
    cin >> n;
    for (int i = 1; i <= n/2 ; i++)
    {
        for (int k = i; k <= n - i; k++)
            a[i][k] = j++;
        //for (int k =n-i; k >i; k--)
        //    a[n-i-k][k] = j++;
        //for (int k = n - i - 2; k > i; k--)
        //    a[k][i] = j++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n - i; k++)
        {
            if (k)cout << " ";
            cout << a[i][k];
        }
        cout << endl;
    }


    return 0;
}