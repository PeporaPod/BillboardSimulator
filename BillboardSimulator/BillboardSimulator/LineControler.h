#pragma once
#include "Header.h"
class LineControler
{
private:
	std::vector<LineInformation> veclineinfo;	//�H�����
public:
	LineControler();							//�R���X�g���N�^
	int Init();									//�ғ��J�n���\�b�h
	/*�Q�Ɨp�Q�b�^*/
	LineInformation GetLineInformation(int id);	//ID����H�������
	int GetLineID(std::string str);				//�H��������ID���
	/*�Q�Ɨp�Q�b�^*/
	~LineControler();							//�f�X�g���N�^
};

