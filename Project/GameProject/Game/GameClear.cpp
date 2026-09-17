#include "GameClear.h"
#include "Title/Title.h"

GameClear::GameClear()
	:Base(eType_GameOver)
{
	//画像データを複製
	m_img = COPY_RESOURCE("GameClear", CImage);
}

void GameClear::Update()
{
	//SUPEACEキーでタイトルへ
	if (PUSH(CInput::eButton5))
	{

		SetKill();

		new Title();
	}
}

void GameClear::Draw()
{
	m_img.SetSize(1920, 1080);

	//描画
	m_img.Draw();
}