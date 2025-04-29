/*
打印X

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

如下的程序目的是在控制台打印输出大X。 
可以控制两个参数：图形的高度，以及笔宽。

用程序中的测试数据输出效果： (如果显示有问题，可以参看下图)

高度=15, 笔宽=3

***           ***
 ***         ***
  ***       ***
   ***     ***
    ***   ***
     *** ***
      *****
       ***
      *****
     *** ***
    ***   ***
   ***     ***
  ***       ***
 ***         ***
***           ***

高度=8, 笔宽=5

*****  *****
 **********
  ********
   ******
   ******
  ********
 **********
*****  *****

请仔细分析程序流程，填写缺失的代码。

源代码
Java

import java.util.Scanner;
public class Main
{
    static void f(int h, int w){

        int a1 = 0;
        int a2 = h - 1;

        for(int k=0; k<h; k++){
            int p = Math.min(a1,a2);
            int q = Math.max(a1+w,a2+w);

            for(int i=0; i<p; i++) System.out.print(" ");

            if(q-p<w*2){
                ____________________________________________ ; //填空
            }
            else{
                for(int i=0; i<w; i++) System.out.print("*");
                for(int i=0; i<q-p-w*2; i++) System.out.print(" ");
                for(int i=0; i<w; i++) System.out.print("*");
            }
            System.out.println();
            a1++;
            a2--;
        }
    }

    public static void main(String[] args){
                                Scanner scan = new Scanner(System.in);
        int a,b;
        a=scan.nextInt();
        b=scan.nextInt();
        f(a,b);

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
