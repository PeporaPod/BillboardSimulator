#pragma once
#include <vector>





//
//	定数定義
//
//
//

/*画面表示関連*/
const int SCREENWIDTH_MAIN				=  640;	//通常時画面幅
const int SCREENHEIGHT_MAIN				=  480;	//通常時画面高
const int SCREENWIDTH_SIMULATOR			= 1600;	//シミュレータ画面幅
const int SCREENHEIGHT_SIMULATOR		=  800;	//シミュレータ画面高
const int SCREENWIDTH_STRINGDISPLAY		= 1500;	//文字列ディスプレイモード画面幅
const int SCREENHEIGHT_STRINGDISPLAY	=  600;	//文字列ディスプレイモード画面幅
const int SCREENWIDTH_STRINGEDITOR		= 1600;	//文字列エディタ画面幅
const int SCREENHEIGHT_STRINGEDITOR		=  800;	//文字列エディタ画面高
const int COLORBITDEPTH					=   32;	//色ビット深度
/*画面表示関連*/

/*表示要素関連*/
const int LED_RADIUS					=    2;	//シミュレータモードLED半径
const int LED_ROW						=   16;	//文字列表示モード時行数
const int LED_COLUMN					=   64;	//文字列表示モード時列数
const int STRING_LENGTH					=   24;	//文字列長
/*表示要素関連*/





//
//	構造体定義
//
//
//

/*列車情報*/
typedef struct TrainInformation {			//シミュレータ用
	int line_id;								//路線ID
	int type_id;								//種別ID
	int destination_id;							//行先ID
}TrainInformation;


typedef struct TrainInformationAsString {	//文字列タイプ
	std::vector<std::string> line;				//路線名
	std::vector<std::string> type;				//種別名
	std::vector<std::string> destination;		//行先
}TrainInformationAsString;
/*列車情報*/


/*文字列情報*/
typedef struct StringInformation {
	char string[STRING_LENGTH] = { NULL };			//文字列
	int width = LED_COLUMN;							//文字列幅
	char type = '?';								//文字列種
	unsigned __int8 R = 32, G = 32, B = 32;			//RGB色
	unsigned long long led_status[LED_ROW] = { 0 };	//点灯表
}StringInformation;
/*文字列情報*/