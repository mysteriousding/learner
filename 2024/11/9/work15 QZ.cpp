/*(1)对角线 - 《C++编程基础及应用》- 习题3-6

//编写程序，实现下述功能：
//
//从键盘读入矩形的长，以厘米为单位，应为小数；
//从键盘读入矩形的宽，以厘米为单位，应为小数；
//使用勾股定理计算对角线的长度并输出，保留1位小数。
//
//输入格式:
//长
//宽
//
//输出格式:
//参见输出样例
//
//输入样例:
//5.1
//4.3
//输出样例:
//The diagonal legnth is: 6.7 cm.

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float n,m;
    cin>>n>>m;
    n=pow(n*n+m*m,1.0/2);

    cout<<setiosflags(ios::fixed)<<setprecision(1);
    cout<<"The diagonal legnth is: "<<n<<" cm."<<endl;

    return 0;
}
*/

/*(2)1378-1 输出素数

//编程实现：输入N，找出1-N之间的素数，并输出。（输出格式，每个素数之间用一个空格隔开，结尾有一个空格）
//
//输入格式:
//输入一个正整数。
//
//输出格式:
//输出1-N之间的素数，每个素数之间用一个空格隔开，结尾有一个空格
//
//输入样例:
//在这里给出一组输入。例如：
//
//10
//输出样例:
//在这里给出相应的输出。例如：
//
//2 3 5 7

#include<iostream>
using namespace std;
int main()
{
    int n,p,k=0;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        p=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                p++;
                break;
            }
        }
        if(p==0){cout<<i<<" ";k++;}
    }
    if(k==0)cout<<" ";
    cout<<endl;

    return 0;
}
*/

/*(3)排序

//请编写程序对不超过50000个整数递增排序。
//备注：本题不允许使用STL sort()或qsort()等现成的排序库函数。
//
//输入格式:
//输入第一行一个正整数n，表示待排序的元素个数。第二行为n个整数，表示待排序的元素。n不超过50000。
//
//输出格式:
//输出为一行，表示排序结果，每个整数后一个空格。
//
//输入样例:
//5
//5 4 3 2 1
//
//输出样例:
//1 2 3 4 5

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,h;
    cin>>n;
    vector<int>m(n);
    for(int i=0;i<n;i++)cin>>m[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(m[j]>m[j+1]){h=m[j];m[j]=m[j+1];m[j+1]=h;}
        }
    }
    for(int j=0;j<n;j++)
    {
        cout<<m[j]<<" ";
        if(j==n-1)cout<<endl;
    }

    return 0;
}
*/

/*(4)计算奇数阶乘之和

//编程序实现：输入一个正整数n（n≤18），求出从1到n之间所有奇数的阶乘之和。
//
//输入格式:
//输入一个正整数n（n≤18）。
//
//输出格式:
//输出阶乘之和，最后换行。
//
//输入样例:
//16
//输出样例:
//sum=1313941673647

#include<iostream>
using namespace std;
int main()
{
    long long J(int x);
    int n;
    long long m=0;
    cin>>n;
    for(int i=1;i<=n;i+=2)m+=J(i);
    cout<<"sum="<<m<<endl;

    return 0;
}
long long J(int x)
{
    long long y=1;
    for(int i=x;x>0;x--)y*=x;
    return y;
}
*/

//字符串比对
//
//输入两个长度相同的字符串，字符串长度小于20，且只包含英文字符。
//将两个字符串逐字符对比的结果输出（由+和-构成的一行字符），具体规则如下：
//如果两个字符串对应字符是同一字母则输出+
//如果两个字符串对应字符不是同一字母则输出-
//注意，一个字母的大写和小写也被认为是同一字母。
//
//输入格式:
//输入两个长度相等的字符串，只包含大小写字母。
//
//输出格式:
//输出一行由+和-构成的一行，表示两个字符串的对比结果。
//
//输入样例:
//aBCDE
//abced
//输出样例:
//+++--

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n, m;
    int k;
    cin >> n >> m;
    k = n.size();
    for (int i = 0; i < k; i++)
    {
        if (n[i] == m[i] || n[i] - 32 == m[i] || n[i] == m[i] - 32)cout << "+";
        else cout << "-";
        if (i == k - 1)cout << endl;
    }

    return 0;
}
