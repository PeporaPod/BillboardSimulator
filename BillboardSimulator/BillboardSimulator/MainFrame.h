#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "SimulatorFrame.h"
#include "StringDisplayFrame.h"
#include "StringEditorFrame.h"



//
//	MainFrame�N���X
//
//		����
//			���[�h
//			���[�h�Z���N�^(�N���X�̃|�C���^)
//			�V�~�����[�^(�N���X�̃|�C���^)
//			������f�B�X�v���C(�N���X�̃|�C���^)
//			������G�f�B�^(�N���X�̃|�C���^)
//		���\�b�h
//			�R���X�g���N�^
//				�E�B���h�E���[�h�ؑ�
//				�t�H���g�ݒ�
//			�ғ��J�n���\�b�h
//				DX���C�u�����̋N��
//				�ғ��J�n
//			�f�X�g���N�^
//				DX���C�u�����̏I��
//
//
//
class MainFrame
{
	int						mode;				//���[�hID
	ModeSelectorFrame	*	modeselectorframe;	//���[�h�Z���N�^
	SimulatorFrame		*	simulatorframe;		//�V�~�����[�^
	StringDisplayFrame	*	stringdisplayframe;	//������f�B�X�v���C
	StringEditorFrame	*	stringeditorframe;	//������G�f�B�^
public:
	MainFrame();	//�R���X�g���N�^
	bool Start();	//�ғ��J�n���\�b�h
	~MainFrame();	//�f�X�g���N�^
};

