#include "StringEditorFrame.h"



//
//	�R���X�g���N�^
//
//
StringEditorFrame::StringEditorFrame()
{
	SetAlwaysRunFlag(FALSE);															//�o�b�N�O���E���h���͏������~
	SetGraphMode(SCREENWIDTH_STRINGEDITOR, SCREENHEIGHT_STRINGEDITOR, COLORBITDEPTH);	//��ʕ��E��ʍ��E�F�r�b�g�[�x��ݒ�
	SetDrawScreen(DX_SCREEN_BACK);														//����ʕ`��
	SetFontSize(font_size);																//�t�H���g�T�C�Y�ݒ�
	SetMouseDispFlag(TRUE);																//�}�E�X�J�[�\���\������
}



//
//	���s�J�n���\�b�h
//
//
void StringEditorFrame::Start()
{
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
	ClearDrawScreen();
	ScreenFlip();
	ClearDrawScreen();
}





//
//	����s���\�b�h
//
//
void StringEditorFrame::MainLoop()
{
	while (!ProcessMessage() && current_id < str_vecsize) {
		StringInformation current_strinfo = stringcontroler.GetStringInformation(current_id);	//��������̎擾

		/*�`�揈��*/
			//����ʂ̏�����
		ClearDrawScreen();
		//LED�}�g���N�X�̓_����Ԃ��N���A
		billboard.Clear();
		//���̕`��
		DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R: %03u G: %03u B: %03u", current_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
		//LED�}�g���N�X�փ}�b�s���O�𔽉f
		billboard.Commit(current_strinfo);
		//LED�}�g���N�X�̕`��
		billboard.Draw();
		//��ʂ̃t���b�s���O
		ScreenFlip();
		/*�`�揈��*/

		/*���[�U����*/
		WaitKey();	//�L�[���͑҂�
		if (CheckHitKey(KEY_INPUT_RETURN))							//���̕�����
			current_id++;
		else if (CheckHitKey(KEY_INPUT_BACK) && current_id > 0)		//�O�̕�����
			current_id--;
		else if (CheckHitKey(KEY_INPUT_HOME))						//�擪�̕�����
			current_id = 0;
		else if (CheckHitKey(KEY_INPUT_END))						//�����̕�����
			current_id = str_vecsize - 1;
		else if (CheckHitKey(KEY_INPUT_PGDN))						//10�O�̕����ֈړ�
			if (current_id > 9)	current_id -= 10;
			else current_id = 0;
		else if (CheckHitKey(KEY_INPUT_PGUP))						//10��̕����ֈړ�
			if (current_id < str_vecsize - 10)	current_id += 10;
			else current_id = str_vecsize - 1;
		else if (CheckHitKey(KEY_INPUT_E))							//���ݕ\�����̕�����̕ҏW���J�n
			EditorMode(current_strinfo, current_id);
		else if (CheckHitKey(KEY_INPUT_N))							//�V�K������̒ǉ����J�n
			EditorMode(StringInformation(), str_vecsize);
		else if (CheckHitKey(KEY_INPUT_ESCAPE))						//�I��
			return;
		/*���[�U����*/
	}
}



