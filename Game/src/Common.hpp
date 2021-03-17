
#ifndef Common_hpp
#define Common_hpp

# include <Siv3D.hpp> // OpenSiv3D v0.4.2

// シーンの名前
enum class State
{
	Title,

	//Communicate_1,

	//Tutoarial_1,

	//Maze_1,

	//GameOver,

	//StageClear,

	//Setting,

	//StageTransition,

	//CollectInfo,

	//FinalBoss,
};

// ゲームデータ
struct GameData
{
	//主人公の名前
	String player_name;

	//今までのステージクリアまでにかかった時間の合計
	double total_t = 0;

	//
	bool continue_flag = false;

	//会話シーンの番号
	int com_num = 1;

	//チュートリアルシーンの番号
	int tuto_num = 1;

	//迷路シーンの番号
	int maze_num = 1;

	//情報収集シーンのフラグ
	bool collect_info = false;
};

// シーン管理クラス
using MyApp = SceneManager<State, GameData>;


//グラフィックをアセットに登録
//static inline void InitTexture(){}


//SEやBGMをアセットに登録
//static inline void InitSound(){}

//フォントをアセットに登録
static inline void InitFonts()
{
	FontAsset::Register(U"Title", 120, U"texture/font/DotGothic16-Regular.ttf");
	FontAsset::Register(U"Menu", 30, U"texture/font/DotGothic16-Regular.ttf");
	FontAsset::Register(U"Talk", 25, U"texture/font/puikko-Regular.otf");

	////代用font
	/*FontAsset::Register(U"Title", 120, Typeface::Black);
	FontAsset::Register(U"Menu", 30, Typeface::Regular);
	FontAsset::Register(U"Talk", 25, U"example/font/AnnyantRoman/AnnyantRoman.ttf");*/

}

#endif