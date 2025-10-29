/*
3、快速排序。
*/
#include<iostream> 
using namespace std; 
#define N 1000 

// 快速排序函数
void sort(int a[], int b, int c)
{
    if (b >= c) return; // 如果子数组只有一个元素或为空，直接返回
    int i = b, j = c;   // 初始化左右指针
    a[0] = a[i];        // 将基准值暂存到数组的第一个位置（哨兵）
    while (i < j)       // 当左右指针未相遇时
    {
        // 从右向左找第一个小于基准值的元素
        while (i < j && a[0] <= a[j])
            j--;
        a[i] = a[j];    // 将该元素移到左边
        // 从左向右找第一个大于基准值的元素
        while (i < j && a[i] <= a[0])
            i++;
        a[j] = a[i];    // 将该元素移到右边
    }
    a[i] = a[0];        // 将基准值放到最终位置
    // 递归对基准值左边和右边的子数组进行快速排序
    sort(a, b, j - 1);
    sort(a, i + 1, c);
}

int main()
{
    int n, a[N];   // 定义数组和数据个数
    cout << "请输入数据个数:" << endl;
    cin >> n;      // 输入数据个数
    cout << "请依次输入数据:" << endl;
    for (int i = 1; i <= n; i++) // 输入数据
        cin >> a[i];
    sort(a, 1, n); // 调用快速排序函数对数组进行排序
    cout << "排序结果为:" << endl;
    for (int i = 1; i <= n; i++) // 输出排序后的结果
        cout << a[i] << " ";

    return 0;

}


