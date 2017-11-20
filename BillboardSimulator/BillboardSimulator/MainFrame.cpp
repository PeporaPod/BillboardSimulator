#include "MainFrame.h"



MainFrame::MainFrame()
{
	SetAlwaysRunFlag(TRUE);							//�펞����
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h�N��
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);	//��ʕ��E�����E�F�r�b�g�[�x
	SetDrawScreen(DX_SCREEN_BACK);					//����ʕ`��
}

bool MainFrame::Start()
{
	DxLib_Init();				//DxLib�̋N��
	do {
		mode = 0;
		modechangerframe = new ModeChangerFrame;
		mode = modechangerframe->Start();
		delete modechangerframe;
		switch (mode) {
		case 0:
			break;
		case 1:
			simulatorframe = new SimulatorFrame;
			simulatorframe->Start();
			delete simulatorframe;
		case 2:
			stringcheckerframe = new StringCheckerFrame;
			delete stringcheckerframe;
		default:
			return false;
		}
	} while (mode);
	DxLib_End();				//DxLib�̏I��
	return true;
}

MainFrame::~MainFrame()
{
}
