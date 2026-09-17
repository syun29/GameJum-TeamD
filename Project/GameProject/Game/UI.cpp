#include"UI.h"
#include"GameData.h"

UI::UI() : Base(eType_UI)
{
	m_img = COPY_RESOURCE("UI", CImage);


}

void UI::Update()
{

}

void UI::Draw()
{
    int time = GameData::s_time / 60;   //•b‚É•ÏŠ·

    for (int i = 0; i < 7; i++, time /= 10) {
        int t = time % 10;

        m_img.SetRect(16 * t, 16, 16 * t + 16, 32);  //‰æ‘œ‚ÌØ‚è”²‚«
        m_img.SetSize(64, 64);

        m_img.SetPos(1700 - 64 * i, 50);  //‰Eã‚É•\Ž¦
        m_img.Draw();
    }
}