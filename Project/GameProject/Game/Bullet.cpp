#include"Bullet.h"


Bullet::Bullet(const CVector2D& pos) : Base(eType_Bullet)
{
	m_img = COPY_RESOURCE("Bullet", CImage);

	m_pos = pos;

	
}