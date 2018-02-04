#pragma once
#include "Billboard.h"
#include "LineControler.h"
#include "StringControler.h"
#include "TimetableControler.h"



//
//	SimulatorFrame�N���X
//
//		�v�f
//			LED�}�g���N�X
//			�����\���
//			��������
//		���\�b�h
//			�R���X�g���N�^
//			�ғ��J�n���\�b�h
//			�f�X�g���N�^
//
//
//
class SimulatorFrame
{
private:
	Billboard			billboard;			//LED�}�g���N�X
	LineControler		linecontroler;		//�H����񐧌�N���X
	StringControler		stringcontroler;	//�������񐧌�N���X
	TimetableControler	timetablecontroler;	//�����\����N���X
public:
	SimulatorFrame();	//�R���X�g���N�^
	void Start();		//�ғ��J�n���\�b�h
	~SimulatorFrame();	//�f�X�g���N�^
private:
	void MainLoop();	//����s���\�b�h
};

