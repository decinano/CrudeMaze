
# pragma once
# include "Common.hpp"

// タイトルシーン
class Title : public MyApp::Scene
{
private:

	RoundRect start_button;

	RoundRect continue_button;

	RoundRect setting_button;

	RoundRect exit_button;
	
	//それぞれのトランジット処理の初期化
	Transition start_transition = Transition(0.2s, 0.1s);

	Transition continue_transition = Transition(0.2s, 0.1s);

	Transition setting_transition = Transition(0.2s, 0.1s);

	Transition exit_transition = Transition(0.2s, 0.1s);
public:

	void initButton();


	Title(const InitData& init);

	void update() override;

	void draw() const override;

	
};
