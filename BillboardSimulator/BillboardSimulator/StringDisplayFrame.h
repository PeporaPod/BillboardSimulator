#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
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
	Billboard			billboard;			//LED�}�g���N�X
	StringControler		stringcontroler;	//�������񐧌�N���X
	/*��f�[�^*/
	/*�\�����̕�������*/
	int					size;				//�\���\�ȕ�����̐�
	int					current_str_id;		//���ݕ\�����Ă��镶����ID
	StringInformation	current_strinfo;	//���ݕ\�����Ă��镶������
	/*�\�����̕�������*/
public:
	StringDisplayFrame();	//�R���X�g���N�^
	void Start();			//���s�J�n���\�b�h
	~StringDisplayFrame();	//�f�X�g���N�^
private:
	void MainLoop();		//����s���\�b�h
};

