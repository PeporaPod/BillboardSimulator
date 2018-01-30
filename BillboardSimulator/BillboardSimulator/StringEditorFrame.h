#pragma once
#include <DxLib.h>
#include "Header.h"
#include "Billboard.h"
#include "Timetable.h"
#include "StringControler.h"
class StringEditorFrame
{
private:
	Billboard billboard;	//LEDマトリクス
	StringControler stringcontroler; //文字列情報制御クラス
	int size;	//読み込んだ文字列情報の数
	int current_id;	//現在表示中の文字列情報ID
	StringInformation current_strinfo;	//現在表示中の文字列情報
	StringInformation new_strinfo;	//新規追加用バッファ
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
private:
	void WriteOut();
};

