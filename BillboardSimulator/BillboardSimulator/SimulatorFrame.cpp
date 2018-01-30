#include "SimulatorFrame.h"



//
//	�R���X�g���N�^
//
//		�펞�����ݒ�
//		��ʕ`��ݒ�
//
//
//
SimulatorFrame::SimulatorFrame()
{
	SetAlwaysRunFlag(TRUE);														//�펞�������I��
	SetGraphMode(SCREENWIDTH_SIMULATOR, SCREENHEIGHT_SIMULATOR, COLORBITDEPTH);	//��ʃT�C�Y
	SetDrawScreen(DX_SCREEN_BACK);												//����ʕ`��
	SetMouseDispFlag(FALSE);
}



//
//	�ғ��J�n���\�b�h
//
//		LED�}�g���N�X�̏�����
//
//
//
void SimulatorFrame::Start()
{
	billboard.Init();	//LED�}�g���N�X�̏�����
	stringcontroler.Init();
	timetable.Init(false);
	billboard.Draw();
	WaitKey();
}



//
//	�f�X�g���N�^
//
//
//
SimulatorFrame::~SimulatorFrame()
{
}
