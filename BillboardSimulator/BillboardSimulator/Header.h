#pragma once
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <DxLib.h>





//フルスクリーンモードで起動するトリガ
//#define FULL_SCREEN





//
//	定数定義
//
//
//

/*画面表示関連*/
#ifdef FULL_SCREEN
const int SCREENWIDTH_MAIN				= 1920;	//通常時画面解像度幅
const int SCREENHEIGHT_MAIN				= 1080;	//通常時画面解像度高
const int SCREENWIDTH_SIMULATOR			= 1920;	//シミュレータ画面解像度幅
const int SCREENHEIGHT_SIMULATOR		= 1080;	//シミュレータ画面解像度高
const int SCREENWIDTH_STRINGDISPLAY		= 1920;	//文字列ディスプレイモード画面解像度幅
const int SCREENHEIGHT_STRINGDISPLAY	= 1080;	//文字列ディスプレイモード画面解像度高
const int SCREENWIDTH_STRINGEDITOR		= 1920;	//文字列エディタ画面解像度幅
const int SCREENHEIGHT_STRINGEDITOR		= 1080;	//文字列エディタ画面解像度高
const int COLORBITDEPTH = 32;	//色ビット深度
#else
const int SCREENWIDTH_MAIN				=  640;	//通常時画面幅
const int SCREENHEIGHT_MAIN				=  480;	//通常時画面高
const int SCREENWIDTH_SIMULATOR			= 1600;	//シミュレータ画面幅
const int SCREENHEIGHT_SIMULATOR		=  800;	//シミュレータ画面高
const int SCREENWIDTH_STRINGDISPLAY		= 1500;	//文字列ディスプレイモード画面幅
const int SCREENHEIGHT_STRINGDISPLAY	=  600;	//文字列ディスプレイモード画面高
const int SCREENWIDTH_STRINGEDITOR		= 1600;	//文字列エディタ画面幅
const int SCREENHEIGHT_STRINGEDITOR		=  800;	//文字列エディタ画面高
const int COLORBITDEPTH = 32;	//色ビット深度
#endif
/*画面表示関連*/

/*表示要素関連*/
const int LED_RADIUS					=    2;	//シミュレータモードのLED半径
const int LED_ROW						=   16;	//文字列表示モードのLED行数
const int LED_COLUMN					=   64;	//文字列表示モードのLED列数
/*表示要素関連*/





//
//	構造体定義
//
//
//

/*路線情報*/
typedef struct LineInformation {
				std::string str		= "Error";		//路線名
	unsigned	__int8		R[2]	= { 255, 255 };	//路線カラー赤光度
	unsigned	__int8		G[2]	= { 255, 255 };	//路線カラー緑光度
	unsigned	__int8		B[2]	= { 255, 255 };	//路線カラー青光度
}LineInformation;
/*路線情報*/


/*列車情報*/
typedef struct TrainInformation {
	int		line_color_id		= -1;			//路線カラーID
	int		line_str_id[2]		= { -1, -1 };	//路線文字列ID
	int		type_id[2]			= { -1, -1 };	//種別文字列ID
	int		departure_time		= -1;			//発車時刻(4桁の整数)
	int		destination_id[2]	= { -1, -1 };	//行先文字列ID
	int		track				= 0;			//のりば番線番号
	bool	dep					= false;		//始発
}TrainInformation;
/*列車情報*/


/*文字列情報*/
typedef struct StringInformation {
				std::string	str			= "Error";	//文字列
				char		type		= '?';		//文字列種
	unsigned	long long	led_map[16] = { NULL };	//LEDマップ
	unsigned	__int8		width		=  0;		//LED使用幅
	unsigned	__int8		R			= 32;		//赤色光度
	unsigned	__int8		G			= 32;		//緑色光度
	unsigned	__int8		B			= 32;		//青色光度
}StringInformation;
/*文字列情報*/





//
//	関数定義
//
//
//

/*文字列から整数への変換を行うことが可能であるか*/
int My_stoi(std::string);