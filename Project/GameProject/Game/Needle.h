#pragma once 
#include "../Base/Base.h"
class Needle : public Base {
private:
CImage m_img;
bool m_Flip;
public: Needle(const CVector2D& pos,bool Flip);
	  void Draw();
	  void Collision(Base* b);
};
