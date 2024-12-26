#include"snake.h"

//图类
Tu::Tu()
{
    for (int i = 0; i < 20; i++)
    {
        if (i == 0 || i == 19)
            for (int j = 0; j < 41; j++)
                if (j % 2 == 0)t[i][j] = '#';
                else t[i][j] = ' ';
        else
            for (int j = 0; j < 41; j++)
                if (j == 0 || j == 40)t[i][j] = '#';
                else t[i][j] = ' ';
    }
}

void Tu::huizhi()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 41; j++)
            cout << t[i][j];
        cout << endl;
    }
}

void Tu::xuigai(int y, int x, int z)
{
    switch(z)
    {
    case 0: t[y][x] = ' '; return;
    case 1: t[y][x] = '@'; return;
    case 2: t[y][x] = '*'; return;
    case 3: t[y][x] = '0'; return;
    default: return;
    }
}



//苹果类
bool Apple::live = 0;

Apple::Apple(Tu& t)
{
    live = 1;
    y = rand() % (20 - 3) + 1;
    x = rand() % (41 - 3) + 1;
    
    t.xuigai(y, x, 3);
}

void Apple::shengzhang(Snake* p)
{
    if (y == p->y && x == p->x)
        live = 0;
}

void Apple::fuhuo(Tu& t)
{
    live = 1;
    y = rand() % (20 - 3) + 1;
    x = rand() % (41 - 3) + 1;

    t.xuigai(y, x, 3);
}

void Apple::chunhui(Tu& t)
{
    t.xuigai(y, x, 3); 
}



//蛇类
bool Snake::live = 0;
int  Snake::longs = 0;

Snake::Snake(int y, int x, int z, Tu& t) :y(y), x(x), next(nullptr) { t.xuigai(y, x, 1); live = 1; longs++; }
Snake::Snake(int y, int x, Snake* head, Tu& t) : y(y),x(x)
{
    next = head->next;
    head->next = this;
    t.xuigai(y, x, 2);
    longs++; 
}

void Snake::kunzhi(Apple& a, Tu& t)
{
    int X = x, Y = y;
    switch (_getch())
    {
    case 'a':
        (1 < x) ? x-- : live = 0;
        break;
    case 'd':
        (x < 39) ? x++ : live = 0;
        break;
    case 'w':
        (1 < y) ? y-- : live = 0;
        break;
    case 's':
        (y < 18) ? y++ : live = 0;
        break;
    default:
        return;
    }

    a.shengzhang(this); 

    if (live)
        if (Apple::live)
            this->chuandi(Y, X, t);
        else this->chengzhang(Y, X, this, t);

    this->zihui();
    if (!Apple::live)a.fuhuo(t);
    a.chunhui(t);
}

void  Snake::chuandi(int Y, int X, Tu& t)
{   
    t.xuigai(Y, X, 2);

    Snake* p = this->next;
    int a, b;
    while (p != nullptr)
    {
        a = p->x, b = p->y;
        p->x = X, p->y = Y;
        X = a, Y = b;
        p = p->next;
    }
    
    t.xuigai(Y, X, 0);
    t.xuigai(y, x, 1);
}

void Snake::chengzhang(int Y, int X, Snake* head, Tu& t)
{
    t.xuigai(y, x, 1); 
    new Snake(Y, X, head, t);
}

void  Snake::zihui()
{
    Snake* p = this, * q;
    int i = 1;
    while (p != nullptr)
    {
        q = p->next;
        while (q != nullptr)
        {
            if (p->y == q->y && p->x == q->x)
            {
                live = 0;
                return;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void  Snake::qichu()
{
    Snake* p = this, * q;
    while (p->next != nullptr)
    {
        q = p->next;
        p->next= p->next->next;
        delete q;
    }
}