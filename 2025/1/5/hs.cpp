//调用直接判断素数
bool pd(int n)
{
    if (n == 1)return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)return 0;
    return 1;
}

//例：
#include<iostream>
using namespace std;
bool sushu(int n)
{
    if (n == 1)return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)return 0;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        if (sushu(i))
        {
            cout << i << " ";
        }
    }

    return 0;
}





//调用直接判断完数
bool wanshu(int n)
{
    int k = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            k += i;
            if (i * i != n)k += n / i;
        }
    }

    if (k == 2 * n)return 1;
    else return 0;
}

//例：
#include<iostream>
using namespace std;
bool wanshu(int n)
{
    int k = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            k += i;
            if (i * i != n)k += n / i;
        }
    }

    if (k == 2 * n)return 1;
    else return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        if (wanshu(i))
        {
            cout << i << " ";
        }
    }

    return 0;
}





//调用直接判断水仙花数
#include<cmath>
bool sxhshu(int n)
{
    int k = 0;

    k += pow(n / 100, 3);
    k += pow(n / 10 % 10, 3);
    k += pow(n % 10, 3);

    if (k == n)return 1;
    else return 0;
}

//例：
#include<iostream>
#include<cmath>
using namespace std;
bool sxhshu(int n)
{
    int k = 0;

    k += pow(n / 100, 3);
    k += pow(n / 10 % 10, 3);
    k += pow(n % 10, 3);

    if (k == n)return 1;
    else return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        if (sxhshu(i))
        {
            cout << i << " ";
        }
    }

    return 0;
}





//类类型投机取巧

//27
#include<iostream>
using namespace std;
int main()
{
    float n, m;
    cin >> n >> m;
    if (n < 0 || n>50)n = 1;
    if (m < 0 || m>50)m = 1;
    cout << (n + m) * 2 << endl;

    return 0;
}

//28
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int x, y, z;
    
    cout << setfill('0');
    while(cin >> x >> y >> z)
    cout << x << "-" << setw(2) << y << "-" << setw(2) << z << endl;

    return 0;
}

//29
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int x, y, z;
    
    cout << setfill('0');
    cin >> x >> y >> z;
    cout << x << "-" << setw(2) << y << "-" << setw(2) << z << endl;

    return 0;
}
