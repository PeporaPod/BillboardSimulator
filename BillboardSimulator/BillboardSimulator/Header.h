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
const int RADIUS		=    2;					//LED���a
const int DISTANCE		= (2 * (RADIUS + 1));	//LED�̒��S����
const int DISPLAYROW	=    8;					//�\����Ԑ�
const int DISPLAYTIME	= 2500;					//�\������[�~���b]



//
//	�^�̕ʖ���`
//
//		���̐�����������	:	unsigned int				�� UNSIGNEDINT
//		�F�R�[�h			:	unsigned int				�� COLOR
//		�u�[������			:	std::vector<std::vector>>	�� BOOLTABLE
//
//
typedef unsigned int			UNSIGNEDINT;	//���̐�����������(�[�� / ���R��)
typedef unsigned int			COLOR;			//�F�R�[�h
typedef std::vector<bool>		BOOLROW;		//�u�[���s
typedef std::vector<BOOLROW>	BOOLTABLE;		//�u�[���\



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
	int		x;		//�����ʒu
	int		y;		//�c���ʒu
	COLOR	color;	//�F
}LED;
typedef std::vector<LED>				LEDROW;		//LED�s
typedef std::vector<std::vector<LED>>	LEDTABLE;	//LED�\
#define LED_OFF							4280229663	//���z�����F(unsigned int GetColor(32, 32, 32))



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
	std::string	string;	//������
	BOOLTABLE	table;	//�_���\
	TABLESIZE	size;	//�T�C�Y
	COLOR		color;	//�F
}StringInformation;
#define SEGDIRECTORY "SEG\\"
#define SEGNUMBERSTRINGDIRECTORY "SEG\\NUMBERSTRING\\"
#define SEGEXTENSION ".seg"



//
//	�H�����
//
//		�H����
//		�H���F
//
//
typedef struct LineInformation {
	std::string	line;
	COLOR		color[2];
}LineInformation;
typedef std::vector<LineInformation> LINELIST;
#define LINEFILE "DATA\\LINE.csv"



//
//	��ԏ��
//
//		�H��(ID)
//		���(ID)
//		���Ԏ���
//		�s��(ID)
//
//
typedef struct TrainInformation {
	COLOR linecolor;
	int	line;
	int	type;
	int	time;
	int	destination;
}TrainInformation;
typedef std::vector<TrainInformation> TIMETABLE;
#define TIMETABLEFILE "DATA\\TIMETABLE.csv"



//
//	�����񂪐����݂̂ō\������Ă��邱�Ƃ��m�F����
//
//		�����̂�			:	bool true
//		�����ȊO���܂܂��	:	bool false
//
//
bool Check_StringToInt(std::string string);