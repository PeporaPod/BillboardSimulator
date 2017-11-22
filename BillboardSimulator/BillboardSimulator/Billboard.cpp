#include "Billboard.h"



Billboard::Billboard()
{
}

void Billboard::Init()
{
	radius = LED_RADIUS;

	/*LEDマトリクスの生成*/
	/*マトリクス基盤の寸法測定*/
	int screenwidth, screenheight, colorbitdepth;					//画面幅, 画面高, 色ビット深度
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//取得
	/*マトリクス基盤の寸法測定*/
	
	
	/*配置できるLEDの数を計算する*/
	led_row = screenheight / (radius + 1) - 1;		//行数
	led_column = screenwidth / (radius + 1) - 1;	//列数
	/*配置できるLEDの数を計算する*/


	/*LEDを配置する*/
	for (int row = 1; row <= led_row; row++)
		axis_y.push_back(row * (radius + 1) * 2);
	for (int column = 1; column <= led_column; column++)
		axis_x.push_back(column * (radius + 1) * 2);
	color = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_off));
	/*LEDを配置する*/
	/*LEDマトリクスの生成*/
}

void Billboard::Init(int top, int bottom, int left, int right, int row, int column)
{
	led_row = row;
	led_column = column;


	if ((right - left) / (led_column + 1) < (bottom - top) / (led_row + 1))
		radius = (right - left) / (led_column + 1) / 2 - 1;
	else
		radius = (bottom - top) / (led_row + 1) / 2 - 1;


	for (int row = 1; row <= led_row; row++)
		axis_y.push_back(top + (bottom - top) / (led_row + 1) * row);
	for (int column = 0; column < led_column; column++)
		axis_x.push_back(left + (right - left) / (led_column + 1) * (column + 1));
	color = std::vector<std::vector<unsigned int>>(led_row, std::vector<unsigned int>(led_column, color_outofrange));
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
