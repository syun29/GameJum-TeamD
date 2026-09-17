#include "Enemy.h"

// コンストラクタ（出現位置と向きの初期化）
Enemy::Enemy(const CVector2D& pos, bool flip) : Base(eType_Enemy) {
	// 画像リソースの複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	// 再生アニメーションの設定（待機状態）
	m_img.ChangeAnimation(0);
	// 座標の設定
	m_pos_old = m_pos = pos;
	m_img.SetSize(64, 64);
	// 中心位置（描画・回転の基準点）の設定
	m_img.SetCenter(32, 32);
	m_img.SetRect(-32, -32, 32, 0);
	// 左右反転フラグの設定
	m_flip = flip;
}

// 更新処理
void Enemy::Update() { 
	// アニメーションの更新
	m_img.UpdateAnimation();
}
// 描画処理 
void Enemy::Draw() {
	// スクロール位置を考慮した画面座標の設定
	m_img.SetPos(GetScreenPos(m_pos));
	// 左右の向き（反転）を設定
	m_img.SetFlipH(m_flip);
	// 描画を実行
	m_img.Draw();
}
// 当たり判定処理（まずは空のままでOK）
	void Enemy::Collision(Base* b) { 
	}
	static TexAnim _run[] = {
	{0,4},
	{1,4},
	{2,4},
	{3,4},
	{4,4},
	{5,4},
	{6,4},
	};
	TexAnimData Enemy::_anim_data[] = {
	ANIMDATA(_run),		//eAnimRun
	};