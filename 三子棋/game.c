#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"
//��Ϸģ��

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
		//��ӡһ�е�����
		for (j = 0; j < col; j++){
			printf(" %c ", board[i][j]);
			if (j < col-1) {
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
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
//��ӡ����˼·
//��һ�� X | X | X         //ע���ӡ����" X "����"X"
//�ڶ���---|---|---        //��Ϊ�ֽ�����"---"������λ
//������ X | X | X
//������---|---|---
//������ X | X | X

void PlayerMove(char board[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));
	printf("\n�������->\n");
	int x, y;//�����������
	
	while (1)//��ѭ��Ҫ�и�break����ѭ������ʶ
	{
		printf("\n���������꣺");
		scanf("%d%d", &x, &y);
		//����ǰ�ж�����ĺϷ���
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {//��Ҷ��������ⲻͬ�ڳ���Ա
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = 'X';//���Ϸ�����������
				break;//������һ����Ҫ������ѭ��
			}
			else {
				printf("\n�����Ѿ��������ˣ�\n");
			}
		}
		else {
			printf("\n��������ȷ�����꣡\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;//�����ߵ�����
	printf("\n��������->\n");
	while (1)//��ѭ��Ҫ�и�break����ѭ������ʶ
	{
		x = rand() % 3;//�������n�����ֶ�nȡģ�Ľ��Ϊ0��n-1
		y = rand() % 3;
		if (board[x][y] == ' ') {
			board[x][y] = 'O';
			break;
		}
	}
}
//����1˵���������ˣ�����0˵������û��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				 return 0;//û��
			}
		}
	}
	return 1;//����
}
//                  ��������ֵ
//���Ӯ            X
//����Ӯ			O
//ƽ��			    E
//��ûӮ��������Ϸ  C
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�ÿ�� �Ƿ���һ����ʤ��
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ') {
			return board[i][0];
		}
	}
	//�ж�ÿ�� �Ƿ���һ����ʤ��
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ') {
			return board[0][i];
		}
	}
	//�ж����Խ��� �Ƿ���һ����ʤ��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ') {
		return board[1][1];
	}
	//�жϸ��Խ��� �Ƿ���һ����ʤ��
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ') {
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (IsFull(board,ROW,COL) == 1) {
		return 'E';
	}
	return 'C';
}
