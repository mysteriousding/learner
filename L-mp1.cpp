/*
MP3 储存【蓝桥杯填空题示例题目】

题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

如果一个 MP3 文件占用磁盘的大小是 4MB，小蓝的硬盘还剩下 100GB 的空间，请问他还可以放多少个这样的 MP3 文件？

正确解法
本题正确答案为 25600，只需要在代码中使用输出语句输出即可，各语言示例如下：

C

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  printf("25600");
  return 0;
}

C++

#include <iostream>
using namespace std;
int main()
{
  cout<<25600<<endl;
return 0;
}

Java

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println(25600);
        scan.close();
    }
}

Python

import os
import sys
print(25600)
*/
#include <iostream>
using namespace std;
int main()
{
    cout << 1024 / 4 * 100 << endl;

    return 0;
}