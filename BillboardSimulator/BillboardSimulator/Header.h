#pragma once
#include <DxLib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>



//
//	�萔��`
//
//		��ʃT�C�Y(��ʕ� / ��ʍ�)
//		LED�̔��a
//		LED�̒��S����
//		�\�����ς��܂ł̎���[�~���b]
//
//
const int SCREENWIDTH	= 1500;					//��ʕ�
const int SCREENHEIGHT	=  775;					//��ʍ�
const int COLORBITDEPTH =   32;					//�F�r�b�g�[�x
const int RADIUS		=    2;					//LED���a
const int DISTANCE		= (2 * (RADIUS + 1));	//LED�̒��S����
const int LED_ROW		=   16;					//LED�s��
const int DISPLAYROW	=    8;					//�\����Ԑ�
const int DISPLAYTIME	= 2500;					//�\������[�~���b]



//
//	LED
//
//		LED�\����
//			LED�P�̂̈ʒu(���� / �c��)
//			LED�P�̂̔����F
//		LED�s
//		LED�\(LED�s��)
//		�����͐F�ŉ��z�I�ɕ\��
//
//
typedef struct LED {
				int	x;		//�����ʒu
				int	y;		//�c���ʒu
	unsigned	int color;	//�F
}LED;
typedef std::vector<LED>				LED_ARRAY;	//LED�z��
typedef std::vector<std::vector<LED>>	LED_MATRIX;	//LED�}�g���N�X



//
//	�\��������
//
//		�yPRE�z�g�p����LED�̏c����
//
//		�����񂪎����
//			����킷������
//			LED�ł̕\��
//			�g�p����LED�̏c����
//			�����F
//
//
typedef struct TABLESIZE {
	int row		= 0;	//�c��
	int column	= 0;	//����
}TABLESIZE;
typedef struct StringInformation {
				char		string[24];		//������
				int			width;			//LED��
				char		type;			//��������
	unsigned	int			R;				//�ԔZ�x
	unsigned	int			G;				//�ΔZ�x
	unsigned	int			B;				//�Z�x
	unsigned	long long	LED_Status[16];	//LED�_���\
}StringInformation;



//
//	�H�����
//
//		�H����
//		�H���F
//
//
typedef struct LineInformation {
	std::string		line;
	unsigned int	color[2];
}LineInformation;
typedef std::vector<LineInformation> LINELIST;



//
//	��ԏ��
//
//
typedef struct TrainInformation {
	std::string line;
	std::string type;
	std::string departure_time;
	std::string destination;
	std::string platform;
}TrainInformation;
typedef std::vector<TrainInformation> TIMETABLE;



//
//	�����񂪐����݂̂ō\������Ă��邱�Ƃ��m�F����
//
//		�����̂�			:	bool true
//		�����ȊO���܂܂��	:	bool false
//
//
bool Check_StringToInt(std::string string);



//
bool LoadBinaryString(std::vector<StringInformation>& vecstrinfo, int filenumber);