#include"Player.h"

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
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