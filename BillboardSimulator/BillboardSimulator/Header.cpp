#pragma once
#include "Header.h"



bool Check_StringToInt(std::string string) {
	if (string.empty()) return false;
	for (unsigned int i = 0; i < string.size(); i++) {
		if ('0' <= string[i] && string[i] <= '9');
		else return false;
	}
	return true;
}

bool LoadBinaryString(std::vector<StringInformation>& vecstrinfo, int filenumber)
{
	char filepath[7];									//�t�@�C���p�X�p�o�b�t�@
	sprintf_s<7>(filepath, "STR\\%02d", filenumber);	//�t�@�C���p�X�ϊ�
	std::ifstream file(filepath, std::fstream::binary);	//�t�@�C���I�[�v��
	if (!file.is_open()) return false;						//�t�@�C���I�[�v���G���[

	StringInformation strinfo;		//�i�[�p�ϐ�
	//������擾
	file.read(strinfo.string, sizeof(StringInformation::string));
	//LED���擾
	file.read((char*)&strinfo.width, sizeof(StringInformation::width));
	//�������ʎ擾
	file.read((char*)&strinfo.type, sizeof(char));
	//�ԔZ�x�擾
	file.read((char*)&strinfo.R, 1);
	//�ΔZ�x�擾
	file.read((char*)&strinfo.G, 1);
	//�Z�x�擾
	file.read((char*)&strinfo.B, 1);
	//LED�_���\�̎擾
	for (int i = 0; i < LED_ROW; i++)
		file.read((char*)&strinfo.LED_Status, sizeof(StringInformation::LED_Status));
	vecstrinfo.push_back(strinfo);	//

	return true;
}