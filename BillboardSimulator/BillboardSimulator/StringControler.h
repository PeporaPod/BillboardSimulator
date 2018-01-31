#pragma once
#include "Header.h"

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
	std::vector<StringInformation> vecstrinfo;			//��������i�[�x�N�g��
	std::array<StringInformation, 11> vecnumstrinfo;	//�������(0-9)+':'�i�[�x�N�g��
public:
	//�������n���\�b�h
	StringControler();												//�R���X�g���N�^
	int Init();														//�f�[�^���[�h

	//��������̃Q�b�^
	StringInformation GetStringInformation(int id);					//�ԍ��ŕ��������ԋp
	StringInformation GetStringInformation(char * str, char type);	//�\�L������ƕ�����킩�當�������ԋp
	StringInformation GetNumberStringInformation(int number);		//���܂��̓R������p�̕�������擾���\�b�h

	//�������ID�ϊ�
	int GetStringID(std::string str, char type);					//������ƕ�����킩�當����ID��ԋp
	
	//�I�������n���\�b�h
	~StringControler();												//�f�X�g���N�^
private:
	//�ו�����������
	bool LoadStringInformation(const unsigned int file_id);			//�t�@�C�����當����������[�h
};

