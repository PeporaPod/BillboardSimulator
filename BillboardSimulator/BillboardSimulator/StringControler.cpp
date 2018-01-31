#include "StringControler.h"



//
//	�R���X�g���N�^
//
//
StringControler::StringControler()
{
}



//
//	�S��������̃��[�h
//
//
int StringControler::Init()
{
	if (!vecstrinfo.empty())
		vecstrinfo.clear();
	if (!error_file.empty())
		error_file.clear();
	for (int i = 1; true; i++) {
		switch (LoadStringInformation(i)) {	//�o�C�i���t�@�C�����當��������擾
		case -1:
			return i - 1;	//�t�@�C�����s�݂̎����[�v���甲���I��
		case 1:
			error_file.push_back(i);
		}
	}
}



//
//	ID�ԍ����當�������ԋp
//
//
StringInformation StringControler::GetStringInformation(int id)
{
	if (id < 0 || id > (int)vecstrinfo.size() - 1) {
		StringInformation strinfo;
		return strinfo;
	}
	return vecstrinfo[id];
}



//
//	�\�L������ƕ�����킩�當�������ԋp
//
//
StringInformation StringControler::GetStringInformation(std::string str, char type)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str && vecstrinfo[i].type == type) return vecstrinfo[i];	//������,������킪���v����
	StringInformation strinfo;
	return strinfo;	//���v������̂��f�[�^��ɂȂ������ꍇ
}



//
//	�\�L������ƕ�����킩��ID��ԋp
//
//
int StringControler::GetStringID(std::string str, char type)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str && vecstrinfo[i].type == type) return i;	//������,������킪���v����
	return -1;	//���v����f�[�^���Ȃ������ꍇ
}



//
//	�f�X�g���N�^
//
//
StringControler::~StringControler()
{
	std::ofstream file("STR\\list.txt");
	if (!file.is_open()) return;
	char number[4];
	for (unsigned int i = 0; i < vecstrinfo.size(); i++) {
		sprintf_s<sizeof(number)>(number, "%3d", i + 1);
		file << number << " | " << vecstrinfo[i].type << ": " << vecstrinfo[i].str << std::endl;
	}
}





//
//	�o�C�i���t�@�C�����當�������ǂݏo��
//
//
int StringControler::LoadStringInformation(const unsigned int file_id) {
	//���𕶎��ɕϊ�
	if (file_id > 999) return -1; //�t�@�C���ԍ���1-999�܂ł̊�. 0�͕ʂ̎�舵��.
	char file_name[8];	//������i�[�o�b�t�@
	sprintf_s<sizeof(file_name)>(file_name, "STR\\%03u", file_id);	//�t�@�C������0�p�f�B���O�����3��


																	//�t�@�C���I�[�v��
	std::ifstream file(file_name, std::fstream::binary);	//�o�C�i���t�@�C���Ƃ��ăI�[�v��
	if (!file.is_open()) return -1; //�ǂݍ��݃��[�v���I�������邽�߂̖߂�l


	//�f�[�^���[�h
	StringInformation strinfo;
	//�}�b�v�擾
	for (int i = 0; i < 16; i++)
		if (!file.read((char*)&strinfo.led_map[i], sizeof(strinfo.led_map[i]))) goto error_jump;
	//�g�pLED���擾
	if (!file.read((char*)&strinfo.width, sizeof(StringInformation::width))) goto error_jump;
	//�Ԍ��x�擾
	if (!file.read((char*)&strinfo.R, sizeof(StringInformation::R))) goto error_jump;
	//�Ό��x�擾
	if (!file.read((char*)&strinfo.G, sizeof(StringInformation::G))) goto error_jump;
	//���x�擾
	if (!file.read((char*)&strinfo.B, sizeof(StringInformation::B))) goto error_jump;
	//������ʎ擾
	if (!file.read(&strinfo.type, sizeof(StringInformation::type))) goto error_jump;
	//������擾
	if (file.eof()) goto error_jump;
	strinfo.str.clear();
	do {
		char character;
		file.read(&character, sizeof(character));
		strinfo.str.push_back(character);
	} while (!file.eof());
	strinfo.str.pop_back(); strinfo.str.pop_back();


	//�擾��������
	vecstrinfo.push_back(strinfo);
	return 0;	//�ǂݎ��𐳏�Ɋ���

				//���r�G���[�������̏���
error_jump:
	vecstrinfo.push_back(strinfo);
	return 1;	//�t�H�[�}�b�g�񏀋��t�@�C���̌��o
}


