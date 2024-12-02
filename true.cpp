#include"snake_.h"

CHANGDI::CHANGDI()
{
    for (int i = 0; i < 20; i++)
    {
        if (i == 0 || i == 19)
            for (int j = 0; j < 41; j++)
                if (j % 2 == 0)N[i][j] = '#';
                else N[i][j] = ' ';
        else
            for (int j = 0; j < 41; j++)
                if(j==0||j==40)N[i][j] = '#';
                else N[i][j] = ' ';
    }
}

void CHANGDI::HZ()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 41; j++)
            cout << N[i][j];
        cout << endl;
    }
}

void CHANGDI::XG(int x,int y,int z)
{
    if (z == 0)N[y][x] = ' ';

    else if (z == 1)N[y][x] = '@';

    else if (z == 2)N[y][x] = '*';

    else N[y][x] = '0';
}





apple::apple(CHANGDI& N)
{
    x = rand() % (41 - 3) + 1;
    y = rand() % (20 - 3) + 1;
    live = 1; 
    N.XG(x, y, 3);
}

void apple::Xapple(CHANGDI& N)
{

    x = rand() % (41 - 3) + 1;
    y = rand() % (20 - 3) + 1;
    live = 1;
    N.XG(x, y, 3);
}

int apple::CXapple(int z)
{
    if (z == 0)return x;
    else return y;
}

bool apple::CXappleB()
{
    return live;
}

void apple::CL()
{
    live = 0;
}

void apple::H(CHANGDI& N)
{
    N.XG(x, y, 3);
}






snake::snake(int a, int b, snake* p, CHANGDI& N, int z)
{
    x = a;
    y = b;
    next = p;
    if (z == 1)live = 1;
    
    N.XG(a, b, z);
}

snake::snake(int a, int b, snake* p)
{
    x = a;
    y = b;
    next = p;
}

void Xsnake(snake& head, apple a, CHANGDI& N)
{
    snake* node = new snake(head.CXsnake1(0), head.CXsnake1(1), head.CXsnake2()); 

    N.XG(head.CXsnake1(0), head.CXsnake1(1), 2);

    head.XGsnake1(a.CXapple(0), 0);
    head.XGsnake1(a.CXapple(1), 1);
    head.XGsnake2(node);

}

int snake::CXsnake1(int z)
{
    if (z == 0)return x;
    else return y;
}

snake* snake::CXsnake2()
{
    return next;
}

bool snake::CXsnakeL()
{
    return live;
}

void snake::XGsnake1(int a, int z)
{
    if (z == 0) x = a;
    else y = a;
}
                                 
void snake::XGsnake2(snake* y)   
{                                
    next = y;                    
}                                
                                 
void snake::XGsnakeL()           
{                                
    live = 0;                    
}

void snake::KZ(snake& head, apple& a, CHANGDI& N, int& DF)
{
    int X, Y;
    switch (_getch())
    {
        case 'w':                         
            X = x; Y = y - 1;             
            if (Y < 1)head.live = 0;      
            break;                        
        case 's':                         
            X = x; Y = y + 1;             
            if (Y > 18)head.live = 0;     
            break;                        
        case 'a':                         
            X = x - 1; Y = y;             
            if (X < 1)head.live = 0;      
            break;                        
        case 'd':                         
            X = x + 1; Y = y;             
            if (X > 39)head.live = 0;     
            break;                        
        default: X = x; Y = y;            
            return;
    }

    if (head.live)
        if (a.CXapple(0) == X && a.CXapple(1) == Y)
        {
            eat(head, a, N);
            DF++;
        }
        else YD(X, Y, head, N);

}

void snake::YD(int X, int Y, snake& head, CHANGDI& N)
{
    snake* p = &head;
    int a, b;
    while (p!=NULL)
    {
        a = p->x; b = p->y;
        p->x = X; p->y = Y;
        X = a; Y = b;
        p = p->next;
    }

    N.XG(X, Y, 0);
    N.XG(head.x, head.y, 1);
    N.XG(head.next->x, head.next->y, 2);
}

void eat(snake& head, apple& a, CHANGDI& N)
{
    Xsnake(head, a, N);

    N.XG(a.CXapple(0), a.CXapple(1), 1);

    a.CL();

    a.Xapple(N);
}

void JIANCHE(snake& head)
{
    snake* p = head.CXsnake2();
    while (p != NULL)
    {
        if (head.CXsnake1(0) == p->CXsnake1(0) && head.CXsnake1(1) == p->CXsnake1(1))
        {
            head.XGsnakeL(); 
            break;
        }
        p = p->CXsnake2();
    }
}