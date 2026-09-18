#include "GameOver.h"
#include "Title/Title.h"

GameOver::GameOver()
	:Base(eType_GameOver)
{
	//画像データを複製
	m_img = COPY_RESOURCE("GameOver", CImage);

	SOUND("Stage")->Stop();
}

void GameOver::Update()
{
	//SUPEACEキーでタイトルへ
	if (PUSH(CInput::eButton5))
	{

		SetKill();

		new Title();
	}
}

void GameOver::Draw()
{
	m_img.SetSize(1920, 1080);

	//描画
	m_img.Draw();
}