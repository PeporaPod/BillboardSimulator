#pragma once
#include <DxLib.h>
#include "Header.h"
#include "Billboard.h"
#include "TimetableControler.h"
#include "StringControler.h"
class StringEditorFrame
{
private:
	/*基幹データ*/
			Billboard			billboard;										//LEDマトリクス
			StringControler		stringcontroler;								//文字列情報制御クラス
	/*基幹データ*/
	/*表示・編集用データ*/
			int					str_vecsize;									//読み込んだ文字列情報の数
			int					current_id;										//現在表示中の文字列情報ID
//			StringInformation	current_strinfo;								//現在表示中の文字列情報
//			StringInformation	new_strinfo;									//新規追加用バッファ
	const	int					font_size = SCREENHEIGHT_STRINGDISPLAY / 12;
	/*表示・編集用データ*/
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
private:
	void MainLoop();
	void EditorMode(StringInformation strinfo, unsigned int register_id);
	void OverWrite(StringInformation rewrite_strinfo, unsigned int current_id);
};

