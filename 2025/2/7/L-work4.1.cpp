/*(1)求奇数分之一序列前N项和

//本题要求编写程序，计算序列 1 + 1/3 + 1/5 + ... 的前N项之和。
//
//输入格式:
//输入在一行中给出一个正整数N。
//
//输出格式:
// 在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后6位。题目保证计算结果不超过双精度范围。
//
//输入样例:
//23
//输出样例:
//sum = 2.549541

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        sum += 1.0 / (2 * i + 1);
    cout << setiosflags(ios::fixed) << setprecision(6) << "sum = " << sum << endl;

    return 0;
}
*/

/*(2)高速公路超速处罚

//按照规定，在高速公路上行使的机动车，达到或超出本车道限速的10%则处200元罚款；
//若达到或超出50%，就要吊销驾驶证。
//请编写程序根据车速和限速自动判别对该机动车的处理。
//
//输入格式:
//输入在一行中给出2个正整数，分别对应车速和限速，其间以空格分隔。
//
//输出格式:
//在一行中输出处理意见：若属于正常行驶，则输出“OK”；
//若应处罚款，则输出“Exceed x%. Ticket 200”；
//若应吊销驾驶证，则输出“Exceed x%. License Revoked”。
//其中x是超速的百分比，精确到整数。
//
//输入样例1:
//65 60
//输出样例1:
//OK
//输入样例2:
//110 100
//输出样例2:
//Exceed 10%. Ticket 200
//输入样例3:
//200 120
//输出样例3:
//Exceed 67%. License Revoked

#include<iostream>
using namespace std;
int main()
{
    float n,m;
    cin>>n>>m;
    n=n/m;
    if(n<1.10000)cout<<"OK";
    else
    {
        cout<<"Exceed "<<int((n-1)*100+0.5)<<"%. ";
        if(n<1.50000)cout<<"Ticket 200";
        else cout<<"License Revoked";
    }
    cout<<endl;

    return 0;
}
*/

/*(3)求e的近似值

//自然常数 e 可以用级数 1+1/1!+1/2!+⋯+1/n!+⋯ 来近似计算。
//本题要求对给定的非负整数 n，求该级数的前 n+1 项和。
//
//输入格式:
//输入第一行中给出非负整数 n（≤1000）。
//
//输出格式:
//在一行中输出部分和的值，保留小数点后八位。
//
//输入样例:
//10
//输出样例:
//2.71828180

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double e=0,k=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        e+=1.0/(k*=i);
    cout<<setiosflags(ios::fixed)<<setprecision(8)<<e+1<<endl;

    return 0;
}
*/

/*



*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct e
{
    int a;
    int b;
};
bool pd(e& x, e& y)
{
    return x.b > y.b;
}
int main()
{
    int n, m, i, j, k;
    bool u;
    cin >> n;
    vector<e>x(n);
    for (i = 0; i < n; i++)
        cin >> x[i].a >> x[i].b;
    cin >> m;
    vector<e>y(m);
    for (j = 0; j < m; j++)
        cin >> y[j].a >> y[j].b;
    vector<e>z(n * m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            z[i * m + j].a = x[i].a * y[j].a, z[i * m + j].b = x[i].b + y[j].b;
    sort(z.begin(), z.end(), pd);
    for (i = 0; i < n * m - 1; i++)
        if (z[i].b == z[i + 1].b)
            z[i + 1].a += z[i].a, z[i].a = 2025;
    u = 1;
    for (i = 0; i < n * m; i++)
        if (z[i].a <= 2000 && z[i].a != 0)
        {
            if (i)cout << " ";
            cout << z[i].a << " " << z[i].b;
            u = 0;
        }
    if (u)cout << "0 0";
    cout << endl;

    z.resize(n + m);
    for (i = 0, j = 0, k = 0; i < n && j < m; k++)
        if (x[i].b == y[j].b)z[k].b = x[i].b, z[k].a = x[i++].a + y[j++].a;
        else if (x[i].b > y[j].b)z[k].b = x[i].b, z[k].a = x[i++].a;
        else z[k].b = y[j].b, z[k].a = y[j++].a;
    for (; i < n; i++)
        z[k].b = x[i].b, z[k++].a = x[i++].a;
    for (; j < m; j++)
        z[k].b = y[j].b, z[k].a = y[j++].a;
    u = 1;
    for (i = 0; i < k; i++)
        if (z[i].a <= 2000 && z[i].a != 0)
        {
            if (i)cout << " ";
            cout << z[i].a << " " << z[i].b;
            u = 0;
        }
    if (u)cout << "0 0";
    cout << endl;

    return 0;
}
