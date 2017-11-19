#include "Billboard.h"



//
//	コンストラクタ
//
//		アクセス違反を避けるための時刻初期化
//		最初のループで表示処理を行うために処理タイミングを設定
//		表記を日本語から開始に設定
//
//
Billboard::Billboard()
{
	prev_datetime.Sec	= 63;					//前回の処理を行った時刻の初期化(63秒で初期化)
	prev_millisecond	= GetNowCount() - 2048;	//前回のディスプレイ出力時のミリ秒時刻(2048ミリ秒前で初期化)
	english_trigger		= false;				//日本語・英語表記のトリガ(日本語で初期化)
	firsttrain_id		= -1;					//先発列車の時刻表IDを存在範囲外で初期化
}



//
//	初期化処理
//
//		LEDマトリクスの生成
//			基盤寸法(画面サイズ)の測定
//			配置するLEDの数を計算
//			LEDを配置
//
//
void Billboard::Init()
{
	/*LEDマトリクスの生成*/
	/*マトリクス基盤の寸法測定*/
	int screenwidth, screenheight, colorbitdepth;					//画面幅, 画面高, 色ビット深度
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//取得
	/*マトリクス基盤の寸法測定*/


	/*配置できるLEDの数を計算する*/
	led_row = (screenheight / DISTANCE) - 1;	//行数
	led_column = (screenwidth / DISTANCE) - 1;	//列数
	/*配置できるLEDの数を計算する*/


	/*LEDを配置する*/
	for (int row = 1; row <= led_row; row++) {
		LED_ARRAY led_array;												//仮LED配列
		for (int column = 1; column <= led_column; column++) {
			LED led = { column * DISTANCE, row * DISTANCE, led_color_off };	//LEDの位置計算
			led_array.push_back(led);											//LEDを仮LED配列へ追加
		}
		led_matrix.push_back(led_array);									//LED配列をLEDマトリクスへ追加
	}
	/*LEDを配置する*/
	/*LEDマトリクスの生成*/


	/*初期表示処理*/
	clsDx();
	ClearDrawScreen();
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(led_matrix[row][column].x, led_matrix[row][column].y, RADIUS, led_color_off);
	ScreenFlip();
	/*初期表示処理*/
}



//
//	電光掲示板の稼働開始
//
//
void Billboard::Start()
{
	DATEDATA now_datetime;
	GetDateTime(&now_datetime);
	Billboard::Process(now_datetime);
}



//
//	LEDを全て消灯する
//
//
void Billboard::Clear()
{
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			led_matrix[row][column].color = led_color_off;	//消灯指示
}



//
//	裏画面へLEDを描画し、ディスプレイに表示されるの待機をする
//
//
void Billboard::Set()
{
	for (int row = 0; row < led_row; row++)
		for (int column = 0; column < led_column; column++)
			DrawCircle(led_matrix[row][column].x, led_matrix[row][column].y, RADIUS, led_matrix[row][column].color);	//描画
}



//
//	逐次更新
//
//		毎分00秒 / DISPLAYTIME[ミリ秒]経過毎に日本語・英語表記を切替 ("Header.h"参照)
//
//
void Billboard::Update()
{
	/*現在時刻の取得*/
	DATEDATA now_datetime;			//現在の日付・時刻
	GetDateTime(&now_datetime);		//現在の日付・時刻の取得
	int now_milsec = GetNowCount();	//現在のミリ秒時刻の取得
	/*現在時刻の取得*/

	/*現在時刻・経過時間による表示の更新処理*/
	if (!now_datetime.Sec && prev_datetime.Sec != now_datetime.Sec) //毎分00秒での更新処理
		Billboard::Process(now_datetime);							//即時反映
	else if (now_milsec - prev_millisecond >= DISPLAYTIME/* * (english_trigger + 1)*/)			//前回の表示更新時刻から2000ミリ秒経過した際の表示更新
		Billboard::Change();
	/*現在時刻・経過時間による表示の更新処理*/

	Billboard::prev_datetime = now_datetime;	//処理を行った時刻を更新
}



//
//	ディスプレイへLEDの出力を実行 及び 次に描画する内容を決定する
//
//
void Billboard::Process(DATEDATA now_datetime)
{
	/*列車情報を更新する必要があるか確認*/
//	int firsttrain_id_next = timetable.GetID(now_datetime.Hour * 100 + now_datetime.Min);
//	if (firsttrain_id == firsttrain_id_next) return;	//必要ない場合は終了
//	firsttrain_id = firsttrain_id_next;					//次発列車を先発列車に変更
	/*列車情報を更新する必要があるか確認*/

	english_trigger = false;	//表記を日本語に設定

	Billboard::Clear();			//LEDを全て消灯
	
								//LEDの点灯状態を反映
//	timetable.Set(led_matrix, tablesize, firsttrain_id, DISPLAYROW, 0, 0, english_trigger);

	Billboard::Set();			//裏画面へ描画

	Billboard::Change();		//ディスプレイへ出力及び次の描画内容を決定
}



//
//	ディスプレイへの出力 及び 日本語・英語表記を切り替えて出力のスタンバイ
//
//
void Billboard::Change()
{
	ScreenFlip();						//ディスプレイへ出力
	prev_millisecond = GetNowCount();	//ディスプレイ更新タイミングを更新

	Billboard::Clear();					//LEDを全て消灯

	//LEDの点灯状態を反映
//	timetable.Set(led_matrix, tablesize, firsttrain_id, DISPLAYROW, 0, 0, english_trigger);

	english_trigger = !english_trigger;	//日本語・英語の表記切替

	Billboard::Set();					//裏画面へ描画
}



Billboard::~Billboard()
{
}
