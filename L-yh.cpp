/*
杨辉三角

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

杨辉三角也叫帕斯卡三角，在很多数量关系中可以看到，十分重要。

第0行：           1
第1行：          1 1
第2行：         1 2 1
第3行：        1 3 3 1
第4行：       1 4 6 4 1
....

两边的元素都是1， 中间的元素是左上角的元素与右上角的元素和。

我们约定，行号，列号都从 0 计数。
所以： 第 6 行的第 2 个元素是 15，第 3 个元素是 20。

直观地看，需要开辟一个二维数组，其实一维数组也可以胜任。 
如下程序就是用一维数组“腾挪”的解法。

请仔细分析源码，填写划线部分缺少的内容。

源代码
C

#include <stdio.h>

// 杨辉三角的第row行，第col列
long long f(int row, int col){
    if(row<2) return 1;
    if(col==0) return 1;
    if(col==row) return 1;

    long long a[1024];
    a[0]=1;
    a[1]=1;
    int p = 2;
    int q;

    while(p<=row){
        a[p] = 1;
        for(_________________) a[q] = a[q] + a[q-1]; //填空
        p++;
    }

    return a[col];
}

int main()
{
    printf("%d\n", f(6,2));
    printf("%d\n", f(6,3));
    printf("%lld\n", f(40,20));
    return 0;
}

Java

import java.util.Scanner;
public class Main
{
    // 杨辉三角形的第row行第col列
    static long f(int row, int col){
        if(row<2) return 1;
        if(col==0) return 1;
        if(col==row) return 1;

        long[] a = new long[row+1];
        a[0]=1;
        a[1]=1;

        int p = 2;

        while(p<=row){
            a[p] = 1;
            for( _________________ ) a[q] = a[q] + a[q-1];
            p++;
        }

        return a[col];
    }

    public static void main(String[] args){
        System.out.println(f(6,2));
        System.out.println(f(6,3));
        System.out.println(f(40,20));

    }
}
*/
#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    return 0;
}
