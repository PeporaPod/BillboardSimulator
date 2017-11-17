#include <DxLib.h>
#include "Billboard.h"
#include "MainFrame.h"



//
//	���C���֐�
//
//		DxLib�̋N���ݒ�
//		�d���f���̎擾
//		���C�����[�v(�d���f���̒����X�V)
//		�I������
//
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*�����ݒ�*/
	SetAlwaysRunFlag(TRUE);
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h�ŋN��
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);	//��ʕ��E�����E�F�r�b�g�[�x
	SetDrawScreen(DX_SCREEN_BACK);					//�`��͗���ʂōs��
	if (DxLib_Init() == -1) return -1;				//DxLib�̋N��
	/*�����ݒ�*/


	/*���C���t���[���̍\�z*/
	MainFrame mainframe;
	mainframe.Start();
	/*���C���t���[���̍\�z*/


	/*�d���f���̗p��*/
	Billboard billboard;			//�d���f����
	if (!billboard.Init()) return -1;	//����������
	/*�d���f���̗p��*/


	/*�又��*/
	if (DxLib_Init() == -1)		//DxLib�̋N��
		return -1;					//�G���[����
	
	billboard.Start();			//�d���f���̉ғ��J�n

	while (!ProcessMessage())	//���C�����[�v
		billboard.Update();			//��������
	
	DxLib_End();				//DxLibrary�̏I��
	/*�又��*/
	

	return 0;	//���C���֐��̏I��
}