#pragma once
#include "Billboard.h"
#include "Timetable.h"
#include "StringControler.h"



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
	Billboard billboard;	//LED�}�g���N�X
	Timetable timetable;	//�����\
	StringControler stringcontroler;	//��������
public:
	SimulatorFrame();	//�R���X�g���N
	void Start();		//�ғ��J�n���\�b�h
	~SimulatorFrame();	//�f�X�g���N�^
};

