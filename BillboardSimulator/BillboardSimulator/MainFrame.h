#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "SimulatorFrame.h"
#include "StringDisplayFrame.h"
#include "StringEditorFrame.h"



//
//	MainFrame�N���X
//
//		�v�f
//			���[�h
//			���[�h�Z���N�^
//			�V�~�����[�^
//			������f�B�X�v���C
//			������G�f�B�^
//		���\�b�h
//			�R���X�g���N�^
//				�E�B���h�E���[�h�ؑ�
//				�t�H���g�ݒ�
//				DX���C�u�����̋N��
//			Start()
//				�ғ��J�n
//			�f�X�g���N�^
//				DX���C�u�����̏I��
//
//
//
class MainFrame
{
	int					mode;				//���[�hID
	ModeSelectorFrame*	modeselectorframe;	//���[�h�Z���N�^
	SimulatorFrame*		simulatorframe;		//�V�~�����[�^
	StringDisplayFrame*	stringdisplayframe;	//������f�B�X�v���C
	StringEditorFrame*	stringeditorframe;	//������G�f�B�^
public:
	MainFrame();	//�R���X�g���N�^
	bool Start();	//�ғ��J�n���\�b�h
	~MainFrame();	//�f�X�g���N�^
};

