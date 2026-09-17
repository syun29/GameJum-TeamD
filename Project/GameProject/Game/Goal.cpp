#include "Goal.h"
#include "Field.h"
#include "Player.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {
    m_img = COPY_RESOURCE("Goal", CImage);
    m_pos = pos;
    m_img.SetSize(180, 90);
    m_img.SetCenter(90, 45);
    m_rect = CRect(-90, -45, 90, 45);
    m_is_goal = false;
}
void Goal::Draw() {
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();
    //DrawRect();
}

void Goal::Collision(Base* b)
{
    switch (b->m_type)
    {
    case eType_Player:

        if (CollisionRect(this, b))
        {
            Base::KillAll();

            new Field(2);
            new Player(CVector2D(256, 540), false);
        }
    }
}
