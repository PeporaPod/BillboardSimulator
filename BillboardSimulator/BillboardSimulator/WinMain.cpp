#include <DxLib.h>
#include "MainFrame.h"



//
//	WinMain�֐�
//
//		���C���t���[���̍\�z
//		���������C���t���[���ֈϏ�
//
//
//
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MainFrame mainframe;	//���C���t���[���̍\�z
	if (mainframe.Start())		//���C���t���[���̉ғ��J�n
		return 0;					//����I��
	else
		return -1;					//�ُ�I��
}