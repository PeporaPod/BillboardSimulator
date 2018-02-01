#pragma once
#include <DxLib.h>
#include "Header.h"
class Billboard
{
private:
	std::vector<int> position_x;								//横方向LED位置
	std::vector<int> position_y;								//縦方向LED位置
	int led_row;												//LED行数
	int led_column;												//LED列数
	int radius;													//LED半径
	std::vector<std::vector<unsigned int>> color_matrix;		//LED点灯色マトリクス
	const unsigned int color_off = GetColor(32, 32, 32);		//消灯色
	const unsigned int color_outofrange = GetColor(16, 16, 16);	//範囲外色
public:
	Billboard();
	void Init();
	void Init(int top, int bottom, int left, int right, int row, int column);
	void Commit(unsigned long long led_matrix[], unsigned int color);
	void Commit(StringInformation, const int offset_row = 0, const int offset_column = 0);
	void Commit(LineInformation, const int offset_row = 0, const int offset_column = 0);
	void Draw();
	void GetPositionReference(std::vector<int>* axis_x, std::vector<int>* axis_y, int* radius);
	~Billboard();
};

