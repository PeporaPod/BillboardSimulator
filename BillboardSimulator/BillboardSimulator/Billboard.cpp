#include "Billboard.h"



Billboard::Billboard()
{
}



//
//	���������\�b�h(�t���p)
//
//		/*�w��LED���a��LED��z�u����*/
//		��ʏ��擾
//		LED�̔z�u�����v�Z
//		�z�u
//
//
//
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



//
//	���������\�b�h(16x64�p)
//
//		/*�w��͈͂Ɏw�萔��LED��z�u*/
//		LED���a�̌v�Z
//		�z�u
//
//
//
void Billboard::Init(int top, int bottom, int left, int right, int row, int column)
{
	/*LED�}�g���N�X�̐���*/
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
	for (int row_index = 1; row_index <= led_row; row_index++)
		position_y.push_back(top + row_index * (bottom - top) / (led_row + 1));			//LED�ʒu(�c������)
	for (int column_index = 1; column_index <= led_column; column_index++)
		position_x.push_back(left + column_index * (right - left) / (led_column + 1));	//LED�ʒu(��������)
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_outofrange));
	/*LED�̔z�u*/
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LED�}�g���N�X�̐���*/
}



//
//	LED�}�g���N�X�̓_����Ԃ̔��f���s�����\�b�h
//
//		LED�̓_�����/�_���F���eLED�ɔ��f���Ă���
//
//
//
void Billboard::Commit(unsigned long long led_matrix[], unsigned int color)
{
	for (int row = 0; row < LED_ROW; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (int column = 0; column < LED_COLUMN; column++) {
			if (led_matrix[row] & operatorbit)
				color_matrix[row][column] = color;
			else
				color_matrix[row][column] = color_off;
			operatorbit >>= 1;
		}
	}
}

void Billboard::Commit(StringInformation strinfo)
{
	for (int row = 0; row < LED_ROW; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (int column = 0; column < strinfo.width; column++) {
			if (strinfo.led_map[row] & operatorbit)
				color_matrix[row][column] = GetColor(strinfo.R, strinfo.G, strinfo.B);
			else
				color_matrix[row][column] = color_off;
			operatorbit >>= 1;
		}
	}
}



//
//	�`�惁�\�b�h
//
//		���݂�LED�̓_����Ԃŉ�ʂւ̕`����s��
//
//
//
void Billboard::Draw()
{
//	ClearDrawScreen();
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(position_x[column], position_y[row], radius, color_matrix[row][column]);
//	ScreenFlip();
}



//
//
//
//
void Billboard::GetPositionReference(std::vector<int>* axis_x, std::vector<int>* axis_y, int* rad)
{
	for (unsigned int i = 0; i < position_x.size(); i++)
		axis_x->push_back(position_x[i]);
	for (unsigned int i = 0; i < position_y.size(); i++)
		axis_y->push_back(position_y[i]);
	*rad = radius;
}



Billboard::~Billboard()
{
}
