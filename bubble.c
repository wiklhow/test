#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void bubble(int* arr,int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++) {
		//a trick to improve the efficiency of the program!!!!!!!!!
		int flag = 1;//������һ�����������е�Ԫ���Ѿ�Ϊ˳��
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tep = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tep;
				flag = 0;
			}
			if (flag == 1) {
				break;
			}
		}
	}
}
int main(void)
{
	//ð������˳��

	int arr[10] = { 5,1,2,10,7,9,8,3,6,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, size);
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	

	return 0;
}