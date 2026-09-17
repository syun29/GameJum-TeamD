#include"Player.h"
#include"Field.h"


Player::Player(const CVector2D& pos, bool flip) : Base(eType_Player) 
{
	m_img = COPY_RESOURCE("Player", CImage);
	//座標設定
	m_pos_old = m_pos = pos;
	//サイズ設定
	m_img.SetSize(72, 72);
	//中心位置設定
	m_img.SetCenter(36, 69);
	//当たり判定用短形設定
	m_rect = CRect(-26, -69, 26, 0);

	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
	m_img.ChangeAnimation(eAnimIdle);

}


void Player::StateIdle()
{
	//移動量
	const float move_speed = 5;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 15;

	//右移動
	if (HOLD(CInput::eButton2)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}

	//左移動
	if (HOLD(CInput::eButton1)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}

	//重力反転
	if (PUSH(CInput::eButton3)) {
		//trueとfalseを切り替える
		if (m_gravity_flip == false) {
			m_gravity_flip = true;	//重力反転ON
		}
		else {
			m_gravity_flip = false;	//重力反転OFF
		}
	}

	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton5)) {
		if (m_gravity_flip == true) {
			m_vec.y = jump_pow;   // 重力反転中 → 下にジャンプ
		}
		else {
			m_vec.y = -jump_pow;  // 通常 → 上にジャンプ
		}

		m_is_ground = false;
	}

	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメ―ション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}

	//地面にいるなら
	else
	{
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
		
}

void Player::StateDown()
{
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}


void Player::Update()
{
	m_pos_old = m_pos;

	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//ダウン状態
	/*case eState_Down:
		StateDown();
		break;*/
	}

	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;

	//重力による落下処理

	float g;
	if (m_gravity_flip == true) {
		g = -GRAVITY;
	}
	else {
		g = GRAVITY;
	}
	m_vec.y += g;
	m_pos += m_vec;


	//アニメーションの更新
	m_img.UpdateAnimation();

	//スクロール値設定
	m_scroll.x = m_pos.x - 1920 / 2;
	m_scroll.y = m_pos.y - 900;
}

void Player::Draw() 
{
	m_img.SetPos(GetScreenPos(m_pos));

	//上下反転（重力反転中だけ）
	if (m_gravity_flip == true) {
		m_img.SetFlipV(true);   // 重力反転中
	}
	else {
		m_img.SetFlipV(false);  // 通常
	}

	m_img.Draw();

	//反転設定
	m_img.SetFlipH(m_flip);
}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
		case eType_Field:
			if (Field* f = dynamic_cast<Field*>(b)) {

				// 横方向の当たり判定（壁）
				int t = f->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
				if (t != 0) {
					m_pos.x = m_pos_old.x;
				}

				// 縦方向の当たり判定（地面）
				t = f->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
				if (t != 0) {
					// 地面に当たったのでY座標を戻す
					m_pos.y = m_pos_old.y;

					// 落下速度リセット
					m_vec.y = 0;

					// 接地フラグON
					m_is_ground = true;
				}
			}
			break;

	}


}

static TexAnim _idle[] = {
	{0,2},
	{1,2},
	{2,2},
	{3,2},
	{4,2},
	{5,2},
};

static TexAnim _down[] = {
	{6,4},
	{7,4},
	{8,4},
	{9,4},
};

static TexAnim _jumpUp[] = {
	{10,4},
	{11,4},
};


static TexAnim _jumpDown[] = {
	{12,4},
	{13,4},
	{14,4},
};

static TexAnim _run[] = {
	{15,4},
	{16,4},
	{17,4},
	{18,4},
	{19,4},
	{20,4},
};

TexAnimData Player::_anim_data[] = {
	ANIMDATA(_idle),	//eAnimIdle=0
	ANIMDATA(_down),	//eAnimDown
	ANIMDATA(_jumpUp),	//eAnimJumpUp
	ANIMDATA(_jumpDown),//eAnimJumpDown
	ANIMDATA(_run),		//eAnimRun
};