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
const int COLORBITDEPTH =   32;					//色ビット深度
const int RADIUS		=    2;					//LED半径
const int DISTANCE		= (2 * (RADIUS + 1));	//LEDの中心距離
const int LED_ROW		=   16;					//LED行数
const int DISPLAYROW	=    8;					//表示列車数
const int DISPLAYTIME	= 2500;					//表示時間[ミリ秒]



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
				int	x;		//横軸位置
				int	y;		//縦軸位置
	unsigned	int color;	//色
}LED;
typedef std::vector<LED>				LED_ARRAY;	//LED配列
typedef std::vector<std::vector<LED>>	LED_MATRIX;	//LEDマトリクス



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
				char		string[24];		//文字列
				int			width;			//LED幅
				char		type;			//文字列種別
	unsigned	int			R;				//赤濃度
	unsigned	int			G;				//緑濃度
	unsigned	int			B;				//青濃度
	unsigned	long long	LED_Status[16];	//LED点灯表
}StringInformation;



//
//	路線情報
//
//		路線名
//		路線色
//
//
typedef struct LineInformation {
	std::string		line;
	unsigned int	color[2];
}LineInformation;
typedef std::vector<LineInformation> LINELIST;



//
//	列車情報
//
//
typedef struct TrainInformation {
	std::string line;
	std::string type;
	std::string departure_time;
	std::string destination;
	std::string platform;
}TrainInformation;
typedef std::vector<TrainInformation> TIMETABLE;



//
//	文字列が数字のみで構成されていることを確認する
//
//		数字のみ			:	bool true
//		数字以外が含まれる	:	bool false
//
//
bool Check_StringToInt(std::string string);



//
bool LoadBinaryString(std::vector<StringInformation>& vecstrinfo, int filenumber);