#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "../Title/Title.h"
#include "Goal.h"
#include "Needle.h"

Game::Game() :Base(eType_Scene)
{
    
    new Field(0);
    new Player(CVector2D(256, 540), false);
    new Needle(CVector2D(900, 1325));
    new Goal(CVector2D(3200, 1275));
}
void Game::Update()
{
    //プレイヤー死亡　ボタン１でゲームシーン終了
    if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
        //全てのオブジェクトを破棄
        Base::KillAll();
        //タイトルシーンへ
        new Title();
    }
}

