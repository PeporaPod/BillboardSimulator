#pragma once
#include <DxLib.h>
#include "Header.h"
#include <vector>
class Billboard
{
private:
	std::vector<int> position_x;
	std::vector<int> position_y;
	int led_row;
	int led_column;
	int radius;
	std::vector<std::vector<unsigned int>> color_matrix;
	const unsigned int color_off = GetColor(32, 32, 32);
	const unsigned int color_outofrange = GetColor(16, 16, 16);
public:
	Billboard();
	void Init();
	void Init(int top, int bottom, int left, int right, int row, int column);
	void Commit(unsigned long long led_matrix[], unsigned int color);
	void Draw();
	~Billboard();
};

