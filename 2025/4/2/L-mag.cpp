﻿/*
神奇的幻方

题目描述
幻方是一种很神奇的 N∗N 矩阵：它由数字 1,2,3,......,N∗N 构成，且每行、每列及两条对角线上的数字之和都相同。

当 N 为奇数时，我们可以通过以下方法构建一个幻方：

首先将 1 写在第一行的中间。 之后，按如下方式从小到大依次填写每个数 K(K=2,3,...,N∗N)：

若 (K−1) 在第一行但不在最后一列，则将 𝐾 填在最后一行，(K−1) 所在列的右一列；
若 (K−1) 在最后一列但不在第一行，则将 𝐾 填在第一列，(K−1) 所在行的上一行；
若 (K−1) 在第一行最后一列，则将 𝐾 填在 (K−1) 的正下方；
若 (K−1) 既不在第一行，也不在最后一列，如果 (K−1) 的右上方还未填数， 则将 K 填在 (K−1)的右上方，否则将 𝐾 填在 (K−1)的正下方。

现给定 N，请按上述方法构造 N∗N 的幻方。

输入描述
输入一行，包含一个整数 N，即幻方的大小，1≤N≤39 且 N 为奇数。

输出描述
输出包含 N 行，每行 N 个整数，即按上述方法构造出的 N∗N 的幻方。相邻两个整数之间用单个空格隔开。

输入输出样例
示例

输入
3

输出
8 1 6
3 5 7
4 9 2
*/
