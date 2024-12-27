/*帅到没朋友

当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。本题就要求你找出那些帅到没有朋友的人。

输入格式：
输入第一行给出一个正整数N（≤100），是已知朋友圈的个数；
随后N行，每行首先给出一个正整数K（≤1000），为朋友圈中的人数，
然后列出一个朋友圈内的所有人——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；
之后给出一个正整数M（≤10000），为待查询的人数；
随后一行中列出M个待查询的ID，以空格分隔。

注意：没有朋友的人可以是根本没安装“朋友圈”，也可以是只有自己一个人在朋友圈的人。
虽然有个别自恋狂会自己把自己反复加进朋友圈，但题目保证所有K超过1的朋友圈里都至少有2个不同的人。

输出格式：
按输入的顺序输出那些帅到没朋友的人。ID间用1个空格分隔，行的首尾不得有多余空格。如果没有人太帅，则输出No one is handsome。

注意：同一个人可以被查询多次，但只输出一次。

输入样例1：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
8
55555 44444 10000 88888 22222 11111 23333 88888
输出样例1：
10000 88888 23333
输入样例2：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
4
55555 44444 22222 11111
输出样例2：
No one is handsome
*/
// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// int main()
// {
//     int n,m;
//     bool u;
//     cin>>n;
//     vector<int>n0(n);
//     vector<vector<string>>N(n,vector<string>(0));
//     for(int i=0;i<n;i++)
//     {
//         cin>>n0[i];
//         N[i].resize(n0[i]);
//         for(int j=0;j<n0[i];j++)
//             cin>>N[i][j];
//     }
//     string h;
//     cin>>m;
//     vector<string>M(m);
//     for(int i=0,j=0;i<m;)
//     {
//         u=1;
//         cin>>h;
//         for(int k=0;k<i;k++)
//             if(M[k]==h)
//             {
//                 u=0;
//                 m--;
//                 break;
//             }
//         if(u)M[i++]=h;
//     }
//     for(int k=0;k<m;k++)
//     {
//         u=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n0[i];j++)
//             {
//                 if(M[k]==N[i][j])
//                 {
//                     M[k]="-1";
//                     u=1;
//                     break;
//                 }
//             }
//             if(u)break;
//         }
//     }
//     u=1;
//     for(int j=0;j<m;j++)
//         if(M[j]!="-1")
//         {
//             if(!u)cout<<" ";
//             cout<<M[j];
//             u=0;
//         }
//     if(u)cout<<"No one is handsome"<<endl;

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int a[100000] = { 0 };

int main() {
    int n, m, k, d = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        if (k == 1 && a[d] == 0)a[d] = 1;
        for (int j = 1; j <= k; j++) {
            cin >> d;
            if (k > 1)a[d] = 2;
        }

    }
    cin >> m;
    k = 0;
    for (int i = 1; i <= m; i++) {
        cin >> d;
        if (k == 0 && a[d] <= 1) {
            a[d] = 2;
            printf("%05d", d);
            n = 0;
            k = 1;
        }
        if (k == 1 && a[d] <= 1) {
            a[d] = 2;
            printf(" %05d", d);
            n = 0;
        }
    }
    if (n != 0)cout << "No one is handsome" << endl;
    return 0;
}