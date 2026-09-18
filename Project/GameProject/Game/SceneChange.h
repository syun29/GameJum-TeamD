#pragma once
#include "Base/Base.h"

class SceneChange : public Base
{
private:
	//画像
	CImage m_img;
	//アルファ値
	float m_alpha;
	//暗転解除
	bool m_alphaChange;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneChange();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update()override;
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw()override;
};