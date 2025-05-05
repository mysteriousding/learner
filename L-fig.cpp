/*
取位数

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

求1个整数的第k位数字有很多种方法。 
以下的方法就是一种。

请仔细分析源码，填写划线部分缺少的内容。

源代码
C

#include <stdio.h>
// 求x用10进制表示时的数位长度
int len(int x){
    if(x<10) return 1;
    return len(x/10)+1;
}

// 取x的第k位数字
int f(int x, int k){
    if(len(x)-k==0) return x%10;
    return _____________________;  //填空
}

int main()
{
    int x = 23574;
    printf("%d\n", f(x,3));
    printf("%d\n", f(893275,2));
}

Java

import java.util.*;
public class Main
{
    static int len(int x){
        if(x<10) return 1;
        return len(x/10)+1;
    }

    // 取x的第k位数字
    static int f(int x, int k){
        if(len(x)-k==0) return x%10;
        return ______________________;  //填空
    }

    public static void main(String[] args)
    {
        int x = 23513;
        //System.out.println(len(x));
        System.out.println(f(x,3));
        System.out.println(f(893275,2));
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
