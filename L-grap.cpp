/*
打印图形

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。
提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

如下的程序会在控制台绘制分形图（就是整体与局部自相似的图形）。

当 n=1,2,3 的时候，输出如下： 请仔细分析程序，并填写划线部分缺少的代码。

n=1 时：

 o
ooo
 o

n=2 时：

    o
   ooo
    o
 o  o  o
ooooooooo
 o  o  o
    o
   ooo
    o

n=3时：

             o
            ooo
             o
          o  o  o
         ooooooooo
          o  o  o
             o
            ooo
             o
    o        o        o
   ooo      ooo      ooo
    o        o        o
 o  o  o  o  o  o  o  o  o
ooooooooooooooooooooooooooo
 o  o  o  o  o  o  o  o  o
    o        o        o
   ooo      ooo      ooo
    o        o        o
             o
            ooo
             o
          o  o  o
         ooooooooo
          o  o  o
             o
            ooo
             o

源代码
C

#include <stdio.h>
#include <stdlib.h>

void show(char* buf, int w){
    int i,j;
    for(i=0; i<w; i++){
        for(j=0; j<w; j++){
            printf("%c", buf[i*w+j]==0? ' ' : 'o');
        }
        printf("\n");
    }
}

void draw(char* buf, int w, int x, int y, int size){
    if(size==1){
        buf[y*w+x] = 1;
        return;
    }

    int n = _________________________ ; //填空
    draw(buf, w, x, y, n);
    draw(buf, w, x-n, y ,n);
    draw(buf, w, x+n, y ,n);
    draw(buf, w, x, y-n ,n);
    draw(buf, w, x, y+n ,n);
}

int main()
{
    int N ;
        scanf("%d",&N);
    int t = 1;
    int i;
    for(i=0; i<N; i++) t *= 3;

    char* buf = (char*)malloc(t*t);
    for(i=0; i<t*t; i++) buf[i] = 0;

    draw(buf, t, t/2, t/2, t);
    show(buf, t);
    free(buf);

    return 0;
}

Java

import java.util.Scanner;

public class Main
{
    static void show(byte[][] buf){
        for(int i=0; i<buf.length; i++){
            for(int j=0; j<buf[i].length; j++){
                System.out.print(buf[i][j]==0? ' ' : 'o');
            }
            System.out.println();
        }
    }

    static void draw(byte[][] buf, int x, int y, int size){
        if(size==1){
            buf[y][x] = 1;
            return;
        }

        int n = ________________________ ;  // 填空
        draw(buf, x, y, n);
        draw(buf, x-n, y ,n);
        draw(buf, x+n, y ,n);
        draw(buf, x, y-n ,n);
        draw(buf, x, y+n ,n);
    }

    public static void main(String[] args){
                Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int t = 1;
        for(int i=0; i<N; i++) t *= 3;

        byte[][] buf = new byte[t][t];
        draw(buf, t/2, t/2, t);
        show(buf);
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
