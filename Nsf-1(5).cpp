#include<iostream>
using namespace std;
int main()
{
    int n, m, a, b, c, y, h, t;
    cin >> n >> m;
    a = m / 10000000;
    for (int i = n / 10000000; i <= a; i++)
    {
        b = 2 + (i > 1);
        for (int l = 0; l <= 1; l++)
        {
            c = l ? 2 : 9;
            for (int j = 0; j <= b; j++)
                for (int k = 0; k <= c; k++)
                {
                    y = i * 1000 + j * 100 + k * 10 + l;
                    h = l * 10 + k;
                    t = j * 10 + i;


                    if (y < n / 1000 || m / 1000 < y)
                        continue;
                    else if (n / 1000 == y)
                    {
                        if (h < n / 100 % 100 && t >= n % 100);
                        else if (h == n / 100 % 100 && t < n % 100);
                    }
                    else if (m % 1000 == y)
                        if (h <= m / 100 % 100 && t <= m % 100);
                        else;

                    if (n % 1000 <= y && y <= m % 1000)
                    {

                        if (h == 2)
                            if (1);
                    }
                }
        }
    }


    return 0;
}