//
//	��������ҏW���[�h
//
//
void StringEditorFrame::EditorMode(StringInformation strinfo, unsigned int register_id)
{
	ClearDrawScreen();
	DrawString(0, (int)(0.5 * font_size), "�ҏW���[�h", GetColor(200, 200, 200));
	ScreenFlip();
	WaitTimer(1000);

	int cursor_row = 0;																												//���݃^�[�Q�b�g���Ă���J�[�\���̍s��������
	int cursor_column = 0;																											//���݃^�[�Q�b�g���Ă���J�[�\���̗��������
	std::vector<int> position_x;
	std::vector<int> position_y;
	int radius;
	billboard.GetPositionReference(&position_x, &position_y, &radius);
	while (!ProcessMessage() && !ClearDrawScreen()) {
		billboard.Clear();
		DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R: %03u G: %03u B: %03u", register_id + 1, strinfo.type, strinfo.str.c_str(), strinfo.width, strinfo.R, strinfo.G, strinfo.B);
		billboard.Commit(strinfo);
		billboard.Draw();
		DrawLine(position_x[cursor_column] - radius, position_y[cursor_row] + radius, position_x[cursor_column] + radius, position_y[cursor_row] + radius, GetColor(255, 255, 255));
		ScreenFlip();
		WaitKey();
		if		(CheckHitKey(KEY_INPUT_UP) && cursor_row > 0)
			cursor_row--;
		else if (CheckHitKey(KEY_INPUT_DOWN) && cursor_row < LED_ROW - 1)
			cursor_row++;
		else if (CheckHitKey(KEY_INPUT_LEFT) && cursor_column > 0)
			cursor_column--;
		else if (CheckHitKey(KEY_INPUT_RIGHT) && cursor_column < LED_COLUMN - 1)
			cursor_column++;
		else if (CheckHitKey(KEY_INPUT_J))
			strinfo.type = 'J';
		else if (CheckHitKey(KEY_INPUT_E))
			strinfo.type = 'E';
		else if (CheckHitKey(KEY_INPUT_S))
			strinfo.type = 'S';
		else if (CheckHitKey(KEY_INPUT_N))
			strinfo.type = 'N';
		else if (CheckHitKey(KEY_INPUT_INSERT)) {
			unsigned long long operatorbit = 0xffffffffffffffff;
			operatorbit >>= cursor_column + 1;
			for (int i = 0; i < LED_ROW; i++)
				strinfo.led_map[i] = (strinfo.led_map[i] >> 1 & operatorbit) | (~operatorbit << 1 & strinfo.led_map[i]);
		}
		else if (CheckHitKey(KEY_INPUT_DELETE)) {
			unsigned long long operatorbit = 0xffffffffffffffff;
			operatorbit >>= cursor_column;
			for (int i = 0; i < LED_ROW; i++)
				strinfo.led_map[i] = (strinfo.led_map[i] << 1 & operatorbit) | (~operatorbit & strinfo.led_map[i]);
		}
		else if (CheckHitKey(KEY_INPUT_RETURN)) {
			unsigned long long operatorbit = 0x8000000000000000;
			operatorbit >>= cursor_column;
			strinfo.led_map[cursor_row] ^= operatorbit;
		}
		else if (GetMouseInput() == MOUSE_INPUT_LEFT) {
			int mouse_x, mouse_y;
			int row = -1, column = -1;
			GetMousePoint(&mouse_x, &mouse_y);
			for (unsigned int i = 0; i < position_y.size(); i++)
				if ((mouse_y - position_y[i]) * (mouse_y - position_y[i]) < (radius + 1) * (radius + 1))
					row = i;
			for (unsigned int i = 0; i < position_x.size(); i++)
				if ((mouse_x - position_x[i]) * (mouse_x - position_x[i]) < (radius + 1) * (radius + 1))
					column = i;
			if (row != -1 && column != -1) {
				cursor_row = row, cursor_column = column;
				unsigned long long operatorbit = 0x8000000000000000;
				operatorbit >>= cursor_column;
				strinfo.led_map[cursor_row] ^= operatorbit;
			}
		}
		else if (CheckHitKey(KEY_INPUT_T)) {
			ClearDrawScreen();
			billboard.Clear();
			DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c /\nwidth: %02d | R: %03u G: %03u B: %03u", register_id + 1, strinfo.type, strinfo.width, strinfo.R, strinfo.G, strinfo.B);
			billboard.Commit(strinfo);
			billboard.Draw();
			ScreenFlip();
			char str[64];
			if (KeyInputString(GetDrawFormatStringWidth("ID:%03d / type:%c / ", register_id + 1, strinfo.type), (int)(0.5 * font_size), 63, str, TRUE) == 1)
				strinfo.str = str;
		}
		else if (CheckHitKey(KEY_INPUT_W)) {
			ClearDrawScreen();
			billboard.Clear();
			DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth:", register_id + 1, strinfo.type, strinfo.str.c_str());
			DrawFormatString(GetDrawFormatStringWidth("width: %02d | ", strinfo.width), (int)(2.5 * font_size), GetColor(200, 200, 200), "R: %03u G: %03u B: %03u", strinfo.R, strinfo.G, strinfo.B);
			billboard.Commit(strinfo);
			billboard.Draw();
			ScreenFlip();
			strinfo.width = KeyInputNumber(GetDrawFormatStringWidth("width: "), (int)(2.5 * font_size), 64, 0, FALSE);
		}
		else if (CheckHitKey(KEY_INPUT_R)) {
			ClearDrawScreen();
			billboard.Clear();
			DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R:", register_id + 1, strinfo.type, strinfo.str.c_str(), strinfo.width);
			DrawFormatString(GetDrawFormatStringWidth("width: %02d | R: %03u ", strinfo.width, strinfo.R), (int)(2.5 * font_size), GetColor(200, 200, 200), "G: %03u B: %03u", strinfo.G, strinfo.B);
			billboard.Commit(strinfo);
			billboard.Draw();
			ScreenFlip();
			strinfo.R = KeyInputNumber(GetDrawFormatStringWidth("width: %02d | R: ", strinfo.width), (int)(2.5 * font_size), 255, 0, FALSE);
		}
		else if (CheckHitKey(KEY_INPUT_G)) {
			ClearDrawScreen();
			billboard.Clear();
			DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R: %03u G:", register_id + 1, strinfo.type, strinfo.str.c_str(), strinfo.width, strinfo.R);
			DrawFormatString(GetDrawFormatStringWidth("width: %02d | R: %03u G: %03u ", strinfo.width, strinfo.R, strinfo.G), (int)(2.5 * font_size), GetColor(200, 200, 200), "B: %03u", strinfo.B);
			billboard.Commit(strinfo);
			billboard.Draw();
			ScreenFlip();
			strinfo.G = KeyInputNumber(GetDrawFormatStringWidth("width: %02d | R: %03u G: ", strinfo.width, strinfo.R), (int)(2.5 * font_size), 255, 0, FALSE);
		}
		else if (CheckHitKey(KEY_INPUT_B)) {
			ClearDrawScreen();
			billboard.Clear();
			DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R: %03u G: %03u B:", register_id + 1, strinfo.type, strinfo.str.c_str(), strinfo.width, strinfo.R, strinfo.G);
			billboard.Commit(strinfo);
			billboard.Draw();
			ScreenFlip();
			strinfo.B = KeyInputNumber(GetDrawFormatStringWidth("width: %02d | R: %03u G: %03u B: ", strinfo.width, strinfo.R, strinfo.G), (int)(2.5 * font_size), 255, 0, FALSE);
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			ClearDrawScreen();
			DrawString(0, (int)(0.5 * font_size), "�ҏW���e��j�����܂�[�ēxESC�Ŋm��]", GetColor(200, 200, 200));
			ScreenFlip();
			WaitKey();
			if (CheckHitKey(KEY_INPUT_ESCAPE))
				return;
		}
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			ClearDrawScreen();
			DrawString(0, (int)(0.5 * font_size), "�ҏW���e���㏑�����܂�[ENTER�Ŋm��]", GetColor(200, 200, 200));
			ScreenFlip();
			WaitKey();
			if (CheckHitKey(KEY_INPUT_RETURN)) {
				OverWrite(strinfo, register_id);
				str_vecsize = stringcontroler.Init();
				return;
			}
		}
	}
}



//
//	�ҏW���e�̏㏑�����\�b�h
//
//
void StringEditorFrame::OverWrite(StringInformation rewrite_strinfo, unsigned int current_id)
{
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
