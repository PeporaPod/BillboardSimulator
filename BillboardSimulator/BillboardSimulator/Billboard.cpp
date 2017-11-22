#include "Billboard.h"



Billboard::Billboard()
{
}

void Billboard::Init()
{
	radius = LED_RADIUS;

	/*LED�}�g���N�X�̐���*/
	/*�}�g���N�X��Ղ̐��@����*/
	int screenwidth, screenheight, colorbitdepth;					//��ʕ�, ��ʍ�, �F�r�b�g�[�x
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//�擾
	/*�}�g���N�X��Ղ̐��@����*/
	
	
	/*�z�u�ł���LED�̐����v�Z����*/
	led_row = screenheight / (radius + 1) - 1;		//�s��
	led_column = screenwidth / (radius + 1) - 1;	//��
	/*�z�u�ł���LED�̐����v�Z����*/


	/*LED��z�u����*/
	for (int row = 1; row <= led_row; row++)
		axis_y.push_back(row * (radius + 1) * 2);
	for (int column = 1; column <= led_column; column++)
		axis_x.push_back(column * (radius + 1) * 2);
	color = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LED��z�u����*/
	/*LED�}�g���N�X�̐���*/
}

void Billboard::Init(int top, int bottom, int left, int right, int row, int column)
{
	led_row = row;
	led_column = column;


	if ((right - left) / (led_column + 1) < (bottom - top) / (led_row + 1))
		radius = (right - left) / (led_column + 1) / 2 - 1;
	else
		radius = (bottom - top) / (led_row + 1) / 2 - 1;


	for (int row = 1; row <= led_row; row++)
		axis_y.push_back(top + (bottom - top) / (led_row + 1) * row);
	for (int column = 0; column < led_column; column++)
		axis_x.push_back(left + (right - left) / (led_column + 1) * (column + 1));
	color = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_outofrange));
}

void Billboard::Draw()
{
	ClearDrawScreen();
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(axis_x[column], axis_y[row], radius, color[row][column]);
	ScreenFlip();
}


Billboard::~Billboard()
{
}
