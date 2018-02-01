#include "ModeSelectorFrame.h"



//
//	�R���X�g���N�^
//
//		�펞�����ݒ�
//		��ʕ`��ݒ�
//		�t�H���g�ݒ�
//
//
//
ModeSelectorFrame::ModeSelectorFrame()
{
	SetAlwaysRunFlag(FALSE);											//�펞�������I�t
	SetGraphMode(SCREENWIDTH_MAIN, SCREENHEIGHT_MAIN, COLORBITDEPTH);	//��ʃT�C�Y�ݒ�
	SetDrawScreen(DX_SCREEN_FRONT);										//�\��ʕ`��
	SetFontSize(font_size);												//�t�H���g�T�C�Y�ݒ�
	SetMouseDispFlag(TRUE);												//�}�E�X�\����"����"�ɐݒ�
}



//
//	Start���\�b�h
//
//		�I�����\��
//		���[�h�I��
//
//
//
int ModeSelectorFrame::Start()
{
	/*�I������\��*/
	DrawString(0, (int)(0.5 * font_size), "���[�h��I�����ĉ�����\n 0: �v���O�����̏I��\n 1: �V�~�����[�^���[�h\n 2: ������m�F���[�h\n 3: ������ҏW���[�h", GetColor(200, 200, 200));
	/*�I������\��*/

	/*���[�h�I��*/
	do {
		WaitKey();										//���͑҂�
		if		(CheckHitKey(KEY_INPUT_0)) return 0;		//�I��
		else if (CheckHitKey(KEY_INPUT_1)) return 1;		//�V�~�����[�^���[�hID
		else if (CheckHitKey(KEY_INPUT_2)) return 2;		//������f�B�X�v���C���[�hID
		else if (CheckHitKey(KEY_INPUT_3)) return 3;		//������G�f�B�^���[�hID
	} while (!ProcessMessage());
	return -1;											//�G���[��
	/*���[�h�I��*/
}



//
//	�f�X�g���N�^
//
//
//
ModeSelectorFrame::~ModeSelectorFrame()
{
}
