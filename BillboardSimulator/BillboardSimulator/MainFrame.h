#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "SimulatorFrame.h"
#include "StringDisplayFrame.h"
#include "StringEditorFrame.h"



//
//	MainFrameクラス
//
//		要素
//			モード
//			モードセレクタ
//			シミュレータ
//			文字列ディスプレイ
//			文字列エディタ
//		メソッド
//			コンストラクタ
//				ウィンドウモード切替
//				フォント設定
//				DXライブラリの起動
//			Start()
//				稼働開始
//			デストラクタ
//				DXライブラリの終了
//
//
//
class MainFrame
{
	int					mode;				//モードID
	ModeSelectorFrame*	modeselectorframe;	//モードセレクタ
	SimulatorFrame*		simulatorframe;		//シミュレータ
	StringDisplayFrame*	stringdisplayframe;	//文字列ディスプレイ
	StringEditorFrame*	stringeditorframe;	//文字列エディタ
public:
	MainFrame();	//コンストラクタ
	bool Start();	//稼働開始メソッド
	~MainFrame();	//デストラクタ
};

