#include "StringEditorFrame.h"



//
//	�R���X�g���N�^
//
//
StringEditorFrame::StringEditorFrame()
{
	SetAlwaysRunFlag(FALSE);															//�o�b�N�O���E���h���͏������~
	SetGraphMode(SCREENWIDTH_STRINGEDITOR, SCREENHEIGHT_STRINGEDITOR, COLORBITDEPTH);	//��ʕ��E��ʍ��E�F�r�b�g�[�x��ݒ�
	SetDrawScreen(DX_SCREEN_FRONT);														//�\��ʕ`��
	SetFontSize(font_size);																//�t�H���g�T�C�Y�ݒ�
	SetMouseDispFlag(TRUE);																//�}�E�X�J�[�\���\������
}



//
//	���s�J�n���\�b�h
//
//
void StringEditorFrame::Start()
{
	cursor_row = 0;																												//���݃^�[�Q�b�g���Ă���J�[�\���̍s��������
	cursor_column = 0;																											//���݃^�[�Q�b�g���Ă���J�[�\���̗��������
	current_id = 0;																												//���ݕ\�����̕�����ID��������
	billboard.Init(SCREENHEIGHT_STRINGEDITOR / 2, SCREENHEIGHT_STRINGEDITOR, 0, SCREENWIDTH_STRINGEDITOR, LED_ROW, LED_COLUMN);	//LED�}�g���N�X�̏�����
	str_vecsize = stringcontroler.Init();																						//��������̏�����,�ǂݍ��񂾕����񐔂̎擾
	MainLoop();																													//����s���\�b�h�ɏ������Ϗ�
}



//
//	�f�X�g���N�^
//
//
StringEditorFrame::~StringEditorFrame()
{
}





//
//	����s���\�b�h
//
//
void StringEditorFrame::MainLoop()
{
	std::vector<int> position_x;
	std::vector<int> position_y;
	int radius;
	billboard.GetPositionReference(&position_x, &position_y, &radius);
	current_strinfo = stringcontroler.GetStringInformation(current_id);
	while (!ProcessMessage() && !ClearDrawScreen() && current_id < str_vecsize) {
		billboard.Commit(current_strinfo.led_map, GetColor(current_strinfo.R, current_strinfo.G, current_strinfo.B));
		billboard.Draw();
		DrawFormatString(0, SCREENHEIGHT_STRINGDISPLAY / 12, GetColor(200, 200, 200), "ID: %03d / type:%c %s\nwidth: %2d | R: %3d G: %3d B: %3d", current_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
		DrawLine(position_x[cursor_column] - radius, position_y[cursor_row] + radius, position_x[cursor_column] + radius, position_y[cursor_row] + radius, GetColor(255, 255, 255));
		ScreenFlip();
		WaitKey();
		if (CheckHitKey(KEY_INPUT_END))
			current_strinfo = stringcontroler.GetStringInformation(++current_id);
		else if (CheckHitKey(KEY_INPUT_HOME) && current_id > 0)
			current_strinfo = stringcontroler.GetStringInformation(--current_id);
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
			return;
		else if (CheckHitKey(KEY_INPUT_UP) && cursor_row > 0)
			cursor_row--;
		else if (CheckHitKey(KEY_INPUT_DOWN) && cursor_row < LED_ROW - 1)
			cursor_row++;
		else if (CheckHitKey(KEY_INPUT_LEFT) && cursor_column > 0)
			cursor_column--;
		else if (CheckHitKey(KEY_INPUT_RIGHT) && cursor_column < LED_COLUMN - 1)
			cursor_column++;
		else if (CheckHitKey(KEY_INPUT_RETURN)) {
			unsigned long long operatorbit = 0x8000000000000000;
			operatorbit >>= cursor_column;
			current_strinfo.led_map[cursor_row] ^= operatorbit;
		}
		else if (CheckHitKey(KEY_INPUT_J))
			current_strinfo.type = 'J';
		else if (CheckHitKey(KEY_INPUT_E))
			current_strinfo.type = 'E';
		else if (CheckHitKey(KEY_INPUT_S))
			current_strinfo.type = 'S';
		else if (CheckHitKey(KEY_INPUT_N))
			current_strinfo.type = 'N';
		else if (CheckHitKey(KEY_INPUT_SPACE)) {
			printfDx("OverWrite?[Return or Not]");
			WaitKey();
			if (CheckHitKey(KEY_INPUT_RETURN)) {
				OverWrite(current_strinfo, current_id);//�㏑���p�֐�
				stringcontroler.Init();
			}
			ClearDrawScreen();
			clsDx();
		}
		else if (CheckHitKey(KEY_INPUT_T)) {
			printfDx("StringEdit[T or Not]");
			WaitKey();
			if (CheckHitKey(KEY_INPUT_T)) {
				char str[64];
				if (KeyInputString(600, 50, 63, str, TRUE) == 1)
					current_strinfo.str = str;
			}
			clsDx();
		}
		else if (CheckHitKey(KEY_INPUT_COLON))
			EditMode();
	}
}



//
//	��������ҏW���[�h
//
//
void StringEditorFrame::EditMode()
{
	ClearDrawScreen();
	DrawString(0, (int)(0.5 * font_size), "�ҏW���[�h", GetColor(200, 200, 200));
	WaitTimer(2000);

	std::vector<int> position_x;
	std::vector<int> position_y;
	int radius;
	billboard.GetPositionReference(&position_x, &position_y, &radius);
}



//
//	�ҏW���e�̏㏑�����\�b�h
//
//
void StringEditorFrame::OverWrite(StringInformation rewrite_strinfo, unsigned int current_id)
{
	cursor_row = 0;																												//���݃^�[�Q�b�g���Ă���J�[�\���̍s��������
	cursor_column = 0;																											//���݃^�[�Q�b�g���Ă���J�[�\���̗��������
	char filepath[8];
	sprintf_s<sizeof(filepath)>(filepath, "STR\\%03u", current_id + 1);
	std::ofstream file(filepath, std::fstream::binary);
	for (int i = 0; i < 16; i++)
		file.write((char*)(rewrite_strinfo.led_map + i), sizeof(unsigned long long));
	file.write((char*)&rewrite_strinfo.width, sizeof(unsigned __int8));
	file.write((char*)&rewrite_strinfo.R, sizeof(unsigned __int8));
	file.write((char*)&rewrite_strinfo.G, sizeof(unsigned __int8));
	file.write((char*)&rewrite_strinfo.B, sizeof(unsigned __int8));
	file.write((char*)&rewrite_strinfo.type, sizeof(unsigned __int8));
	for (unsigned int i = 0; i < rewrite_strinfo.str.size(); i++)
		file.write(&rewrite_strinfo.str[i], sizeof(char));
	char terminator = 0;
	file.write((char*)&terminator, sizeof(char));
}
