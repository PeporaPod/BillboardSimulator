#include "MainFrame.h"



//
//	�R���X�g���N�^
//
//		�E�B���h�E���[�h�ؑ�
//		�O���[�o���t�H���g�ݒ�
//
//
//
MainFrame::MainFrame()
{
#ifndef FULL_SCREEN
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h
#endif
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);	//�A���`�G�C���A�X�t�H���g
	ChangeFont("Yu Gothic");						//�t�H���g: Yu Gothic
	SetFontThickness(4);							//�t�H���g�̑���
}



//
//	Start���\�b�h
//
//		DX���C�u�����̋N��
//		���[�h�I�� / �I��
//		�I���������[�h�֏����������p��
//
//
//
bool MainFrame::Start()
{
	DxLib_Init();											//DX���C�u�����̋N��
	
	/*���C�����[�v*/
	do {
		mode = -1;											//�I�����[�h��������

		/*���[�h�Z���N�^*/
		modeselectorframe = new ModeSelectorFrame;			//���[�h�Z���N�^���\�z
		mode = modeselectorframe->Start();					//�ғ��J�n
		delete modeselectorframe;							//���[�h�Z���N�^���I��
		/*���[�h�Z���N�^*/

		/*���򏈗�*/
		switch (mode) {
		case 1:													//�V�~�����[�^���[�h
			simulatorframe = new SimulatorFrame;					//�V�~�����[�^���\�z
			simulatorframe->Start();								//�ғ��J�n
			delete simulatorframe;									//�V�~�����[�^���I��
			break;
		case 2:													//������f�B�X�v���C���[�h
			stringdisplayframe = new StringDisplayFrame;			//������f�B�X�v���C���\�z
			stringdisplayframe->Start();							//�ғ��J�n
			delete stringdisplayframe;								//������f�B�X�v���C���I��
			break;
		case 3:													//������G�f�B�^���[�h
			stringeditorframe = new StringEditorFrame;				//������G�f�B�^���\�z
			stringeditorframe->Start();								//�ғ��J�n
			delete stringeditorframe;								//������G�f�B�^���I��
			break;
		case 0:													//����I��
			return true;
		default:												//�ُ�I��
			return false;
		}
		/*���򏈗�*/
	} while (true);
	/*���C�����[�v*/
}



//
//	�f�X�g���N�^
//
//		DX���C�u�����̏I��
//
//
//
MainFrame::~MainFrame()
{
	DxLib_End();	//DX���C�u�����̏I��
}

