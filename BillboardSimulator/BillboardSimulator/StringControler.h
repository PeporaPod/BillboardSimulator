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
	std::vector<StringInformation> vecstrinfo;	//��������i�[�x�N�g��
	std::list<int> error_file;	//�G���[���܂ރt�@�C���̔ԍ�
public:
	StringControler();	//�R���X�g���N�^
	int Init();	//�f�[�^���[�h
	StringInformation GetStringInformation(int id);	//�ԍ��ŕ��������ԋp
	StringInformation GetStringInformation(std::string str, char type);	//�\�L������ƕ�����킩�當�������ԋp
	int GetStringID(std::string str, char type);
	~StringControler();	//�f�X�g���N�^
private:
//	void singularity();
	int LoadStringInformation(const unsigned int file_id);
};

