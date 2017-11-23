#pragma once
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
const int SCREENHEIGHT_STRINGDISPLAY	=  600;	//������f�B�X�v���C���[�h��ʕ�
const int SCREENWIDTH_STRINGEDITOR		= 1600;	//������G�f�B�^��ʕ�
const int SCREENHEIGHT_STRINGEDITOR		=  800;	//������G�f�B�^��ʍ�
const int COLORBITDEPTH					=   32;	//�F�r�b�g�[�x
/*��ʕ\���֘A*/

/*�\���v�f�֘A*/
const int LED_RADIUS					=    2;	//�V�~�����[�^���[�hLED���a
const int LED_ROW						=   16;	//������\�����[�h���s��
const int LED_COLUMN					=   64;	//������\�����[�h����
const int STRING_LENGTH					=   24;	//������
/*�\���v�f�֘A*/





//
//	�\���̒�`
//
//
//

/*��ԏ��*/
typedef struct TrainInformation {			//�V�~�����[�^�p
	int line_id;								//�H��ID
	int type_id;								//���ID
	int destination_id;							//�s��ID
}TrainInformation;


typedef struct TrainInformationAsString {	//������^�C�v
	std::vector<std::string> line;				//�H����
	std::vector<std::string> type;				//��ʖ�
	std::vector<std::string> destination;		//�s��
}TrainInformationAsString;
/*��ԏ��*/


/*��������*/
typedef struct StringInformation {
	char string[STRING_LENGTH] = { NULL };			//������
	int width = LED_COLUMN;							//������
	char type = '?';								//�������
	unsigned __int8 R = 32, G = 32, B = 32;			//RGB�F
	unsigned long long led_status[LED_ROW] = { 0 };	//�_���\
}StringInformation;
/*��������*/