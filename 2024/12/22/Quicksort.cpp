//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//// 自定义交换函数
//void swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//// 快速排序函数
//void qs(vector<int>& arr, int s, int e)
//{
//    if (e <= s)return;
//
//    int p = s;
//    int v = arr[s];
//    int l = s;
//    int r = e;
//
//    while (l < r)
//    {
//        while (l < r && arr[r] >= v)
//        {
//            r -= 1;
//        }
//        while (l < r && arr[l] <= v)
//        {
//            l += 1;
//        }
//        if (l < r)
//        {
//            swap(arr[l], arr[r]);
//        }
//    }
//
//    swap(arr[p], arr[l]);
//
//    qs(arr, s, l - 1);
//    qs(arr, l + 1, e);
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//
//    qs(arr, 0, arr.size() - 1);
//
//    for (int num : arr)
//        cout << num << " ";
//    cout << endl;
//
//    return 0;
//}



#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>& m, int x, int y)
{
	if (x >= y)return;
	int v = m[x];
	int f = x;
	int g = y;
	int sum;
	while (f < g)
	{
		while (f < g && m[g] >= v)
			g--;
		while (f < g && m[f] <= v)
			f++;
		if (f < g)
		{
			sum = m[f]; m[f] = m[g]; m[g] = sum;
		}
	}
	sum = m[x]; m[x] = m[f]; m[f] = sum;
	sort(m, x, f - 1);
	sort(m, f + 1, y);
}
int main()
{
	int n;
	cin >> n;
	vector<int>m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i];
	sort(m, 0, n - 1);
	for (int j = 0; j < n; j++)
		cout << m[j] << " ";

	return 0; 
}
