/*(6)计算圆柱体相关信息

//设圆半径r=1.5，圆柱体高度h通过键盘输入，请编程求圆柱体体积。（都使用double类型，圆周率取3.14159）
//
//输入格式:
//输入高度h带2位小数点
//
//输出格式:
//输出带2位小数点的结果
//
//输入样例:
//在这里给出一组输入。例如：
//
//1
//输出样例:
//在这里给出相应的输出。例如：
//
//7.07

#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14159
int main()
{
    double r=1.5,h;
    cin>>h;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<pi*r*r*h<<endl;

    return 0;
}
*/

/*(7)买复印纸(误差)

//某办公室到年底准备将剩余的办公经费全部用于购买复印纸。请编写程序，输入办公经费的余额和每包复印纸的单价，计算并输出最多可购买多少包复印纸。
//
//输入格式
//办公经费余额和复印纸单价
//
//输出格式
//可购复印纸的最大数量
//
//输入样例1
//660.8 47.2
//
//输出样例1
//14
//
//输入样例2
//504.9 19.8
//
//输出样例2
//25
//
//提示：注意实数的误差。

#include<iostream>
using namespace std;
int main()
{
    double n,m;
    cin>>n>>m;

    cout<<(int)(n/m+1e-5)<<endl;

    return 0;
}
*/

/*(8)判断奇偶性

//编写程序：输入一个整数，判断该数的奇偶性。
//
//输入格式:
//一个整数。
//
//输出格式:
//输出奇数或偶数。
//
//输入样例:
//2
//
//输出样例:
//请输入一个整数:2 是偶数。

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"请输入一个整数:"<<n<<" 是";
    if(n%2==0)cout<<"偶数。";
    else cout<<"奇数。";
    cout<<endl;

    return 0;
}
*/

/*(9)反向输出一个三位数

//将一个三位数反向输出。
//
//输入格式:
//一个三位数n。
//
//输出格式:
//反向输出n（去前导零）。
//
//输入样例:
//123
//输出样例:
//321

#include<iostream>
using namespace std;
int main()
{
    int n,m,p=0;
    cin>>n;
    while(1)
    {
        m=n%10;
        n/=10;
        if(m==0&&p==0)continue;
        cout<<m;
        p=1;
        if(n==0)break;
    }
    cout<<endl;

    return 0;
}
*/

//a+10
// 
//a+10
//
//输入样例:
//在这里给出一组输入。例如：
//
//1
//输出样例:
//在这里给出相应的输出。例如：
//
//11

#include<iostream>
using namespace std;
int main()
{
    long long a;
    cin >> a;
    cout << a + 10 << endl;

    return 0;
}
