#pragma once
#include <DxLib.h>
#include "Header.h"
#include <vector>
class Billboard
{
private:
	std::vector<int> axis_x;
	std::vector<int> axis_y;
	int led_row;
	int led_column;
	int radius;
	int distance;
	std::vector<std::vector<unsigned int>> color;
	const unsigned int color_off = GetColor(32, 32, 32);
	const unsigned int color_outofrange = GetColor(16, 16, 16);
public:
	Billboard();
	void Init();
	void Init(int top_ratio, int bottom_ratio, int left_ratio, int right_ratio, int row, int column);
	void Draw();
	~Billboard();
};

