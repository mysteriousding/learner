/*(6)二维数组

//存在一个二维数组a[10][10],每个元素的值为该元素下标的平方和，求该矩阵主对角线元素的和及平均值。
//
//输出格式:
//如 45 4.5
//
//输入样例:
//
//输出样例:


#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    for(int i=0;i<=10;i++)
        sum+=i*i*2;
    cout<<sum<<" "<<sum/10<<endl;

    return 0;
}
*/

/*(7)用递归法求解Fibonacci数列

//这是一个编程题模板。
//
//已知斐波那契数列公式如下：
//F(n)=F(n−1)+F(n−2),(n>2);
//F(1)=1;F(2)=1。
//
//输入格式:
//输入一个正整数n(1<=n<=50)。
//
//输出格式:
//输出该正整数n对应的斐波那契数列的F(n)。
//如果输入的n<1或者n>50，输出"Wrong Input!"
//
//输入样例:
//在这里给出一组输入。例如：
//
//2
//输出样例:
//在这里给出相应的输出。例如：
//
//F(2)=1
//输入样例:
//在这里给出一组输入。例如：
//
//3
//输出样例:
//在这里给出相应的输出。例如：
//
//F(3)=2
//输入样例:
//在这里给出一组输入。例如：
//
//-7
//输出样例:
//在这里给出相应的输出。例如：
//
//Wrong Input!

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<1||n>50)cout<<"Wrong Input!"<<endl;
    else
    {
        vector<int>m(n);
        m[0]=m[1]=1;
        for(int i=2;i<n;i++)
            m[i]=m[i-2]+m[i-1];
        cout<<"F("<<n<<")="<<m[n-1]<<endl;
    }

    return 0;
}
*/

/*(8)素数判断

//键盘输入一个正整数，要求判断该数是否为素数。素数即质数，只能被1和它本身整除。
//特别说明，1不是素数。如果是素数，输出“YES”，否则输出“NO”。
//
//输入格式:
//输入只有一个用例，即一个整数n。
//
//输出格式:
//如果n是素数，输出“YES”，否则输出“NO”。
//
//输入样例:
//11
//输出样例:
//在这里给出相应的输出。例如：
//
//YES

#include<iostream>
using namespace std;
bool pd(int n)
{
    if(n==1)return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    cout<<(pd(n)?"YES":"NO")<<endl;

    return 0;
}
*/

/*(9)显示指定范围内的素数

//输入整数m，将所有大于1小于整数m的素数存入所指定的数组中(数组最多只存放100个素数，超过则提示“OVERFLOW”)，输出各素数——若输入的m≤2，则提示“NO”，程序终止。
//注：素数(Prime Number)，亦称质数，指在一个大于1的自然数中，除了1和此整数自身外，没法被其他自然数整除的数。
//
//输入格式:
//输入一个非0的整数。
//
//输出格式:
//素数的输出格式为每个素数5列宽、右对齐、每行显示15个。
//
//输入样例:
//100
//输出样例:
//    2    3    5    7   11   13   17   19   23   29   31   37   41   43   47
//   53   59   61   67   71   73   79   83   89   97
//输入样例:
//568
//输出样例:
//OVERFLOW
//输入样例:
//1
//输出样例:
//NO

#include<iostream>
#include<iomanip>
using namespace std;
bool pd(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(n<=2)cout<<"NO"<<endl;
    else
    {
        int a[100],k=0;
        for(int i=2;i<n;i++)
        {
            if(pd(i))a[k++]=i;
            if(k==101){cout<<"OVERFLOW"<<endl;return 0;}
        }
        for(int j=0;j<k;j++)
        {
            if(j!=0&&j%15==0)cout<<endl;
            cout<<setw(5)<<a[j];
        }
    }

    return 0;
}
*/

//计算区间最大素数
//
//杨老师正在上《离散数学》课程的“数论”内容，讲授素数的知识。素数又称为质数。
//一个大于1的整数 p 是素数，当且仅当 p 只能被 1 和自身整除。
//很显然，2 是最小的素数。请你帮助他设计一个程序，可以找到整数 m 和 n 之间最大的素数。
//如果整数 m 和 n 之间不存在素数，则输出 None。
//
//输入格式:
//输入两个整数 m,n,  题目不保证 m≤n，但是保证 0≤m≤1000000,0≤n≤1000000。
//
//输出格式:
//输出 m 和 n 之间的最大的素数。
//
//输入样例01:
//在这里给出一组输入。例如：
//
//10 0
//输出样例01:
//在这里给出相应的输出。例如：
//
//7
//输入样例02:
//在这里给出一组输入。例如：
//
//100 200
//输出样例02:
//在这里给出相应的输出。例如：
//
//199
//输入样例03:
//在这里给出一组输入。例如：
//
//100 100
//输出样例02:
//在这里给出相应的输出。例如：
//
//None

#include<iostream>
using namespace std;
bool pd(long long n)
{
    if (n == 1)return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)return 0;
    return 1;
}
int main()
{
    long long n, m;
    cin >> n >> m;
    if (n > m)n = m + n, m = n - m, n = n - m;
    for (; m >= n; m--)
        if (pd(m))
        {
            cout << m << endl;
            return 0;
        }
    cout << "None" << endl;

    return 0;
}