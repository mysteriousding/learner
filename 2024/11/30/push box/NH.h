﻿#pragma once
#include<iostream>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;

char N[20][41]
{
    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
};

char k;
//int p0 = 0, p1 = 0, p2 = 0;

void QC(int x,int y)
{
    N[y][x] = ' ';
}
void HZ1(int x, int y)
{
    N[y][x] = '@';
}
void HZ2(int x, int y, bool z)
{
    if (z)
    N[y][x] = '$';
}


class MY
{
public:
    MY() { x = y = 1; }
    void XMY()
    {
        N[y][x] = ' ';
        x = rand() % (41 - 2 - 1) + 1;
        y = rand() % (20 - 2 - 1) + 1;
        N[y][x] = '@';         //★
    }
    void CZ();

//private:
    int x;
    int y;
}my;

void MY::CZ()
{
    QC(my.x, my.y);
    switch (k = _getch())
    {
    case 'w':
        my.y--;
        if (my.y < 1)my.y = 1;
        break;
    case 's':
        my.y++;
        if (my.y > 18)my.y = 18;
        break;
    case 'a':
        my.x--;
        if (my.x < 1)my.x = 1;
        break;
    case 'd':
        my.x++;
        if (my.x > 39)my.x = 39;
        break;
    }
    HZ1(my.x, my.y);
}


class door
{
public:
    door() { x = y = 1; live = 0; }
    void Xdoor()
    {
        N[y][x] = ' ';
        x = rand() % (41 - 2 - 1) + 1;
        y = rand() % (20 - 2 - 1) + 1;
        live = 1;
        N[y][x] = '0';
    }
    void HD()
    {
        if (live)
            N[y][x] = '0';
    }
    void SW() { live = 0; }
    //private:
    int x;
    int y;
    bool live;
}d[20];

bool SL(int a)
{
    for (int i = 0; i < a; i++)
        if (d[i].live == 1)
            return 0;
        
    return 1;
}



class box
{
public:
    box() { x = y = 1; live = 0; }
    void Xbox()
    {
        N[y][x] = ' ';
        x = rand() % (41 - 3 - 2) + 2;
        y = rand() % (20 - 3 - 2) + 2;
        live = 1;
        N[y][x] = '$';          //■
    }
    void YD(int a);
private:
    int x;
    int y;
    bool live;
}b[20];

void box::YD(int a)
{
    if (x == my.x && y == my.y)
        switch (k)
        {
        case 'w':
            y--;
            if (y < 1)y = 1;
            break;
        case 's':
            y++;
            if (y > 18)y = 18;
            break;
        case 'a':
            x--;
            if (x < 1)x = 1;
            break;
        case 'd':
            x++;
            if (x > 39)x = 39;
            break;
        }
    QC(x, y);
    HZ2(x, y, live);
    for (int i = 0; i < a; i++)
        if (x == d[i].x && y == d[i].y && d[i].live && live)
        {
            live = 0;
            d[i].SW();
            break;
        }
}