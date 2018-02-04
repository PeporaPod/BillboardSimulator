#include "LineControler.h"



//
//	�R���X�g���N�^
//
//
LineControler::LineControler()
{
}

int LineControler::Init()
{
	/*�t�@�C�����I�[�v��*/
	std::ifstream file("LINE\\�H��.csv");								//�H�����t�@�C�����I�[�v��
	if (!file.is_open()) return 0;											//�G���[����
	/*�t�@�C�����I�[�v��*/

	veclineinfo.clear();												//�H�����z��̏�����
	/*�H�����̃��[�h*/
	while (!file.eof()) {
		/*CSV�t�@�C������1�H�����̏����擾*/
		std::list<std::string> strlist;
		std::string str;
		std::getline(file, str);
		std::istringstream strstream(str);
		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');
			if (!str.empty()) strlist.push_back(str);
		}
		if (strlist.empty()) break;
		/*CSV�t�@�C������1�H�����̏����擾*/
		/*�t�H�[�}�b�g�ϊ�*/
		LineInformation lineinfo;										//�V�K�H�����̃o�b�t�@
		lineinfo.str = strlist.front();										//�H�����̎擾
		strlist.pop_front();
		switch (strlist.size()) {
		case 3:																//�H���J���[��1��̏ꍇ
			lineinfo.R[0] = lineinfo.R[1] = My_stoi(strlist.front());			//R���x
			strlist.pop_front();
			lineinfo.G[0] = lineinfo.G[1] = My_stoi(strlist.front());			//G���x
			strlist.pop_front();
			lineinfo.B[0] = lineinfo.B[1] = My_stoi(strlist.front());			//B���x
			strlist.pop_front();
			break;
		case 6:																//�H���J���[��2��̏ꍇ
			for (int i = 0; i < 2; i++) {
				lineinfo.R[i] = My_stoi(strlist.front());						//R���x
				strlist.pop_front();
				lineinfo.G[i] = My_stoi(strlist.front());						//G���x
				strlist.pop_front();
				lineinfo.B[i] = My_stoi(strlist.front());						//B���x
				strlist.pop_front();
			}
		}
		/*�t�H�[�}�b�g�ϊ�*/
		veclineinfo.push_back(lineinfo);									//�H������z��֒ǉ�
	}
	/*�H�����̃��[�h*/

	return veclineinfo.size();											//�擾�����H������ԋp
}



//
//
//
//
LineInformation LineControler::GetLineInformation(int id)
{
	if (id < 0 || id > (int)veclineinfo.size() - 1) {
		LineInformation lineinfo;
		return lineinfo;								//���v����f�[�^���Ȃ������ꍇ
	}
	return veclineinfo[id];								//�w��̘H������ԋp
}



//
//
//
//
int LineControler::GetLineID(std::string str)
{
	for (unsigned int i = 0; i < veclineinfo.size(); i++)
		if (veclineinfo[i].str == str) return i;			//������,������킪���v����
	return -1;												//���v����f�[�^���Ȃ������ꍇ
}



//
//	�f�X�g���N�^
//
//
LineControler::~LineControler()
{
}

