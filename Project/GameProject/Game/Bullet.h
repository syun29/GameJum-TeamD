#pragma once
#include"../Base/Base.h"

class Bullet : public Base
{
public:
	CImage m_img;
	int m_dir = 1;	//1=âEÅA -1=ç∂

public:
	Bullet(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
