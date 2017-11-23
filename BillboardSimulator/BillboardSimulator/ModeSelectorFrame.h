#pragma once
#include <DxLib.h>
#include "Header.h"



//
//	ModeSelectorFrameクラス
//
//		メソッド
//			コンストラクタ
//				常時処理設定
//				描画画面設定
//				フォント設定
//			Start()
//				稼働開始
//			デストラクタ
//
class ModeSelectorFrame
{
public:
	ModeSelectorFrame();	//コンストラクタ
	int Start();			//稼働開始メソッド
	~ModeSelectorFrame();	//デストラクタ
};

