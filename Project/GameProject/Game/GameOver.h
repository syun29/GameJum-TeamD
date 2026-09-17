#pragma once
#include "Base/Base.h"

class GameOver : public Base
{
public:

	CImage m_img;

private:

	GameOver();
	void Update()override;
	void Draw()override;
};