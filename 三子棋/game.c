#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"
//游戏模块

void InitBoard(char board[ROW][COL],int row,int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j ++ ) {
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++){
		//打印一行的数据
		for (j = 0; j < col; j++){
			printf(" %c ", board[i][j]);
			if (j < col-1) {
				printf("|");
			}
		}
		printf("\n");
		//打印分割行
		if (i < row - 1){
			for (j = 0; j < col; j++){
				printf("---");
				if (j < col - 1){
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
//打印棋盘思路
//第一行 X | X | X         //注意打印的是" X "而非"X"
//第二行---|---|---        //因为分界线是"---"三个单位
//第三行 X | X | X
//第四行---|---|---
//第五行 X | X | X

void PlayerMove(char board[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));
	printf("\n玩家下棋->\n");
	int x, y;//玩家输入坐标
	
	while (1)//死循环要有个break跳出循环的意识
	{
		printf("\n请输入坐标：");
		scanf("%d%d", &x, &y);
		//填入前判断坐标的合法性
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {//玩家对坐标的理解不同于程序员
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = 'X';//若合法则填入棋子
				break;//走完这一步就要跳出死循环
			}
			else {
				printf("\n这里已经有棋子了！\n");
			}
		}
		else {
			printf("\n请输入正确的坐标！\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;//电脑走的坐标
	printf("\n电脑下棋->\n");
	while (1)//死循环要有个break跳出循环的意识
	{
		x = rand() % 3;//任意大于n的数字对n取模的结果为0到n-1
		y = rand() % 3;
		if (board[x][y] == ' ') {
			board[x][y] = 'O';
			break;
		}
	}
}
//返回1说明棋盘满了，返回0说明棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				 return 0;//没满
			}
		}
	}
	return 1;//满了
}
//                  函数返回值
//玩家赢            X
//电脑赢			O
//平局			    E
//都没赢，继续游戏  C
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断每行 是否有一方否胜利
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ') {
			return board[i][0];
		}
	}
	//判断每列 是否有一方否胜利
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ') {
			return board[0][i];
		}
	}
	//判断主对角线 是否有一方否胜利
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ') {
		return board[1][1];
	}
	//判断副对角线 是否有一方否胜利
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ') {
		return board[1][1];
	}
	//判断是否平局
	if (IsFull(board,ROW,COL) == 1) {
		return 'E';
	}
	return 'C';
}
