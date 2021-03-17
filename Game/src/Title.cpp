
# include "Title.hpp"

Title::Title(const InitData& init)
	: IScene(init)
{
	Scene::SetBackground(ColorF(0.0));

	//ボタン初期化
	initButton();
	
}

void Title::initButton()
{
	//「つづきから」がある場合
	if (getData().continue_flag)
	{
		start_button = RoundRect(Arg::center = Scene::Center().movedBy(0, 0), 300, 60, 20);
		continue_button = RoundRect(Arg::center = Scene::Center().movedBy(0, 80), 300, 60, 20);
		setting_button = RoundRect(Arg::center = Scene::Center().moveBy(0, 160), 300, 60, 20);
		exit_button = RoundRect(Arg::center = Scene::Center().moveBy(0, 240), 300, 60, 20);
	}

	//ない場合
	else
	{
		start_button = RoundRect(Arg::center = Scene::Center().movedBy(0, 0), 300, 60, 20);
		setting_button = RoundRect(Arg::center = Scene::Center().moveBy(0, 100), 300, 60, 20);
		exit_button = RoundRect(Arg::center = Scene::Center().moveBy(0, 200), 300, 60, 20);

	}
}

void Title::update()
{


	//初めからボタンのトランジット処理
	start_transition.update(start_button.mouseOver());

	//続きからのトランジット処理
	continue_transition.update(continue_button.mouseOver());

	//設定ボタンのトランジット処理
	setting_transition.update(setting_button.mouseOver());

	//終了ボタンのトランジット処理
	exit_transition.update(exit_button.mouseOver());


	//ボタンの上にカーソルがあるとき形を変える
	if (start_button.mouseOver() 
		|| continue_button.mouseOver() 
		|| setting_button.mouseOver() 
		|| exit_button.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	//「はじめから」ボタンを押したとき
	if (start_button.leftClicked())
	{
		//changeScene(State::Communicate_1);
	}

	//「つづきから」ボタンを押したとき
	if (continue_button.leftClicked())
	{
		if (getData().maze_num == 1)
		{
			//ステージ１へ
			//changeScene(State::StageTransition);
		}
	}

	//「せってい」ボタンを押したとき
	if (setting_button.leftClicked())
	{
		//changeScene(State::Setting);
	}


	//「おわる」ボタンを押したとき
	if (exit_button.leftClicked())
	{
		System::Exit();
	}




	//BGM用の処理（アセットを使用）

}

void Title::draw() const
{
	

	//タイトル描画（ココにはロゴを挿入予定）
	const String titleText = U"Crude Maze";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Title")(titleText).drawAt(center.movedBy(4, 6), ColorF(1.0, 0.5));
	FontAsset(U"Title")(titleText).drawAt(center);
	

	//「つづきから」ができる場合のボタンの描画処理
	if (getData().continue_flag) {
		start_button.draw(ColorF(0.55, 0.25, 0.67, start_transition.value())).drawFrame(2);
		continue_button.draw(ColorF(0.55, 0.25, 0.67, continue_transition.value())).drawFrame(2);
		setting_button.draw(ColorF(0.55, 0.25, 0.67, setting_transition.value())).drawFrame(2);
		exit_button.draw(ColorF(0.55, 0.25, 0.67, exit_transition.value())).drawFrame(2);


		FontAsset(U"Menu")(U"はじめから").drawAt(start_button.center(), ColorF(1.0));
		FontAsset(U"Menu")(U"つづきから").drawAt(continue_button.center(), ColorF(1.0));
		FontAsset(U"Menu")(U"せってい").drawAt(setting_button.center(), ColorF(1.0));
		FontAsset(U"Menu")(U"おわる").drawAt(exit_button.center(), ColorF(1.0));
	}


	//「つづきから」ができない場合
	else {
		start_button.draw(ColorF(0.55, 0.25, 0.67, start_transition.value())).drawFrame(2);
		setting_button.draw(ColorF(0.55, 0.25, 0.67, setting_transition.value())).drawFrame(2);
		exit_button.draw(ColorF(0.55, 0.25, 0.67, exit_transition.value())).drawFrame(2);


		FontAsset(U"Menu")(U"はじめから").drawAt(start_button.center(), ColorF(1.0));
		FontAsset(U"Menu")(U"せってい").drawAt(setting_button.center(), ColorF(1.0));
		FontAsset(U"Menu")(U"おわる").drawAt(exit_button.center(), ColorF(1.0));
	}


}
