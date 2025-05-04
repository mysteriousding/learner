/*
字母组串

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

由 A,B,C 这3个字母就可以组成许多串。
比如："A","AB","ABC","ABA","AACBB" ....

现在，小明正在思考一个问题： 如果每个字母的个数有限定，能组成多少个已知长度的串呢？

他请好朋友来帮忙，很快得到了代码， 解决方案超级简单，然而最重要的部分却语焉不详。

请仔细分析源码，填写划线部分缺少的内容。

源代码
C

#include <stdio.h>

// a个A，b个B，c个C 字母，能组成多少个不同的长度为n的串。
int f(int a, int b, int c, int n)
{
    if(a<0 || b<0 || c<0) return 0;
    if(n==0) return 1;

    return ______________________________________ ;  // 填空
}

int main()
{
    printf("%d\n", f(1,1,1,2));
    printf("%d\n", f(1,2,3,3));
    return 0;
}

Java

import java.util.*;
public class Main
{
    // a个A，b个B，c个C 字母，能组成多少个不同的长度为n的串。
    static int f(int a, int b, int c, int n)
    {
        if(a<0 || b<0 || c<0) return 0;
        if(n==0) return 1;

        return ________________________________;  //填空
    }

    public static void main(String[] args)
    {
        System.out.println(f(1,1,1,2));
        System.out.println(f(1,2,3,3));
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