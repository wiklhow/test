#define  _CRT_SECURE_NO_WARNINGS 

#include "game.h"
//���ļ����ڲ�����������Ϸ
void menu()
{
	printf("*********************************\n");
	printf("**********1.play  0.exit*********\n");
	printf("*********************************\n");
}
void game()
{
	//���������̵���Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)//������壬Ҫѭ��//��ѭ��Ҫ�и�break����ѭ������ʶ
	{
		//�������
		PlayerMove(board, ROW, COL);
		//���ÿ����һ����Ҫ�ٳ���һ������
		system("cls");//����
		DisplayBoard(board, ROW, COL);
		//���ÿ����һ�ξ��ж���Ϸ״̬(�Ƿ��ж���Ӯ��ƽ�֣���ûӮ�ͼ�����Ϸ)
		IsWin(board, ROW, COL);
		//ֻҪ��Ϸ״̬����continue������ѭ��(��������)
		if (IsWin(board, ROW, COL) != 'C') {
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		//����ÿ����һ����Ҫ�ٳ���һ������
		system("cls");//����
		DisplayBoard(board, ROW, COL);
		//����ÿ����һ�ξ��ж���Ϸ״̬
		IsWin(board, ROW, COL);
		//ֻҪ��Ϸ״̬����continue������ѭ��
		if (IsWin(board, ROW, COL) != 'C') {
			break;
		}
	}
	if (IsWin(board, ROW, COL) == 'X') {
		printf("\n��ϲ��,��Ӯ����\n\n");
	}
	else if (IsWin(board, ROW, COL) == 'O') {
		printf("\n����ʤ��!\n\n");
	}
	else if (IsWin(board, ROW, COL) == 'E') {
		printf("\nƽ��\n\n");
	}
}

//�����X��
//������O��
void test()
{
	int input = 0;
	do {
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("\n�����������������\n");
			break;
		}
	} while (input!=0);
}

int main(void)
{
	test();
	return 0;
}
