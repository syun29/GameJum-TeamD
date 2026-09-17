#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "../Title/Title.h"
#include "Goal.h"
#include "Needle.h"
#include "UI.h"
#include "GameData.h"

Game::Game() :Base(eType_Scene)
{
    
    new Field(0);
    new Player(CVector2D(256, 540), false);
    new Goal(CVector2D(3200, 1275));

    

    new UI();
    m_cnt = 0;
}
void Game::Update()
{
    GameData::s_time--;

    //時間切れ → プレイヤー死亡扱い
    if (GameData::s_time <= 0) {
        Player* p = (Player*)Base::FindObject(eType_Player);
        if (p) {
            p->SetKill();   //プレイヤー死亡
        }
    }

    //プレイヤー死亡　ボタン１でゲームシーン終了
    if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
        //全てのオブジェクトを破棄
        Base::KillAll();
        //タイトルシーンへ
        new Title();
    }
}

