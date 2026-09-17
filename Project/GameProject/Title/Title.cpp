#include "Title.h"
#include "Game/Game.h"
#include "Game/Goal.h"

Title::Title()
	: Base(eType_Scene)
{
	//画像の複製
	m_img = COPY_RESOURCE("Title", CImage);
	m_font = COPY_RESOURCE("Title_Font", CImage);
	//GetSizeで元画像のサイズを取得
	m_fontSize = m_font.GetSize() * 1.2f;

	Goal::m_area = 1;
}

void Title::Update()
{
	//ボタン１でタイトル破棄
	if (m_cnt++ > 2 && PUSH(CInput::eButton1)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーンへ
		new Game();
	}
}

void Title::Draw()
{
	//サイズを設定
	m_img.SetSize(1920, 1080);
	m_font.SetSize(m_fontSize);
	
	//座標設定
	m_font.SetPos(100, 100);

	//描画
	m_img.Draw();
	m_font.Draw();
}
