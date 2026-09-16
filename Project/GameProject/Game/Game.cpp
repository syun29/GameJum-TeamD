#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "../Title/Title.h"
#include "Goal.h"

Game::Game() :Base(eType_Scene)
{
    new Title();
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