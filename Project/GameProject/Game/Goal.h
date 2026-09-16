#pragma once
#include "../Base/Base.h"
class Goal :public Base {
private:
	CImage m_img;
	bool m_is_goal;
public:
	Goal(const CVector2D& pos);
	void Draw();
	bool GetGoal() {
		return m_is_goal;
	}
	void SetGoal() {
		m_is_goal = true;
	}
};