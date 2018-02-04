#pragma once
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <DxLib.h>





//�t���X�N���[�����[�h�ŋN������g���K
//#define FULL_SCREEN





//
//	�萔��`
//
//
//

/*��ʕ\���֘A*/
#ifdef FULL_SCREEN
const int SCREENWIDTH_MAIN				= 1920;	//�ʏ펞��ʉ𑜓x��
const int SCREENHEIGHT_MAIN				= 1080;	//�ʏ펞��ʉ𑜓x��
const int SCREENWIDTH_SIMULATOR			= 1920;	//�V�~�����[�^��ʉ𑜓x��
const int SCREENHEIGHT_SIMULATOR		= 1080;	//�V�~�����[�^��ʉ𑜓x��
const int SCREENWIDTH_STRINGDISPLAY		= 1920;	//������f�B�X�v���C���[�h��ʉ𑜓x��
const int SCREENHEIGHT_STRINGDISPLAY	= 1080;	//������f�B�X�v���C���[�h��ʉ𑜓x��
const int SCREENWIDTH_STRINGEDITOR		= 1920;	//������G�f�B�^��ʉ𑜓x��
const int SCREENHEIGHT_STRINGEDITOR		= 1080;	//������G�f�B�^��ʉ𑜓x��
const int COLORBITDEPTH = 32;	//�F�r�b�g�[�x
#else
const int SCREENWIDTH_MAIN				=  640;	//�ʏ펞��ʕ�
const int SCREENHEIGHT_MAIN				=  480;	//�ʏ펞��ʍ�
const int SCREENWIDTH_SIMULATOR			= 1600;	//�V�~�����[�^��ʕ�
const int SCREENHEIGHT_SIMULATOR		=  800;	//�V�~�����[�^��ʍ�
const int SCREENWIDTH_STRINGDISPLAY		= 1500;	//������f�B�X�v���C���[�h��ʕ�
const int SCREENHEIGHT_STRINGDISPLAY	=  600;	//������f�B�X�v���C���[�h��ʍ�
const int SCREENWIDTH_STRINGEDITOR		= 1600;	//������G�f�B�^��ʕ�
const int SCREENHEIGHT_STRINGEDITOR		=  800;	//������G�f�B�^��ʍ�
const int COLORBITDEPTH = 32;	//�F�r�b�g�[�x
#endif
/*��ʕ\���֘A*/

/*�\���v�f�֘A*/
const int LED_RADIUS					=    2;	//�V�~�����[�^���[�h��LED���a
const int LED_ROW						=   16;	//������\�����[�h��LED�s��
const int LED_COLUMN					=   64;	//������\�����[�h��LED��
/*�\���v�f�֘A*/





//
//	�\���̒�`
//
//
//

/*�H�����*/
typedef struct LineInformation {
				std::string str		= "Error";		//�H����
	unsigned	__int8		R[2]	= { 255, 255 };	//�H���J���[�Ԍ��x
	unsigned	__int8		G[2]	= { 255, 255 };	//�H���J���[�Ό��x
	unsigned	__int8		B[2]	= { 255, 255 };	//�H���J���[���x
}LineInformation;
/*�H�����*/


/*��ԏ��*/
typedef struct TrainInformation {
	int		line_color_id		= -1;			//�H���J���[ID
	int		line_str_id[2]		= { -1, -1 };	//�H��������ID
	int		type_id[2]			= { -1, -1 };	//��ʕ�����ID
	int		departure_time		= -1;			//���Ԏ���(4���̐���)
	int		destination_id[2]	= { -1, -1 };	//�s�敶����ID
	int		track				= 0;			//�̂�ΔԐ��ԍ�
	bool	dep					= false;		//�n��
}TrainInformation;
/*��ԏ��*/


/*��������*/
typedef struct StringInformation {
				std::string	str			= "Error";	//������
				char		type		= '?';		//�������
	unsigned	long long	led_map[16] = { NULL };	//LED�}�b�v
	unsigned	__int8		width		=  0;		//LED�g�p��
	unsigned	__int8		R			= 32;		//�ԐF���x
	unsigned	__int8		G			= 32;		//�ΐF���x
	unsigned	__int8		B			= 32;		//�F���x
}StringInformation;
/*��������*/





//
//	�֐���`
//
//
//

/*�����񂩂琮���ւ̕ϊ����s�����Ƃ��\�ł��邩*/
int My_stoi(std::string);