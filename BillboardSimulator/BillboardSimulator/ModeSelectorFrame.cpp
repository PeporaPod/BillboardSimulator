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
	SetFontSize(SCREENHEIGHT_MAIN / 14);								//�t�H���g�T�C�Y�ݒ�
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
	//�I������\��
	DrawString(0, 0, "\nSelect Mode\n 0: End\n 1: Simulator\n 2: String Display\n 3: String Editor", GetColor(200, 200, 200));

	/*���[�h�I��*/
	do {
		WaitKey();							//���͑҂�
		if (CheckHitKey(KEY_INPUT_0))
			return 0;							//�I��
		else if (CheckHitKey(KEY_INPUT_1))
			return 1;							//�V�~�����[�^���[�hID
		else if (CheckHitKey(KEY_INPUT_2))
			return 2;							//������f�B�X�v���C���[�hID
		else if (CheckHitKey(KEY_INPUT_3))
			return 3;							//������G�f�B�^���[�hID
	} while (!ProcessMessage());
	/*���[�h�I��*/

	return -1;									//�G���[��
}



//
//	�f�X�g���N�^
//
//
//
ModeSelectorFrame::~ModeSelectorFrame()
{
}
