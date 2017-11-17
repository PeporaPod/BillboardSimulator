#include <DxLib.h>
#include "Billboard.h"
#include "MainFrame.h"



//
//	メイン関数
//
//		DxLibの起動設定
//		電光掲示板の取得
//		メインループ(電光掲示板の逐次更新)
//		終了処理
//
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*初期設定*/
	SetAlwaysRunFlag(TRUE);
	ChangeWindowMode(TRUE);							//ウィンドウモードで起動
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);	//画面幅・高さ・色ビット深度
	SetDrawScreen(DX_SCREEN_BACK);					//描画は裏画面で行う
	if (DxLib_Init() == -1) return -1;				//DxLibの起動
	/*初期設定*/


	/*メインフレームの構築*/
	MainFrame mainframe;
	mainframe.Start();
	/*メインフレームの構築*/


	/*電光掲示板の用意*/
	Billboard billboard;			//電光掲示板
	if (!billboard.Init()) return -1;	//初期化処理
	/*電光掲示板の用意*/


	/*主処理*/
	if (DxLib_Init() == -1)		//DxLibの起動
		return -1;					//エラー処理
	
	billboard.Start();			//電光掲示板の稼働開始

	while (!ProcessMessage())	//メインループ
		billboard.Update();			//逐次処理
	
	DxLib_End();				//DxLibraryの終了
	/*主処理*/
	

	return 0;	//メイン関数の終了
}