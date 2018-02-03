#include "Billboard.h"



//
//	コンストラクタ
//
//
Billboard::Billboard()
{
	matrix_row		= 0;
	matrix_column	= 0;
	color_off		= GetColor(32, 32, 32);
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
	matrix_row = screenheight / (2 * (radius + 1)) - 1;			//行数
	matrix_column = screenwidth / (2 * (radius + 1)) - 1;		//列数
	/*配置できるLEDの数を計算する*/


	/*LEDを配置する*/
	for (unsigned int row = 1; row <= matrix_row; row++)
		position_y.push_back(row * (radius + 1) * 2);		//LED位置(縦軸方向)
	for (unsigned int column = 1; column <= matrix_column; column++)
		position_x.push_back(column * (radius + 1) * 2);	//LED位置(横軸方向)
	//LED発光色を`消灯色`で初期化
	color_matrix = std::vector<std::vector<unsigned int>>(matrix_row, std::vector<unsigned int>(matrix_column, color_off));
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
void Billboard::Init(const int top, const int bottom, const int left, const int right, const unsigned int row, const unsigned int column)
{
	/*LEDマトリクスの生成*/
	/*配置できるLEDの数の確定*/
	matrix_row = row;																//行数
	matrix_column = column;														//列数
	/*配置できるLEDの数の確定*/


	/*LED半径の計算*/
	if ((right - left) / (matrix_column + 1) < (bottom - top) / (matrix_row + 1))
		radius = (right - left) / (matrix_column + 1) / 2 - 1;						//横幅準拠の半径
	else
		radius = (bottom - top) / (matrix_row + 1) / 2 - 1;						//縦幅準拠の半径
	/*LED半径の計算*/


	/*LEDの配置*/
	for (unsigned int row_index = 1; row_index <= matrix_row; row_index++)
		position_y.push_back(top + row_index * (bottom - top) / (matrix_row + 1));			//LED位置(縦軸方向)
	for (unsigned int column_index = 1; column_index <= matrix_column; column_index++)
		position_x.push_back(left + column_index * (right - left) / (matrix_column + 1));	//LED位置(横軸方向)
	color_matrix = std::vector<std::vector<unsigned int>>(matrix_row, std::vector<unsigned int>(matrix_column, color_off));
	/*LEDの配置*/
	/*LEDマトリクスの生成*/
}



//
//	路線カラーバーの表示メソッド
//
//
void Billboard::Commit(LineInformation lineinformation, const int offset_row)
{
	unsigned int line_color[2] = { GetColor(lineinformation.R[0], lineinformation.G[0], lineinformation.B[0]), GetColor(lineinformation.R[1], lineinformation.G[1], lineinformation.B[1]) };	//路線カラーをRGBから変換
	for (unsigned int row = 1; row < 8 && row + offset_row < color_matrix.size(); row++)
		for (int column = 0; column < 4; column++)
			color_matrix[row + offset_row][column] = color_matrix[row + offset_row][matrix_column - 1 - column] = line_color[0];	//路線カラー1の反映
	for (unsigned int row = 8; row < 15 && row + offset_row < matrix_row; row++)
		for (int column = 0; column < 4; column++)
			color_matrix[row + offset_row][column] = color_matrix[row + offset_row][matrix_column - 1 - column] = line_color[1];	//路線カラー2の反映
}



//
//	LEDマトリクスの点灯状態の反映を行うメソッド
//
//		LEDの点灯状態/点灯色を各LEDに反映していく
//
//
//
void Billboard::Commit(StringInformation strinfo, const int offset_row, const int offset_column)
{
	unsigned int color = GetColor(strinfo.R, strinfo.G, strinfo.B);
	for (unsigned int row = 0; row < LED_ROW && row + offset_row < matrix_row; row++) {
		unsigned long long operatorbit = 0x8000000000000000;
		for (unsigned int column = 0; column < LED_COLUMN && column + offset_column < matrix_column; column++) {
			if (strinfo.led_map[row] & operatorbit)
				color_matrix[row + offset_row][column + offset_column] = color;
			operatorbit >>= 1;
		}
	}
}



//
//	LEDを全て消灯した状態にするメソッド
//
//
void Billboard::Clear()
{
	for (unsigned int row = 0; row < color_matrix.size(); row++)
		for (unsigned int column = 0; column < color_matrix[row].size(); column++)
			color_matrix[row][column] = color_off;
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
	for (unsigned int row = 0; row < matrix_row; row++)
		for (unsigned int column = 0; column < matrix_column; column++)
			DrawCircle(position_x[column], position_y[row], radius, color_matrix[row][column]);
}



//
//
//
//
void Billboard::GetPositionReference(std::vector<int> * axis_x, std::vector<int> * axis_y, int * rad)
{
	axis_x->clear(), axis_y->clear();						//挿入用の可変長配列をクリア
	for (unsigned int i = 0; i < position_x.size(); i++)
		axis_x->push_back(position_x[i]);					//x軸方向(列)の位置情報を格納
	for (unsigned int i = 0; i < position_y.size(); i++)
		axis_y->push_back(position_y[i]);					//y軸方向(行)の位置情報を格納
	*rad = radius;											//LED半径を格納
}



//
//
//
//
void Billboard::GetMatrixSize(unsigned int * row, unsigned int * column)
{
	*row	= position_y.size();
	*column = position_x.size();
}



//
//	デストラクタ
//
//		描画情報を削除
//
//
Billboard::~Billboard()
{
	ClearDrawScreen();
	ScreenFlip();
	ClearDrawScreen();
}

