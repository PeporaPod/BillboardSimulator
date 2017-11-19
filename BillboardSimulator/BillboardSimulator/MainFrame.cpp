#include "MainFrame.h"



MainFrame::MainFrame()
{
	SetAlwaysRunFlag(TRUE);							//常時処理
	ChangeWindowMode(TRUE);							//ウィンドウモード起動
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);	//画面幅・高さ・色ビット深度
	SetDrawScreen(DX_SCREEN_BACK);					//裏画面描画
	DxLib_Init();									//DxLibの起動
}

bool MainFrame::Start()
{
	printfDx("Initializing Billboard\n"); ScreenFlip();
	billboard.Init();
	billboard.Start();

	return true;
}

MainFrame::~MainFrame()
{
	DxLib_End();							//DxLibの終了
}
