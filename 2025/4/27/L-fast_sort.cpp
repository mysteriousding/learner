/*
快速排序

题目描述
本题为代码补全填空题，请将题目中给出的源代码补全，并复制到右侧代码框中，选择对应的编译语言（C/Java）后进行提交。
若题目中给出的源代码语言不唯一，则只需选择其一进行补全提交即可。
复制后需将源代码中填空部分的下划线删掉，填上你的答案。提交后若未能通过，除考虑填空部分出错外，还需注意是否因在复制后有改动非填空部分产生错误。

以下代码可以从数组 a[ ] 中找出第 k 小的元素。

它使用了类似快速排序中的分治算法，期望时间复杂度是 O(N)的。

请仔细阅读分析源码，填写划线部分缺失的内容。

源代码
C

#include <stdio.h>

int quick_select(int a[], int l, int r, int k) {
    int p = rand() % (r - l + 1) + l;
    int x = a[p];
    {int t = a[p]; a[p] = a[r]; a[r] = t;}
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[i] < x) i++;
        if(i < j) {
            a[j] = a[i];
            j--;
        }
        while(i < j && a[j] > x) j--;
        if(i < j) {
            a[i] = a[j];
            i++;
        }
    }
    a[i] = x;
    p = i;
    if(i - l + 1 == k) return a[i];
    if(i - l + 1 < k) return quick_select( _____________________________ ); //填空
    else return quick_select(a, l, i - 1, k);
}

int main()
{
    int a[100];
    int n;
    scanf("%d %d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("%d\n", quick_select(a, 0, n-1, 5));
    return 0;
}

Java


import java.util.Scanner;
import java.util.Random;
public class Main{
    public static int quickSelect(int a[], int l, int r, int k) {
        Random rand = new Random();
        int p = rand.nextInt(r - l + 1) + l;
        int x = a[p];
        int tmp = a[p]; a[p] = a[r]; a[r] = tmp;
        int i = l, j = r;
        while(i < j) {
                    while(i < j && a[i] < x) i++;
                    if(i < j) {
                            a[j] = a[i];
                            j--;
                    }
                    while(i < j && a[j] > x) j--;
                    if(i < j) {
                            a[i] = a[j];
                            i++;
                    }
            }
            a[i] = x;
            p = i;
            if(i - l + 1 == k) return a[i];
            if(i - l + 1 < k) return quickSelect( _________________________________ ); //填空
            else return quickSelect(a, l, i - 1, k);
    }
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int a[]=new int[110];
        for(int i=0;i<n;i++)
        {
          a[i]=scan.nextInt();
        }
        System.out.println(quickSelect(a, 0, n-1, 5));
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
