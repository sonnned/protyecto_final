#include "firstlevelscene.h"

FirstLevelScene::FirstLevelScene()
{
    //player = new Player(100, 10, 10, 10, 0, 0, 3, ":/spritres/characters/Rick.png", 1000);
}

FirstLevelScene::~FirstLevelScene()
{
    delete player;
}
