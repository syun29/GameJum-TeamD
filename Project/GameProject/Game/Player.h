#pragma once
#include"Base/Base.h"

class Player : public Base {
private:
	//アニメーションの種類
	enum {
		eAnimIdle = 0,
		eAnimRun,
		eAnimJumpUp,
		eAnimJumpDown,
		eAnimDown,
	};

	//状態
	enum {
		eState_Idle,
		eState_Down,
	};

	//各状態での挙動
	void StateIdle();
	void StateDown();

	//状態変数
	int m_state;
	//着地フラグ
	bool m_is_ground;
	CImage m_img;


public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);

	static TexAnimData _anim_data[];
};
