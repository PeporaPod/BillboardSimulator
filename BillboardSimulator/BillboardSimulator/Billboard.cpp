#include "Billboard.h"



Billboard::Billboard()
{
}

void Billboard::Init()
{
	/*LED�}�g���N�X�̐���*/
	/*�}�g���N�X��Ղ̐��@����*/
	int screenwidth, screenheight, colorbitdepth;					//��ʕ�, ��ʍ�, �F�r�b�g�[�x
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);		//�擾
	/*�}�g���N�X��Ղ̐��@����*/


	/*LED���a�̊m��*/
	radius = LED_RADIUS;								//LED���a
	/*LED���a�̊m��*/
	
	
	/*�z�u�ł���LED�̐����v�Z����*/
	led_row = screenheight / (radius + 1) - 1;			//�s��
	led_column = screenwidth / (radius + 1) - 1;		//��
	/*�z�u�ł���LED�̐����v�Z����*/


	/*LED��z�u����*/
	for (int row = 1; row <= led_row; row++)
		position_y.push_back(row * (radius + 1) * 2);		//LED�ʒu(�c������)
	for (int column = 1; column <= led_column; column++)
		position_x.push_back(column * (radius + 1) * 2);	//LED�ʒu(��������)
	//LED�����F��`�����F`�ŏ�����
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LED��z�u����*/
	/*LED�}�g���N�X�̐���*/
}

void Billboard::Init(int top, int bottom, int left, int right, int row, int column)
{
	/*�z�u�ł���LED�̐��̊m��*/
	led_row = row;																//�s��
	led_column = column;														//��
	/*�z�u�ł���LED�̐��̊m��*/


	/*LED���a�̌v�Z*/
	if ((right - left) / (led_column + 1) < (bottom - top) / (led_row + 1))
		radius = (right - left) / (led_column + 1) / 2 - 1;						//���������̔��a
	else
		radius = (bottom - top) / (led_row + 1) / 2 - 1;						//�c�������̔��a
	/*LED���a�̌v�Z*/


	/*LED�̔z�u*/
	for (int row = 1; row <= led_row; row++)
		position_y.push_back(top + row * (bottom - top) / (led_row + 1));			//LED�ʒu(�c������)
	for (int column = 1; column <= led_column; column++)
		position_x.push_back(left + column * (right - left) / (led_column + 1));	//LED�ʒu(��������)
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_outofrange));
	/*LED�̔z�u*/
}

void Billboard::Commit(unsigned long long led_matrix[], unsigned int color)
{
	for (int row = 0; row < led_row; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (int column = 0; column < led_column; column++) {
			if (led_matrix[row] & operatorbit)
				color_matrix[row][column] = color;
			else
				color_matrix[row][column] = color_off;
			operatorbit = operatorbit >> 1;
		}
	}
}

void Billboard::Draw()
{
	ClearDrawScreen();
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(position_x[column], position_y[row], radius, color_matrix[row][column]);
	ScreenFlip();
}


Billboard::~Billboard()
{
}
