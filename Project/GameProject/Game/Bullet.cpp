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
	m_rect = CRect(-24, -24, 24, 24);

	SOUND("Bullet")->Play();
}

void Bullet::Update() {
	
	const int move_speed = 15;

	
	m_pos.x += move_speed * m_dir;

	// ‰æ–Êã‚ÌˆÊ’u‚ðŒvŽZ
	CVector2D screenPos = Base::GetScreenPos(m_pos);

	if (screenPos.x > screenPos.x + 10.0f || screenPos.x < screenPos.x-10.0f) {
		SetKill();
	}


}

void Bullet::Draw() {
	CVector2D screenPos = GetScreenPos(m_pos);

	m_img.SetPos(screenPos);
	m_img.Draw();

	DrawRect();
}

void Bullet::Collision(Base* b)
{
	switch (b->m_type)
	{
	case eType_Enemy:

		if (Base::CollisionRect(this, b))
		{
			SOUND("Enemy")->Play();

			b->SetKill();
			SetKill();
		}
	}
}