#pragma once
#include "Header.h"
class LineControler
{
private:
	std::vector<LineInformation> veclineinfo;	//路線情報
public:
	LineControler();							//コンストラクタ
	int Init();									//稼働開始メソッド
	/*参照用ゲッタ*/
	LineInformation GetLineInformation(int id);	//IDから路線情報を提供
	int GetLineID(std::string str);				//路線名からIDを提供
	/*参照用ゲッタ*/
	~LineControler();							//デストラクタ
};

