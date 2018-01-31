#include "Billboard.h"



Billboard::Billboard()
{
}



//
//	初期化メソッド(フル用)
//
//		/*指定LED半径でLEDを配置する*/
//		画面情報取得
//		LEDの配置数を計算
//		配置
//
//
//
void Billboard::Init()
{
	/*LEDマトリクスの生成*/
	/*マトリクス基盤の寸法測定*/
	int screenwidth, screenheight, colorbitdepth;					//画面幅, 画面高, 色ビット深度
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);		//取得
	/*マトリクス基盤の寸法測定*/


	/*LED半径の確定*/
	radius = LED_RADIUS;								//LED半径
	/*LED半径の確定*/
	
	
	/*配置できるLEDの数を計算する*/
	led_row = screenheight / (radius + 1) - 1;			//行数
	led_column = screenwidth / (radius + 1) - 1;		//列数
	/*配置できるLEDの数を計算する*/


	/*LEDを配置する*/
	for (int row = 1; row <= led_row; row++)
		position_y.push_back(row * (radius + 1) * 2);		//LED位置(縦軸方向)
	for (int column = 1; column <= led_column; column++)
		position_x.push_back(column * (radius + 1) * 2);	//LED位置(横軸方向)
	//LED発光色を`消灯色`で初期化
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LEDを配置する*/
	/*LEDマトリクスの生成*/
}



//
//	初期化メソッド(16x64用)
//
//		/*指定範囲に指定数のLEDを配置*/
//		LED半径の計算
//		配置
//
//
//
void Billboard::Init(int top, int bottom, int left, int right, int row, int column)
{
	/*LEDマトリクスの生成*/
	/*配置できるLEDの数の確定*/
	led_row = row;																//行数
	led_column = column;														//列数
	/*配置できるLEDの数の確定*/


	/*LED半径の計算*/
	if ((right - left) / (led_column + 1) < (bottom - top) / (led_row + 1))
		radius = (right - left) / (led_column + 1) / 2 - 1;						//横幅準拠の半径
	else
		radius = (bottom - top) / (led_row + 1) / 2 - 1;						//縦幅準拠の半径
	/*LED半径の計算*/


	/*LEDの配置*/
	for (int row_index = 1; row_index <= led_row; row_index++)
		position_y.push_back(top + row_index * (bottom - top) / (led_row + 1));			//LED位置(縦軸方向)
	for (int column_index = 1; column_index <= led_column; column_index++)
		position_x.push_back(left + column_index * (right - left) / (led_column + 1));	//LED位置(横軸方向)
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_outofrange));
	/*LEDの配置*/
	color_matrix = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LEDマトリクスの生成*/
}



//
//	LEDマトリクスの点灯状態の反映を行うメソッド
//
//		LEDの点灯状態/点灯色を各LEDに反映していく
//
//
//
void Billboard::Commit(unsigned long long led_matrix[], unsigned int color)
{
	for (int row = 0; row < LED_ROW; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (int column = 0; column < LED_COLUMN; column++) {
			if (led_matrix[row] & operatorbit)
				color_matrix[row][column] = color;
			else
				color_matrix[row][column] = color_off;
			operatorbit >>= 1;
		}
	}
}

void Billboard::Commit(StringInformation strinfo)
{
	for (int row = 0; row < LED_ROW; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (int column = 0; column < strinfo.width; column++) {
			if (strinfo.led_map[row] & operatorbit)
				color_matrix[row][column] = GetColor(strinfo.R, strinfo.G, strinfo.B);
			else
				color_matrix[row][column] = color_off;
			operatorbit >>= 1;
		}
	}
}



//
//	描画メソッド
//
//		現在のLEDの点灯状態で画面への描画を行う
//
//
//
void Billboard::Draw()
{
//	ClearDrawScreen();
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(position_x[column], position_y[row], radius, color_matrix[row][column]);
//	ScreenFlip();
}



//
//
//
//
void Billboard::GetPositionReference(std::vector<int>* axis_x, std::vector<int>* axis_y, int* rad)
{
	for (unsigned int i = 0; i < position_x.size(); i++)
		axis_x->push_back(position_x[i]);
	for (unsigned int i = 0; i < position_y.size(); i++)
		axis_y->push_back(position_y[i]);
	*rad = radius;
}



Billboard::~Billboard()
{
}
