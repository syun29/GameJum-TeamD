#include"Player.h"

static TexAnim idle[] = {
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

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	//座標設定
	m_pos_old = m_pos = pos;
	//サイズ設定
	


	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;

}

void Player::Update() {

}

void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Player::Collision(Base* b) {

}

TexAnimData Player::_anim_data[] = {

};