#pragma once
//��������дͷ�ļ���
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
//���鴫�Ĳ�����Ԫ�ص�ַ��ΪʲôҪ��������ն���ָ���أ���������������
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//������Ϸ״̬
//���Ӯ            X
//����Ӯ			O
//ƽ��			    E
//��ûӮ��������Ϸ  C
char IsWin(char board[ROW][COL], int row, int col);