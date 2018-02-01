#pragma once
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
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
const int SCREENHEIGHT_STRINGDISPLAY	=  600;	//文字列ディスプレイモード画面高
const int SCREENWIDTH_STRINGEDITOR		= 1600;	//文字列エディタ画面幅
const int SCREENHEIGHT_STRINGEDITOR		=  800;	//文字列エディタ画面高
const int COLORBITDEPTH					=   32;	//色ビット深度
/*画面表示関連*/

/*表示要素関連*/
const int LED_RADIUS					=    2;	//シミュレータモードLED半径
const int LED_ROW						=   16;	//文字列表示モード時行数
const int LED_COLUMN					=   64;	//文字列表示モード時列数
/*表示要素関連*/





//
//	構造体定義
//
//
//

/*路線情報*/
typedef struct LineInformation {
				std::string str		= "Error";
	unsigned	__int8		R[2]	= { 255, 255 };
	unsigned	__int8		G[2]	= { 255, 255 };
	unsigned	__int8		B[2]	= { 255, 255 };
}LineInformation;
/*路線情報*/


/*列車情報*/
typedef struct TrainInformation {			//シミュレータ用
	int line_id = -1;							//路線ID
	int type_id[2] = { -1, -1 };				//種別ID
	int departure_time = -1;					//発車時刻用の数字ID
	int destination_id[2] = { -1, -1 };			//行先ID
}TrainInformation;
/*列車情報*/


/*文字列情報*/
typedef struct StringInformation {
				std::string	str			= "Error";	//文字列
				char		type		= '?';		//文字列種
	unsigned	long long	led_map[16] = { NULL };	//LEDマップ
	unsigned	__int8		width		= 0;		//LED使用幅
	unsigned	__int8		R			= 32;		//赤色光度
	unsigned	__int8		G			= 32;		//緑色光度
	unsigned	__int8		B			= 32;		//青色光度
}StringInformation;
/*文字列情報*/