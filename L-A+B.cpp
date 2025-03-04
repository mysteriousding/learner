/*
A+B 问题【OJ 示例题目】

题目描述
欢迎开启算法 OJ 题的大门，本题为经典的 A+B 入门题，我们会以此题为示例介绍蓝桥云课 OJ 系统的正确使用方法。

问题描述

输入两个正整数 A,B，请你计算 A+B，并输出。

根据题目描述，你需要做以下事情：

编写一个程序，使用标准输入来输入两个整数 A 和 B，然后把 A+B 的结果使用标准输出来输出。
你可以滚动到本页面下方查看题目的示例输入和输出，这将极大地帮助你理解和完成题目。

那么，什么是标准输入和输出呢？

C 语言中的标准输入输出方法为 scanf() 和 printf()；
C++ 中的标准输入输出方法为 cin 和 cout，或者使用 scanf() 和 printf()；
Java 中的标准输入输出流为 System.in 和 System.out；
Python 中的标准输入输出方法为 input()和 print()；
特别地，在编写程序时，不要输出任何多余的信息，所输出的答案要与样例输出的形式一致。
例如以下 C 语言程序则输出了多余信息，不能通过测试：

#include<stdio.h>
int main()
{
int a,b;
printf("输入两个正整数:\n");
scanf("%d %d",&a,&b);
printf("a + b = %d\n",a + b);
return 0;
}

正确的写法为：

#include<stdio.h>
int main()
{
int a,b;
scanf("%d %d",&a,&b);
printf("%d\n",a + b);
return 0;
}


本题其他语言的正确示例：

C++ 实现：

#include<iostream>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
cout<<a+b<<endl;
}


Java 实现：

import java.util.Scanner;
public class Main{
public static void main(String[] args){
Scanner input = new Scanner(System.in);
int a = input.nextInt();
int b = input.nextInt();
System.out.println(a+b);
input.close();
}
}


Python 实现：

import os
s=input().split(' ')
a=int(s[0])
b=int(s[1])
print(a+b)


注意：

C/C++语言中，main() 函数最后的 return 0; 语句不可缺少。
Java 语言中无需 package ，类名必须为 Main ，不可修改。
main() 函数中 xxx.close() ; 语句不可缺少。
后台测试会忽略行末空格及换行。
代码提交后，可能会得到以下结果：

PASS(通过)：你的程序输出的答案与测试样例答案完全一致，但并不保证你的算法最优。
答案错误：你的程序输出的结果与测试答案不一致，出现错误（通过样例数据并不代表程序正确，因为后台会有大量的测试数据，只有通过了后台全部数据才可以通过本题）。
超过时间限制：你的程序超过了运行的规定时间，时间复杂度太高或者陷入了死循环。
运行时错误：你的程序发生了运行时错误，可能存在除 0，内存大小或访问违规等运行时问题。
编译错误：你的程序不能编译。
输入描述
输入一行，为用空格分隔的两个正整数a,b（1≤a,b≤100 ）。

输出描述
输出一行，为 a+b 的结果。（后台测试会忽略行末空格及换行）

输入输出样例
示例

输入
1 2

输出
3
*/
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	cout << n + m << endl;

	return 0;
}