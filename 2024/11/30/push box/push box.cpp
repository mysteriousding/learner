#include"NH.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int a = 1; a < 20; a++)
    {
        my.XMY(); 
        for (int i = 0; i < a; i++)
        {
            d[i]. Xdoor();
            b[i].Xbox();
        }

        while (1)
        {
            system("cls");
            cout << "第" << a << "关" << endl;
            if (SL(a))
                break;

            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 41; j++)
                    cout << N[i][j];
                cout << endl;
            }

            my.CZ();

            for (int i = 0; i < a; i++)
            {
                d[i].HD();
                b[i].YD(a);
            }
        }

        cout << "恭喜！你通关了！！" << endl;
        Sleep(3000);
    }

    cout << "恭喜你!！完全胜利了！！！" << endl;

    /*system("pause");*/

    return 0;
}
