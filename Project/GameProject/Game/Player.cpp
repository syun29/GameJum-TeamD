#include"Player.h"

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	//m_pos = pos;
}

void Player::Update() {

}

void Player::Draw() {
	m_img.Draw();
}