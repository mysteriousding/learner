////最大计算20的阶乘
//#include<iostream>
 //using namespace std;
 //long long Fact(int  n)
 //{
 //    int  i;
 //    long long result = 1;
 //    for (i=2; i<=n; i++)
 //        result *= i;
 //    return result;
 //}
 //int main()
 //{
 //    int n;
 //    cin>>n;
 //    for(int i=1;i<=n;i++)
 //        cout<<i<<"! = "<<Fact(i)<<endl;

 //    return 0;
 //}



////最大计算68的阶乘
//#include<iostream>
//#include<string>
//using namespace std;
//string sum = "1xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
//void Fact(int n)
//{
//    string m[5];
//
//        for (int i = 0; i < 5; i++)
//            m[i] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
//        int r = 0;
//        while (n != 0)
//        {
//            int d = n % 10;
//            n /= 10;
//
//            int j = 0, k = 0;
//            while (j < r)
//                m[r][j++] = '0';
//            j = 0;
//            while (sum[j] != 'x' || k != 0) 
//            {
//                m[r][j + r] = ((sum[j] - ((sum[j] == 'x') ? 'x' : '0')) * d + k) % 10 + '0'; 
//                k = ((sum[j] - ((sum[j] == 'x') ? 'x' : '0')) * d + k) / 10; 
//                j++;
//            }
//            r++;
//        }
//
//        for (int i = 0; i < r; i++)
//        {
//            int j = 0, k = 0;
//            while (m[4][j] != 'x' || m[i][j] != 'x' || k != 0)
//            {
//                int cw = ((m[4][j] - ((m[4][j] == 'x') ? 'x' : '0')) + (m[i][j] - ((m[i][j] == 'x') ? 'x' : '0')) + k);
//                m[4][j] = cw % 10 + '0';
//                k = cw / 10;
//                j++;
//            }
//        }
//        sum = m[4];
//}
//int main()
//{
//    int n, j;
//    string m0;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cout << i << "! = ";
//        Fact(i);
//        j = 0;
//        m0 = "";
//        while (sum[j] != 'x')
//            m0 = sum[j++] + m0;
//        cout << m0 << endl;
//    }
//
//    return 0;
//}



#include<iostream>
using namespace std;
int Fact(int *arr,int  n)
{
    int j, temp, mod = 0;
    for (j = 1; j < 10000; j++)
    {
        temp = arr[j] * n + mod;    
        mod = temp / 10;               
        arr[j] = temp % 10;            
    }
    for (j = 9999; j > 0; j--)
        if (arr[j] != 0)
            return j;
}
 int main()
 {
     int n, j;
     cin >> n;
     int* arr = new int[10000] { 1, 1 }; 
     for (int k = 1; k <= n; k++)
     {
         cout << k << "! = ";
         j = Fact(arr, k);
         while (j)
             cout << arr[j--];

         cout << endl;
     }
     delete [] arr;

     return 0;
 }
