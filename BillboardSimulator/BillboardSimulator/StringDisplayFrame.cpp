#include "StringDisplayFrame.h"



//
//	�R���X�g���N�^
//
//
StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);	//�o�b�N�O���E���h�������~
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);	//�`��T�C�Y,�F�r�b�g�[�x�w��
	SetDrawScreen(DX_SCREEN_BACK);	//�`����ʂ𗠉�ʂɎw��
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);	//�t�H���g�T�C�Y�ݒ�
	SetMouseDispFlag(FALSE);	//�}�E�X�|�C���^���\��
	current_str_id = 0;	//�����\��������ID��������
}



//
//	���s�J�n���\�b�h
//
//
void StringDisplayFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGDISPLAY / 3, SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);	//LED�}�g���N�X�̏�����
	size = stringcontroler.Init();	//��������̏�����,�ǂݍ��񂾕����񐔂̎擾
	StringDisplayFrame::MainLoop();	//����s���\�b�h�֐�����Ϗ�
}



//
//	�f�X�g���N�^
//
//
StringDisplayFrame::~StringDisplayFrame()
{
}



//
//	����s���\�b�h
//
//
void StringDisplayFrame::MainLoop()
{
	while (!ProcessMessage() && !ClearDrawScreen() && current_str_id < size) {
		current_strinfo = stringcontroler.GetStringInformation(current_str_id);
		billboard.Commit(current_strinfo.led_map, GetColor(current_strinfo.R, current_strinfo.G, current_strinfo.B));
		billboard.Draw();
		DrawFormatString(0, SCREENHEIGHT_STRINGDISPLAY / 12, GetColor(200, 200, 200), "ID: %03d / type:%c %s\nwidth: %2d | R: %3d G: %3d B: %3d", current_str_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
		ScreenFlip();
		WaitKey();
		if (CheckHitKey(KEY_INPUT_RETURN))
			current_str_id++;
		else if (CheckHitKey(KEY_INPUT_BACK)) {
			if (current_str_id > 0) current_str_id--;
		}
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
			return;
	}
}
