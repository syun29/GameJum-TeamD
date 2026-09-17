#include"Bullet.h"
#include"Player.h"


Bullet::Bullet(const CVector2D& pos) : Base(eType_Bullet)
{
	m_img = COPY_RESOURCE("Bullet", CImage);

	m_pos = pos;

	//”¼Œa
	m_rad = 24;

	m_img.SetSize(48, 48);
	m_img.SetCenter(24, 24);
}

void Bullet::Update() {
	
	const int move_speed = 20;

	
	m_pos.x += move_speed * m_dir;

	// ‰æ–Êã‚ÌˆÊ’u‚ðŒvŽZ
	CVector2D screenPos = Base::GetScreenPos(m_pos);

	if (screenPos.x > SCREEN_WIDTH + 50 || screenPos.x < -50) {
		SetKill();
	}


}

void Bullet::Draw() {
	CVector2D screenPos = GetScreenPos(m_pos);

	m_img.SetPos(screenPos);
	m_img.Draw();


}

void Bullet::Collision(Base* b) {

}