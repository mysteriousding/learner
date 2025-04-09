﻿/*
花匠

题目描述
花匠栋栋种了一排花，每株花都有自己的高度。花儿越长越大，也越来越挤。栋栋决定把这排中的一部分花移走，将剩下的留在原地，使得剩下的花能有空间长大，同时，栋栋希望剩下的花排列得比较别致。

具体而言，栋栋的花的高度可以看成一列整数
h
1
,
h
2
,
.
.
.
,
h
𝑛
h
1
​
 ,h
2
​
 ,...,h
n
​
 。设当一部分花被移走后， 剩下的花的高度依次为
𝑔
1
,
𝑔
2
,
.
.
.
,
𝑔
𝑚
g
1
​
 ,g
2
​
 ,...,g
m
​
 ，则栋栋希望下面两个条件中至少有一个满足：

条件 A：对于所有的 $𝑖，𝑔{2𝑖} > 𝑔{2𝑖−1}
，且
，且𝑔{2𝑖} > 𝑔{2𝑖+1}$；

条件 B：对于所有的 $𝑖，𝑔{2𝑖} < 𝑔{2𝑖−1}
，且
，且𝑔{2𝑖} < 𝑔{2𝑖+1}$。

注意上面两个条件在
𝑚
=
1
m=1 时同时满足，当
𝑚
>
1
m>1时最多有一个能满足。

请问，栋栋最多能将多少株花留在原地。

输入描述
输入的第一行包含一个整数
𝑛
n，表示开始时花的株数。

第二行包含
𝑛
n 个整数，依次为
h
1
,
h
2
,
.
.
.
,
h
𝑛
h
1
​
 ,h
2
​
 ,...,h
n
​
 ，表示每株花的高度。

保证
1
≤
𝑛
≤
1
0
5
，
0
≤
h
𝑖
≤
1
0
6
1≤n≤10
5
 ，0≤hi≤10
6
 ，所有的
h
𝑖
h
i
​
  随机生成，所有随机数服从某区间内的均匀分布。

输出描述
输出一行，包含一个整数
𝑚
m，表示最多能留在原地的花的株数。

输入输出样例
示例
输入

5
5 3 2 1 2
copy
输出

3
*/
