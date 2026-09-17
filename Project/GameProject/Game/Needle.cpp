#include "Needle.h"

Needle::Needle(const CVector2D& pos) : Base(eType_Needle) {
	m_img = COPY_RESOURCE("Needle", CImage);
	m_pos = pos;
	m_img.SetSize(64, 64);
	m_img.SetCenter(32, 64);
}
void Needle::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}