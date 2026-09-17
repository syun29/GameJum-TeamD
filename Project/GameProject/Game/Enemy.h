#pragma once
#include "../Base/Base.h"
class Enemy : public Base {
	enum {
		eAnimRun,
	};
private:
	CImage m_img; // 画像オブジェクト
	bool m_flip; // 左右反転フラグ (true: 左向き / false: 右向き)
	int m_hp; // 体力 (HP)
	int m_state; // 状態管理用変数
	bool m_is_ground; // 接地フラグ
public:
	// コンストラクタ（出現位置と向きを設定）
	Enemy(const CVector2D& pos, bool flip);

	// 各フレームで呼び出される処理（Baseクラスの仮想関数をオーバーライド）
	void Update();
	void Draw();
	void Collision(Base* b);

	// ダメージ受ける処理
	void TakeDamage(int damage);

	// アニメーションデータ
	static TexAnimData _anim_data[];
};