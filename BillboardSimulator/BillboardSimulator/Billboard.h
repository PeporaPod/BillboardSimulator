#pragma once
#include <DxLib.h>
#include "Header.h"
class Billboard
{
private:
	unsigned	int										matrix_row;		//LED�s��
	unsigned	int										matrix_column;	//LED��
	unsigned	int										radius;			//LED���a
	unsigned	int										color_off;		//�����F
				std::vector<int>						position_x;		//������LED�ʒu
				std::vector<int>						position_y;		//�c����LED�ʒu
				std::vector<std::vector<unsigned int>>	color_matrix;	//LED�_���F�}�g���N�X
public:
	Billboard();																													//�R���X�g���N�^
	/*LED�}�g���N�X�{�̂̎�����*/
	void Init();																													//���������\�b�h(LED���Œ蔼�a�ŉ�ʂ����ς��ɔz�u)
	void Init(const int top, const int bottom, const int left, const int right, const unsigned int row, const unsigned int column);	//���������\�b�h(�w��͈͂Ɏw�萔LED��z�u)
	void Commit(LineInformation, const int offset_row = 0);																			//�w��̘H���o�[���w��s�I�t�Z�b�g���ĕ\��
	void Commit(StringInformation, const int offset_row = 0, const int offset_column = 0);											//�w��̕�������w��I�t�Z�b�g�ŕ\��
	void Clear();																													//LED��S�ď�����Ԃɂ���
	void Draw();																													//���݂�LED�_����Ԃ�LED�}�g���N�X��`��
	/*LED�}�g���N�X�{�̂̎�����*/
	/*�Q�Ɨp�Q�b�^*/
	void GetPositionReference(std::vector<int> * axis_x, std::vector<int> * axis_y, int * radius);									//LED�̈ʒu�ELED���a���
	void GetMatrixSize(unsigned int * row, unsigned int * column);																	//LED�}�g���N�X�̍s���E�񐔂��
	/*�Q�Ɨp�Q�b�^*/
	~Billboard();																													//�f�X�g���N�^
};

