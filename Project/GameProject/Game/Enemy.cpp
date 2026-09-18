#include "Enemy.h"
#include "Player.h"
#include "GameOver.h"

#define MOVE_DIST 400.0f

// コンストラクタ（出現位置と向きの初期化）
Enemy::Enemy(const CVector2D& pos, bool flip) : Base(eType_Enemy) {
	// 画像リソースの複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	// 再生アニメーションの設定（待機状態）
	
	// 座標の設定
	m_pos_old = m_pos = pos;
	m_img.SetSize(125, 68);
	// 中心位置（描画・回転の基準点）の設定
	m_img.SetCenter(64.5, 68);
	m_rect = CRect(-32, -68, 32, 0);
	//m_img.SetRect(-125, -17, -60, 34);
	// 左右反転フラグの設定
	m_flip = flip;

	m_img.ChangeAnimation(eAnimRun);


}

// 更新処理
void Enemy::Update()
{ 
	//プレイヤーのポインタ
	Player* mp_player = dynamic_cast<Player*>(Base::FindObject(eType_Player));
	//プレイヤーまでのベクトルを求める
	CVector2D vec = m_pos - mp_player->m_pos;
	//距離を求める
	float dist = vec.Length();
	//指定した距離よりも小さければ
	if (dist < MOVE_DIST)
	{
		//ベクトルを正規化
		vec.GetNormalize();
		//ベクトルを反転させる
		m_vec = -vec;
	}
	else
	{
		//指定した距離よりも大きければ
		//ベクトルをゼロに
		m_vec = CVector2D::zero;
	}
	
	//座標にベクトルを足して移動
	m_pos += m_vec * CFPS::GetDeltaTime() / 2;

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
	DrawRect();
}
// 当たり判定処理（まずは空のままでOK）
	void Enemy::Collision(Base* b) 
	{ 
		switch (b->m_type)
		{
		case eType_Player:

			if (Base::CollisionRect(this, b))
			{
				Base::KillAll();

				new GameOver();
			}
		}
	}
	static TexAnim _run[] = {
	{0,9},
	{1,9},
	{2,9},
	{3,9},
	{4,9},
	{5,9},
	{6,9},
	};
	TexAnimData Enemy::_anim_data[] = {
	ANIMDATA(_run),		//eAnimRun
	};