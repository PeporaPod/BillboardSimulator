#include <DxLib.h>
#include "MainFrame.h"



//
//	WinMain関数
//
//		メインフレームの構築
//		処理をメインフレームへ委譲
//
//
//
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MainFrame mainframe;	//メインフレームの構築
	if (mainframe.Start())		//メインフレームの稼働開始
		return 0;					//正常終了
	else
		return -1;					//異常終了
}