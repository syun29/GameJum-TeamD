#pragma once
#include "../Base/Base.h"
class Goal :public Base {
private:
	CImage m_img;
	bool m_is_goal;
public:
	static int m_area;
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">座標</param>
	Goal(const CVector2D& pos);
	/// <summary>
	/// エリアチェンジ
	/// </summary>
	void AreaChange();
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw()override;
	/// <summary>
	/// 当たり判定
	/// </summary>
	/// <param name="b">対象</param>
	void Collision(Base* b)override;
	bool GetGoal() {
		return m_is_goal;
	}
	void SetGoal() {
		m_is_goal = true;
	}
};