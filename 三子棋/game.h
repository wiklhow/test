#pragma once
//函数声明写头文件里
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
//数组传的不是首元素地址吗，为什么要用数组接收而非指针呢？？？？？？？？
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//四种游戏状态
//玩家赢            X
//电脑赢			O
//平局			    E
//都没赢，继续游戏  C
char IsWin(char board[ROW][COL], int row, int col);