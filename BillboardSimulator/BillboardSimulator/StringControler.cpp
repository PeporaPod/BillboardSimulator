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
	vecstrinfo.clear();	//�ēǂݍ��ݎ��̂��߂̏�����

	//�t�@�C���̃��[�h
	unsigned int file_id = 0;	//�ǂݍ��ރt�@�C���ԍ�
	do if (!LoadStringInformation(++file_id)) break;	//�t�@�C���̓ǂݍ���: �֐�����G���[�̕Ԃ�l�Ń��[�v��E�o
	while (true);

	//�����p�̕ʘg��������
	char num[2] = "0";
	for (int i = 0; i < 10; i++)
		vecnumstrinfo[i] = GetStringInformation(num, 'N'), num[0]++;
	num[0] = ':';
	vecnumstrinfo[10] = GetStringInformation(num, 'N');

	return file_id - 1;	//�ǂݍ��񂾃t�@�C������ԋp
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
StringInformation StringControler::GetStringInformation(char * str, char type)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str && vecstrinfo[i].type == type) return vecstrinfo[i];	//������,������킪���v����
	StringInformation strinfo;
	return strinfo;	//���v������̂��f�[�^��ɂȂ������ꍇ
}



//
//	���܂��̓R�������琔���������ԋp
//
//
StringInformation StringControler::GetNumberStringInformation(int number)
{
	if (number < 0 || number > 10)
		return StringInformation();
	return vecnumstrinfo[number];
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
		sprintf_s<sizeof(number)>(number, "%03d", i + 1);
		file << number << " | " << vecstrinfo[i].type << ": " << vecstrinfo[i].str << std::endl;
	}
}





//
//	�o�C�i���t�@�C�����當�������ǂݏo��
//
//
bool StringControler::LoadStringInformation(const unsigned int file_id) {
	//���𕶎��ɕϊ�
	if (file_id > 999) return false; //�t�@�C���ԍ���1-999�܂ł̊�. 0�͕ʂ̎�舵��.
	char file_name[8];	//������i�[�o�b�t�@
	sprintf_s<sizeof(file_name)>(file_name, "STR\\%03u", file_id);	//�t�@�C������0�p�f�B���O�����3��


	//�t�@�C���I�[�v��
	std::ifstream file(file_name, std::fstream::binary);	//�o�C�i���t�@�C���Ƃ��ăI�[�v��
	if (!file.is_open()) return false; //�ǂݍ��݃��[�v���I�������邽�߂̖߂�l


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
error_jump:
	vecstrinfo.push_back(strinfo);

	return true;	//�ǂݎ����I��
}


