/*
【编程大题】花朵数
一个 N 位的十进制正整数，如果它的每个位上的数字的 N 次方的和等于这个数本身，
则称其为花朵数。
例如：当 N=3 时，153 就满足条件，因为 1^3 + 5^3 + 3^3 = 153，这样的数字也被称为
水仙花数（其中，“^”表示乘方，5^3 表示 5 的 3 次方，也就是立方）。
当 N=4 时，1634 满足条件，因为 1^4 + 6^4 + 3^4 + 4^4 = 1634。
当 N=5 时，92727 满足条件。
实际上，对 N 的每个取值，可能有多个数字满足条件。
程序的任务是：求 N=21 时，所有满足条件的花朵数。注意：这个整数有 21 位，它的
各个位数字的 21 次方之和正好等于这个数本身。
如果满足条件的数字不只有一个，请从小到大输出所有符合条件的数字，每个数字占一
行。因为这个数字很大，请注意解法时间上的可行性。要求程序在 1 分钟内运行完毕。
【程序运行参考结果】
128468643043731391252
449177399146038697307
*/
//#include<iostream>
//#include<iomanip>
//#include<string>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	string s;
//	double arr[10];
//	for (int i = 0; i < 10; i++)
//		arr[i] = pow(i, 21);
//	cout << fixed << setprecision(0);
//
//	for (int i = 0; i < 10; i++)
//		cout << arr[i] << endl;
//	s=to_string(arr[9]);
//
//	cout << s << endl;
//
//
//	return 0;
//}

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool v = 0;

// 打印当前分配方案
void shuchu(const vector<int>& Arr,double arr[])
{
    string s;
    double sum = 0;
    //cout << fixed << setprecision(0);
    for (size_t i = 0; i < Arr.size(); ++i)
        sum += arr[i] * Arr[i]; 
    s = to_string(sum);
    if (s.length() != 21+7) return;
    vector<int>h(Arr.size(),0);
    int i = 0;
    for (; s[i] != '.'; i++)
        h[s[i] - '0']++;
    for (; s[i] != '\0'; i++)
        s[i] = '\0';
    bool u = 1;
    for ( i = 0; i < Arr.size(); ++i)
        if (h[i] != Arr[i])
        {
            u = 0;
            break;
        }

    if (u)
    {
        v = 1;
        cout << s << endl;
    }




  /*  for (size_t i = 0; i < Arr.size(); ++i) {
        std::cout << Arr[i];
        if (i < Arr.size() - 1) {
            std::cout << "-";
        }
    }
    cout << endl << endl;*/
}

// 生成所有组合
void digui(int ci, int wei, vector<int>& Arr, int index,double arr[])
{
    if (index == wei - 1)
    {
        Arr[index] = ci;
        shuchu(Arr,arr);
        return;
    }
    for (int i = 0; i <= ci; ++i) 
    {
        Arr[index] = i;
        digui(ci - i, wei, Arr, index + 1, arr);
    }
}

int main() {
    int ci = 21;
    int wei = 10;
    vector<int> Arr(wei, 0);
    double arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = pow(i, ci);
    digui(ci, wei, Arr, 0, arr);

    cout << v << endl;

    return 0;
}
//28116440335967