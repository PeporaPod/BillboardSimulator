#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "TimetableControler.h"
#include "StringControler.h"



//
//	StringDisplayFrame�N���X
//
//		�v�f
//			LED�}�g���N�X
//			�����\���
//			��������
//			�\����������ID
//			�\������������
//		���\�b�h
//			�R���X�g���N�^
//			�ғ��J�n���\�b�h
//			�f�X�g���N�^
//		�������\�b�h
//			�ғ����[�v
//
//
//
class StringDisplayFrame
{
private:
	/*��f�[�^*/
			Billboard			billboard;										//LED�}�g���N�X
			StringControler		stringcontroler;								//�������񐧌�N���X
			const	int			font_size = SCREENHEIGHT_STRINGDISPLAY / 12;	//�t�H���g�T�C�Y
	/*��f�[�^*/
	/*�\�����̕�������*/
			int					str_vecsize;									//�ǂݍ��񂾂ȕ�����̐�
			int					current_id;										//���ݕ\�����Ă��镶����ID
			StringInformation	current_strinfo;								//���ݕ\�����Ă��镶������
	/*�\�����̕�������*/
public:
	StringDisplayFrame();	//�R���X�g���N�^
	void Start();			//���s�J�n���\�b�h
	~StringDisplayFrame();	//�f�X�g���N�^
private:
	void MainLoop();		//����s���\�b�h
};

