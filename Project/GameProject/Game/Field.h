#pragma once

#include"Base/Base.h"
#define MAP_WIDTH    50
#define MAP_HEIGHT		20
#define MAP_TIP_SIZE	70

class Field : public Base {
private:
	CImage m_img;
	CImage m_background;
	int m_stage_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Field();
	void Draw()override;
	int GetTip(const CVector2D& pos, int* tx = nullptr, int* ty = nullptr);
	int GetTip(int x, int y);
	int CollisionPoint(const CVector2D& pos);
	int CollisionRect(const CVector2D& pos, const CRect& rect);
};