#include "Billboard.h"



//
//	コンストラクタ
//
//		電光掲示板の生成
//			寸法の測定(画面サイズ)
//			配置するLEDの数を計算
//			LEDを配置
//		その他細かな初期化
//			アクセス違反を避けるための時刻初期化
//			最初のループで表示処理を行うために処理タイミングを設定
//			表記を日本語から開始に設定
//
//
Billboard::Billboard()
{
/*電光掲示板の生成*/
	/*基盤の寸法を測る*/
	int screenwidth, screenheight, colorbitdepth;				//画面幅, 画面高, 色ビット深度
	GetScreenState(&screenwidth, &screenheight, &colorbitdepth);	//取得
	/*基盤の寸法を測る*/


	/*配置できるLEDの数を計算する*/
	Billboard::tablesize.row	= (screenheight	/ DISTANCE) - 1;	//行数
	Billboard::tablesize.column	= (screenwidth	/ DISTANCE) - 1;	//列数
	/*配置できるLEDの数を計算する*/


	/*LEDを配置する*/
	for (int row = 1; row <= Billboard::tablesize.row; row++) {
		LEDROW led_row;												//仮LED行

		/*LED配置計算*/
		for (int column = 1; column <= Billboard::tablesize.column; column++) {
			LED led = { column * DISTANCE, row * DISTANCE, LED_OFF };	//LEDの位置計算
			led_row.push_back(led);										//LEDを仮LED行へ追加
		}
		/*LED配置計算*/

		ledtable.push_back(led_row);								//LED行をLED板へ追加
	}
	/*LEDを配置する*/
/*電光掲示板の生成*/


/*その他初期化*/
	prev_datetime.Sec	= 63;					//前回の処理を行った時刻の初期化(63秒で初期化)
	prev_millisecond	= GetNowCount() - 2048;	//前回のディスプレイ出力時のミリ秒時刻(2048ミリ秒前で初期化)
	english_trigger		= false;				//日本語・英語表記のトリガ(日本語で初期化)
	firsttrain_id		= -1;					//先発列車の時刻表IDを存在範囲外で初期化
/*その他初期化*/
}



//
//	時刻表の読み込み
//
//
bool Billboard::Init()
{
	if (timetable.Init() == -1)	//時刻表の生成
		return false;								//エラー時
	return true;
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
	for (int row = 0; row < Billboard::tablesize.row; row++)
		for (int column = 0; column < Billboard::tablesize.column; column++)
			ledtable[row][column].color = LED_OFF;	//消灯指示
}



//
//	裏画面へLEDを描画し、ディスプレイに表示されるの待機をする
//
//
void Billboard::Set()
{
	for (int row = 0; row < Billboard::tablesize.row; row++)
		for (int column = 0; column < Billboard::tablesize.column; column++)
			DrawCircle(ledtable[row][column].x, ledtable[row][column].y, RADIUS, ledtable[row][column].color);	//描画
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
	int firsttrain_id_next = timetable.GetID(now_datetime.Hour * 100 + now_datetime.Min);
	if (firsttrain_id == firsttrain_id_next) return;	//必要ない場合は終了
	firsttrain_id = firsttrain_id_next;					//次発列車を先発列車に変更
	/*列車情報を更新する必要があるか確認*/

	english_trigger = false;	//表記を日本語に設定

	Billboard::Clear();			//LEDを全て消灯
	
								//LEDの点灯状態を反映
	timetable.Set(ledtable, tablesize, firsttrain_id, DISPLAYROW, 0, 0, english_trigger);

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
	timetable.Set(ledtable, tablesize, firsttrain_id, DISPLAYROW, 0, 0, english_trigger);

	english_trigger = !english_trigger;	//日本語・英語の表記切替

	Billboard::Set();					//裏画面へ描画
}



Billboard::~Billboard()
{
}
