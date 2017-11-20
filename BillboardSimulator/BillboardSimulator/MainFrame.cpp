#include "MainFrame.h"



MainFrame::MainFrame()
{
	SetAlwaysRunFlag(TRUE);							//常時処理
	ChangeWindowMode(TRUE);							//ウィンドウモード起動
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);	//画面幅・高さ・色ビット深度
	SetDrawScreen(DX_SCREEN_BACK);					//裏画面描画
}

bool MainFrame::Start()
{
	DxLib_Init();				//DxLibの起動
	do {
		mode = 0;
		modechangerframe = new ModeChangerFrame;
		mode = modechangerframe->Start();
		delete modechangerframe;
		switch (mode) {
		case 0:
			break;
		case 1:
			simulatorframe = new SimulatorFrame;
			simulatorframe->Start();
			delete simulatorframe;
		case 2:
			stringcheckerframe = new StringCheckerFrame;
			delete stringcheckerframe;
		default:
			return false;
		}
	} while (mode);
	DxLib_End();				//DxLibの終了
	return true;
}

MainFrame::~MainFrame()
{
}
