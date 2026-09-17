#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "../Title/Title.h"
#include "Goal.h"

Game::Game() :Base(eType_Scene)
{
    
    new Field();
    new Player(CVector2D(256, 540), false);
    
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

