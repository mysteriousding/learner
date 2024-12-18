/*
问题描述
话说林黛玉闲来无事，打算在潇湘馆摆个茶局，邀上宝钗、探春她们一起品茗赏花。黛玉素来讲究，用的茶杯也各有不同，大的小的，高的矮的，煞是好看。
这不，她从柜子里拿出了N 只茶杯，这N 只茶杯的容量分别是C1,C2,…,CN 。为了泡茶，黛玉还特意准备了一个容量为M 的茶壶。

天气炎热，姐妹们都想着多喝点，所以至少得斟满K 杯茶才够大家喝。可是这茶壶来回取水太麻烦了，黛玉想尽量少跑几趟。

对此，请你帮黛玉算算，她最少需要用茶壶取多少次水，才能斟满至少K 杯茶呢？

输入描述
第一行包含三个整数N、M 和K（ 1≤K≤N≤10^3 ，1≤M≤10^3 ），分别表示茶杯的数量、茶壶的容量以及黛玉想要斟满的茶杯数量。

第二行包含
N 个整数C1,C2,…,CN ​（1≤Ci≤10^3 ），表示每个茶杯的容量。

输出描述
输出一个整数，表示黛玉最少需要用茶壶取水的次数。

样例输入
2 3 1
5 7
copy
样例输出
2
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int h, H;
    for (int i = 0; i < n - 1; i++)
    {
        h = i; H = arr[i];
        for (int j = i; j < n; j++)
            if (arr[j] < H) { h = j; H = arr[j]; }
        arr[h] = arr[i];
        arr[i] = H;
    }
    int sum = 0;
    for (int j = 0; j < k; j++)
        sum += arr[j];
    cout << sum / m + ((sum % m == 0) ? 0 : 1) << endl;

    return 0;
}