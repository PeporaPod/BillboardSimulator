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
	SetMouseDispFlag(FALSE);													//�}�E�X�\��"�Ȃ�"
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
	billboard.Init();														//LED�}�g���N�X�̏�����
	linecontroler.Init();													//�H�����̏�����
	stringcontroler.Init();													//��������̏�����
	if (!timetablecontroler.Init(linecontroler, stringcontroler)) return;	//�����\���̏�����
	MainLoop();																//�又�����\�b�h�֐�����Ϗ�
}



//
//	�f�X�g���N�^
//
//
//
SimulatorFrame::~SimulatorFrame()
{
	ClearDrawScreen();
	ScreenFlip();
	ClearDrawScreen();
}





//
//	�又�����\�b�h
//
//
void SimulatorFrame::MainLoop()
{
	std::vector<int> position_x, position_y;
	int radius;
	billboard.GetPositionReference(&position_x, &position_y, &radius);
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
		for (unsigned int i = 0; i < position_y.size() / 16; i++) {
			unsigned int offset_column = 5;
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).line_str_id[engtrig]), 16 * i, offset_column);
			offset_column += 32 + 5;
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).type_id[engtrig]), 16 * i, offset_column);
			offset_column += 32;
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).destination_id[engtrig]), 16 * i, offset_column);
			offset_column += 64;
			if (timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000)
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000), 16 * i, offset_column);
			offset_column += 12;
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 100 % 10), 16 * i, offset_column);
			offset_column += 12;
			billboard.Commit(stringcontroler.GetNumberStringInformation(10), 16 * i, offset_column);
			offset_column +=  3;
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time / 10 % 10), 16 * i, offset_column);
			offset_column += 12;
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 10), 16 * i, offset_column);
			offset_column += 12;
			if (timetablecontroler.GetTrainInformation(id + i).dep) {
				if (engtrig) billboard.Commit(stringcontroler.GetStringInformation("�n��", 'E'), 16 * i, offset_column);
				else billboard.Commit(stringcontroler.GetStringInformation("�n��", 'J'), 16 * i, offset_column);
			}
			if (timetablecontroler.GetTrainInformation(id + i).track / 10) {
				offset_column += 16;
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).track / 10), 16 * i, offset_column);
				offset_column += 10;
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).track % 10), 16 * i, offset_column);
			}
			else {
				offset_column += 21;
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).track % 10), 16 * i, offset_column);
			}
			billboard.Commit(linecontroler.GetLineInformation(timetablecontroler.GetTrainInformation(id + i).line_color_id), 16 * i);
		}
		billboard.Draw();
		ScreenFlip();
		billboard.Clear();
	}
}

