#pragma once
#include <DxLib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>



//
//	定数定義
//
//		画面サイズ(画面幅 / 画面高)
//		LEDの半径
//		LEDの中心距離
//		表示が変わるまでの時間[ミリ秒]
//
//
const int SCREENWIDTH	= 1500;					//画面幅
const int SCREENHEIGHT	=  775;					//画面高
const int RADIUS		=    2;					//LED半径
const int DISTANCE		= (2 * (RADIUS + 1));	//LEDの中心距離
const int DISPLAYROW	=    8;					//表示列車数
const int DISPLAYTIME	= 2500;					//表示時間[ミリ秒]



//
//	型の別名定義
//
//		負の数を除く整数	:	unsigned int				→ UNSIGNEDINT
//		色コード			:	unsigned int				→ COLOR
//		ブール平面			:	std::vector<std::vector>>	→ BOOLTABLE
//
//
typedef unsigned int			UNSIGNEDINT;	//負の数を除く整数(ゼロ / 自然数)
typedef unsigned int			COLOR;			//色コード
typedef std::vector<bool>		BOOLROW;		//ブール行
typedef std::vector<BOOLROW>	BOOLTABLE;		//ブール表



//
//	LED
//
//		LED構造体
//			LED単体の位置(横軸 / 縦軸)
//			LED単体の発光色
//		LED行
//		LED表(LED行列)
//		消灯は色で仮想的に表す
//
//
typedef struct LED {
	int		x;		//横軸位置
	int		y;		//縦軸位置
	COLOR	color;	//色
}LED;
typedef std::vector<LED>				LEDROW;		//LED行
typedef std::vector<std::vector<LED>>	LEDTABLE;	//LED表
#define LED_OFF							4280229663	//仮想消灯色(unsigned int GetColor(32, 32, 32))



//
//	表示文字列
//
//		【PRE】使用するLEDの縦横幅
//
//		文字列が持つ情報
//			あらわす文字列
//			LEDでの表現
//			使用するLEDの縦横幅
//			発光色
//
//
typedef struct TABLESIZE {
	int row		= 0;	//縦幅
	int column	= 0;	//横幅
}TABLESIZE;
typedef struct StringInformation {
	std::string	string;	//文字列
	BOOLTABLE	table;	//点灯表
	TABLESIZE	size;	//サイズ
	COLOR		color;	//色
}StringInformation;
#define SEGDIRECTORY "SEG\\"
#define SEGNUMBERSTRINGDIRECTORY "SEG\\NUMBERSTRING\\"
#define SEGEXTENSION ".seg"



//
//	路線情報
//
//		路線名
//		路線色
//
//
typedef struct LineInformation {
	std::string	line;
	COLOR		color[2];
}LineInformation;
typedef std::vector<LineInformation> LINELIST;
#define LINEFILE "DATA\\LINE.csv"



//
//	列車情報
//
//		路線(ID)
//		種別(ID)
//		発車時刻
//		行先(ID)
//
//
typedef struct TrainInformation {
	COLOR linecolor;
	int	line;
	int	type;
	int	time;
	int	destination;
}TrainInformation;
typedef std::vector<TrainInformation> TIMETABLE;
#define TIMETABLEFILE "DATA\\TIMETABLE.csv"



//
//	文字列が数字のみで構成されていることを確認する
//
//		数字のみ			:	bool true
//		数字以外が含まれる	:	bool false
//
//
bool Check_StringToInt(std::string string);