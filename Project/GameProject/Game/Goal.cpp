#include "Goal.h"
#include "Field.h"
#include "Player.h"
#include "UI.h"
#include "GameClear.h"
#include "Enemy.h"
#include "SceneChange.h"

int Goal::m_area = 1;

Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {
    m_img = COPY_RESOURCE("Goal", CImage);
    m_pos = pos;
    m_img.SetSize(180, 90);
    m_img.SetCenter(90, 45);
    m_rect = CRect(-90, -45, 90, 45);
    m_is_goal = false;
}
void Goal::AreaChange()
{
    Base::KillAll();

    new Field(m_area);

    switch (m_area)
    {
    case 1:
        new Player(CVector2D(321, 1329), false);
        new Enemy(CVector2D(2171, 769), false);
        new Goal(CVector2D(4800, 1290));
        new UI();
        break;
    case 2:
        new Player(CVector2D(256, 1329), false);
        new Enemy(CVector2D(1576, 559), false);
        new Enemy(CVector2D(3091, 349), false);
        new Goal(CVector2D(2300, 730));
        new UI();
        break;
    case 3:
        new GameClear();
        break;
    }

    m_area++;
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

        if (CollisionRect(this, b)&&m_is_goal==false)
        {
            if (m_area == 3)
            {
                AreaChange();
            }
            else
            {
                new SceneChange();
                m_is_goal = true;
            }

        }
    }
}
