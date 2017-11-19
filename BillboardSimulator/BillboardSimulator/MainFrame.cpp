#include "MainFrame.h"



MainFrame::MainFrame()
{
	SetAlwaysRunFlag(TRUE);							//�펞����
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h�N��
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);	//��ʕ��E�����E�F�r�b�g�[�x
	SetDrawScreen(DX_SCREEN_BACK);					//����ʕ`��
	DxLib_Init();									//DxLib�̋N��
}

bool MainFrame::Start()
{
	printfDx("Initializing Billboard\n"); ScreenFlip();
	billboard.Init();
	billboard.Start();

	return true;
}

MainFrame::~MainFrame()
{
	DxLib_End();							//DxLib�̏I��
}
