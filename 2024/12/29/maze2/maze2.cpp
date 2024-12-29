#include"maze2.h";

int main()
{
    srand((unsigned)time(nullptr));

    for (int i = 0; i < 32; i++)
    {
        tu t;
        system("cls");
        cout << "第" << i + 1 << "关" << endl; 
        t.huizhi(); 
        do {

            t.kunzhi();
            system("cls");
            cout << "第" << i + 1 << "关" << endl;
            t.huizhi();

        } while (tu::live);

        Sleep(1000);
        cout << "\n过关了！你真厉害！" << endl;
        cout << "继续挑战下一关吧！!" << endl;
        system("pause");
    }

    cout << "\n恭喜你！游戏胜利了！！！" << endl;
    cout << "再来一局吧！!" << endl;
    system("pause");

    return 0;
}
