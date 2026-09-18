#include "SceneChange.h"
#include "Goal.h"

#define ALPHA_SCALE 0.5f

SceneChange::SceneChange()
	:Base(eType_SceneChange)
	, m_alpha(0.0f)
	, m_alphaChange(false)
{
	//画像の複製
	m_img = COPY_RESOURCE("Scene", CImage);
}

void SceneChange::Update()
{
	if (m_alpha > 1.0 && m_alphaChange == false)
	{
		m_alphaChange = true;
		//フィールド生成
		Goal* mp_goal = dynamic_cast<Goal*>(Base::FindObject(eType_Goal));

		mp_goal->AreaChange();
	}

	//暗転

	m_alpha += ALPHA_SCALE * CFPS::GetDeltaTime();
	

}

void SceneChange::Draw()
{
	//画像の設定と描画
	m_img.SetColor(0.0f, 0.0f, 0.0f, m_alpha);
	m_img.Draw();
}
