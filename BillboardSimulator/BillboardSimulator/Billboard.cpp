#include "Billboard.h"



Billboard::Billboard()
{
}

void Billboard::Init()
{
	///*LED�}�g���N�X�̐���*/
	///*�}�g���N�X��Ղ̐��@����*/
	//int screenwidth, screenheight, colorbitdepth;					//��ʕ�, ��ʍ�, �F�r�b�g�[�x
	//GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//�擾
	///*�}�g���N�X��Ղ̐��@����*/


	///*�z�u�ł���LED�̐����v�Z����*/
	//led_row = (screenheight / DISTANCE) - 1;	//�s��
	//led_column = (screenwidth / DISTANCE) - 1;	//��
	///*�z�u�ł���LED�̐����v�Z����*/


	//											/*LED��z�u����*/
	//for (int row = 1; row <= led_row; row++) {
	//	LED_ARRAY led_array;												//��LED�z��
	//	for (int column = 1; column <= led_column; column++) {
	//		LED led = { column * DISTANCE, row * DISTANCE, color_off };	//LED�̈ʒu�v�Z
	//		led_array.push_back(led);											//LED����LED�z��֒ǉ�
	//	}
	//	led_matrix.push_back(led_array);									//LED�z���LED�}�g���N�X�֒ǉ�
	//}
	///*LED��z�u����*/
	///*LED�}�g���N�X�̐���*/


	///*�����\������*/
	//clsDx();
	//ClearDrawScreen();
	//for (int row = 0; row < led_row; row++)
	//	for (int column = 0; column < led_column; column++)
	//		DrawCircle(led_matrix[row][column].x, led_matrix[row][column].y, RADIUS, led_color_off);
	//ScreenFlip();
	///*�����\������*/
}

void Billboard::Init(int top_ratio, int bottom_ratio, int left_ratio, int right_ratio, int row, int column)
{
	int screenwidth, screenheight, colorbitdepth;
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);


	led_row = row;
	led_column = column;
}

void Billboard::Draw()
{
	ClearDrawScreen();
	for (int row = 0; row < 16; row++)
		for (int column = 0; column < 64; column++)
			DrawCircle(axis_x[column], axis_y[row], radius, color[row][column]);
	ScreenFlip();
}


Billboard::~Billboard()
{
}
