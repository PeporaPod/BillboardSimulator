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
	Billboard			billboard;
	Timetable			timetable;
	StringControler			stringfile;
	/*��f�[�^*/
	/*�\�����̕�������*/
	int					string_id;
	StringInformation	stringinformation;
	int					size;
	/*�\�����̕�������*/
public:
	StringDisplayFrame();
	void Start();
	~StringDisplayFrame();
private:
	void MainLoop();
};

