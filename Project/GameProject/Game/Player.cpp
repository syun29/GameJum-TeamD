#include"Player.h"

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