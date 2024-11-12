/*(1)FP18-计算速度和距离

//输入物体匀加速运动的初速度、加速度和移动时间t（整数），计算物体在t秒中移动的距离，t秒后的速度，和t秒中的平均速度。
//
//输入格式:
//输入在一行中给出初速度、加速度和移动时间t，分别用空格分开。
//
//输出格式:
//在一行中t秒中移动的距离，t秒后的速度，和t秒中的平均速度，小数点后面保留2位。
//
//输入样例:
//10.0 20.0 30
//输出样例:
//9300.00,610.00,15.25


*/

/*(2)圆的周长和面积

//请编写程序，输入圆的半径 r，计算并输出三角形的周长 p 和面积 a。
//
//输入格式
//r
//
//输出格式
//p  a
//
//输入样例
//2.8
//
//输出样例
//17.5929 24.6301
//
//要求：输出 4 位小数(末位四舍五入)。

#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.141592653589793
int main()
{
    double r,c,s;
    cin>>r;
    c=2*pi*r;//+5e-5;
    s=pi*r*r;//+5e-5;
    cout<<setiosflags(ios::fixed)<<setprecision(4);
    cout<<c<<" "<<s<<endl;

    return 0;
}
*/

/*(3)要求在屏幕上输出以下一行信息

//This is a C program.
//
//输入格式:
//无需输入
//
//输出格式:
//This is a C program.
//
//输入样例:
//在这里给出一组输入。例如：
//
//
//输出样例:
//在这里给出相应的输出。例如：
//
//This is a C program.

#include<iostream>
using namespace std;
int main()
{
    cout<<"This is a C program."<<endl;

    return 0;
}
*/

/*(4)求两个整数中的较大者。

例1.3求两个整数中的较大者。

//输入格式:
//输出格式:
//输入样例:
//在这里给出一组输入。例如：
//
//1,2
//输出样例:
//在这里给出相应的输出。例如：
//
//max=2

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    char c;
    cin>>a>>c>>b;

    cout<<"max="<<((a>b)?a:b)<<endl;

    return 0;
}
*/

//梯形面积(误差)
//
//请编写程序，输入梯形的上底 t、下底 b 和高 h，计算并输出梯形的面积 a。
//
//输入格式
//t  b  h
//
//输出格式
//a
//
//输入样例
//4.493 5.507 5.765
//
//输出样例
//28.83
//
//要求：输出 2 位小数(末尾四舍五入)。

//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//    double t, b, h, a;
//    cin >> t >> b >> h;
//    a = (t + b) * h * 0.5 + 1e-7;
//
//    cout << setiosflags(ios::fixed) << setprecision(2) << a << endl;
//
//    return 0;
//}











//#include<iostream>
//#include<iomanip>
////#include<string>
//using namespace std;
//int main()
//{
//    int a[10]={0};
//    for (int i = 0; i < 5; i++)cin >> a[i];
//    for (int i = 0; a[i]!=0; i++)
//    {
//        if (i != 0)cout << " ";
//        cout << a[i];
//        a[i]=0;
//    }
//    cout << endl;
//    for (int i = 0; i<10; ++i)
//    {
//        if (i != 0)cout << " ";
//        cout << a[i];
//    }
//
//
//
//    return 0;
//}





//#include<iostream>
//#include<iomanip>
//#include<cmath>
//using namespace std;
//int main()
//{
//    int x[50] = { 0 };
//    int i;
//    cin >> i;
//        int k = 0, y = 0;
//        for (int j = 1; j <= sqrt(i); j++)
//        {
//            if (i % j == 0)
//            {
//                x[k++] = j;
//                if (j != i / j)x[k++] = i / j;
//            }
//        }
//        for (int l = 0; x[l] != 0; l++)cout << x[l] << " ";
//        for (int l = 0; x[l] != 0; l++)
//        {
//            y += x[l];
//            x[l] = 0;
//        }
//        /*if (y == i)cout << setw(5) << i;*/
//        cout << y;
//    
//
//    return 0;
//}







//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int i, n, k = 0, f, j, flag;
//    cin >> n;
//    vector<int>a(n);
//    k = n;
//    for (i = 0; i < n; i++) cin >> a[i];
//    while (k != 0)
//    {
//        f = 0;
//        while (a[f] == -1) f++;
//        flag = a[f];
//        j = f;
//        cout << j + 1 << " ";
//        a[j] = -1;
//        k--;
//        j++;
//        while (j < n)
//        {
//            if (a[j] != flag && a[j] != -1)
//            {
//                cout << j + 1 << " ";
//                flag = a[j];
//                a[j] = -1;
//                k--;
//                j++;
//            }
//            else j++;
//        }
//        cout << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<iomanip>
//#include<cmath>
//using namespace std;
//int main()
//{
//    int x[50] = { 0 };
//    for (int i = 2; 1 <= 1000; i++)
//    {
//        int k = 0, y = 0;
//        for (int j = 1; j <= sqrt(i); j++)
//        {
//            if (i % j == 0)
//            {
//                x[k++] = j;
//                x[k++] = i / j;
//            }
//        }
//        for (int l = 0; x[l] != 0; l++)
//        {
//            y += x[l];
//            x[l] = 0;
//        }
//        if (y == i)cout << setw(5) << i;
//    }
//
//    return 0;
//}



//#include<iostream>
//using namespace std;
//int main() {
//    char x[1000];
//    long long a[1000];
//    int n = 0;
//    cin.getline(x, 1000);
//    int len = 0;
//    while (x[len] != '\0') {
//        len++;
//    }
//    long long num = 0;
//    for (int i = 0; i < len; ++i) {
//        if (x[i] >= '0' && x[i] <= '9') {
//            num = num * 10 + (x[i] - '0');
//        }
//        else {
//            if (num != 0) {
//                a[n++] = num;
//                num = 0;
//            }
//        }
//    }
//    if (num != 0) {
//        a[n++] = num;
//    }
//    cout << n << endl;
//    if (n > 0) {
//        cout << a[0];
//        for (int i = 1; i < n; ++i) {
//            cout << " " << a[i];
//        }
//    }
//    return 0;
//}






//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string n;
//    int m[50];
//    int o, k = 0;
//    getline(cin, n);
//    o = n.size();
//    for (int j = 0; j < o;)
//    {
//        int a = 0, p = 0, l = 1;
//        for (;; j++)
//        {
//            if (n[j] < 48 || n[j]>57)break;
//            a = (n[j] - 48) + a * 10;
//            //l *= 10;
//            p = 1;
//        }
//        if (p == 1)
//        {
//            m[k] = a;
//            k++;
//        }
//        else j++;
//    }
//    cout << k << endl;
//    for (int i = 0; i < k; i++)
//    {
//        if (i != 0)cout << " ";
//        cout << m[i];
//    }
//
//    return 0;
//}



#include<iostream>
#include<string>
using namespace std;
int main()
{
    char ip[33];
    int i, sum = 0;
    cin >>ip;
    for(i = 0; i < 32; i++)
    {
        sum += (ip[i] - '0') * pow(2, 8-1-i%8);
        if ((i + 1) % 8 == 0)
        {
            cout << sum;
            if (i != 31)cout << ".";
            sum = 0;
        }
    }
    
    return 0;
}