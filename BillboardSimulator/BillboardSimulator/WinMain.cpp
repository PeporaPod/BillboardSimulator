#include <DxLib.h>
#include "MainFrame.h"



//
//	メイン関数
//
//		メインフレームの構築 / 稼働
//		プログラムの終了
//
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MainFrame mainframe;	//メインフレームの構築
	mainframe.Start();			//稼働開始
	return 0;				//プログラムの終了
}