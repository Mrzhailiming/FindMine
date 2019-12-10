#include "game.h"


void Menu(){
	printf("**************************\n");
	printf("****** 1. 开始扫雷 ********\n");
	printf("****** 2. 退出     ********\n");
	printf("**************************\n");
}
int main () {
	Menu();
	srand((unsigned int)time(NULL));
	int input = 0;
	while (1){
		printf("请输入选择:\n");
		scanf("%d", &input);
		switch (input){
		case 1:
			Game(MAX_ROW,MAX_COl);
			break;
		case 2:
			printf("退出成功!\n");
			break;
		default:
			break;
		}
	}
	//int num = 0;
	//num = (1 > 2) + (2 > 1);
	return 0;
}
