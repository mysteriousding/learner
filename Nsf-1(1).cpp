#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a, b, c, d;
    string n, m = "", h = "0aA";
    cin >> a >> b >> c;
    cin.ignore();
    getline(cin, n, '\n');
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '-' && (n[i + 1] > n[i - 1] && n[i + 1] - n[i - 1] < 26||a==3))
        {
            if (a == 3)
                for (int j = n[i - 1] + 1; j < n[i + 1]; j++)
                    for (int l = 0; l < b; l++)
                        m += '*';
            else
            {
                d = n[i + 1] <= '9' ? h[a] : n[i + 1] < 'a' ? 'A' : 'a';

                if (c == 1)
                    for (int j = n[i - 1] + 1; j < n[i + 1]; j++)
                        for (int l = 0; l < b; l++)
                            m += char(j - d + h[a]);
                else
                    for (int j = n[i + 1] - 1; j > n[i - 1]; j--)
                        for (int l = 0; l < b; l++)
                            m += char(j - d + h[a]);
            }
        }
        else m += n[i];
    cout << m << endl;

    return 0;

}

