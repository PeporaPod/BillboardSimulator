#pragma once
#include <DxLib.h>
#include "Header.h"
class Billboard
{
private:
	std::vector<int> position_x;								//������LED�ʒu
	std::vector<int> position_y;								//�c����LED�ʒu
	int led_row;												//LED�s��
	int led_column;												//LED��
	int radius;													//LED���a
	std::vector<std::vector<unsigned int>> color_matrix;		//LED�_���F�}�g���N�X
	const unsigned int color_off = GetColor(32, 32, 32);		//�����F
	const unsigned int color_outofrange = GetColor(16, 16, 16);	//�͈͊O�F
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

