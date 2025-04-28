/*
书号验证

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

2004年起，国际 ISBN 中心出版了《13位国际标准书号指南》。

原有 10 位书号前加 978 作为商品分类标识；校验规则也改变。

校验位的加权算法与 10 位 ISBN 的算法不同，具体算法是：
用 1 分别乘 ISBN 的前 12 位中的奇数位（从左边开始数起），用 3 乘以偶数位，乘积之和以 10 为模，10 与模值的差值再对 10 取模（即取个位的数字）即可得到校验位的值，其值范围应该为 0~9。

下面的程序实现了该算法，请仔细阅读源码，填写缺失的部分。

验证成功返回 1，否则返回 0。

源代码
C

#include <stdio.h>

int f(const char* s)
{
    int k=1;
    int sum = 0;
    int i;
    for(i=0; s[i]!='\0'; i++){
        char c = s[i];
        if(c=='-' || c==' ') continue;
        sum += _________________________________________ ;  //填空
        k++;
        if(k>12) break;
    }

    while(s[i]!='\0') i++;

    return (s[i-1]-'0') == (10-sum % 10)%10;
}

int main()
{
    char s[105];
    scanf("%s",s);
    if(f(s)) printf("true");
    else printf("false");
    return 0;
}

Java

import java.util.Scanner;
public class Main
{
    static boolean f(String s){
        int k=1;
        int sum = 0;
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c=='-' || c==' ') continue;
            sum += ______________________________;  //填空
            k++;
            if(k>12) break;
        }

        return s.charAt(s.length()-1)-'0' == (10-sum % 10)%10;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        System.out.println(f(a));
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