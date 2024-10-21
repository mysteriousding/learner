/*(1)
#include<iostream>
using namespace std;
int main()
{
    char n;
    float m, w;
    cin >> n >> m;
    if (m >= 3) { m -= 3; }
    else { m = 0; }
    if (n == 'A') { w = 20 + m * 5; }
    else if (n == 'B') { w = 15 + m * 4; }
    else { w = 10 + m * 3; }
    cout << "车费的整数部分：" << (int)(w + 0.5) << endl;

    return 0;
}
*/

/*(2)
#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    a/=10;
    switch(a)
    {
        case 10:
        case 9 : cout<<"A\n";break;
        case 8 : cout<<"B\n";break;
        case 7 : cout<<"C\n";break;
        case 6 : cout<<"D\n";break;
        case 5 :
        case 4 :
        case 3 :
        case 2 :
        case 1 :
        case 0 : cout<<"E\n";break;
        default :cout<<"error\n";break;
    }

    return 0;
}
*/

/*(3)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    char n;
    cin>>n;
    if(65<=n&&n<=90){cout<<((int)n-65)*10<<endl;}
       else{cout<<setiosflags(ios::fixed)<<setprecision(2)<<((float)n-122)/3<<endl;}

    return 0;
}
*/

/*(4)
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float x,y;
    cin>>x;
    if(x<-2){y=x/3+1;}
       else if(-2<=x&&x<2){y=2*x+1/3.0;}
          else{y=x/7-1;}
    cout<<setiosflags(ios::fixed)<<setprecision(4);
    cout<<y<<endl;

    return 0;
}
*/


#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float n, m, m0 = 0, v = 0;
    float arr[10];
    for (int i = 0; i < 5; i++) 
    { 
        cin >> n >> m;
        m0 += m;
       
        arr[i] = n;
    }
    cout << m0;
    for (int i = 0; i < 5; i++)
    {
        n = arr[i];
        if (n >= 90) { v += 4.0 * (m / m0); }
        else { v += (4.0 * n / 90.0) * (m / m0); }
    }

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "GPA: " << v << endl;

    return 0;
}
