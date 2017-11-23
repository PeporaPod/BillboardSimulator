#include "Billboard.h"



Billboard::Billboard()
{
}

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
		axis_y.push_back(row * (radius + 1) * 2);		//LED位置(縦軸方向)
	for (int column = 1; column <= led_column; column++)
		axis_x.push_back(column * (radius + 1) * 2);	//LED位置(横軸方向)
	//LED発光色を`消灯色`で初期化
	color = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LEDを配置する*/
	/*LEDマトリクスの生成*/
}

void Billboard::Init(int top, int bottom, int left, int right, int row, int column)
{
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
	for (int row = 1; row <= led_row; row++)
		axis_y.push_back(top + row * (bottom - top) / (led_row + 1));			//LED位置(縦軸方向)
	for (int column = 1; column <= led_column; column++)
		axis_x.push_back(left + column * (right - left) / (led_column + 1));	//LED位置(横軸方向)
	color = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_outofrange));
	/*LEDの配置*/
}

void Billboard::GetAxis(std::vector<int>& axis_1, std::vector<int>& axis_2)
{
	axis_1 = axis_x;
	axis_2 = axis_y;
}

void Billboard::Draw()
{
	ClearDrawScreen();
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(axis_x[column], axis_y[row], radius, color[row][column]);
	ScreenFlip();
}


Billboard::~Billboard()
{
}
