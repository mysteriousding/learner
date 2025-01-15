/*
正则问题

题目描述
考虑一种简单的正则表达式：

只由 x ( ) | 组成的正则表达式。

小明想求出这个正则表达式能接受的最长字符串的长度。

例如 ((xx|xxx)x|(x|xx))xx 能接受的最长字符串是： xxxxxx，长度是 6。

输入描述
一个由 x()| 组成的正则表达式。输入长度不超过 100，保证合法。

输出描述
这个正则表达式能接受的最长字符串的长度。

输入输出样例
示例
输入

((xx|xxx)x|(x|xx))xx

输出

6
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int max(int a,int b)
{
  return (a>b)?a:b;
}

int dg(string x,int a,int b)
{
  vector<vector<int>>huo;
  vector<vector<int>>h;
  h.push_back({a-1,b,0});
  int kh=0;
  int shu=0;
  int j=0,k=1,p=0;
  for(int i=a;i<b;i++)
  {
    switch(x[i])
    {
      case '(':kh++;
      h.push_back({i,0,kh});
      k++;
      break;

      case ')':kh--;
      for(int l=0;l<k;l++)
      if(h[l][2]==kh+1&&h[l][1]==0){p=l;break;}
      h[p][1]=i; 
      if(!kh)h[0][1]=i;
      if(j)shu=0;
      break;

      case '|':
      huo.push_back({kh, i});
      j++;
      break;

      default :shu++;break;
    }
  }
  if(j==0)return shu;
  int min=1000,d;
  for(int i=0;i<j;i++)
  if(min>huo[i][0])min=huo[i][0],d=i;
  return max(dg(x,h[d][0]+1,huo[d][1]),dg(x,huo[d][1]+1,h[d][1]))+shu; 
}

int main()
{
  int n;
  string m;
  getline(cin,m);
  n=dg(m,0,m.size());
  cout<<n<<endl;
  
  return 0;
}
