#include"snake.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Tu t;
	Apple a(t);
	Snake head(10, 21, 1, t);
	head.chengzhang(10, 19, &head, t), head.chengzhang(10, 20, &head, t);
	int i = 0;
	
	while (Snake::live)
	{
		system("cls");
		cout << "长度: " << Snake::longs << "\n游戏步数: " << i << endl;
		t.huizhi();
		head.kunzhi(a, t);
		i++;
	}

	head.qichu();
	Sleep(500);
	cout << "\n\n游戏结束了！" << endl;
	cout << "本局得分: " << Snake::longs - 3 << endl;
	cout << "\n再来一局吧！!" << endl;

	system("pause");

	return 0;
}
