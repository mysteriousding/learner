/*
4、众数问题
★问题描述：给定含有n个元素的多重集合S，每个元素在S中出现的次数称为该元素的重数。
多重集S中重数最大的元素称为众数。
例如，S={1,2,2,2,3,5}。
多重集S的众数是2，其重数为3。

★编程任务：对于给定的由n个自然数组成的多重集S，编程计算S的众数及其重数。
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, num, m = 0;           // m 用于存储最大的出现次数
    unordered_map<int, int> arr; // 用于存储每个元素的出现次数
    vector<int> brr;             // 存储所有众数
    cout << "请输入元素个数: ";
    cin >> n;
    cout << "请输入 " << n << " 个元素:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        cin >> num;
        arr[num]++; // 增加元素出现次数
    }
    
    // 遍历映射，找到最大的出现次数
    for (auto& k : arr) 
        if (k.second > m) 
        {
            m = k.second;
            brr.clear();            // 清空brr，因为找到了更大的出现次数
            brr.push_back(k.first); // 添加新的众数
        }
        else if (k.second == m) 
            brr.push_back(k.first); // 添加另一个众数
    
    // 输出结果
    if (brr.empty())
        cout << "没有众数" << endl;
    else 
    {
        cout << "众数为: ";
        for (int v : brr) 
            cout << v << " ";

        cout << "重数为: " << m << endl;
    }

    return 0;

}

