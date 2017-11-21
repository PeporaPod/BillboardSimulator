#include "Billboard.h"



Billboard::Billboard()
{
}

void Billboard::Init()
{
	///*LEDマトリクスの生成*/
	///*マトリクス基盤の寸法測定*/
	//int screenwidth, screenheight, colorbitdepth;					//画面幅, 画面高, 色ビット深度
	//GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//取得
	///*マトリクス基盤の寸法測定*/


	///*配置できるLEDの数を計算する*/
	//led_row = (screenheight / DISTANCE) - 1;	//行数
	//led_column = (screenwidth / DISTANCE) - 1;	//列数
	///*配置できるLEDの数を計算する*/


	//											/*LEDを配置する*/
	//for (int row = 1; row <= led_row; row++) {
	//	LED_ARRAY led_array;												//仮LED配列
	//	for (int column = 1; column <= led_column; column++) {
	//		LED led = { column * DISTANCE, row * DISTANCE, color_off };	//LEDの位置計算
	//		led_array.push_back(led);											//LEDを仮LED配列へ追加
	//	}
	//	led_matrix.push_back(led_array);									//LED配列をLEDマトリクスへ追加
	//}
	///*LEDを配置する*/
	///*LEDマトリクスの生成*/


	///*初期表示処理*/
	//clsDx();
	//ClearDrawScreen();
	//for (int row = 0; row < led_row; row++)
	//	for (int column = 0; column < led_column; column++)
	//		DrawCircle(led_matrix[row][column].x, led_matrix[row][column].y, RADIUS, led_color_off);
	//ScreenFlip();
	///*初期表示処理*/
}

void Billboard::Init(int top_ratio, int bottom_ratio, int left_ratio, int right_ratio, int row, int column)
{
	int screenwidth, screenheight, colorbitdepth;
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);


	led_row = row;
	led_column = column;
}

void Billboard::Draw()
{
	ClearDrawScreen();
	for (int row = 0; row < 16; row++)
		for (int column = 0; column < 64; column++)
			DrawCircle(axis_x[column], axis_y[row], radius, color[row][column]);
	ScreenFlip();
}


Billboard::~Billboard()
{
}
