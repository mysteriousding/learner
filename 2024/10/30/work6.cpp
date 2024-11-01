/*(6)
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    float n,m;
    cin>>n>>m;
    n=pow(n*n+m*m,1.0/2);

    cout<<"The diagonal legnth is: "<<setiosflags(ios::fixed)<<setprecision(1)<<n<<" cm."<<endl;

    return 0;
}
*/

/*(7）
#include<iostream>
using namespace std;
int main()
{
    int n,m=0;
    for(int i=0;i<3;i++)
    {
        cin>>n;
        m+=n;
    }

    cout<<m/3;

    return 0;
}
*/

/*(8)错
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z, m;
    char k[10];
    int h;
    cin >> x >> y >> z;
    for (int j = 0; j < 3; j++)
    {
        if (j == 0) { m = x; }
        else if (j == 1) { m = y; }
        else { m = z; }
        h = m.size();
        for (int i = 0; i < h; i++)
        {
            k[i] = m[i];
            k[i + 1] = m[i + 1];
            if ((int)k[i] == 92)
            {
                if (k[i + 1] == 'n') { cout << "\n"; }
                if (k[i + 1] == 't') { cout << "\t"; }
                if (k[i + 1] == '?') { cout << "\?"; }
                if ((int)k[i + 1] == 39) { cout << "\'"; }
                if (k[i + 1] == '"') { cout << "\""; }
                if ((int)k[i + 1] == 92) { cout << "\\"; }
                if (k[i + 1] == 'a') { cout << "\a"; }
                if (k[i + 1] == 'b') { cout << "\b"; }
                if (k[i + 1] == 'f') { cout << "\f"; }
                if (k[i + 1] == 'v') { cout << "\v"; }
                if (k[i + 1] == 'r') { cout << "\r"; }
                if (k[i + 1] == '0') { cout << "\0"; }
                i += 1;
            }
            else { cout << k[i]; }
        }
        if (j != 2)cout << endl;
    }


    return 0;
}
*/

/*(8)错
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x, y, z, m;
    char k[10];
    int i,h;
    cin >> x >> y >> z;
    for (int j = 0; j < 4; j++)
    {
        if (j == 0) { m = x; }
        else if (j == 1) { m = y; }
        else { m = z; }
        h = m.size();
        for (i = 0; i < h; i++)
        {
            k[i] = m[i];
            k[i + 1] = m[i + 1];
            if ((int)k[i] == 92)
            {
                if (k[i + 1] == 'n') { cout << "\n"; }
                if (k[i + 1] == 't') { cout << "\t"; }
                if (k[i + 1] == '?') { cout << "\?"; }
                if ((int)k[i + 1] == 39) { cout << "\'"; }
                if (k[i + 1] == '"') { cout << "\""; }
                if ((int)k[i + 1] == 92) { cout << "\\"; }
                if (k[i + 1] == 'a') { cout << "\a"; }
                if (k[i + 1] == 'b') { cout << "\b"; }
                if (k[i + 1] == 'f') { cout << "\f"; }
                if (k[i + 1] == 'v') { cout << "\v"; }
                if (k[i + 1] == 'r') { cout << "\r"; }
                if (k[i + 1] == '0') { cout << "\0"; }
                i += 1;
            }
            else { cout << k[i]; }
        }
        if (j != 2)cout << endl;
        if ((int)k[i] == '^' && k[i + 1] == 'z') { goto end; }
    }

end:

    return 0;
}
*/

/*(8)
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str(string x, int y);
    string n;
    int m, k = 0;
    do
    {
        getline(cin, n);
        if (cin.eof())k = 1;
        m = n.size();
        string a = str(n, m);
        cout << a;
        if (k == 0)cout << endl;
    } while (k == 0);

    return 0;
}

string str(string x, int y)
{
    string z;
    int i = 0;
    while (i < y)
    {
        if ((int)x[i] == 92)
        {
            i++;
            if (x[i] == 'n') { z += "\n"; }
            if (x[i] == 't') { z += "\t"; }
            if (x[i] == '?') { z += "\?"; }
            if ((int)x[i] == 39) { z += "\'"; }
            if (x[i] == '"') { z += "\""; }
            if ((int)x[i] == 92) { z += "\\"; }
            if (x[i] == 'a') { z += "\a"; }
            if (x[i] == 'b') { z += "\b"; }
            if (x[i] == 'f') { z += "\f"; }
            if (x[i] == 'v') { z += "\v"; }
            if (x[i] == 'r') { z += "\r"; }
        }
        else z += x[i];
        i++;
    }
    return z;
}
*/

/*(9)错
#include<iostream>
#include<cstdint>
#include<chrono>
#include<thread>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    int64_t num = 0, x = pow(2, 12), y = pow(2, 22);
    int n, m, b, i = 0, h = 0;
    int arr[5];
    arr[0] = 1024;
    cin >> n >> m;
    num += n * x;
    num += m * y;
    string a;
    while (1)
    {
        cin >> a >> b;
        for (int k = 0; k <= i; k++)
        {
            if (arr[k] == b)
            {
                num++;
                for (int j = 0; j <= i; j++)
                {
                    arr[j] = 1024;
                }
                i = 0;
            }
        }
        if (a == "next")
        {
            if (h != 0) { cout << endl; }
            cout << b * x + m * y + num % x;
        }
        if (a == "sync")
        {
            m = b;
            num = (b + num / y) * y;
            num = (num / x) * x;
            cout << endl << "ok";
            arr[i] = 1024;
        }
        i++;
        arr[i] = b;
        if (cin.peek() == istream::traits_type::eof()) { break; }
        h++;
    }

    return 0;
}
*/

#include<iostream>
using namespace std;
int main()
{
    int x, y = 1;
    cin >> x;
    for (int i = 1; i <= 3; i++)
    {
        y = (y + 1) * 100 / (100 - x);
    }

    cout << "The monkey taken " << y << " peaches at the first day." << endl;

    return 0;
}
