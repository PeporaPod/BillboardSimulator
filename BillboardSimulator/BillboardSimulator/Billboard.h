#pragma once
#include <DxLib.h>
#include "Header.h"
class Billboard
{
private:
	unsigned	int										matrix_row;		//LED行数
	unsigned	int										matrix_column;	//LED列数
	unsigned	int										radius;			//LED半径
	unsigned	int										color_off;		//消灯色
				std::vector<int>						position_x;		//横方向LED位置
				std::vector<int>						position_y;		//縦方向LED位置
				std::vector<std::vector<unsigned int>>	color_matrix;	//LED点灯色マトリクス
public:
	Billboard();																													//コンストラクタ
	/*LEDマトリクス本体の実操作*/
	void Init();																													//初期化メソッド(LEDを固定半径で画面いっぱいに配置)
	void Init(const int top, const int bottom, const int left, const int right, const unsigned int row, const unsigned int column);	//初期化メソッド(指定範囲に指定数LEDを配置)
	void Commit(LineInformation, const int offset_row = 0);																			//指定の路線バーを指定行オフセットして表示
	void Commit(StringInformation, const int offset_row = 0, const int offset_column = 0);											//指定の文字列を指定オフセットで表示
	void Clear();																													//LEDを全て消灯状態にする
	void Draw();																													//現在のLED点灯状態でLEDマトリクスを描画
	/*LEDマトリクス本体の実操作*/
	/*参照用ゲッタ*/
	void GetPositionReference(std::vector<int> * axis_x, std::vector<int> * axis_y, int * radius);									//LEDの位置・LED半径を提供
	void GetMatrixSize(unsigned int * row, unsigned int * column);																	//LEDマトリクスの行数・列数を提供
	/*参照用ゲッタ*/
	~Billboard();																													//デストラクタ
};

