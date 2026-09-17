#include "Needle.h"

Needle::Needle(const CVector2D& pos) : Base(eType_Needle) {
	m_img = COPY_RESOURCE("Needle", CImage);
	m_pos = pos;	
	m_img.SetSize(64, 64);
	m_img.SetCenter(32, 64);
	m_rect = CRect(-24, -48, 24, 0);
}
void Needle::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}

void Needle::Collision(Base* b)
{
	switch (b->m_type)
	{
	case eType_Player:
		if (CollisionRect(this, b)) {
			b->SetKill();
		}
	}
}
