/*
2、用贪心算法解决多机调度问题。
设有n个独立的作业{1, 2, …, n}，由m台相同的机器{M1, M2, …, Mm}进行加工处理，作业i所需的处理时间为ti（1≤i≤n），每个作业均可在任何一台机器上加工处理，但不可间断、拆分。
多机调度问题要求给出一种作业调度方案，使所给的n个作业在尽可能短的时间内由m台机器加工处理完成。
*/
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
bool pd(int a, int b) 
{
    return a > b;   // 降序
}
int main() 
{
    int n, m,h;
    cin >> n >> m;              // 作业数、机器数
    vector<int> t(n);           // 作业时间
    vector<int> a(m, 0);        // 每台机器总时间
    for (int i = 0; i < n; i++) 
        cin >> t[i];

    sort(t.begin(), t.end(),pd);
    for (int i = 0; i < n; i++) 
    {
         h = 0;              // 找最闲的机器
        for (int j = 1; j < m; j++)
            if (a[j] < a[h])
                h = j;

        a[h] += t[i];        // 当前作业给谁
    }

    h = a[0];
    for (int j = 1; j < m; j++)
        if (a[j] > h) 
            h = a[j];
    cout << "最短完成时间：" << h << endl;

    return 0;

}

