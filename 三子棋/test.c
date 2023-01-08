#define  _CRT_SECURE_NO_WARNINGS 

#include "game.h"
//该文件用于测试三子棋游戏
void menu()
{
	printf("*********************************\n");
	printf("**********1.play  0.exit*********\n");
	printf("*********************************\n");
}
void game()
{
	//数组存放棋盘的信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)//多次下棋，要循环//死循环要有个break跳出循环的意识
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		//玩家每走完一步就要再呈现一次棋盘
		system("cls");//清屏
		DisplayBoard(board, ROW, COL);
		//玩家每走完一次就判断游戏状态(是否有对象赢，平局，都没赢就继续游戏)
		IsWin(board, ROW, COL);
		//只要游戏状态不是continue就跳出循环(巧妙的设计)
		if (IsWin(board, ROW, COL) != 'C') {
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		//电脑每走完一步就要再呈现一次棋盘
		system("cls");//清屏
		DisplayBoard(board, ROW, COL);
		//电脑每走完一次就判断游戏状态
		IsWin(board, ROW, COL);
		//只要游戏状态不是continue就跳出循环
		if (IsWin(board, ROW, COL) != 'C') {
			break;
		}
	}
	if (IsWin(board, ROW, COL) == 'X') {
		printf("\n恭喜你,你赢啦！\n\n");
	}
	else if (IsWin(board, ROW, COL) == 'O') {
		printf("\n电脑胜利!\n\n");
	}
	else if (IsWin(board, ROW, COL) == 'E') {
		printf("\n平局\n\n");
	}
}

//玩家下X棋
//电脑下O棋
void test()
{
	int input = 0;
	do {
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("\n输入错误！请重新输入\n");
			break;
		}
	} while (input!=0);
}

int main(void)
{
	test();
	return 0;
}
