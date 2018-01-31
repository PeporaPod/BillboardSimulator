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
	stringcontroler.Init();	//��������̏�����
	if (!timetablecontroler.Init(stringcontroler)) return;	//�����\���̏�����
	MainLoop();
}



//
//	�f�X�g���N�^
//
//
//
SimulatorFrame::~SimulatorFrame()
{
}

void SimulatorFrame::MainLoop()
{
	for (int i = 0; i < 8; i++) {
		billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(i).type_id[0]), 16 * i, 0);
		billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(i).destination_id[0]), 16 * i, 48);
		if (timetablecontroler.GetTrainInformation(i).departure_time / 1000)
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time / 1000), 16 * i, 102);
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time / 100 % 10), 16 * i, 114);
		billboard.Commit(stringcontroler.GetNumberStringInformation(10), 16 * i, 126);
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time / 10 % 10), 16 * i, 129);
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time % 10), 16 * i, 141);
	}
	billboard.Draw();
	ScreenFlip();
	WaitKey();
}
