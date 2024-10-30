/*(16)字符错序（错误版）
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;
int main()
{
    string n,m;
    string arr[40320];
    cin >> n;
    int a = n.size();
    srand(static_cast<unsigned int>(time(nullptr)));
    int  k = 0, h = 0;
    int x1, x2, x3, x4, x5, x6, x7, x8;
    x1 = x2 = x3 = x4 = x5 = x6 = x7 = x8 = 0;
    set<int>generatedIndexes;
    for (int i = 0; i < 40320; i++)
    { 
        h = 0;

        //后来加入
        ////写一个函数！！！！！！！！！
        for (;;)
        {
            switch (a)
            {
            case 8:   x8 = rand() % a;
            case 7:   x7 = rand() % a;
            case 6:   x6 = rand() % a;
            case 5:   x5 = rand() % a;
            case 4:   x4 = rand() % a;
            case 3:   x3 = rand() % a;
            case 2:   x2 = rand() % a;
            case 1:   x1 = rand() % a;
            }
            // 根据当前的a值，将随机生成的数组成一个索引值
            int index = 0;
            switch (a)
            {
            case 8:  index += x8; index *= a;
            case 7:  index += x7; index *= a;
            case 6:  index += x6; index *= a;
            case 5:  index += x5; index *= a;
            case 4:  index += x4; index *= a;
            case 3:  index += x3; index *= a;
            case 2:  index += x2; index *= a;
            case 1:  index += x1;
            }
            // 检查生成的索引值是否已在set中存在
            if (generatedIndexes.find(index) == generatedIndexes.end()) {
                k++;
                // 将新生成的索引值插入到set中
                generatedIndexes.insert(index);
            }
            // 判断是否所有生成的随机数组成的情况都不同
            bool allDifferent = (generatedIndexes.size() == k);
            if (generatedIndexes.size() == k) 
            { 
                switch (a)
                {
                case 8:   m += n[x8];
                case 7:   m += n[x7];
                case 6:   m += n[x6];
                case 5:   m += n[x5];
                case 4:   m += n[x4];
                case 3:   m += n[x3];
                case 2:   m += n[x2];
                case 1:   m += n[x1];
                }
                break;
            }
        }
        //以上后来加入


        //for (;;)
        //{
        //    switch (a)
        //    {
        //    case 8:  int x8 = rand() % a;
        //    case 7:  int x7 = rand() % a;
        //    case 6:  int x6 = rand() % a;
        //    case 5:  int x5 = rand() % a;
        //    case 4:  int x4 = rand() % a;
        //    case 3:  int x3 = rand() % a;
        //    case 2:  int x2 = rand() % a;
        //    case 1:  int x1 = rand() % a;
        //    }
        //    if()

        //}
        ////cout << x<<y<<z<< endl;
        //switch (a)
        //{
        //case 8:   m += n[x8];
        //case 7:   m += n[x7];
        //case 6:   m += n[x6];
        //case 5:   m += n[x5];
        //case 4:   m += n[x4];
        //case 3:   m += n[x3];
        //case 2:   m += n[x2];
        //case 1:   m += n[x1];
        //}


        for (int j = 0; j <= 40320; j++)
        {
            if (m == arr[j]) { h = 1; break; }
        }

        if (h == 0)
        {
            cout << m << endl;
            arr[k] = m;
            k++;
        }

        m = "";

    }

    return 0;
}
*/

/*(16)
#include<iostream>
#include<string>
using namespace std;
int main()
{
start:
    string n;
    cin >> n;
    int a = n.size();

    //int a;
    //cin >> a;

    int  k1 = 0, k2 = 1;
    int X[8];
    int p1 = 0, p2 = 0;
    int h = 0, g = 0,hh=0;

    while (1)
    {
        for (int i = 0; i < a; i++) { X[i] = i; }
        if (p1 != 0)
        {
            h = X[k1]; X[k1] = X[k2]; X[k2] = h;
            k2++;
            if (a <= 3)
            {
                if (k2 >= a - 1) { k1++; k2 = k1 + 1; }
                if (k1 >= a - 1) { break; }
            }
               else
               {
                   if (k2 > a - 1) { k1++; k2 = k1 + 1; }
                   if (k1 > a - 1) { break; }
               }
        }
        p1 = 1; p2 = 0;
        for (int j = 0; j < a; j++)
        {
            if (p2 != 0)
            {
                h = X[0];
                for (int l = 0; l < a - 1; l++) { X[l] = X[l + 1]; }
                X[a - 1] = h;
            }
            p2 = 1;
            for (int k = 0; k < a; k++) { g = X[k]; cout << n[g]; }// { cout << X[k]; }
            cout << endl;
        }
        hh++;
        cout << endl;
    }
    cout << endl << hh;
    goto start;

    return 0;
}
*/

/*(17)
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;

    cout<<n+m<<endl;

    return 0;
}
*/

/*(18)
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b, c, n, m;
    cin >> a >> b >> c;

    n = (-b + pow(pow(b, 2) - 4 * a * c, 1.0 / 2)) / 2 * a;
    m = (-b - pow(pow(b, 2) - 4 * a * c, 1.0 / 2)) / 2 * a;

    cout << "x1+ " << n << endl << "x2= " << m << endl;

    return 0;
}
*/

/*(19)
#include<iostream>
using namespace std;
int main()
{
    int n, m = 1;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        m *= i;
    }

    cout << n << "!=" << m << endl;

    return 0;
}
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z;
    cin >> x >> y >> z;
    string n[3];
    char a, b, c;
    int A, B, C, m;
    A = B = C = 2;
    int max(string x, string y);
    a = max(x, y);
    (a == 1) ? A-- : B--;
    
    a = max(y, z);
    (a == 1) ? B-- : C--;
  
    a = max(x, z);
    (a == 1) ? A-- : C--;
   
    n[A] = x; n[B] = y; n[C] = z;
    for (int j = 0; j < 3; j++)
    {
        cout << n[j] << endl;
    }


    return 0;
}


int max(string x, string y)
{
    char a, b; int k;
    for (int i = 0;; i++)
    {
        a = x[i]; b = y[i];
        if (a == b) { continue; }
        k=((int)a < (int)b) ? 1:0;
        break;
    }

    return(k);
}