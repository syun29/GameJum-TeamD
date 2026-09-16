#include"Player.h"


Player::Player(const CVector2D& pos, bool flip) : Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	//座標設定
	m_pos_old = m_pos = pos;
	//サイズ設定
	

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
	const float move_speed = 7;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 21;

	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}

	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}

	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
}


void Player::Update() {

}

void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Player::Collision(Base* b) {

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
	{12,4},
	{13,4},
	{14,4},
};

static TexAnim _run[] = {
	{15,2},
	{16,2},
	{17,2},
	{18,2},
	{19,2},
	{20,2},
};

TexAnimData Player::_anim_data[] = {
	ANIMDATA(_idle),	//eAnimIdle=0
	ANIMDATA(_down),	//eAnimDown
	ANIMDATA(_jumpUp),	//eAnimJumpUp
	ANIMDATA(_run),		//eAnimRun
};