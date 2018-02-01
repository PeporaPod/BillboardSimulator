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
	linecontroler.Init();	//�H�����̏�����
	stringcontroler.Init();	//��������̏�����
	if (!timetablecontroler.Init(linecontroler, stringcontroler)) return;	//�����\���̏�����
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
	int update_time = GetNowCount();
	int engtrig = 0;
	DATEDATA datedata;
	while (!CheckHitKey(KEY_INPUT_ESCAPE)) {
		GetDateTime(&datedata);
		int id = -1;
		if (GetNowCount() - update_time > 3000) {
			update_time = GetNowCount();
			engtrig = engtrig ? 0 : 1;
		}
		while (timetablecontroler.GetTrainInformation(++id).departure_time <= datedata.Hour * 100 + datedata.Min);
		for (int i = 0; i < 8; i++) {
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).type_id[engtrig]), 16 * i, 5);
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).destination_id[engtrig]), 16 * i, 53);
			if (timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000)
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000), 16 * i, 117);
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 100 % 10), 16 * i, 129);
			billboard.Commit(stringcontroler.GetNumberStringInformation(10), 16 * i, 141);
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time / 10 % 10), 16 * i, 144);
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 10), 16 * i, 156);
			billboard.Commit(linecontroler.GetLineInformation(timetablecontroler.GetTrainInformation(id + i).line_id), 16 * i);
		}
		billboard.Draw();
		ScreenFlip();
	}
}
