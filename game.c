#include "game.h"

void Game(int row, int col){
	char arr[MAX_ROW][MAX_COl] = { 0 };//展示图
	char min[MAX_ROW][MAX_COl] = { 0 };//雷图
	Init(arr,row, col);//初始化展示地图
	int flg = 1;
	ShowMap(arr, row, col);//打印地图
	ShowMap(min, row, col);//打印雷图 用于调试
	while (1){
		Player(arr, min, row, col);//玩家翻雷
		if (flg == 1){
			MineMap(min, row, col);//玩家第一次翻雷之后,再初始化地雷图,保证第一次不炸死
			flg = 0;
		}
		ShowMap(arr, row, col);//再打印地图
		ShowMap(min, row, col);//打印雷图 用于调试
	}
}

//初始化地图
void Init(char (*arr)[MAX_COl],int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			arr[i][j] = '*';
		}
	}
}
//地雷的地图
void MineMap(char (*arr)[MAX_COl], int row, int col){
	int i = 0;
	int count = 0;
	while (count < MAX_MINE){//放置MAX_MINE个雷
		int x = rand() % row;
		int y = rand() % col;
		if (arr[x][y] != ' ' && arr[i][j] != '$'){//第一次翻雷 不炸死
			arr[x][y] = '$';
			count++;
		}
	}
}

//打印展示地图
void ShowMap(char (*arr)[MAX_COl], int row, int col){
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 0; i < col; i++){
		printf(" %d ", i + 1);
	}
	putchar('\n');
	for (i = 0; i < row; i++){
		printf(" %d ", i + 1);
		for (j = 0; j < col; j++){
			printf(" %c ", arr[i][j]);
		}
		printf("\n");
	}
}

//玩家翻雷
void Player(char (*arr)[MAX_COl], char (*min)[MAX_COl], int row, int col){
	while (1){
		int x = 0;
		int y = 0;
		printf("请输入坐标:");
		scanf("%d %d", &x, &y);
		if (!(x > 0 && x <= row && y > 0 && y <= col)){
			printf("输入坐标不合法,请重新输入!\n");
			continue;
		}
		else if (min[x - 1][y - 1] == '$'){//翻到雷,结束游戏
			system("cls");//在每次打印新的地图之前,清屏
			printf("********GAME OVER!*********\n");
			ShowMap(min, row, col);//打印雷图
			break;
		}
		else if (arr[x - 1][y - 1] == ' '){
			printf("该位置已经被掀开了!\n");//被掀开了,则继续输入坐标
			continue;
		}
		arr[x - 1][y - 1] = ' ';
		AroundMine(arr, min, x - 1, y - 1);//判断周围的雷
		system("cls");//在每次打印新的地图之前,清屏
		break;
	}
}

