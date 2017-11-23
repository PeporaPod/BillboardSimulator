#include "MainFrame.h"



//
//	�R���X�g���N�^
//
//		�E�B���h�E���[�h�ؑ�
//		�t�H���g�ݒ�
//		DX���C�u�����̋N��
//
//
//
MainFrame::MainFrame()
{
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);	//�A���`�G�C���A�X�t�H���g
	ChangeFont("Yu Gothic");						//�t�H���g: Yu Gothic
	DxLib_Init();									//DX���C�u�����̋N��
}



//
//	Start���\�b�h
//
//		���[�h�ݒ� / �I��
//		�e���[�h�֏������Ϗ�
//
//
//
bool MainFrame::Start()
{
	/*���C�����[�v*/
	do {
		mode = -1;//�G���[�Ή��p�̏�����

		/*���[�h�Z���N�^*/
		modeselectorframe = new ModeSelectorFrame;	//���[�h�Z���N�^���\�z
		mode = modeselectorframe->Start();			//�ғ��J�n
		delete modeselectorframe;					//���[�h�Z���N�^���I��
		/*���[�h�Z���N�^*/

		/*���򏈗�*/
		switch (mode) {
		case 0:												//�I��
			break;
		case 1:												//�V�~�����[�^���[�h
			simulatorframe = new SimulatorFrame;				//�V�~�����[�^���\�z
			simulatorframe->Start();							//�ғ��J�n
			delete simulatorframe;								//�V�~�����[�^���I��
			break;
		case 2:												//������f�B�X�v���C���[�h
			stringdisplayframe = new StringDisplayFrame;		//������f�B�X�v���C���\�z
			stringdisplayframe->Start();						//�ғ��J�n
			delete stringdisplayframe;							//������f�B�X�v���C���I��
			break;
		case 3:												//������G�f�B�^���[�h
			stringeditorframe = new StringEditorFrame;			//������G�f�B�^���\�z
			stringeditorframe->Start();							//�ғ��J�n
			delete stringeditorframe;							//������G�f�B�^���I��
			break;
		default:											//�G���[��
			return false;
		}
		/*���򏈗�*/
	} while (mode);
	/*���C�����[�v*/

	return true;
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
