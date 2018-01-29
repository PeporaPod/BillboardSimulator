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
//
//
//
StringInformation StringControler::GetStringInformation(int id)
{
	if (id < 0 || id > vecstrinfo.size() - 1) {
		StringInformation strinfo;
		return strinfo;
	}
	return vecstrinfo[id];
}



//
//
//
//
StringInformation StringControler::GetStringInformation(std::string str)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str) return vecstrinfo[i];	//�����񂪍��v����
	StringInformation strinfo;
	return strinfo;
}

//bool StringControler::GetStringInformation(StringInformation& stringinformation, int number)
//{
//	if ((unsigned int)number < stringvector.size()) {
//		stringinformation = stringvector[number];
//		return true;
//	}
//	return false;
//}



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


	//�擾��������
	vecstrinfo.push_back(strinfo);
	return 0;	//�ǂݎ��𐳏�Ɋ���

				//���r�G���[�������̏���
error_jump:
	vecstrinfo.push_back(strinfo);
	return 1;	//�t�H�[�}�b�g�񏀋��t�@�C���̌��o
}





//void StringControler::singularity()
//{
//	std::ifstream file;
//	file.open("0.seg");
//	if (file.is_open()) {
//		StringInformation strinfo;
//		for (int row = 0; row < LED_ROW; row++) {
//			std::string str;
//			std::getline(file, str);
//			unsigned long long led_array = 0;
//			unsigned long long operatorbit = 0x8000000000000000;
//			for (int column = 0; (unsigned int)column < str.size() && column < LED_COLUMN; row++) {
//				if (str[column] = '1')
//					led_array = led_array & operatorbit;
//				operatorbit >>= 1;
//			}
//			strinfo.led_status[row] = led_array;
//		}
//		stringvector.push_back(strinfo);
//		file.close();
//	}
//	file.open("0", std::fstream::binary);
//	if (file.is_open()) {
//		StringInformation strinfo;
//		file.read(strinfo.string, sizeof(StringInformation::string));
//		file.read((char*)&strinfo.width, sizeof(StringInformation::width));
//		file.read(&strinfo.type, sizeof(StringInformation::type));
//		file.read((char*)&strinfo.R, sizeof(StringInformation::R));
//		file.read((char*)&strinfo.G, sizeof(StringInformation::G));
//		file.read((char*)&strinfo.B, sizeof(StringInformation::B));
//		for (int row = 0; row < LED_ROW; row++)
//			file.read((char*)&strinfo.led_status[row], sizeof(unsigned long long));
//		stringvector.push_back(strinfo);
//		file.close();
//	}
//}