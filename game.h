#ifndef __GAME_H__
#define __GAME_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 8
#define MAX_COl 8
#define MAX_MINE 10

void Game(int row,int col);
void Init(char (*arr)[MAX_COl],int row, int col);
void ShowMap(char (*arr)[MAX_COl], int row, int col);
void MineMap(char (*arr)[MAX_COl], int row, int col);
void Player(char (*arr)[MAX_COl], char (*min)[MAX_COl], int row, int col);
void AroundMine(char(*arr)[MAX_COl], char (*min)[MAX_COl], int row, int col);
#endif //__GAME_H__
