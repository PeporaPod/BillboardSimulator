#pragma once
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>





//
//	�萔��`
//
//
//

/*��ʕ\���֘A*/
const int SCREENWIDTH_MAIN				=  640;	//�ʏ펞��ʕ�
const int SCREENHEIGHT_MAIN				=  480;	//�ʏ펞��ʍ�
const int SCREENWIDTH_SIMULATOR			= 1600;	//�V�~�����[�^��ʕ�
const int SCREENHEIGHT_SIMULATOR		=  800;	//�V�~�����[�^��ʍ�
const int SCREENWIDTH_STRINGDISPLAY		= 1500;	//������f�B�X�v���C���[�h��ʕ�
const int SCREENHEIGHT_STRINGDISPLAY	=  600;	//������f�B�X�v���C���[�h��ʍ�
const int SCREENWIDTH_STRINGEDITOR		= 1600;	//������G�f�B�^��ʕ�
const int SCREENHEIGHT_STRINGEDITOR		=  800;	//������G�f�B�^��ʍ�
const int COLORBITDEPTH					=   32;	//�F�r�b�g�[�x
/*��ʕ\���֘A*/

/*�\���v�f�֘A*/
const int LED_RADIUS					=    2;	//�V�~�����[�^���[�hLED���a
const int LED_ROW						=   16;	//������\�����[�h���s��
const int LED_COLUMN					=   64;	//������\�����[�h����
/*�\���v�f�֘A*/





//
//	�\���̒�`
//
//
//

/*�H�����*/
typedef struct LineInformation {
				std::string str		= "Error";
	unsigned	__int8		R[2]	= { 255, 255 };
	unsigned	__int8		G[2]	= { 255, 255 };
	unsigned	__int8		B[2]	= { 255, 255 };
}LineInformation;
/*�H�����*/


/*��ԏ��*/
typedef struct TrainInformation {			//�V�~�����[�^�p
	int line_id = -1;							//�H��ID
	int type_id[2] = { -1, -1 };				//���ID
	int departure_time = -1;					//���Ԏ����p�̐���ID
	int destination_id[2] = { -1, -1 };			//�s��ID
}TrainInformation;
/*��ԏ��*/


/*��������*/
typedef struct StringInformation {
				std::string	str			= "Error";	//������
				char		type		= '?';		//�������
	unsigned	long long	led_map[16] = { NULL };	//LED�}�b�v
	unsigned	__int8		width		= 0;		//LED�g�p��
	unsigned	__int8		R			= 32;		//�ԐF���x
	unsigned	__int8		G			= 32;		//�ΐF���x
	unsigned	__int8		B			= 32;		//�F���x
}StringInformation;
/*��������*/