//判断周围的雷
void AroundMine(char (*arr)[MAX_COl], char (*min)[MAX_COl], int row, int col){
	char MinNum = 0;
	if (row > 0 && col > 0 && row < MAX_ROW - 1 && col < MAX_COl - 1 ){//当坐标不在边界时
		if (MinNum = ((min[row - 1][col - 1] == '$') + (min[row - 1][col] == '$') + (min[row - 1][col + 1] == '$') +
			(min[row][col - 1] == '$') + (min[row][col + 1] == '$') + (min[row + 1][col - 1] == '$') +
			(min[row + 1][col] == '$') + (min[row + 1][col + 1] == '$'))){
			arr[row][col] = MinNum + '0';
		}
		else
		{
			arr[row - 1][col - 1] = ' ';
			arr[row - 1][col] = ' ';
			arr[row - 1][col + 1] = ' ';
			arr[row][col - 1] = ' ';
			arr[row][col + 1] = ' ';
			arr[row + 1][col - 1] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 1][col + 1] = ' ';
		}
	}
	else if (row == 0 && col > 0 && col < MAX_COl - 1){//第一排中间
		if (MinNum = ((min[row][col - 1] == '$') + (min[row][col + 1] == '$') + (min[row + 1][col - 1] == '$') +
			(min[row + 1][col] == '$') + (min[row + 1][col + 1] == '$'))){
			arr[row][col] = MinNum + '0';
		}
		else
		{
			arr[row][col - 1] = ' ';
			arr[row][col + 1] = ' ';
			arr[row + 1][col - 1] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 1][col + 1] = ' ';
		}
	}
	else if (row == MAX_ROW - 1 && col > 0 && col < MAX_COl - 1){//最后一排中间
		if (MinNum = ((min[row - 1][col - 1] == '$') + (min[row - 1][col] == '$') + (min[row - 1][col + 1] == '$') +
			(min[row][col - 1] == '$') + (min[row][col + 1] == '$'))){
			arr[row][col] = MinNum + '0';
		}
		else
		{
			arr[row - 1][col - 1] = ' ';
			arr[row - 1][col] = ' ';
			arr[row - 1][col + 1] = ' ';
			arr[row][col - 1] = ' ';
			arr[row][col + 1] = ' ';
		}
	}
	else if (col == 0 && row > 0 && row < MAX_ROW - 1){//第一列中间
		if (MinNum = ((min[row - 1][col] == '$') + (min[row - 1][col + 1] == '$') +
			(min[row][col + 1] == '$') + (min[row + 1][col + 1] == '$') +
			(min[row + 1][col] == '$') ) ){
			arr[row][col] = MinNum + '0';
		}
		else
		{
			arr[row - 1][col] = ' ';
			arr[row - 1][col + 1] = ' ';
			arr[row][col + 1] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 1][col + 1] = ' ';
		}
	}
	else if (col == MAX_COl - 1 && row > 0 && row < MAX_ROW - 1){//最后一列中间
		if (MinNum = ((min[row - 1][col - 1] == '$') + (min[row - 1][col] == '$') +
			(min[row][col - 1] == '$')+ (min[row + 1][col - 1] == '$') +
			(min[row + 1][col] == '$'))){
			arr[row][col] = MinNum + '0';
		}
		else
		{
			arr[row - 1][col - 1] = ' ';
			arr[row - 1][col] = ' ';
			arr[row][col - 1] = ' ';
			arr[row + 1][col - 1] = ' ';
			arr[row + 1][col] = ' ';
		}
	}
	else if (col == 0 && row == 0){//左上角
		if (MinNum = (min[row][col + 1] == '$') + (min[row + 1][col] == '$') +
			(min[row + 1][col + 1] == '$')){
			arr[row][col] = MinNum + '0';
		}
		else{
			arr[row][col + 1] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 1][col + 1] = ' ';
		}
	}
	else if (col == 0 && row == MAX_ROW - 1){//左下角
		if (MinNum = (min[row - 1][col] == '$') + (min[row - 1][col + 1] == '$') +
			(min[row][col + 1] == '$')){
			arr[row][col] = MinNum + '0';
		}
		else{
			arr[row - 1][col] = ' ';
			arr[row - 1][col + 1] = ' ';
			arr[row][col + 1] = ' ';
		}
	}
	else if (col == MAX_COl - 1 && row == 0){//右上角
		if (MinNum = (min[row][col - 1] == '$') + (min[row + 1][col - 1] == '$') +
			(min[row + 1][col] == '$')){
			arr[row][col] = MinNum + '0';
		}
		else{
			arr[row][col - 1] = ' ';
			arr[row + 1][col] = ' ';
			arr[row + 1][col - 1] = ' ';
		}
	}
	else if (col == MAX_COl - 1 && row == MAX_ROW - 1){//右下角
		if (MinNum = (min[row][col - 1] == '$') + (min[row - 1][col - 1] == '$') +
			(min[row - 1][col] == '$')){
			arr[row][col] = MinNum + '0';
		}
		else{
			arr[row][col - 1] = ' ';
			arr[row - 1][col - 1] = ' ';
			arr[row - 1][col] = ' ';
		}
	}
}
