#include "StringDisplayFrame.h"



//
//	�R���X�g���N�^
//
//
StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);															//�o�b�N�O���E���h�������~
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);	//�`��T�C�Y,�F�r�b�g�[�x�w��
	SetDrawScreen(DX_SCREEN_BACK);														//�`����ʂ𗠉�ʂɎw��
	SetFontSize(font_size);																//�t�H���g�T�C�Y�ݒ�
	SetMouseDispFlag(TRUE);																//�}�E�X�|�C���^��\��
	current_id = 0;																		//�����\��������ID��������
}



//
//	���s�J�n���\�b�h
//
//
void StringDisplayFrame::Start()
{
	billboard.Init((int)(font_size * 4), SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);	//LED�}�g���N�X�̏�����
	str_vecsize = stringcontroler.Init();																					//��������̏�����,�ǂݍ��񂾕����񐔂̎擾
	StringDisplayFrame::MainLoop();																							//����s���\�b�h�֐�����Ϗ�
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
	while (!ProcessMessage() && current_id < str_vecsize) {
		current_strinfo = stringcontroler.GetStringInformation(current_id);	//��������̎擾

		/*�`�揈��*/
			//����ʂ̏�����
		ClearDrawScreen();
			//���̕`��
		DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R: %02x G: %02x B: %02x", current_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
			//LED�}�g���N�X�փ}�b�s���O�𔽉f
		billboard.Commit(current_strinfo.led_map, GetColor(current_strinfo.R, current_strinfo.G, current_strinfo.B));
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
		else if (CheckHitKey(KEY_INPUT_ESCAPE))						//�I��
			return;
		/*���[�U����*/
	}
}

