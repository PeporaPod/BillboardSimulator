#pragma once
#include "Header.h"
#include <fstream>
#include <iostream>
#include <string>
#include <list>

//
//	�������񐧌�N���X
//
//		Init()���\�b�h�ɂ��f�[�^�擾
//
//
//
class StringControler
{
private:
	int count = 0;
//	std::vector<StringInformation>	stringvector;
	std::vector<StringInformation> vecstrinfo;	//��������i�[�x�N�g��
	std::list<int> error_file;	//�G���[���܂ރt�@�C���̔ԍ�
public:
	StringControler();	//�R���X�g���N�^
	int Init();	//�f�[�^���[�h
	StringInformation GetStringInformation(int id);	//�ԍ��ŕ���������擾
	StringInformation GetStringInformation(std::string str);
//	bool GetStringInformation(StringInformation& stringinformation, int number);
	~StringControler();	//�f�X�g���N�^
private:
//	void singularity();
	int LoadStringInformation(const unsigned int file_id);
};

