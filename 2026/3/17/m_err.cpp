#include<iostream> 
#include<string>
#include<vector>
#include<queue> 
using namespace std;
//int main()
//{
//    int t, n, m, k, num, l, h, b;
//    string s;
//    vector<int>v;
//    queue<int>q;
//    cin >> t;
//    cin.ignore();
//    while (t--)
//    {
//        n = m = k = num = b = 0;
//        getline(cin, s);
//        l = s.size();
//        v.resize(l + 1, 0);
//        for (int i = 0; i < l; i++)
//            if (s[i] == '(')
//            {
//                n++;
//                if (k)
//                {
//                    h = q.front();
//                    q.pop();
//                    num += i  - h - v[h];
//					for (int j = h + 1; j < i; j++)
//						v[j]++;
//                    k--;
//                }
//            }
//            else
//            {
//                m++;
//                if (m > n)
//                {
//                    k++;
//                    q.push(i);
//                }
//            }
//        cout << num << endl;
//    }
//
//    return 0;
//}
//))))((((()()())()(
#include<map>
#include<algorithm>

using namespace std;

//int main()
//{
//    int n, ma = 0, h;
//    cin >> n;
//    vector<int>a(n), b(n), c(n);
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//    b[0] = 0, c[n - 1] = n - 1;
//    for (int i = 1; i < n; i++)
//        if (a[i] < a[i - 1])
//            b[i] = b[i - 1];
//        else b[i] = i;
//    for (int i = n - 1; i > 0; i--)
//        if (a[i] < a[i - 1])
//            c[i-1] = c[i];
//        else c[i] = i;
//
//    for (int i = 0; i < n; i++)
//    {
//        h = b[i] - c[i];
//        if (ma < h)
//            ma = h;
//    }
//    cout << ma << endl;
//    return 0;
//}

int main()
{
    int n, ma = 0, h;
    cin >> n;
    vector<int>a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[0] = 0, c[n - 1] = n - 1;
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            b[i] = i;
        else b[i] = b[i - 1];
    for (int i = n - 2; i > 0; i--)
        if (a[i] < a[i + 1])
            c[i] = i;
        else c[i] = c[i + 1];

    for (int i = 0; i < n; i++)
    {
        h = c[i] - b[i] + 1;
        if (ma < h)
            ma = h;
    }
    cout << ma << endl;

    return 0;
}
/*
8
1 2 1 1 1 3 3 4
*/
