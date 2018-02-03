#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "SimulatorFrame.h"
#include "StringDisplayFrame.h"
#include "StringEditorFrame.h"



//
//	MainFrameクラス
//
//		属性
//			モード
//			モードセレクタ(クラスのポインタ)
//			シミュレータ(クラスのポインタ)
//			文字列ディスプレイ(クラスのポインタ)
//			文字列エディタ(クラスのポインタ)
//		メソッド
//			コンストラクタ
//				ウィンドウモード切替
//				フォント設定
//			稼働開始メソッド
//				DXライブラリの起動
//				稼働開始
//			デストラクタ
//				DXライブラリの終了
//
//
//
class MainFrame
{
	int						mode;				//モードID
	ModeSelectorFrame	*	modeselectorframe;	//モードセレクタ
	SimulatorFrame		*	simulatorframe;		//シミュレータ
	StringDisplayFrame	*	stringdisplayframe;	//文字列ディスプレイ
	StringEditorFrame	*	stringeditorframe;	//文字列エディタ
public:
	MainFrame();	//コンストラクタ
	bool Start();	//稼働開始メソッド
	~MainFrame();	//デストラクタ
};

