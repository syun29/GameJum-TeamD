#include "Needle.h"

Needle::Needle(const CVector2D& pos,bool Flip) : Base(eType_Needle) {
	m_img = COPY_RESOURCE("Needle", CImage);
	m_pos = pos;	
	m_img.SetSize(64*1.2, 64 * 1.2);
	m_img.SetCenter(32 * 1.3, 64 * 1.3);
	m_rect = CRect(-24 * 1.6, -48 * 1.6, 24 * 1.6, 0 * 1.6);
	m_Flip = Flip;
}
void Needle::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	m_img.SetFlipV(m_Flip);
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
