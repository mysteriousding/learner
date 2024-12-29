#pragma once
#include <algorithm>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <stack>
using namespace std;

//dx最大65！
static int dx = 1;

// 迷宫格子状态
enum CellState：int { PATH = 0, WALL, FLAG };

// 迷宫格二维点结构
struct Point2
{
    int x, y;
    Point2(int _x, int _y) :x(_x), y(_y) {}
};

// 迷宫生成接口--递归版
void DFS_generator(int _x, int _y, std::vector<std::vector<int>>& maze)
{
    // 定义方向容器
    std::vector<std::vector<int>> dir{ {1,0},{-1,0},{0,1},{0,-1} };
    // 随机打乱方向
    std::random_shuffle(dir.begin(), dir.end());
    // 递归生成迷宫
    maze[_x][_y] = PATH;
    for (int i = 0; i < 4; ++i)
    {
        if (_x + 2 * dir[i][0] >= 1 && _x + 2 * dir[i][0] <= dx - 2 && _y + 2 * dir[i][1] >= 1 && _y + 2 * dir[i][1] <= dx - 2
            && maze[_x + 2 * dir[i][0]][_y + 2 * dir[i][1]] == WALL)
        {
            maze[_x + dir[i][0]][_y + dir[i][1]] = PATH;
            DFS_generator(_x + 2 * dir[i][0], _y + 2 * dir[i][1], maze);
        }
    }
}

// 迷宫生成接口--迭代版
void DFS_iterative_generator(std::vector<std::vector<int>>& maze)
{
    // 定义栈容器
    std::stack<Point2> sp;
    // 定义方向容器
    std::vector<std::vector<int>> dir{ {1,0},{-1,0},{0,1},{0,-1} };
    // 要求参数为奇数
    Point2 temp((rand() % (dx - 2) + 1) | 1, (rand() % (dx - 2) + 1) | 1);
    sp.push(temp);
    // 后续迭代生成迷宫，并绘制
    while (!sp.empty())
    {
        if (maze[temp.x][temp.y] != PATH)
            maze[temp.x][temp.y] = PATH;
        // 随机打乱方向
        std::random_shuffle(dir.begin(), dir.end());
        int i = 0;
        for (; i < 4; ++i)
        {
            if (temp.x + 2 * dir[i][0] >= 1 && temp.x + 2 * dir[i][0] <= dx - 2 && temp.y + 2 * dir[i][1] >= 1 && temp.y + 2 * dir[i][1] <= dx - 2
                && maze[temp.x + 2 * dir[i][0]][temp.y + 2 * dir[i][1]] == WALL)
            {
                maze[temp.x + dir[i][0]][temp.y + dir[i][1]] = PATH;
                temp.x += 2 * dir[i][0];
                temp.y += 2 * dir[i][1];
                sp.push(temp);
                break;
            }
        }
        if (i == 4) sp.pop();
        if (!sp.empty()) temp = sp.top();
    }
}

class tu
{
public:
    static bool live;

    tu();
    void huizhi();
    void kunzhi();
    void xuigao(int x, int y, int z);
private:
    vector<vector<char>>T;
    int x;
    int y;
};

bool tu::live = 0;

tu::tu() : x(0), y(1), T(vector<vector<char>>(dx + 2, vector<char>(dx * 2 + 4)))
{
    dx += 2;
    live = 1;

    // 入口出口
    Point2 start(0, 1);
    Point2 end(dx - 1, dx - 2);

    // 二维迷宫容器
    std::vector<std::vector<int>> maze;

    // 初始化迷宫
    for (int i = 0; i < dx; ++i) maze.push_back(std::vector<int>());
    for (int i = 0; i < dx; ++i)
        for (int j = 0; j < dx; ++j)
            maze[i].push_back(WALL);
    maze[start.x][start.y] = maze[end.x][end.y] = PATH;

    // 生成迷宫（迭代和非迭代二选一生成）
    DFS_generator((rand() % (dx - 2) + 1) | 1, (rand() % (dx - 2) + 1) | 1, maze);
    // DFS_iterative_generator(maze);

    for (int i = 0; i < dx; ++i)
        for (int j = 0; j < dx * 2; ++j)
            T[i][j] = (maze[j / 2][i]) ? '#' : ' ';

    T[1][0] = 'O';
    T[dx - 2][dx * 2 - 1] = 'X';
}

void tu::huizhi()
{
    // 打印迷宫
    for (int i = 0; i < dx; ++i)
    {
        for (int j = 0; j < dx * 2; ++j)
            cout << T[i][j];
        cout << endl;
    }
}

void tu::kunzhi()
{
    this->xuigao(y, x, 0);
    int X = x, Y = y;
    switch (_getch())
    {
    case 'a':x--; break;
    case 'd':x++; break;
    case 'w':y--; break;
    case 's':y++; break;
    default:return;
    }

    if (T[y][x] == '#')y = Y, x = X;

    this->xuigao(y, x, 1);

    if (y == dx - 2 && x == dx * 2 - 1)tu::live = 0;

}

void tu::xuigao(int y, int x, int z)
{
    T[y][x] = (z) ? 'O' : ' ';
}