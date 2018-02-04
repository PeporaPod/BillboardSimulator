#include "Billboard.h"



//
//	�R���X�g���N�^
//
//
Billboard::Billboard()
{
	matrix_row		= 0;
	matrix_column	= 0;
	color_off		= GetColor(32, 32, 32);
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
	matrix_row = screenheight / (2 * (radius + 1)) - 1;			//�s��
	matrix_column = screenwidth / (2 * (radius + 1)) - 1;		//��
	/*�z�u�ł���LED�̐����v�Z����*/


	/*LED��z�u����*/
	for (unsigned int row = 1; row <= matrix_row; row++)
		position_y.push_back(row * (radius + 1) * 2);		//LED�ʒu(�c������)
	for (unsigned int column = 1; column <= matrix_column; column++)
		position_x.push_back(column * (radius + 1) * 2);	//LED�ʒu(��������)
	//LED�����F��`�����F`�ŏ�����
	color_matrix = std::vector<std::vector<unsigned int>>(matrix_row, std::vector<unsigned int>(matrix_column, color_off));
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
void Billboard::Init(const int top, const int bottom, const int left, const int right, const unsigned int row, const unsigned int column)
{
	/*LED�}�g���N�X�̐���*/
	/*�z�u�ł���LED�̐��̊m��*/
	matrix_row = row;																//�s��
	matrix_column = column;														//��
	/*�z�u�ł���LED�̐��̊m��*/


	/*LED���a�̌v�Z*/
	if ((right - left) / (matrix_column + 1) < (bottom - top) / (matrix_row + 1))
		radius = (right - left) / (matrix_column + 1) / 2 - 1;						//���������̔��a
	else
		radius = (bottom - top) / (matrix_row + 1) / 2 - 1;						//�c�������̔��a
	/*LED���a�̌v�Z*/


	/*LED�̔z�u*/
	for (unsigned int row_index = 1; row_index <= matrix_row; row_index++)
		position_y.push_back(top + row_index * (bottom - top) / (matrix_row + 1));			//LED�ʒu(�c������)
	for (unsigned int column_index = 1; column_index <= matrix_column; column_index++)
		position_x.push_back(left + column_index * (right - left) / (matrix_column + 1));	//LED�ʒu(��������)
	color_matrix = std::vector<std::vector<unsigned int>>(matrix_row, std::vector<unsigned int>(matrix_column, color_off));
	/*LED�̔z�u*/
	/*LED�}�g���N�X�̐���*/
}



//
//	�H���J���[�o�[�̕\�����\�b�h
//
//
void Billboard::Commit(LineInformation lineinformation, const int offset_row)
{
	unsigned int line_color[2] = { GetColor(lineinformation.R[0], lineinformation.G[0], lineinformation.B[0]), GetColor(lineinformation.R[1], lineinformation.G[1], lineinformation.B[1]) };	//�H���J���[��RGB����ϊ�
	for (unsigned int row = 1; row < 8 && row + offset_row < color_matrix.size(); row++)
		for (int column = 0; column < 4; column++)
			color_matrix[row + offset_row][column] = color_matrix[row + offset_row][matrix_column - 1 - column] = line_color[0];	//�H���J���[1�̔��f
	for (unsigned int row = 8; row < 15 && row + offset_row < matrix_row; row++)
		for (int column = 0; column < 4; column++)
			color_matrix[row + offset_row][column] = color_matrix[row + offset_row][matrix_column - 1 - column] = line_color[1];	//�H���J���[2�̔��f
}



//
//	LED�}�g���N�X�̓_����Ԃ̔��f���s�����\�b�h
//
//		LED�̓_�����/�_���F���eLED�ɔ��f���Ă���
//
//
//
void Billboard::Commit(StringInformation strinfo, const int offset_row, const int offset_column)
{
	unsigned int color = GetColor(strinfo.R, strinfo.G, strinfo.B);
	for (unsigned int row = 0; row < LED_ROW && row + offset_row < matrix_row; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (unsigned int column = 0; column < LED_COLUMN && column + offset_column < matrix_column; column++) {
			if (strinfo.led_map[row] & operatorbit)
				color_matrix[row + offset_row][column + offset_column] = color;
			operatorbit >>= 1;
		}
	}
}



//
//	LED��S�ď���������Ԃɂ��郁�\�b�h
//
//
void Billboard::Clear()
{
	for (unsigned int row = 0; row < color_matrix.size(); row++)
		for (unsigned int column = 0; column < color_matrix[row].size(); column++)
			color_matrix[row][column] = color_off;
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
	for (unsigned int row = 0; row < matrix_row; row++)
		for (unsigned int column = 0; column < matrix_column; column++)
			DrawCircle(position_x[column], position_y[row], radius, color_matrix[row][column]);
}



//
//
//
//
void Billboard::GetPositionReference(std::vector<int> * axis_x, std::vector<int> * axis_y, int * rad)
{
	axis_x->clear(), axis_y->clear();						//�}���p�̉ϒ��z����N���A
	for (unsigned int i = 0; i < position_x.size(); i++)
		axis_x->push_back(position_x[i]);					//x������(��)�̈ʒu�����i�[
	for (unsigned int i = 0; i < position_y.size(); i++)
		axis_y->push_back(position_y[i]);					//y������(�s)�̈ʒu�����i�[
	*rad = radius;											//LED���a���i�[
}



//
//
//
//
void Billboard::GetMatrixSize(unsigned int * row, unsigned int * column)
{
	*row	= position_y.size();
	*column = position_x.size();
}



//
//	�f�X�g���N�^
//
//		�`������폜
//
//
Billboard::~Billboard()
{
	ClearDrawScreen();
	ScreenFlip();
	ClearDrawScreen();
}

