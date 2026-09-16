#pragma once
#include "Base/Base.h"

class Title : public Base
{
private:
	//画像
	CImage m_img;
	CImage m_font;

	//フォント画像のサイズ
	CVector2D m_fontSize;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Title();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update()override;
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw()override;
};